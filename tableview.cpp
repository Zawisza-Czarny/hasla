#include "tableview.h"
#include <QMessageBox>
#include <QFile>
#include <QDataStream>
#include <QTableWidget>
#include <mainwindow.h>
TableView::TableView(QWidget *parent) : QTableView(parent)
{
    Model = new Password;
    setModel(Model);
    setSelectionBehavior(QAbstractItemView::SelectRows);
    show();
}

void TableView::readFromFile(QString filename)
{
    QFile file(filename);

    if (!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::information(this, tr("Nie można otworzyć pliku"), file.errorString());
        return ;
    }

    QList<QPair<QString, QString> > list = Model->getList();
    QList<QString> description = Model->getDescription();
    QDataStream in(&file);
    in >> description >> list;

    int i;

    if (list.isEmpty())
    {
        QMessageBox::information(this, tr("Błąd"), tr("Plik jest pusty"));
        return ;
    }
    else
    {
        for (i=0; i<list.size(); i++)
        {
            QPair<QString, QString> pair = list.at(i);
            addAction(description.at(i), pair.first, pair.second);
        }
    }
}

void TableView::saveToFile(QString filename)
{
    QFile file(filename);

    if (!file.open(QIODevice::WriteOnly))
    {
        QMessageBox::information(this, tr("Blad"), tr("Plik tylko do zapisu"));
    }

    QList<QPair<QString, QString> > list = Model->getList();
    QList<QString> description = Model->getDescription();
    QDataStream out(&file);
    out << description << list;

    file.close();
}

void TableView::addAction()
{
    AddDialog dialog;

    if (dialog.exec())
    {
        QString description = dialog.desc->text();
        QString username = dialog.nick->text();
        QString password = dialog.pass->text();

        addAction(description, username, password);
    }
}

void TableView::addAction(QString description, QString username, QString password)
{
    QList<QPair<QString, QString> > list = Model->getList();
    QPair<QString, QString> pair(username, password);

    if (!list.contains(pair))
    {
        Model->insertRows(0, 1, QModelIndex());
        QModelIndex a = Model->index(0, 0, QModelIndex());
        Model->setData(a, description, Qt::EditRole);
        a = Model->index(0, 1, QModelIndex());
        Model->setData(a, username, Qt::EditRole);
        a = Model->index(0, 2, QModelIndex());
        Model->setData(a, password, Qt::EditRole);
    }
    else
    {
        QMessageBox::information(this, tr("Kopia"), tr("Juz zostało dodane konto o tej nazwie").arg(username));
    }
}

void TableView::modAction()
{
    QModelIndexList indexes = selectionModel()->selectedIndexes();
    if (indexes.isEmpty())
        return;
    QModelIndex index, index1;
    index = indexes.at(0);
    index1 = Model->index(index.row(), 0, QModelIndex());
    QString username, password, description;
    QVariant varName = Model->data(index1, Qt::DisplayRole);
    description = varName.toString();
    index1 = Model->index(index.row(), 1, QModelIndex());
    varName = Model->data(index1, Qt::DisplayRole);
    username = varName.toString();
    index1 = Model->index(index.row(), 2, QModelIndex());
    varName = Model->data(index1, Qt::DisplayRole);
    password = varName.toString();

    AddDialog dialog;
    dialog.setWindowTitle(tr("Edycja"));
    dialog.desc->setText(description);
    dialog.nick->setText(username);
    dialog.pass->setText(password);

    if (dialog.exec())
    {
        QString descripMod = dialog.desc->text();
        QString usernameMod = dialog.nick->text();
        QString passwordMod = dialog.pass->text();
        index1 = Model->index(index.row(), 0, QModelIndex());
        Model->setData(index1, descripMod, Qt::EditRole);
        index1 = Model->index(index.row(), 1, QModelIndex());
        Model->setData(index1, usernameMod, Qt::EditRole);
        index1 = Model->index(index.row(), 2, QModelIndex());
        Model->setData(index1, passwordMod, Qt::EditRole);
    }
}

void TableView::delAction()
{
    QModelIndexList indexes = selectionModel()->selectedIndexes();
    if (indexes.isEmpty())
        return;
    QModelIndex index;
    index = indexes.at(0);
    int pos = index.row();
    Model->removeRows(pos, 1, QModelIndex());
}

void TableView::infoAction()
{
    QMessageBox::about(this, "Informacje", "Aplikacja stworzona przez Mateusza Tomczyka");
}


void TableView::clearAction()
{
    QModelIndexList indexes = selectionModel()->selectedIndexes();
    if (indexes.isEmpty())
        return;
    Model->removeRows(0, indexes.size(), QModelIndex());

}
