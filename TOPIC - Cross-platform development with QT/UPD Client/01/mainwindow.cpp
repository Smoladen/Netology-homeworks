#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    udpWorker = new UDPworker(this);
    udpWorker->InitSocketTime();

    connect(udpWorker, &UDPworker::sig_sendTimeToGUI, this, &MainWindow::DisplayTime);



    udpWorkerMS = new UDPworker(this);
    udpWorkerMS->InitMSSocket();
    connect(udpWorkerMS, &UDPworker::sig_receivedMessage, this, &MainWindow::datagramReceiveMS);


    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, [&]{

        QDateTime dateTime = QDateTime::currentDateTime();

        QByteArray dataToSend;
        dataToSend.resize(sizeof(dateTime));

        memcpy(dataToSend.data(), &dateTime, sizeof(dateTime));

        udpWorker->SendTimeDatagram(dataToSend);
        timer->start(TIMER_DELAY);

    });

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_start_clicked()
{
    timer->start(TIMER_DELAY);
}


void MainWindow::DisplayTime(QByteArray data)
{
    counterPck++;
    QDateTime rcvDateTime;

    memcpy(&rcvDateTime, data.data(), sizeof(rcvDateTime));


    if(counterPck % 20 == 0){
        ui->te_result->clear();
    }

    ui->te_result->append("Текущее время: " + rcvDateTime.toString() + ". "
                "Принято пакетов " + QString::number(counterPck));


}
void MainWindow::datagramReceiveMS( QByteArray data, QNetworkDatagram datagram){
    counterPck++;
    QString str;

    memcpy(&str, data.data(), sizeof(str));
    if(counterPck % 20 == 0){
        ui->te_result->clear();
    }


    ui->te_result->append(" Принято сообщение от: " + datagram.senderAddress().toString() + ", " + "размер сообщения " + QString::number(str.size()) );

}

void MainWindow::on_pb_sendDatagram_clicked()
{
    QString textToSend = ui->le_input->text();
    QByteArray datastr;
    datastr.resize(sizeof(textToSend));
    memcpy(datastr.data(), &textToSend, sizeof(textToSend));

    udpWorkerMS->SendMSDatagram(datastr);
    ui->le_input->clear();
}




void MainWindow::on_pb_stop_clicked()
{
    timer->stop();
}

