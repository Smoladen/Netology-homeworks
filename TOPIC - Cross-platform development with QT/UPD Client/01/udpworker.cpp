#include "udpworker.h"

UDPworker::UDPworker(QObject *parent) : QObject(parent)
{


}


/*!
 * @brief Метод инициализирует UDP сервер
 */
void UDPworker::InitSocketTime()
{

    serviceUdpSocket = new QUdpSocket(this);
    /*
     * Соединяем присваиваем адрес и порт серверу и соединяем функцию
     * обраотчик принятых пакетов с сокетом
     */
    serviceUdpSocket->bind(QHostAddress::LocalHost, BIND_PORT_TIME);

    connect(serviceUdpSocket, &QUdpSocket::readyRead, this, &UDPworker::readTimePendingDatagrams);

}

void UDPworker::SendTimeDatagram(QByteArray data)
{
    serviceUdpSocket->writeDatagram(data, QHostAddress::LocalHost, BIND_PORT_TIME);
}

void UDPworker::ReadTimeDatagram(QNetworkDatagram datagram)
{

    QByteArray time_data;

    time_data.resize(datagram.data().size());
    time_data = datagram.data();

    emit sig_sendTimeToGUI(time_data);

}

void UDPworker::readTimePendingDatagrams( void )
{
    while(serviceUdpSocket->hasPendingDatagrams())
    {
        QNetworkDatagram datagram = serviceUdpSocket->receiveDatagram();

        ReadTimeDatagram(datagram);
    }

}



void UDPworker::InitMSSocket()
{
    MsUdpSocket = new QUdpSocket(this);
    MsUdpSocket->bind(QHostAddress::LocalHost, BIND_PORT_MS)/* + 1*/;  // Use a different port

    connect(MsUdpSocket, &QUdpSocket::readyRead, this, &UDPworker::MSreadDatagrams);
}

void UDPworker::SendMSDatagram(QByteArray data)
{
    MsUdpSocket->writeDatagram(data, QHostAddress::LocalHost, BIND_PORT_MS);
}

void UDPworker::ReadMSDatagram(QNetworkDatagram datagram)
{

    QByteArray str_data;

    str_data.resize(datagram.data().size());
    str_data = datagram.data();

    emit sig_receivedMessage(str_data,datagram);

}

void UDPworker::MSreadDatagrams( void )
{
    while(MsUdpSocket->hasPendingDatagrams())
    {
        QNetworkDatagram datagram = MsUdpSocket->receiveDatagram();

        ReadMSDatagram(datagram);
    }

}
