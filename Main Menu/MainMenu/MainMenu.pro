#-------------------------------------------------
#
# Project created by QtCreator 2016-12-04T16:28:25
#
#-------------------------------------------------

QT       += core gui \
            multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MainMenu
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    sfx.cpp \
    instructions.cpp

HEADERS  += mainwindow.h \
    sfx.h \
    instructions.h

FORMS    += mainwindow.ui \
    instructions.ui

RESOURCES += \
    resource.qrc

DISTFILES +=
