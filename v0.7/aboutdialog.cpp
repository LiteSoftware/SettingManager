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
#include "aboutdialog.h"
#include "ui_aboutdialog.h"

#include "revision.h"

cAboutDialog::cAboutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cAboutDialog)
{
    ui->setupUi(this);
    ui->lineEdit->setText(QString("%1").arg((double)APP_VERSION));
}

cAboutDialog::~cAboutDialog()
{
    delete ui;
}

void cAboutDialog::on_commandLinkButton_clicked()
{
    QApplication::aboutQt();
}
