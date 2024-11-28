#include "udpworker.h"

UDPworker::UDPworker(QObject *parent) : QObject(parent)
{



}


/*!
 * @brief Метод инициализирует UDP сервер
 */
void UDPworker::InitSocket()
{

    serviceUdpSocket = new QUdpSocket(this);
    /*
     * Соединяем присваиваем адрес и порт серверу и соединяем функцию
     * обраотчик принятых пакетов с сокетом
     */
    serviceUdpSocket->bind(QHostAddress::LocalHost, BIND_PORT);

    connect(serviceUdpSocket, &QUdpSocket::readyRead, this, &UDPworker::readPendingDatagrams);

}

/*!
 * @brief Метод осуществляет обработку принятой датаграммы
 */
void UDPworker::ReadDatagram(QNetworkDatagram datagram)
{

    QByteArray data;
    data = datagram.data();


    QDataStream inStr(&data, QIODevice::ReadOnly);
    QDateTime dateTime;
    inStr >> dateTime;

    emit sig_sendTimeToGUI(dateTime);
//    QString senderAddress = datagram.senderAddress().toString();
//    int messageSize = datagram.data().size();
//    QString message = QString("Accept message from %1, message size (bytes): %2")
//                          .arg(senderAddress)
//                          .arg(messageSize);

//    emit sig_receivedMessage(message);
}
/*!
 * @brief Метод осуществляет опередачу датаграммы
 */
void UDPworker::SendDatagram(QByteArray data)
{
    /*
     *  Отправляем данные на localhost и задефайненный порт
     */
    serviceUdpSocket->writeDatagram(data, QHostAddress::LocalHost, BIND_PORT);
}

/*!
 * @brief Метод осуществляет чтение датаграм из сокета
 */
void UDPworker::readPendingDatagrams( void )
{
    /*
     *  Производим чтение принятых датаграмм
     */
    while(serviceUdpSocket->hasPendingDatagrams()){
            QNetworkDatagram datagram = serviceUdpSocket->receiveDatagram();
            ReadDatagram(datagram);
    }

}
void UDPworker::InitMoneySocket()
{
    moneyUdpSocket = new QUdpSocket(this);
    moneyUdpSocket->bind(QHostAddress::LocalHost, BIND_PORT + 1);  // Use a different port

    connect(moneyUdpSocket, &QUdpSocket::readyRead, this, &UDPworker::readPendingMoneyDatagrams);
}

void UDPworker::SendMoneyDatagram(QByteArray data)
{
    moneyUdpSocket->writeDatagram(data, QHostAddress::LocalHost, BIND_PORT + 1);
}

void UDPworker::readPendingMoneyDatagrams(void)
{
    while (moneyUdpSocket->hasPendingDatagrams()) {
            QNetworkDatagram datagram = moneyUdpSocket->receiveDatagram();
            QString senderAddress = datagram.senderAddress().toString();
            int messageSize = datagram.data().size();
            QString message = QString("Accept message from %1, message size (bytes): %2")
                                  .arg(senderAddress)
                                  .arg(messageSize);

            emit sig_receivedMoneyMessage(message);
    }
}
