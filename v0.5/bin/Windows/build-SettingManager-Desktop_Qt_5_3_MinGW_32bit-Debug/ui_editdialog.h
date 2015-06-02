/********************************************************************************
** Form generated from reading UI file 'editdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITDIALOG_H
#define UI_EDITDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EditDialog
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *typeLabel;
    QComboBox *typeComboBox;
    QLabel *varLabel;
    QLineEdit *varLineEdit;

    void setupUi(QDialog *EditDialog)
    {
        if (EditDialog->objectName().isEmpty())
            EditDialog->setObjectName(QStringLiteral("EditDialog"));
        EditDialog->resize(320, 240);
        buttonBox = new QDialogButtonBox(EditDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(10, 200, 301, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        formLayoutWidget = new QWidget(EditDialog);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(20, 20, 281, 171));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(formLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        lineEdit = new QLineEdit(formLayoutWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit);

        typeLabel = new QLabel(formLayoutWidget);
        typeLabel->setObjectName(QStringLiteral("typeLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, typeLabel);

        typeComboBox = new QComboBox(formLayoutWidget);
        typeComboBox->setObjectName(QStringLiteral("typeComboBox"));

        formLayout->setWidget(1, QFormLayout::FieldRole, typeComboBox);

        varLabel = new QLabel(formLayoutWidget);
        varLabel->setObjectName(QStringLiteral("varLabel"));

        formLayout->setWidget(2, QFormLayout::LabelRole, varLabel);

        varLineEdit = new QLineEdit(formLayoutWidget);
        varLineEdit->setObjectName(QStringLiteral("varLineEdit"));

        formLayout->setWidget(2, QFormLayout::FieldRole, varLineEdit);


        retranslateUi(EditDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), EditDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), EditDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(EditDialog);
    } // setupUi

    void retranslateUi(QDialog *EditDialog)
    {
        EditDialog->setWindowTitle(QApplication::translate("EditDialog", "Edit", 0));
        label->setText(QApplication::translate("EditDialog", "Name:", 0));
        lineEdit->setText(QApplication::translate("EditDialog", "Unknown", 0));
        typeLabel->setText(QApplication::translate("EditDialog", "Type:", 0));
        typeComboBox->clear();
        typeComboBox->insertItems(0, QStringList()
         << QApplication::translate("EditDialog", "boolean", 0)
         << QApplication::translate("EditDialog", "integer", 0)
         << QApplication::translate("EditDialog", "string", 0)
         << QApplication::translate("EditDialog", "array", 0)
        );
        varLabel->setText(QApplication::translate("EditDialog", "Var:", 0));
        varLineEdit->setText(QApplication::translate("EditDialog", "0", 0));
    } // retranslateUi

};

namespace Ui {
    class EditDialog: public Ui_EditDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITDIALOG_H
