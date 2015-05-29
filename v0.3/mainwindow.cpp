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
#include <QResizeEvent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":pictures/forms/logo_small"));

    about=new cAboutDialog(this);
    about->setWindowFlags(Qt::Tool);//окно с одной кнопкой
    about->setModal(true);

    listener=new ObjectListener(this);

    //---------------menu file-----------------
    actionNew = new QAction(QIcon(":/pictures/menus/new"),"New",this);
    actionQuit = new QAction(QIcon(":/pictures/menus/quit"),"Quit",this);
    actionOpen = new QAction(QIcon(":/pictures/menus/open"),"Open",this);
    actionSave = new QAction(QIcon(":/pictures/menus/save"),"Save",this);
    actionSave_as = new QAction(QIcon(":/pictures/menus/save_as"),"Save As...",this);
    actionClose = new QAction(QIcon(":/pictures/menus/close"),"Close",this);

    menuFile = new QMenu("File",ui->menuBar);
    ui->menuBar->addMenu(menuFile);

    menuFile->addAction(actionNew);
    menuFile->addAction(actionOpen);
    menuFile->addAction(actionSave);
    menuFile->addAction(actionSave_as);
    menuFile->addAction(actionClose);
    menuFile->addSeparator();
    menuFile->addAction(actionQuit);
    //----------------menu menuHelp----------------
    actionAbout=new QAction(QIcon(":/pictures/menus/help"),QObject::tr("About"),this);

    menuHelp=new QMenu(QObject::tr("Help"),ui->menuBar);
    ui->menuBar->addMenu(menuHelp);

    menuHelp->addAction(actionAbout);

    connect(menuFile,SIGNAL(triggered(QAction*)),listener,SLOT(menuClicked(QAction*)));
    connect(menuHelp,SIGNAL(triggered(QAction*)),listener,SLOT(menuClicked(QAction*)));

    btnEdit=new QPushButton(this);
    btnEdit->hide();
    btnEdit->setText(QObject::tr("Edit"));

    btnNew=new QPushButton(this);
    btnNew->hide();
    btnNew->setText(QObject::tr("New record"));

    btnDel=new QPushButton(this);
    btnDel->hide();
    btnDel->setText(QObject::tr("Delete"));

    tabs=new ExQTabWidget(this);//Визуальный контейнер для вкладок
    connect(tabs,SIGNAL(keyPressed(QKeyEvent*)),listener,SLOT(TabWidget_keyPressed(QKeyEvent*)));

    menuTableView=new QMenu(tabs);
    QList<QAction*> commands;
    actionEdit=new QAction(QIcon(":pictures/forms/edit"),QObject::tr("Edit"),this);
    actionRemove=new QAction(QIcon(":pictures/forms/delete"),QObject::tr("Remove"),
                             this);

    commands.append(actionEdit);
    commands.append(actionRemove);
    menuTableView->addActions(commands);

    editDialog=new EditDialog(this);
    connect(editDialog,SIGNAL(dialogAccepted(QString*,int,QString*,bool)),listener,SLOT(dialogAccepted(QString*,int,QString*,bool)));
    editDialog->setWindowFlags(Qt::Tool);//окно с одной кнопкой
    editDialog->setModal(true);
}

MainWindow::~MainWindow()
{
    delete editDialog;

    delete menuTableView;
    delete actionEdit;
    delete actionRemove;

    delete menuHelp;
    delete actionAbout;

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
    delete about;
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    client=this->geometry();
    QRect menurect=ui->menuBar->geometry();
    ui->line->setGeometry(client.width()/5,menurect.height(),2,client.height()-menurect.height());
    tabs->setGeometry(client.width()/5,menurect.height(),
                      client.width()-(client.width()/5),client.height()-menurect.height());
    btnEdit->setGeometry(4,21, ui->line->geometry().left()-5,24);
    btnNew->setGeometry(4,btnEdit->geometry().top()+btnEdit->geometry().height()+5, ui->line->geometry().left()-5,24);
    btnDel->setGeometry(4,btnNew->geometry().top()+btnNew->geometry().height()+5, ui->line->geometry().left()-5,24);
    event->accept();
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    emit CloseWindow(event);
    //-----------copyrites--------------
    QTime midnight(0,0,0);
    qsrand(midnight.secsTo(QTime::currentTime()));
    if(qrand() % 12>9)
    {
        QDesktopServices::openUrl(QUrl("http://java-virys.narod.ru/"));
    }
}
