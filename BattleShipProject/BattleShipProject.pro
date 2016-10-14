#-------------------------------------------------
#
# Project created by QtCreator 2016-10-14T12:07:06
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BattleShipProject
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    onenamedb.cpp \
    twonamesdb.cpp \
    twoplgame.cpp \
    oneplgame.cpp

HEADERS  += mainwindow.h \
    onenamedb.h \
    twonamesdb.h \
    twoplgame.h \
    oneplgame.h

FORMS    += mainwindow.ui \
    onenamedb.ui \
    twonamesdb.ui \
    twoplgame.ui \
    oneplgame.ui
