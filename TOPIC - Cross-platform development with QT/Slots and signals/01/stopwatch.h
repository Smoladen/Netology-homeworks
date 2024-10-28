#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QObject>
#include <QTimer>
#include <QElapsedTimer>

class Stopwatch : public QObject
{
    Q_OBJECT
public:
    explicit Stopwatch(QObject *parent = nullptr);

    void start();
    void stop();
    void reset();
    qint64 lap();

    bool isRunning() const;
    qint64 elapsedTime() const;

signals:
    void timeUpdated(qint64);

private:
    QTimer *timer;
    QElapsedTimer elapsedTimer;
    qint64 previousLapTime;
    bool running;
};

#endif // STOPWATCH_H
