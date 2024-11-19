#include "dbdata.h"
#include "database.h"
#include "ui_dbdata.h"

//окно ввода параметров подключения к базе данных
DBData::DBData(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DBData)
{
    ui->setupUi(this);

    //установим параметры по умолчанию
    ui->le_hostName->setText("981757-ca08998.tmweb.ru");
    ui->le_dbName->setText("netology_cpp");
    ui->le_login->setText("netology_usr_cpp");
    ui->le_password->setText("CppNeto3");
    ui->sb_connProt->setValue(5432);
    //определяем размер вектора для хранения параметров поключения
    data.resize(NUM_DATA_FOR_CONNECT_TO_DB);
}

DBData::~DBData()
{
    delete ui;
}

void DBData::on_buttonBox_accepted()
{
    //кнопка ОК нажата
    //сохраняем введенные параметры подключения в вектор
    data[hostName] = ui->le_hostName->text();
    data[dbName] = ui->le_dbName->text();
    data[login] = ui->le_login->text();
    data[pass] = ui->le_password->text();
    data[port] = ui->sb_connProt->text();

    emit sig_sendData(data);//сигнал что можно работать с базой - параметры подключения заполнены

}
