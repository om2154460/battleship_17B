#include "mainwindow.h"
#include "logmenu.h"
#include <QApplication>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    logmenu w;
    w.show();

    return a.exec();
}
