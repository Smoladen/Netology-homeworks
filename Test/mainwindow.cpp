#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    udpWorker = new UDPworker(this);
    udpWorker->InitSocket();
    udpWorker->InitMoneySocket();
    connect(udpWorker, &UDPworker::sig_sendTimeToGUI, this, &MainWindow::DisplayTime);
    connect(udpWorker, &UDPworker::sig_receivedMoneyMessage, this, &MainWindow::displayReceivedMoneyMessage); // new conncet socket
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, [&]{

        QDateTime dateTime = QDateTime::currentDateTime();

        QByteArray dataToSend;
        QDataStream outStr(&dataToSend, QIODevice::WriteOnly);

        outStr << dateTime;

        udpWorker->SendDatagram(dataToSend);
        timer->start(TIMER_DELAY);

    });
connect(ui->pb_editDatagram, &QPushButton::clicked, this, &MainWindow::on_pb_editDatagram_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_start_clicked()
{
    timer->start(TIMER_DELAY);
}


void MainWindow::DisplayTime(QDateTime data)
{
    counterPck++;
    if(counterPck % 20 == 0){
        ui->te_result->clear();
    }

    ui->te_result->append("Текущее время: " + data.toString() + ". "
                "Принято пакетов " + QString::number(counterPck));


}
void MainWindow::on_pb_editDatagram_clicked()
{
    QString textToSend = ui->le_input->text();
    if (!textToSend.isEmpty()) {
        udpWorker->SendDatagram(textToSend.toUtf8());
        ui->le_input->clear();
    }
}
void MainWindow::displayReceivedMoneyMessage(const QString& message)
{
    ui->te_result->append(message);
}
void MainWindow::on_pb_stop_clicked()
{
    timer->stop();
}

