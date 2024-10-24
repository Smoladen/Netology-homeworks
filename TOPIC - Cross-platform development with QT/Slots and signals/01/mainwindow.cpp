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


    ui->lapButton->setEnabled(false);


    ui->timeLabel->setText("0.0");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_startStopButton_clicked()
{
    if (running) {

        timer->stop();
        running = false;
        ui->startStopButton->setText("Start");
        ui->lapButton->setEnabled(false);
    } else {

        elapsedTimer.start();
        timer->start(100);
        running = true;
        ui->startStopButton->setText("Stop");
        ui->lapButton->setEnabled(true);
    }
}


void MainWindow::on_resetButton_clicked()
{

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

    qint64 time = elapsedTimer.elapsed();
    ui->timeLabel->setText(QString::number(time / 1000.0, 'f', 1));
}
