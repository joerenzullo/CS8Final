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

LIBS += -L"/usr/local/lib/" -lmarblewidget-qt5

INCLUDEPATH +=/usr/local/include
DEPENDPATH +=/usr/local/include


