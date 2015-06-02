/********************************************************************************
** Form generated from reading UI file 'aboutdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTDIALOG_H
#define UI_ABOUTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_cAboutDialog
{
public:
    QCommandLinkButton *commandLinkButton;
    QTextBrowser *textBrowser;

    void setupUi(QDialog *cAboutDialog)
    {
        if (cAboutDialog->objectName().isEmpty())
            cAboutDialog->setObjectName(QStringLiteral("cAboutDialog"));
        cAboutDialog->resize(382, 508);
        cAboutDialog->setMinimumSize(QSize(382, 508));
        cAboutDialog->setMaximumSize(QSize(382, 508));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        cAboutDialog->setPalette(palette);
        commandLinkButton = new QCommandLinkButton(cAboutDialog);
        commandLinkButton->setObjectName(QStringLiteral("commandLinkButton"));
        commandLinkButton->setGeometry(QRect(110, 440, 172, 41));
        textBrowser = new QTextBrowser(cAboutDialog);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(10, 10, 361, 421));

        retranslateUi(cAboutDialog);

        QMetaObject::connectSlotsByName(cAboutDialog);
    } // setupUi

    void retranslateUi(QDialog *cAboutDialog)
    {
        cAboutDialog->setWindowTitle(QApplication::translate("cAboutDialog", "About", 0));
        commandLinkButton->setText(QApplication::translate("cAboutDialog", "About QT", 0));
        textBrowser->setHtml(QApplication::translate("cAboutDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt; font-weight:600;\">SettingManager</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><img src=\":/pictures/forms/logo_big\" /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">This app is for friendly presentation (in the form of tables) and editing configuration files (ini)</span></p>\n"
"<p styl"
                        "e=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:9pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">Vendor:	</span><span style=\" font-size:12pt; font-weight:600;\">j </span><span style=\" font-size:12pt; font-weight:600; vertical-align:super;\">a </span><span style=\" font-size:12pt; font-weight:600;\">v </span><span style=\" font-size:12pt; font-weight:600; vertical-align:super;\">a </span><span style=\" font-size:12pt; font-weight:600;\">v </span><span style=\" font-size:12pt; font-weight:600; vertical-align:sub;\">i </span><span style=\" font-size:12pt; font-weight:600;\">r </span><span style=\" font-size:12pt; font-weight:600; vertical-align:sub;\">y </span><span style=\" font-size:12pt; font-weight:600;\">s</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; m"
                        "argin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">web:	</span><span style=\" font-size:8pt; font-weight:600;\">http://java-virys.narod.ru</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">e-mail:	</span><span style=\" font-size:8pt; font-weight:600;\">j</span><span style=\" font-size:8pt; font-weight:600; text-decoration: underline;\">avavirys@mail.ru</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt; font-weight:600; text-decoration: underline;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600; text-decoration: underline;\">WEB-maney:</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bot"
                        "tom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600; text-decoration: underline;\">U298164948334</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600; text-decoration: underline;\">R419967703201</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600; text-decoration: underline;\">Z140565878867</span></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class cAboutDialog: public Ui_cAboutDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTDIALOG_H
