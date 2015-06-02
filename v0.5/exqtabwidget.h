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

#ifndef EXQTABWIDGET_H
#define EXQTABWIDGET_H

#include <qtabwidget.h>

class ExQTabWidget: public QTabWidget
{
    Q_OBJECT
public:
    explicit ExQTabWidget(QWidget *parent = 0);
private:
    void keyPressEvent(QKeyEvent * e);
    void mousePressEvent(QMouseEvent * event);
signals:
    void keyPressed(QKeyEvent * e);
    void mousePressed(QMouseEvent * event);
};

#endif // EXQTABWIDGET_H
