#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QTableView>
#include <QSqlError>
#include <QTableWidget>

//--- параметры драйвера БД ---//
#define POSTGRE_DRIVER "QPSQL"
#define DB_NAME "MyDB"
//-----------------------------//

//Количество полей данных необходимых для подключения к БД
#define NUM_DATA_FOR_CONNECT_TO_DB 5

//Перечисление полей данных
enum fieldsForConnect{
    hostName = 0,
    dbName = 1,
    login = 2,
    pass = 3,
    port = 4
};

//Типы запросов
enum requestType{

    requestAllFilms = 1,
    requestComedy   = 2,
    requestHorrors  = 3

};
//модель запроса
enum class modelType{
    query = 1,
    table
};

class DataBase : public QObject
{
    Q_OBJECT

public:
    explicit DataBase(QObject *parent = nullptr);
    ~DataBase();

    void AddDataBase(QString driver, QString nameDB = "");//подтягиваем драйвер БД
    void DisconnectFromDataBase(QString nameDb = "");//отключаемся
    void RequestToDB(QString request);//запрос запросная модель
    void RequestToTableDB();//запрос табличная модель
    QSqlError GetLastError(void);//прочитать последнюю ошибку работы с БД
    void ConnectToDataBase(QVector<QString> dataForConnect);//подключаемся к БД
    void ReadAnswerFromDB();//покажем результаты запроса к БД
    void BindView(QTableView* view_);//подтягиваем таблицу для вывода результатов запроса

signals:
   void sig_SendStatusConnection(bool);//сигнал показывает статус соединения с БД
   void sig_SendStatusRequest(QSqlError err);//сигнал показывает, что произведен запрос к БД и нужно выводить результат



private:
    QSqlDatabase* dataBase;//наша база
    QSqlQueryModel* qModel;//здесь храним результаты запроса
    QSqlTableModel* tModel;//здесь храним результаты запроса
    QTableView* view;//здесь отображаем результаты запроса

    modelType currentRequestedModel;//здесь храним выбранную модель запроса


};

#endif // DATABASE_H
