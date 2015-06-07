#include "settingdialog.h"
#include "ui_settingdialog.h"

cSettingDialog::cSettingDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cSettingDialog)
{
    ui->setupUi(this);
}

cSettingDialog::~cSettingDialog()
{
    delete ui;
}
