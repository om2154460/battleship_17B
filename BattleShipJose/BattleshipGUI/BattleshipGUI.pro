#-------------------------------------------------
#
# Project created by QtCreator 2016-12-05T12:54:56
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BattleshipGUI
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    logmenu.cpp

HEADERS  += mainwindow.h \
    logmenu.h

FORMS    += mainwindow.ui \
    logmenu.ui
