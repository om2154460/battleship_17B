#-------------------------------------------------
#
# Project created by QtCreator 2016-12-10T12:33:30
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BattleShipDatabasing
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    AI_Attack_Algorithm.cpp \
    AI_Ship_Placer.cpp \
    Game.cpp \
    Player.cpp \
    Ship.cpp \
    Database.cpp

HEADERS  += mainwindow.h \
    AI_Attack_Algorithm.h \
    AI_Ship_Placer.h \
    Game.h \
    Player.h \
    Ship.h \
    considerations.h \
    Database.h

FORMS    += mainwindow.ui
