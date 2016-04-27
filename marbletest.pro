#-------------------------------------------------
#
# Project created by QtCreator 2016-04-21T13:45:52
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = marbletest
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

LIBS += -L"/home/joe/Documents/marble-build/src/lib/marble" -L"/home/joe/Documents/marble-build/src/lib/astro"
CONFIG(debug, debug|release): LIBS += -lmarblewidget-qt5
CONFIG(release, debug|release): LIBS += -lmarblewidget-qt5
