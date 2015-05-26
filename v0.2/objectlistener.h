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

#ifndef OBJECTLISTENER_H
#define OBJECTLISTENER_H

#include <QObject>

#include "mainwindow.h"

class ObjectListener : public QObject
{
    Q_OBJECT
public:
    explicit ObjectListener(QObject *parent = 0);

private:
    class MainWindow *wnd;
    void openFile   (bool newfile);
    void saveFile   (bool save_as, int index);
signals:

public slots:
    void menuClicked();
    void menuClicked(QAction* action);
    void tableDoubleClicked(const QModelIndex & index);
    void dialogAccepted(QString *_title,int _type,QString *_text,bool _createnew);
    void CloseWindow(QCloseEvent *event);
};

#endif // OBJECTLISTENER_H
