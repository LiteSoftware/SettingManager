#ifndef SETTINGDIALOG_H
#define SETTINGDIALOG_H

#include <QDialog>

namespace Ui {
class cSettingDialog;
}

class cSettingDialog : public QDialog
{
    Q_OBJECT

public:
    explicit cSettingDialog(QWidget *parent = 0);
    ~cSettingDialog();

private:
    Ui::cSettingDialog *ui;
};

#endif // SETTINGDIALOG_H
