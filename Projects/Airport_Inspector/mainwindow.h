#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QtConcurrent>
#include <QTimer>
#include "database.h"


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
    void updateConnectionStatus(bool status);
    void tryConnectToDatabase();
private:
     QVector<QString> dataForConnect;
    Ui::MainWindow *ui;

    DataBase* dataBase;
    QTimer* connectionRetryTimer;
};
#endif // MAINWINDOW_H
