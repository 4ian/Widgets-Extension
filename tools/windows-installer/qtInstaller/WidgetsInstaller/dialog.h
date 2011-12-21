#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QProgressDialog>
#include "installthread.h"

namespace Ui {
    class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private slots:
    void on_pushButton_clicked();
    void on_commandLinkButton_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

    void on_checkBox_clicked();

    void installFinished();

private:
    void VerifyGD();

    bool IsFolderContainGD(QString path);
    bool IsGDCorrectVersion(QString path);

    Ui::Dialog *ui;

    InstallThread *installThread;
    QProgressDialog *installDialog;
};

#endif // DIALOG_H
