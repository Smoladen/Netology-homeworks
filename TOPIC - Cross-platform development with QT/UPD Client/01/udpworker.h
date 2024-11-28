#ifndef UDPWORKER_H
#define UDPWORKER_H

#include <QUdpSocket>
#include <QNetworkDatagram>
#include <QDateTime>


#define BIND_PORT_TIME 12345
#define BIND_PORT_MS 23456

class UDPworker : public QObject
{
    Q_OBJECT
public:
    explicit UDPworker(QObject *parent = nullptr);
    void InitSocketTime( void );
    void ReadTimeDatagram( QNetworkDatagram datagram);
    void SendTimeDatagram(QByteArray data );

    void InitMSSocket(void);
    void ReadMSDatagram( QNetworkDatagram datagram);
    void SendMSDatagram(QByteArray data );


private slots:
    void readTimePendingDatagrams(void);
    void MSreadDatagrams(void);
private:
    QUdpSocket* serviceUdpSocket;
    QUdpSocket* MsUdpSocket;
signals:
    void sig_sendTimeToGUI(QByteArray data);
    void sig_receivedMessage(QByteArray str_data, QNetworkDatagram datagram);
};

#endif // UDPWORKER_H
