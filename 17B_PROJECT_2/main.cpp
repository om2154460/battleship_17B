#include "mainwindow.h"
#include <QApplication>
#include <QSplashScreen>
#include <QTimer>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSplashScreen *splash = new QSplashScreen;
    //splash->setPixmap(QPixmap("C:/Users/Brandon/Documents/Qt Projects/17B_PROJECT_2/battleship.jpg"));
    splash->setPixmap(QPixmap("C:/BattleShip_Pictures/battleship.jpg"));
    splash->showMaximized();

    MainWindow w;

    QTimer::singleShot(1500,splash,SLOT(close())); // NOT WAITINT LONG ENOUGH
    QTimer::singleShot(1500,&w,SLOT(show()));
   // w.show();



    return a.exec();
}

//Note: If splashscreen or other images are not displaying, make sure to place the "BattleShip_Pictures" folder in your C drive.
//Straight in the C drive and the program will find it there.
