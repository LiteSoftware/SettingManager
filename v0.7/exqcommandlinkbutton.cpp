#include "exqcommandlinkbutton.h"
#include <QMessageBox>

ExQCommandLinkButton::ExQCommandLinkButton(QWidget *parent):
    QCommandLinkButton(parent)
{

}

ExQCommandLinkButton::ExQCommandLinkButton(const QString &text, QWidget *parent):
    QCommandLinkButton(text,parent)
{

}

ExQCommandLinkButton::ExQCommandLinkButton(const QString &text, const QString &description, QWidget *parent):
    QCommandLinkButton(text,description,parent)
{

}

void ExQCommandLinkButton::focusInEvent(QFocusEvent *e)
{
    emit sfocusInEvent(e);
}
