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

#include "editdialog.h"
#include "ui_editdialog.h"

#include "mainwindow.h"
#include <QStandardItemModel>
#include <QStandardItem>

EditDialog::EditDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditDialog)
{
    ui->setupUi(this);
    connect(this,SIGNAL(accepted()),this,SLOT(Accepted()));
    connect(ui->lineEdit,SIGNAL(textChanged(QString)),this,SLOT(textChanged(QString)));
}

EditDialog::~EditDialog()
{
    delete ui;
}

void EditDialog::show(QString *_title, int _type, QString *_text, bool _createnew)
{
    createnew=_createnew;

    if(_createnew)
    {
        ui->lineEdit->setText("New variable");
        ui->typeComboBox->setCurrentIndex(2);
        ui->varLineEdit->setText("");
    }else
    {
        ui->lineEdit->setText(*_title);
        ui->typeComboBox->setCurrentIndex(_type);
        ui->varLineEdit->setText(*_text);
        title=*_title;
    }
    ui->typeComboBox->setEnabled(false);//типы данных неподдерживаются
    ui->buttonBox->setStandardButtons(QDialogButtonBox::Cancel | QDialogButtonBox::Ok);
    ui->scrollArea->hide();
    QDialog::show();
}

bool EditDialog::getParam() const
{
    return createnew;
}

void EditDialog::setParam(bool _createnew)
{
    createnew=_createnew;
}

void EditDialog::Accepted()
{
    QString _title=ui->lineEdit->text();
    QString _text=ui->varLineEdit->text();

    emit dialogAccepted(&_title,
                        ui->typeComboBox->currentIndex(),
                        &_text,createnew);
}
/*
 * textChanged
 * здесь происходит проверка на совпадения с таблицей
*/
void EditDialog::textChanged(const QString &text)
{
    MainWindow *wnd=static_cast<MainWindow *>(this->parent());
    if(!wnd)
    {
        MSGDEBUG(this,"Error no parent");
        return;
    }

    int index=wnd->tabs->currentIndex();
    QStandardItemModel *model=static_cast<QStandardItemModel*>(wnd->tables[index]->model());
    if(!model)
        QMessageBox::about(wnd,"DoubleClicked","Error model");
    //int curRow=wnd->tables[index]->currentIndex().row();
    int countRow=model->rowCount();
    ui->buttonBox->setStandardButtons(QDialogButtonBox::Cancel | QDialogButtonBox::Ok);
    ui->scrollArea->hide();
    for(int i=0;i<countRow-1;i++)
    {
        QStandardItem *item=model->item(i);
        if(item->text()==text)
        {
            if(!createnew && text==title)
                return;
            //MSGDEBUG(this,"equals");
            ui->buttonBox->setStandardButtons(QDialogButtonBox::Cancel);
            ui->scrollArea->show();
            return;
        }
    }
}

