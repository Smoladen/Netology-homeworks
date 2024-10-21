#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Increase_clicked()
{
    int value = ui->SoundSensitivityBar->value();
    value += 1;
    if (value > ui->SoundSensitivityBar->maximum()) {
        value = 0;
    }
    ui->SoundSensitivityBar->setValue(value);
}

