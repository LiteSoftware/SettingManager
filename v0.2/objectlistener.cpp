/*
 * Copyright 2015 Vitaliy Sychеv

 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at

 *    http://www.apache.org/licenses/LICENSE-2.0

 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
*/

#include "objectlistener.h"
#include <QMessageBox>
#include <QStandardItemModel>
#include <QFileDialog>
#include <QCloseEvent>

static int              count;
static int              curIndex;
static QList<QString>   lsavePath;
static QList<bool>      lisSaveSelect;//флаг проверки, есть ли путь сохранения каждой таблицы
static QList<bool>      lisEditable;  //флаг индикатор сохранения


ObjectListener::ObjectListener(QObject *parent) :
    QObject(parent)
{
    wnd=static_cast<MainWindow*>(parent);
    count=0;
    connect(wnd,SIGNAL(CloseWindow(QCloseEvent*)),this,SLOT(CloseWindow(QCloseEvent*)));
}

void ObjectListener::openFile(bool newfile)
{
    QSettings *sFile=NULL;
    QStringList str_list;
    QString filePath;
    if(!newfile)
    {
        filePath=QFileDialog::getOpenFileName(wnd,"Open file...",QString(),tr("File setting (*.jsg)"));
        if(filePath.isEmpty())
            return;
        sFile=new QSettings(filePath,QSettings::IniFormat);

        str_list=sFile->allKeys();
    }
    //-------------------------------------------------------
    QTableView *table=new QTableView(wnd);
    connect(table,SIGNAL(doubleClicked(QModelIndex)),
            this,SLOT(tableDoubleClicked(QModelIndex)));
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    table->setSelectionBehavior(QAbstractItemView::SelectRows);
    table->setSelectionMode(QAbstractItemView::SingleSelection);
    QStandardItemModel *model=new QStandardItemModel(0,3,table);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Name") );
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Type") );
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Value"));
    table->setModel(model);
    table->setColumnWidth(0,125);
    table->setColumnWidth(1,50);
    table->setColumnWidth(2,200);

    //--------------------------------------------------------
    for(int i=0;i<str_list.length();i++)
    {
        QStandardItem *addItemRow=new QStandardItem(str_list.at(i));

        QList<QStandardItem *>list;
        list.append(addItemRow);
        list.append(new QStandardItem("2"));
        list.append(new QStandardItem(sFile->value(str_list.at(i)).toString()));
        model->appendRow(list);
    }
    //---------------------------------------------------------
    QStandardItem *addSysItemRow=new QStandardItem("Add new setting");

    QList<QStandardItem *>list;
    list.append(addSysItemRow);
    list.append(new QStandardItem(""));
    list.append(new QStandardItem(""));
    model->appendRow(list);

    wnd->tabs->addTab(table,"New tab "+QString("%1").arg(++count));
    wnd->tables.append(table);
    lisSaveSelect.append(!newfile);
    lsavePath.append(filePath);//сохранили путь к файлу
    lisEditable.append(true);//
    //----------------------------------------------------------
    existdel(sFile);
}

void ObjectListener::saveFile(bool save_as,int index)
{
    if(index>-1){
        if(save_as)
        {
            lisSaveSelect[index]=false;
        }
        if(!lisSaveSelect.at(index)){
            QString filePath=QFileDialog::getSaveFileName(wnd,"Save file as...",QString(),tr("File setting (*.jsg)"));
            if(filePath.isEmpty())
                return;
            lisSaveSelect[index]=true;
            lsavePath[index]=filePath;
        }
        QFile file(lsavePath[index]);
        if(file.exists())
            file.remove();
        QSettings sFile(lsavePath[index],QSettings::IniFormat);

        QStandardItemModel *model=static_cast<QStandardItemModel*>(wnd->tables[index]->model());
        for(int row=0;row<model->rowCount()-1;row++)
        {
            sFile.setValue(model->item(row,0)->text(),QVariant(model->item(row,2)->text()));
        }
        lisEditable[index]=false;
    }
}

void ObjectListener::menuClicked()
{
    QObject * object = QObject::sender();
    if (!object)
        return;

    //QAction * action = static_cast<QAction *>(object);
}

