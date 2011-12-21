/********************************************************************************
** Form generated from reading UI file 'loading.ui'
**
** Created: Tue 20. Dec 13:30:35 2011
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOADING_H
#define UI_LOADING_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QProgressBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Loading
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QProgressBar *progressBar;

    void setupUi(QWidget *Loading)
    {
        if (Loading->objectName().isEmpty())
            Loading->setObjectName(QString::fromUtf8("Loading"));
        Loading->resize(342, 58);
        verticalLayout = new QVBoxLayout(Loading);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(Loading);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        progressBar = new QProgressBar(Loading);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setMaximum(0);
        progressBar->setValue(-1);
        progressBar->setTextVisible(false);
        progressBar->setInvertedAppearance(false);
        progressBar->setTextDirection(QProgressBar::TopToBottom);

        verticalLayout->addWidget(progressBar);


        retranslateUi(Loading);

        QMetaObject::connectSlotsByName(Loading);
    } // setupUi

    void retranslateUi(QWidget *Loading)
    {
        Loading->setWindowTitle(QApplication::translate("Loading", "D\303\251marrage de l'installation", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Loading", "Installation...", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Loading: public Ui_Loading {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOADING_H
