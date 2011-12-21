#ifndef INSTALLTHREAD_H
#define INSTALLTHREAD_H

#include <QThread>
#include <QProcess>

class InstallThread : public QThread
{
    Q_OBJECT
public:
    explicit InstallThread(QString dir, QObject *parent = 0);

    void run();

signals:

public slots:

private:
    QProcess *installProc;
    QString installDir;

};

#endif // INSTALLTHREAD_H
