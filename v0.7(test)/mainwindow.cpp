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
    actionNew->setShortcut(QKeySequence("Ctrl+n"));
    actionQuit = new QAction(QIcon(":/pictures/menus/quit"),"Quit",this);
    actionQuit->setShortcut(QKeySequence("Ctrl+q"));
    actionOpen = new QAction(QIcon(":/pictures/menus/open"),"Open",this);
    actionOpen->setShortcut(QKeySequence("Ctrl+o"));
    actionSave = new QAction(QIcon(":/pictures/menus/save"),"Save",this);
    actionSave->setShortcut(QKeySequence("Ctrl+s"));
    actionSave_as = new QAction(QIcon(":/pictures/menus/save_as"),"Save As...",this);
    actionSave_as->setShortcut(QKeySequence("Ctrl+Alt+s"));
    actionClose = new QAction(QIcon(":/pictures/menus/close"),"Close",this);
    actionClose->setShortcut(QKeySequence("Ctrl+x"));

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
    actionAbout->setShortcut(QKeySequence("Ctrl+h"));
    menuHelp=new QMenu(QObject::tr("Help"),ui->menuBar);
    ui->menuBar->addMenu(menuHelp);

    menuHelp->addAction(actionAbout);

    connect(menuFile,SIGNAL(triggered(QAction*)),listener,SLOT(menuClicked(QAction*)));
    connect(menuHelp,SIGNAL(triggered(QAction*)),listener,SLOT(menuClicked(QAction*)));

    pBtnEdit=QSharedPointer<ExQCommandLinkButton>
            (new ExQCommandLinkButton(QObject::tr("Edit"),this));
    pBtnEdit->setIcon(QIcon(":/pictures/forms/edit_button"));

    pBtnNew=QSharedPointer<ExQCommandLinkButton>
            (new ExQCommandLinkButton(QObject::tr("Add"),this));
    pBtnNew->setIcon(QIcon(":/pictures/forms/add_button"));

    pBtnDel=QSharedPointer<ExQCommandLinkButton>
            (new ExQCommandLinkButton(QObject::tr("Delete"),this));
    pBtnDel->setIcon(QIcon(":/pictures/forms/delete"));

    connect(pBtnEdit.data(),SIGNAL(clicked()),listener,SLOT(Button_clicked()));
    connect(pBtnNew.data(),SIGNAL(clicked()),listener,SLOT(Button_clicked()));
    connect(pBtnDel.data(),SIGNAL(clicked()),listener,SLOT(Button_clicked()));

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

    //menues
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
    pBtnNew->setGeometry(4,21, ui->line->geometry().left()-5,35);
    pBtnEdit->setGeometry(4,pBtnNew->geometry().top()+pBtnNew->geometry().height()+5, ui->line->geometry().left()-5,35);
    pBtnDel->setGeometry(4,pBtnEdit->geometry().top()+pBtnEdit->geometry().height()+5, ui->line->geometry().left()-5,35);
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
