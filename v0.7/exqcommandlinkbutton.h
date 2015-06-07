#ifndef EXQCOMMANDLINKBUTTON_H
#define EXQCOMMANDLINKBUTTON_H

#include <QCommandLinkButton>

class ExQCommandLinkButton : public QCommandLinkButton
{
    Q_OBJECT
public:
    explicit ExQCommandLinkButton(QWidget *parent = 0);
    ExQCommandLinkButton(const QString & text, QWidget * parent = 0);
    ExQCommandLinkButton(const QString & text, const QString & description, QWidget * parent = 0);
protected:
    void focusInEvent(QFocusEvent * e);
private:

signals:
    void sfocusInEvent(QFocusEvent * e);
};

#endif // EXQCOMMANDLINKBUTTON_H
