#include "mainwindow.h"
#include <QApplication>



/*    ALL VARIABLES IN ENTIRE PROJECT GET SET
 * ALL THAT IS LEFT TO DO IS DATABASE AND SET INPUT VALIDATOR FOR: DATE LINE-EDIT
 *
 *
 *  &&&&&& ADD LAYOUTS TO WINDOWS TO RESIZE WIDGETS WITH WINDOW....................
 */






int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
