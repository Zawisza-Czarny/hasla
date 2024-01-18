#include "adddialog.h"

#include <QGridLayout>

AddDialog::AddDialog(QWidget *parent) : QDialog(parent)
{
    name = new QLabel("nick");
    passLabel = new QLabel("haslo");
    label = new QLabel("nazwa");
    add = new QPushButton("dodaj");
    close = new QPushButton("zamknij");

    nick = new QLineEdit;
    pass = new QLineEdit;
    desc = new QLineEdit;

    setWindowTitle("Dodawanie hasla");

    QGridLayout *gLayout = new QGridLayout;
    gLayout->setColumnStretch(1, 2);
    gLayout->addWidget(label, 0, 0);
    gLayout->addWidget(desc, 0, 1);
    gLayout->addWidget(name, 1, 0);
    gLayout->addWidget(nick, 1, 1);
    gLayout->addWidget(passLabel, 2, 0);
    gLayout->addWidget(pass, 2, 1);

    QHBoxLayout *boxLayout = new QHBoxLayout;

    boxLayout->addWidget(add);
    boxLayout->addWidget(close);

    gLayout->addLayout(boxLayout, 3, 1);

    QVBoxLayout *mainLayout = new QVBoxLayout;

    mainLayout->addLayout(gLayout);
    setLayout(mainLayout);

    connect(add, SIGNAL(clicked()), this, SLOT(accept()));
    connect(close, SIGNAL(clicked()), this, SLOT(reject()));
}
