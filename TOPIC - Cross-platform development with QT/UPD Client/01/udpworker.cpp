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
/*!
 * @brief Метод осуществляет обработку принятой датаграммы
 */
//void UDPworker::ReadDatagram(QNetworkDatagram datagram)
//{

//    QByteArray data;
//    data = datagram.data();


//    QDataStream inStr(&data, QIODevice::ReadOnly);
//    QDateTime dateTime;
//    inStr >> dateTime;

//    emit sig_sendTimeToGUI(dateTime);
//}
//void UDPworker::ReadDatagram(QNetworkDatagram datagram)
//{
//    QString senderAddress = datagram.senderAddress().toString();
//    int messageSize = datagram.data().size();
//    QString message = QString("Принято сообщение от %1, размер сообщения (байт): %2")
//                          .arg(senderAddress)
//                          .arg(messageSize);

//    emit sig_receivedMessage(message);
//}
//void UDPworker::readMesDatagrams(void)
//{
//    while (mesUdpSocket->hasPendingDatagrams()) {
//        QNetworkDatagram datagram = mesUdpSocket->receiveDatagram();
//        QString senderAddress = datagram.senderAddress().toString();
//        int messageSize = datagram.data().size();
//        QString message = QString("Accept message from %1, message size (bytes): %2")
//                              .arg(senderAddress)
//                              .arg(messageSize);

//        emit sig_receivedMessage(message);
//    }
//}
/*!
 * @brief Метод осуществляет опередачу датаграммы
 */
//void UDPworker::SendDatagram(QByteArray data)
//{
//    /*
//     *  Отправляем данные на localhost и задефайненный порт
//     */
//    serviceUdpSocket->writeDatagram(data, QHostAddress::LocalHost, BIND_PORT);
//}

/*!
 * @brief Метод осуществляет чтение датаграм из сокета
 */
//void UDPworker::readPendingDatagrams( void )
//{
//    /*
//     *  Производим чтение принятых датаграмм
//     */
//    while(serviceUdpSocket->hasPendingDatagrams()){
//            QNetworkDatagram datagram = serviceUdpSocket->receiveDatagram();
//            ReadDatagram(datagram);
//    }

//}
