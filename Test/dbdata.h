#ifndef DBDATA_H
#define DBDATA_H

#include <QDialog>

//окно диалога ввода параметров подключения к БД
namespace Ui {
class DBData;
}

class DBData : public QDialog
{
    Q_OBJECT

public:
    explicit DBData(QWidget *parent = nullptr);
    ~DBData();

//сигналы
signals:
   void sig_sendData(QVector<QString> dbData);//сигнал, что параметры подключения заполнены

//обработчики нажатия кнопок
private slots:
    void on_buttonBox_accepted();//пользователь нажал ОК в диалоговом окне ввода параметров подключения

private:
    Ui::DBData *ui;
    QVector<QString> data;//вектор для хранения параметров подключения в форме

};

#endif // DBDATA_H
