#ifndef DATABASE_H
#define DATABASE_H

#include <QTableWidget>
#include <QObject>
#include <QSqlError>
#include <QSqlDatabase>
#include  <QSqlTableModel>

class DataBase : public QObject
{
public:
    explicit DataBase(QObject *parent = nullptr);
    ~DataBase();
private:
    QSqlDatabasePrivate* dataBase;
};

#endif // DATABASE_H
