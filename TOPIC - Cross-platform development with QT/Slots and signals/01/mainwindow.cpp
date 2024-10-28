#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
    stopwatch(new Stopwatch(this)),
    lapCounter(0)
{
    ui->setupUi(this);

    connect(stopwatch, &Stopwatch::timeUpdated, this, &MainWindow::updateDisplay);

    ui->lapButton->setEnabled(false);
    ui->timeLabel->setText("0.0");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startStopButton_clicked() {
    if (stopwatch->isRunning()) {
        stopwatch->stop();
        ui->startStopButton->setText("Start");
        ui->lapButton->setEnabled(false);
    } else {
        stopwatch->start();
        ui->startStopButton->setText("Stop");
        ui->lapButton->setEnabled(true);
    }
}

void MainWindow::on_resetButton_clicked() {
    stopwatch->reset();
    ui->timeLabel->setText("0.0");
    ui->lapTextBrowser->clear();
    lapCounter = 0;
    ui->lapTextBrowser->setEnabled(false);
}

void MainWindow::on_lapButton_clicked() {
    lapCounter++;
    qint64 lapTime = stopwatch->lap();
    ui->lapTextBrowser->append(QString("Lap %1, time: %2 sec").arg(lapCounter).arg(lapTime / 1000.0, 0, 'f', 1));
}

void MainWindow::updateDisplay(qint64 time) {
    ui->timeLabel->setText(QString::number(time / 1000.0, 'f', 1));
}
