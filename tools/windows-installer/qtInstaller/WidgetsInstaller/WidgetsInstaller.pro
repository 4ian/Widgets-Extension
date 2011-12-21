#-------------------------------------------------
#
# Project created by QtCreator 2011-12-19T12:46:04
#
#-------------------------------------------------

QT       += core gui

TARGET = WidgetsInstaller
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp \
    installthread.cpp

HEADERS  += dialog.h \
    version.h \
    installthread.h

FORMS    += dialog.ui

RESOURCES += \
    res.qrc
