#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QDateTime>
#include "udpworker.h"

#define TIMER_DELAY 1000

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pb_start_clicked();
    void on_pb_stop_clicked();
    void on_pb_sendDatagram_clicked();


    void DisplayTime(QByteArray data);
    void datagramReceiveMS( QByteArray data, QNetworkDatagram datagram);

private:
    Ui::MainWindow *ui;
    QTimer* timer;
    UDPworker* udpWorker;
    UDPworker* udpWorkerMS;
    uint32_t counterPck = 0;



};
#endif // MAINWINDOW_H
