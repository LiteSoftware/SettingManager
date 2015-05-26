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

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    listener=new ObjectListener(this);

    actionNew = new QAction("New",this);
    actionQuit = new QAction("Quit",this);
    actionOpen = new QAction("Open",this);
    actionSave = new QAction("Save",this);
    actionSave_as = new QAction("Save As...",this);
    actionClose = new QAction("Close",this);

    menuFile = new QMenu("File",ui->menuBar);
    ui->menuBar->addMenu(menuFile);

    menuFile->addAction(actionNew);
    menuFile->addAction(actionOpen);
    menuFile->addAction(actionSave);
    menuFile->addAction(actionSave_as);
    menuFile->addAction(actionClose);
    menuFile->addSeparator();
    menuFile->addAction(actionQuit);
    connect(menuFile,SIGNAL(triggered(QAction*)),listener,SLOT(menuClicked(QAction*)));

    tabs=new QTabWidget(this);

    editDialog=new EditDialog(this);
    connect(editDialog,SIGNAL(dialogAccepted(QString*,int,QString*,bool)),listener,SLOT(dialogAccepted(QString*,int,QString*,bool)));
    editDialog->setModal(true);
}

MainWindow::~MainWindow()
{
    delete editDialog;

    delete menuFile;
    delete actionNew;
    delete actionQuit;
    delete actionOpen;
    delete actionSave;
    delete actionSave_as;
    delete actionClose;

    for(int i=0;i<tables.size();i++)
    {
        delete tables[i];
    }

    delete tabs;
    delete listener;
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    client=this->geometry();
    QRect menurect=ui->menuBar->geometry();
    ui->line->setGeometry(client.width()/5,menurect.height(),2,client.height()-menurect.height());
    tabs->setGeometry(client.width()/5,menurect.height(),
                      client.width()-(client.width()/5),client.height()-menurect.height());
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    /*if()
    {
        QMessageBox::about(this,"Warning","You not disconnected!!!");
        event->ignore();
    }else
    {
        event->accept();
    }*/
    emit CloseWindow(event);
}
