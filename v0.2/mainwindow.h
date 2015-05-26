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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "editdialog.h"
#include <objectlistener.h>

#include <QTabWidget>
#include <QTableWidget>
#include <QSettings>
#include <QList>
#include <QTableView>


#define existdel(obj) if(obj) (delete obj)

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Ui::MainWindow          *wnd;
    EditDialog              *editDialog;
    class ObjectListener    *listener;
    QTabWidget              *tabs;
    QMenu                   *menuFile;
    QMenu                   *menuHelp;
    QAction                 *actionNew;
    QAction                 *actionQuit;
    QAction                 *actionOpen;
    QAction                 *actionSave;
    QAction                 *actionSave_as;
    QAction                 *actionClose;
    QList<QTableView*>       tables;
protected:
    void closeEvent(QCloseEvent *event);
private:
    Ui::MainWindow          *ui;
    QRect                   client;
    void resizeEvent(QResizeEvent * event);
public slots:

signals:
    void CloseWindow(QCloseEvent *event);
};

#endif // MAINWINDOW_H
