#include "database.h"
//объект базы данных
DataBase::DataBase(QObject *parent)
    : QObject{parent}
{

    dataBase = new QSqlDatabase();//создаем объект базы данных
    qModel = new QSqlQueryModel(this);//объект запросной модель для запроса данных из БД

}

DataBase::~DataBase()
{
    delete dataBase;
}

/*!
 * \brief Метод добавляет БД к экземпляру класса QSqlDataBase
 * \param driver драйвер БД
 * \param nameDB имя БД (Если отсутствует Qt задает имя по умолчанию)
 */
void DataBase::AddDataBase(QString driver, QString nameDB)
{

    *dataBase = QSqlDatabase::addDatabase(driver, nameDB);//драйвер для соединения с БД
    //теперь можно создать объект табличной модели запроса
    tModel = new QSqlTableModel(this, *dataBase);//табличная модель для запроса данных из БД

}

/*!
 * \brief Метод подключается к БД
 * \param для удобства передаем контейнер с данными необходимыми для подключения
 * \return возвращает тип ошибки
 */
void DataBase::ConnectToDataBase(QVector<QString> data)
{
    //установим параметры подключения к БД
    dataBase->setHostName(data[hostName]);
    dataBase->setDatabaseName(data[dbName]);
    dataBase->setUserName(data[login]);
    dataBase->setPassword(data[pass]);
    dataBase->setPort(data[port].toInt());

    bool status;
    status = dataBase->open( );//откроем соединение с БД

    emit sig_SendStatusConnection(status);//сигнал о том, что подключились

}

void DataBase::ReadAnswerFromDB()
{
    // позволяют пользователю отображать данные при помощи классов QListView, QTableView и QTreeView
    switch(currentRequestedModel)//мы тип запроса сохранили
    {
    case modelType::query:
        //откуда берем данные
        view->setModel(qModel);//*view = QTableView укажем сохраненную модель запроса
        view->showColumn(0);//покажем первый столбец
        break;
    case modelType::table:
        //откуда берем данные
        view->setModel(tModel);//укажем сохраненую модель запроса
        view->hideColumn(0);//скроем лишние столбцы (в исходной таблице их 14)
        view->hideColumn(3);
        view->hideColumn(4);
        view->hideColumn(5);
        view->hideColumn(6);
        view->hideColumn(7);
        view->hideColumn(8);
        view->hideColumn(9);
        view->hideColumn(10);
        view->hideColumn(11);
        view->hideColumn(12);
        view->hideColumn(13);
        break;
    default:
        break;
    };

    view->setWindowTitle("ПоискКино");//укажем заголовок выводимой таблицы
    view->show();//выводим таблицу с результатами запроса

}


void DataBase::BindView(QTableView* view_)
{
    view = view_;//куда выводить результаты запроса
}


/*!
 * \brief Метод производит отключение от БД
 * \param Имя БД
 */
void DataBase::DisconnectFromDataBase(QString nameDb)
{

    *dataBase = QSqlDatabase::database(nameDb);//обязательно указываем какую БД закрыть
    dataBase->close();//закроем подключение

}
/*!
 * \brief Метод формирует запрос к БД.
 * \param request - SQL запрос
 * \return
 */
void DataBase::RequestToDB(QString request)
{
    //запросим данные через запросную модель
    qModel->setQuery(request, *dataBase);//определяем запрос и к какой БД
    qModel->setHeaderData(0, Qt::Horizontal, QObject::tr("Название фильма"));   //заголовок отображаемой таблицы
    qModel->setHeaderData(1, Qt::Horizontal, QObject::tr("Описание фильма"));

    //Запрос осуществляется автоматически, когда пользователь запрашивает данные
    //любым способом. Например при помощи методов data() или record()

    //если произошла ошибка запроса - прочитаем ее
    QSqlError err;
    if (qModel->lastError().isValid()){
            err = qModel->lastError();
    }

    currentRequestedModel = modelType::query;//запомним какого типа был запрос

    emit sig_SendStatusRequest(err);//сигнал что мы запросили данные
}

void DataBase::RequestToTableDB()
{
    //запросим данные через табличную модель
    //используется для чтения и записи данных из одной таблицы БД.
    tModel->setTable("film");//выберем таблицу
    tModel->setEditStrategy(QSqlTableModel::OnManualSubmit);//стратегия изменения таблицы - все изменения будут кешироваться

    //Для получения данных используется метод select()
    tModel->select();//получить данные

    tModel->setHeaderData(1, Qt::Horizontal, QObject::tr("Название фильма"));//заголовок отображаемой таблицы
    tModel->setHeaderData(2, Qt::Horizontal, QObject::tr("Описание фильма"));

    //если произошла ошибка запроса - прочитаем ее
    QSqlError err;
    if(tModel->lastError().isValid()){
        err = tModel->lastError();
    }

    currentRequestedModel = modelType::table;//запомним какого типа был запрос

    emit sig_SendStatusRequest(err);//сигнал что мы запросили данные
}

/*!
 * @brief Метод возвращает последнюю ошибку БД
 */
QSqlError DataBase::GetLastError()
{
    return dataBase->lastError();//последняя ошибка при работе с БД
}



