/********************************************************************************
** Form generated from reading UI file 'settingdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGDIALOG_H
#define UI_SETTINGDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_cSettingDialog
{
public:
    QDialogButtonBox *buttonBox;
    QCheckBox *checkBox;

    void setupUi(QDialog *cSettingDialog)
    {
        if (cSettingDialog->objectName().isEmpty())
            cSettingDialog->setObjectName(QStringLiteral("cSettingDialog"));
        cSettingDialog->resize(446, 320);
        buttonBox = new QDialogButtonBox(cSettingDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(210, 270, 221, 41));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        checkBox = new QCheckBox(cSettingDialog);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(10, 40, 201, 17));

        retranslateUi(cSettingDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), cSettingDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), cSettingDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(cSettingDialog);
    } // setupUi

    void retranslateUi(QDialog *cSettingDialog)
    {
        cSettingDialog->setWindowTitle(QApplication::translate("cSettingDialog", "Dialog", 0));
        checkBox->setText(QApplication::translate("cSettingDialog", "Show dialog with delete", 0));
    } // retranslateUi

};

namespace Ui {
    class cSettingDialog: public Ui_cSettingDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGDIALOG_H
