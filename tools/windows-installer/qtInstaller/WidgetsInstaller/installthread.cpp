#include "installthread.h"

#include <QtGui/QApplication>

InstallThread::InstallThread(QString dir, QObject *parent) :
    QThread(parent)
{
    installProc = new QProcess(this);
    installDir = dir;
}

void InstallThread::run()
{
    installProc->execute(QApplication::applicationDirPath() + "/content.exe /VERYSILENT /DIR=\"" + installDir + "\"");
    installProc->waitForFinished();
    emit finished();
}
