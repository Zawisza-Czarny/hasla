#ifndef __ADDDIALOG_H
#define __ADDDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>

class AddDialog : public QDialog
{
    Q_OBJECT

public:
    AddDialog(QWidget *parent = 0);

    QLineEdit *nick;
    QLineEdit *pass;
    QLineEdit *desc;

private:
    QLabel *name;
    QLabel *passLabel;
    QLabel *label;
    QPushButton *add;
    QPushButton *close;
};

#endif
