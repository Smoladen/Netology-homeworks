#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->lb_connection_status->setStyleSheet("color:red");

     dataBase = new DataBase(this);
    connectionRetryTimer = new QTimer(this);
    dataForConnect.resize(NUM_DATA_FOR_CONNECT_TO_DB);

    dataBase->AddDataBase(POSTGRE_DRIVER, DB_NAME);
    connect(dataBase, &DataBase::sig_SendStatusConnection, this, &MainWindow::updateConnectionStatus);

    tryConnectToDatabase();


}

MainWindow::~MainWindow()
{
    delete ui;
    delete dataBase;
    delete connectionRetryTimer;
}

void MainWindow::tryConnectToDatabase(){
    auto connect_to_DB = [this]{
        ui->lb_connection_status->setText("Подключение...");
        ui->lb_connection_status->setStyleSheet("color:black");
        dataBase->ConnectToDataBase();
    };
    auto future = QtConcurrent::run(connect_to_DB);
}
void MainWindow::updateConnectionStatus(bool status_connection) {
    if(status_connection) {
        ui->lb_connection_status->setText("Подключено к БД");
        ui->lb_connection_status->setStyleSheet("color:green");
               qDebug("succeesd");

    } else {
      //  dataBase->DisconnectFromDataBase(DB_NAME);

        ui->lb_connection_status->setText("Не удалось подключиться к БД!");
        ui->lb_connection_status->setStyleSheet("color:red");
                qDebug("failed");
        connectionRetryTimer->start(5000);

    }
}
