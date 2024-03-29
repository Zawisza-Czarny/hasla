#ifndef __TABLEVIEW_H
#define __TABLEVIEW_H

#include <QTableView>
#include "passwordmodel.h"
#include "adddialog.h"

class TableView : public QTableView
{
    Q_OBJECT

public:
    TableView(QWidget *parent = 0);

    Password *Model;

    void readFromFile(QString filename);
    void saveToFile(QString filename);

public slots:
    void addAction();
    void modAction();
    void delAction();
    void infoAction();
    void clearAction();

private:
    void addAction(QString description, QString username, QString password);



};

#endif
