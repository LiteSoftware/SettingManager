#-------------------------------------------------
#
# Project created by QtCreator 2015-02-21T10:31:03
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SettingManager
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    objectlistener.cpp \
    editdialog.cpp

HEADERS  += mainwindow.h \
    objectlistener.h \
    editdialog.h

FORMS    += mainwindow.ui \
    editdialog.ui
