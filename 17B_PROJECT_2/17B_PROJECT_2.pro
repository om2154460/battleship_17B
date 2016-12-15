#-------------------------------------------------
#
# Project created by QtCreator 2016-12-13T17:05:36
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 17B_PROJECT_2
TEMPLATE = app
QT += widgets
QT += sql

SOURCES += main.cpp\
        mainwindow.cpp \
    conversionfunctions.cpp \
    ai_ship_placer.cpp \
    ship.cpp \
    player.cpp \
    database.cpp \
    logmenu.cpp

HEADERS  += mainwindow.h \
    conversionfunctions.h \
    ai_ship_placer.h \
    ship.h \
    player.h \
    database.h \
    logmenu.h

FORMS    += mainwindow.ui \
    game.ui
