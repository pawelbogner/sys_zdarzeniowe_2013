#-------------------------------------------------
#
# Project created by QtCreator 2013-10-14T23:01:29
#
#-------------------------------------------------

QT       += core gui network

TARGET = klient
TEMPLATE = app


SOURCES += main.cpp\
        klient.cpp \
    qclient.cpp \
    field.cpp \
    eter.cpp \
    robot.cpp

HEADERS  += klient.h \
    qclient.h \
    qprotocol.h \
    field.h \
    eter.h \
    robot.h

FORMS    += klient.ui
