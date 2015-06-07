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
#include <QMenu>
#include <QCursor>

static int              curIndex;       //текущий элемент таблицы
static QList<QString>   lsavePath;      //
static QList<bool>      lisSaveSelect;  //флаг проверки, есть ли путь сохранения каждой таблицы
static QList<bool>      lisEditable;    //флаг индикатор сохранения


ObjectListener::ObjectListener(QObject *parent) :
    QObject(parent)
{
    wnd=static_cast<MainWindow*>(parent);
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
    ExQTableView *table=new ExQTableView(wnd);
    connect(table,SIGNAL(doubleClicked(QModelIndex)),
            this,SLOT(tableDoubleClicked(QModelIndex)));
    connect(table,SIGNAL(mousePressed(QMouseEvent*)),
            this,SLOT(TabView_mousePressed(QMouseEvent*)));
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

    if(!newfile)
    {
        QString fname;
        cStrUtils::replaceFileName(&fname,filePath);
        wnd->tabs->addTab(table,QIcon(":/pictures/forms/table"),fname);//имя вкладки==имя файла
    }else
    {
        wnd->tabs->addTab(table,QIcon(":/pictures/forms/table"),"Noname");
    }

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
        QString fstr;
        cStrUtils::replaceFileName(&fstr,lsavePath[index]);
        wnd->tabs->setTabText(index,fstr);
    }
}

void ObjectListener::deleteItem(int tab)
{
    if(tab<0)//проверка коректности tab
        return;//Выходим

    QStandardItemModel *model=static_cast<QStandardItemModel*>(wnd->tables[tab]->model());
    if(!model)
    {
        MSGDEBUG(wnd,"Error delete item");
        return;
    }
    QItemSelectionModel *mod=wnd->tables[tab]->selectionModel();
    if(!mod)
        return;
    QModelIndexList select=mod->selectedRows();
    if(select.length()>0)
    {
        int item=select.at(0).row();//получение текущего итема
        if(item!=model->rowCount()-1)//последний не трогаем
        {
            QMessageBox msg;
            msg.setText("Are you sure you want to delete the record ?");
            msg.setStandardButtons(QMessageBox::Cancel | QMessageBox::Ok);
            msg.setDefaultButton(QMessageBox::Ok);
            int ret = msg.exec();
            switch(ret)
            {
            case QMessageBox::Cancel:
                return;
            }
            model->removeRow(item);
        }
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
    }else if(action==wnd->actionAbout)
    {
        wnd->about->show();
    }else if(action==wnd->pActionEdit.data())
    {
        index=wnd->tabs->currentIndex();
        if(index>-1)
            tableDoubleClicked(wnd->tables[index]->currentIndex());
    }else if(action==wnd->pActionRemove.data())
    {
        index=wnd->tabs->currentIndex();
        if(index>-1)
            deleteItem(index);
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
        int     _type=0;
        QString _var;
        bool    _createnew=false;
        if(index.row()<0)
            return;
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

void ObjectListener::TabWidget_keyPressed(QKeyEvent *e)
{
    int code=e->key();
    int ind=-1;
    if(code==Qt::Key_Delete)
    {
        ind=wnd->tabs->currentIndex();
        deleteItem(ind);
    }
    if(code==Qt::Key_Return)
    {
        ind=wnd->tabs->currentIndex();
        tableDoubleClicked(wnd->tables[ind]->currentIndex());
    }

}

void ObjectListener::TabView_mousePressed(QMouseEvent *event)
{
    int index=-1;
    if(event->button()==Qt::RightButton)
    {
        index=wnd->tabs->currentIndex();
        QPoint p=QCursor::pos();
        QRect area=wnd->pMenuEdit->geometry();
        area.setLeft(p.x());
        area.setTop(p.y());
        wnd->pMenuEdit->setGeometry(area);
        QAction *result=wnd->pMenuEdit->exec();
        if(result==wnd->pActionEdit.data())
        {
            tableDoubleClicked(wnd->tables[index]->currentIndex());
        }else if(result==wnd->pActionRemove.data())
        {
            deleteItem(index);
        }
    }
    event->accept();
}

void ObjectListener::Button_clicked()
{
    QObject * object = QObject::sender();
    if (!object)
        return;

    int index=-1;
    ExQCommandLinkButton * button = static_cast<ExQCommandLinkButton *>(object);
    if(button==wnd->pBtnNew.data())
    {
        index=wnd->tabs->currentIndex();
        if(index>-1)
            wnd->editDialog->show();
    }
    else if(button==wnd->pBtnEdit.data())
    {
        index=wnd->tabs->currentIndex();
        if(index>-1)
        {
            tableDoubleClicked(wnd->tables[index]->currentIndex());
        }
    }else if(button==wnd->pBtnDel)
    {
        deleteItem(wnd->tabs->currentIndex());
    }
}

