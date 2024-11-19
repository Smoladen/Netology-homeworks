#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QtConcurrent>
#include "database.h"
#include "dbdata.h"

//главное окно программы
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

//обработчики сигналов
public slots:
    void ReceiveStatusConnectionToDB(bool status);//обработчик сигнала, что открыто соединение с БД - обработаем соединение с БД по статусу соединения
    void ReceiveStatusRequestToDB(QSqlError err);//обработчик сигнала, что запросили данные из БД - примем данные из БД

//обработчики нажатия кнопок
private slots:
    void on_act_addData_triggered();//нажали кнопку Ввести параметры подключения к БД
    void on_act_connect_triggered();//нажали кнопку Подключиться/Отключиться к БД
    void on_pb_request_clicked();//нажали кнопку Получить данные
    void on_pb_clear_clicked();//нажали кнопку Очистить данные


private:
    QVector<QString> dataForConnect; //Данные для подключения к БД.

    Ui::MainWindow *ui;
    DBData *dataDb;//параметры подключения к БД
    DataBase* dataBase;//база данных
    QMessageBox* msg;//окно сообщения в случае ошибки запроса

    QString request = "";//строка запроса

};
#endif // MAINWINDOW_H
