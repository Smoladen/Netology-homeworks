#include "mainwindow.h"
#include "./ui_mainwindow.h"

//основное окно программы
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //Исходное состояние виджетов
    ui->setupUi(this);

    //настроим индикатор связи с БД
    ui->lb_statusConnect->setStyleSheet("color:red");
    //запретим запрашивать данные - мы еще не подключены к БД
    ui->pb_request->setEnabled(false);

    /*
     * Выделим память под необходимые объекты. Все они наследники
     * QObject, поэтому воспользуемся иерархией.
    */

    dataDb = new DBData(this);//памаметры соединения с базой (при создании заносятся данные по умолчанию)
    dataBase = new DataBase(this);//наша база данных
    msg = new QMessageBox(this);//окно сообщений

    //Установим размер вектора данных для подключения к БД
    dataForConnect.resize(NUM_DATA_FOR_CONNECT_TO_DB);

    /*
     * Добавим БД используя стандартный драйвер PSQL и зададим имя.
    */
    dataBase->AddDataBase(POSTGRE_DRIVER, DB_NAME);//подтянем драйвер бБД
    dataBase->BindView(ui->tb_result);//укажем объекту БД таблицу, куда будем выводить результаты запроса к БД

    /*
     * Устанавливаем данные для подключениея к БД.
     * Поскольку метод небольшой используем лямбда-функцию.
     */
    //пользователь нажал кнопку ОК в диалоге параметров подключения
    //сигнал передает параметры подключения
    //эти параметры мы запоминаем в векторе
    connect(dataDb, &DBData::sig_sendData, this, [&](QVector<QString> receivData){
        dataForConnect = receivData;
    });

    /*
     *  Сигнал для подключения к БД
     */
    //сигнал, что открыто соединение с БД - обработаем соединение с БД
    connect(dataBase, &DataBase::sig_SendStatusConnection, this, &MainWindow::ReceiveStatusConnectionToDB);
    //сигнал, что запросили данные из БД - примем данные из БД
    connect(dataBase, &DataBase::sig_SendStatusRequest, this, &MainWindow::ReceiveStatusRequestToDB);
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*!
 * @brief Слот отображает форму для ввода данных подключения к БД
 */

//нажали кнопку Ввести параметры подключения к БД
void MainWindow::on_act_addData_triggered()
{
    //Отобразим диалоговое окно. Какой метод нужно использовать?
    dataDb->show();
}

/*!
 * @brief Слот выполняет подключение к БД. И отображает ошибки.
 */

//нажали кнопку Подключиться/Отключиться к БД
void MainWindow::on_act_connect_triggered()
{
    /*
     * Обработчик кнопки у нас должен подключаться и отключаться от БД.
     * Можно привязаться к надписи лейбла статуса. Если он равен
     * "Отключено" мы осуществляем подключение, если "Подключено" то
     * отключаемся
    */

    if(ui->lb_statusConnect->text() == "Отключено"){

       ui->lb_statusConnect->setText("Подключение");
       ui->lb_statusConnect->setStyleSheet("color : black");


       auto conn = [&]{dataBase->ConnectToDataBase(dataForConnect);};//пытаемся подключиться к БД
       QtConcurrent::run(conn);//запускаем в фоновом режиме, чтобы программа не зависла

    }
    else{
        dataBase->DisconnectFromDataBase(DB_NAME);//отключаемся от БД
        ui->lb_statusConnect->setText("Отключено");
        ui->act_connect->setText("Подключиться");
        ui->lb_statusConnect->setStyleSheet("color:red");
        ui->pb_request->setEnabled(false);
    }

}

/*!
 * \brief Обработчик кнопки "Получить"
 */

//нажали кнопку Получить данные
void MainWindow::on_pb_request_clicked()
{
   uint8_t type = (ui->cb_category->currentIndex() + 1);//определим категорию запроса
   std::function<void(void)> req;

   switch(type)
   {
   case requestAllFilms:
       req = [&]{dataBase->RequestToTableDB();};//все категории - запрос через табличную модель
       break;
   case requestComedy:
       request = "SELECT title, description FROM film f "
                 "JOIN film_category fc on f.film_id = fc.film_id "
                 "JOIN category c on c.category_id = fc.category_id "
                 "WHERE c.name = 'Comedy'";
       req = [&]{dataBase->RequestToDB(request);};//запрос через запросную модель
       break;
   case requestHorrors:
       request = "SELECT title, description FROM film f "
                 "JOIN film_category fc on f.film_id = fc.film_id "
                 "JOIN category c on c.category_id = fc.category_id "
                 " WHERE c.name = 'Horror'";
       req = [&]{dataBase->RequestToDB(request);};//запрос через запросную модель
       break;
   default:
       break;
   }

   QtConcurrent::run(req);//запуситим в фоновом режиме

}

//нажата кнопка Очистить
void MainWindow::on_pb_clear_clicked()
{
    ui->tb_result->reset(); //чистим таблицу результатов
}

/*!
 * \brief Метод изменяет стотояние формы в зависимости от статуса подключения к БД
 * \param status
 */

//сигнал, что открыто соединение с БД - обработаем соединение с БД по статусу соединения
void MainWindow::ReceiveStatusConnectionToDB(bool status)
{
    if(status){
        //все отлично - связь есть - ставим флажки
        ui->act_connect->setText("Отключиться");
        ui->lb_statusConnect->setText("Подключено к БД");
        ui->lb_statusConnect->setStyleSheet("color:green");
        ui->pb_request->setEnabled(true);
    }
    else{
        //что-то пошло не так - отключаемся
        dataBase->DisconnectFromDataBase(DB_NAME);
        ui->lb_statusConnect->setText("Отключено");
        ui->lb_statusConnect->setStyleSheet("color:red");

        msg->setIcon(QMessageBox::Critical);
        msg->setText(dataBase->GetLastError().text());
        msg->exec();//выводим окно сообщений с ругательством!!
    }

}

//сигнал, что запросили данные из БД - примем данные из БД
void MainWindow::ReceiveStatusRequestToDB(QSqlError err)
{

    if(err.type() != QSqlError::NoError){
        msg->setText(err.text());
        msg->exec();
    }
    else{
        dataBase->ReadAnswerFromDB();//прочитаем результаты запроса к БД
    }

}


