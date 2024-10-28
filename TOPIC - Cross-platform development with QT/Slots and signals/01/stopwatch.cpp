#include "stopwatch.h"

Stopwatch::Stopwatch(QObject *parent) : QObject(parent), running(false), previousLapTime(0)
{
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, [=]() {
        emit timeUpdated(elapsedTime());
    });
}

void Stopwatch::start() {
    if (!running) {
        elapsedTimer.start();
        previousLapTime = 0;
        timer->start(100);
        running = true;
    }
}

void Stopwatch::stop() {
    if (running) {
        timer->stop();
        running = false;
    }
}

void Stopwatch::reset() {
    timer->stop();
    running = false;
    previousLapTime = 0;
    elapsedTimer.invalidate();
}

qint64 Stopwatch::lap() {
    qint64 lapTime = elapsedTime() - previousLapTime;
    previousLapTime = elapsedTime();
    return lapTime;
}

bool Stopwatch::isRunning() const {
    return running;
}

qint64 Stopwatch::elapsedTime() const {
    return elapsedTimer.isValid() ? elapsedTimer.elapsed() : 0;
}