void ObjectListener::menuClicked(QAction *action)
{
    int index=-1;
    if(action==wnd->actionQuit)
    {
        wnd->close();
    }else if(action==wnd->actionNew)
    {
        openFile(true);
    }else if(action==wnd->actionClose)
    {
        index=wnd->tabs->currentIndex();
        if(index>-1)
        {
            count--;
            wnd->tabs->removeTab(index);
            delete wnd->tables.at(index);
            wnd->tables.removeAt(index);
            lisSaveSelect.removeAt(index);
            lsavePath.removeAt(index);
            lisEditable.removeAt(index);
        }
    }else if(action==wnd->actionSave)
    {
        index=wnd->tabs->currentIndex();
        saveFile(false,index);

    }else if(action==wnd->actionSave_as)
    {
        index=wnd->tabs->currentIndex();
        saveFile(true,index);
    }else if(action==wnd->actionOpen)
    {
        openFile(false);
    }
}

void ObjectListener::tableDoubleClicked(const QModelIndex &index)
{
    int i=-1;
    i=wnd->tabs->currentIndex();
    if(i>-1)
    {
        QStandardItemModel *model=static_cast<QStandardItemModel*>(wnd->tables[i]->model());
        if(!model)
            QMessageBox::about(wnd,"DoubleClicked","Error model");
        QString _title;
        int     _type;
        QString _var;
        bool    _createnew;
        if(index.row()==model->rowCount()-1)
        {
            //Открыть диалог для создания нового значения
            _createnew=true;
        }else{
            _title=model->item(index.row(),0)->text();
            _type=model->item(index.row(),1)->text().toInt();
            _var=model->item(index.row(),2)->text();
            curIndex=index.row();
            _createnew=false;
        }
        wnd->editDialog->show(&_title,_type,&_var,_createnew);
    }
}

void ObjectListener::dialogAccepted(QString *_title=0,int _type=0,QString *_text=0,bool _createnew=true)
{
    //После успешного редактирования сюда будет направлены все значения
    int ind=-1;
    ind=wnd->tabs->currentIndex();
    if(ind>-1)
    {
        QStandardItemModel *model=static_cast<QStandardItemModel*>(wnd->tables[ind]->model());
        if(!model)
            QMessageBox::about(wnd,"DoubleClicked","Error model");
        if(_createnew)
        {
            //Добавление нового итема
            model->setItem(model->rowCount()-1,0,new QStandardItem(*_title));
            model->setItem(model->rowCount()-1,1,new QStandardItem(QString("%1").arg(_type)));
            model->setItem(model->rowCount()-1,2,new QStandardItem(*_text));
            //----------------------добавление в самый конец--------------
            QStandardItem *addItemRow=new QStandardItem("Add new setting");
            QList<QStandardItem *>list;
            list.append(addItemRow);
            list.append(new QStandardItem(""));
            list.append(new QStandardItem(""));
            model->appendRow(list);
            //------------------------------------------------------------

        }else
        {
            //Редактируем существующий
            model->setItem(curIndex,0,new QStandardItem(*_title));
            model->setItem(curIndex,1,new QStandardItem(QString("%1").arg(_type)));
            model->setItem(curIndex,2,new QStandardItem(*_text));
        }
        lisEditable[ind]=true;
    }

}

void ObjectListener::CloseWindow(QCloseEvent *event)
{
    QList<int> list;//список индексов файлов которые не закрытые

    for(int i=0;i<lisEditable.length();i++)
    {
        if(lisEditable[i])
        {
            list.append(i);//добавляем новый индекс
        }

    }
    if(list.length()!=0)
    {
        QMessageBox msg;
        msg.setText("The documents has been modified");
        msg.setInformativeText("Do you want to save your changes?");
        msg.setStandardButtons(QMessageBox::SaveAll | QMessageBox::Discard |
                                                            QMessageBox::Cancel);
        msg.setDefaultButton(QMessageBox::SaveAll);
        int ret = msg.exec();
        switch (ret) {
        case QMessageBox::SaveAll:
          // Save was clicked
            for(int i=0;i<list.length();i++)
            {
                saveFile(false,list[i]);
            }
            break;
        case QMessageBox::Discard:
          // Don't Save was clicked
            return;
        case QMessageBox::Cancel:
          // Cancel was clicked
            event->ignore();
        }
    }
}

