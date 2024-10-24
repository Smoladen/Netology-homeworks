#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , running(false),
    lapCounter(0),
    previousLapTime(0)
{
    ui->setupUi(this);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateDisplay);

    // Изначально кнопка "Круг" неактивна
    ui->lapButton->setEnabled(false);

    // Устанавливаем начальное значение на лейбле времени
    ui->timeLabel->setText("0.0");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_startStopButton_clicked()
{
    if (running) {
        // Остановка секундомера
        timer->stop();
        running = false;
        ui->startStopButton->setText("Start");
        ui->lapButton->setEnabled(false);
    } else {
        // Запуск секундомера
        elapsedTimer.start();
        timer->start(100); // Обновляем каждую 0.1 секунды
        running = true;
        ui->startStopButton->setText("Stop");
        ui->lapButton->setEnabled(true);
    }
}


void MainWindow::on_resetButton_clicked()
{
    // Сброс всех данных
    timer->stop();
    running = false;
    lapCounter = 0;
    previousLapTime = 0;

    ui->timeLabel->setText("0.0");
    ui->lapsTextBrowser->clear();
    ui->startStopButton->setText("Start");
    ui->lapButton->setEnabled(false);
}


void MainWindow::on_lapButton_clicked()
{
    lapCounter++;
    qint64 lapTime = elapsedTimer.elapsed() - previousLapTime;
    previousLapTime = elapsedTimer.elapsed();
    ui->lapsTextBrowser->append(QString("Lap %1: %2 sec").arg(lapCounter).arg(lapTime / 1000.0, 0, 'f', 1));
}

void MainWindow::updateDisplay() {
    // Обновляем время на лейбле каждую 0.1 секунды
    qint64 time = elapsedTimer.elapsed();
    ui->timeLabel->setText(QString::number(time / 1000.0, 'f', 1)); // Время в секундах
}
