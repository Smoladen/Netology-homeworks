#ifndef UDPWORKER_H
#define UDPWORKER_H

#include <QUdpSocket>
#include <QNetworkDatagram>
#include <QDateTime>


#define BIND_PORT 12345

class UDPworker : public QObject
{
    Q_OBJECT
public:
    explicit UDPworker(QObject *parent = nullptr);
    void InitSocket( void );

     void InitMoneySocket(void);//new

    void ReadDatagram( QNetworkDatagram datagram);
    void SendDatagram(QByteArray data );

    void SendMoneyDatagram(QByteArray data);  // New method

private slots:
    void readPendingDatagrams(void);
    void readPendingMoneyDatagrams(void);  // New slot

private:
    QUdpSocket* serviceUdpSocket;
  QUdpSocket* moneyUdpSocket;  // New socket
signals:
    void sig_sendTimeToGUI(QDateTime data);
void sig_receivedMoneyMessage(const QString& message);  // New signal
};

#endif // UDPWORKER_H
