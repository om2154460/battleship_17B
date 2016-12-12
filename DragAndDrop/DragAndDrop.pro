#-------------------------------------------------
#
# Project created by QtCreator 2016-11-09T17:27:24
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DragAndDrop
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    color.cpp \
    cell.cpp \
    graphicsview.cpp

HEADERS  += mainwindow.h \
    color.h \
    cell.h \
    graphicsview.h

FORMS    += mainwindow.ui
