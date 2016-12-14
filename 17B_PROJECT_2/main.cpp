#include "mainwindow.h"
#include <QApplication>
#include <QSplashScreen>
#include <QTimer>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSplashScreen *splash = new QSplashScreen;
    splash->setPixmap(QPixmap("C:/Users/User/17B_PROJECT/battleship.jpg"));
    splash->showMaximized();

    MainWindow w;

    QTimer::singleShot(1500,splash,SLOT(close())); // NOT WAITINT LONG ENOUGH
    QTimer::singleShot(1500,&w,SLOT(show()));
   // w.show();

    return a.exec();
}
