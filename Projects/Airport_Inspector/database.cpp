#include "database.h"

DataBase::DataBase(QObject *parent)
    : QObject{parent}
{

    //dataBase = new QSqlDatabase();
     dataBase = new QSqlDatabase(QSqlDatabase::addDatabase("QPSQL"));


}
void DataBase::AddDataBase(QString driver, QString nameDB)
{

     *dataBase = QSqlDatabase::addDatabase(driver, nameDB);

}
void DataBase::ConnectToDataBase(){

     dataBase->setHostName("981757-ca08998.tmweb.ru");
     dataBase->setDatabaseName(DB_NAME);
     dataBase->setUserName("netology_usr_cpp");
     dataBase->setPassword("CppNeto3");
     dataBase->setPort(5432);

     bool status;
     status = dataBase->open();
     emit sig_SendStatusConnection(status);
}
DataBase::~DataBase()
{
    delete dataBase;
}
