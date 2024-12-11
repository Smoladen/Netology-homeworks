#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->lb_connection_status->setStyleSheet("color:red");

     dataBase = new DataBase(this);

    if(ui->lb_connection_status->text() == "Отключено"){

        ui->lb_connection_status->setText("Подключение");
        ui->lb_connection_status->setStyleSheet("color : black");


        auto conn = [&]{dataBase->ConnectToDataBase(dataForConnect);};
        QtConcurrent::run(conn);

    }
    else{
        dataBase->DisconnectFromDataBase(DB_NAME);
        ui->lb_statusConnect->setText("Отключено");
        ui->act_connect->setText("Подключиться");
        ui->lb_statusConnect->setStyleSheet("color:red");
        ui->pb_request->setEnabled(false);
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

