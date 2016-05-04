TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    graph.cpp \
    drive.cpp

HEADERS += \
    edge.h \
    graph.h \
    drive.h
    airport.h \
    route.h

