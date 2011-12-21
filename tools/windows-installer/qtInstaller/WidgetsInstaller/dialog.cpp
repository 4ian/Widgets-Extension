#include "dialog.h"
#include "ui_dialog.h"

#include "version.h"

#include <QtCore>
#include <QMessageBox>
#include <QFileDialog>



Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    ui->commandLinkButton->setText("Procéder à l'installation de l'extension Widgets " + QString(WIDGETVERSION));

    installDialog = new QProgressDialog(this);
    installDialog->setMinimum(0);
    installDialog->setMaximum(0);
    installDialog->setValue(-1);
    installDialog->setLabelText("Installation en cours...");

    VerifyGD();
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    ui->lineEdit->setText(QFileDialog::getExistingDirectory(this, "Où se situe Game Develop ?", ui->lineEdit->text()));
    VerifyGD();
}

void Dialog::on_lineEdit_textChanged(const QString &arg1)
{
    VerifyGD();

    QDir directo(ui->lineEdit->text());

    if(!directo.exists())
    {
        ui->label_2->setText("<b><font color=\"red\">Ce dossier n'existe pas et ne contient donc pas Game Develop.</font></b>");
        ui->commandLinkButton->setEnabled(false);
    }
}

void Dialog::on_checkBox_clicked()
{
    VerifyGD();
}

void Dialog::VerifyGD()
{
    if(!IsFolderContainGD(ui->lineEdit->text()))
    {
        ui->label_2->setText("<b><font color=\"red\">Game Develop est introuvable dans ce dossier.</font></b>");
        ui->commandLinkButton->setEnabled(false);
    }
    else
    {
        if(!IsGDCorrectVersion(ui->lineEdit->text()))
        {
            ui->label_2->setText("<font color=\"red\">Cette version de Game Develop est incompatible avec l'extension Widgets.</font>");
            ui->commandLinkButton->setEnabled(false);
        }
        else
        {
            ui->label_2->setText("<b><i><font color=\"darkgreen\">Cette version de Game Develop est compatible avec l'extension Widgets.</font></i></b>");
            ui->commandLinkButton->setEnabled(true);
        }
    }

    if(ui->checkBox->isChecked())
    {
        ui->commandLinkButton->setEnabled(true);
    }
}

void Dialog::on_commandLinkButton_clicked()
{
    installThread = new InstallThread(ui->lineEdit->text(), this);
    installThread->start();

    connect(installThread, SIGNAL(finished()), this, SLOT(installFinished()));

    ui->lineEdit->setEnabled(false);
    ui->commandLinkButton->setEnabled(false);

    installDialog->show();
}

void Dialog::installFinished()
{
    installDialog->close();
    qApp->quit();
}

bool Dialog::IsFolderContainGD(QString path)
{
    if (QFile::exists(path + "/GDEditor.exe"))
        return true;
    else
        return false;
}

bool Dialog::IsGDCorrectVersion(QString path)
{
    QString pathToVersion = path + "/include/GDL/GDL/Version.h";

    QFile file(pathToVersion);

    if(!file.open(QFile::ReadOnly))
    {
        return false;
    }
    else
    {
        QTextStream stream(&file);
        QString content = stream.readAll();

        QRegExp findVer("static const char FULLVERSION_STRING\\[\\] = \"(.+)\";");

        if(content.contains(findVer))
        {
            if(findVer.capturedTexts().size() > 1 && findVer.capturedTexts().at(1) == QString(GDVERSION))
            {
                return true;
            }
        }
    }

    return false;
}
