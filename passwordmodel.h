#ifndef __PASSWORD_MODEL_H
#define __PASSWORD_MODEL_H

#include <QAbstractTableModel>
#include <QList>

#define NUMBEROFCOLUMNS 3

class Password : public QAbstractTableModel
{
    Q_OBJECT
public:
    Password(QObject *parent = 0);
    int rowCount(const QModelIndex &parent) const Q_DECL_OVERRIDE;
    int columnCount(const QModelIndex &parent) const Q_DECL_OVERRIDE;
    QVariant data(const QModelIndex &index, int role) const Q_DECL_OVERRIDE;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const Q_DECL_OVERRIDE;
    Qt::ItemFlags flags(const QModelIndex &index) const Q_DECL_OVERRIDE;
    bool insertRows(int position, int rows, const QModelIndex &index = QModelIndex()) Q_DECL_OVERRIDE;
    bool removeRows(int position, int rows, const QModelIndex &index = QModelIndex()) Q_DECL_OVERRIDE;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) Q_DECL_OVERRIDE;

    QList<QPair<QString, QString> > getList();
    QList<QString> getDescription();
private:
    QList<QPair<QString, QString> > list;
    QList<QString> description;
};

#endif
