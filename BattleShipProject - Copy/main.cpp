#include "mainwindow.h"
#include <QApplication>
#include <QSplashScreen>
#include <QTimer>


// main(num players) -> setShips ->

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSplashScreen *splash = new QSplashScreen;
    splash->setPixmap(QPixmap("C:/Users/User/BattleShipProject/BattleshipPic.jpg"));
    // setGeometry!!!! choose middle of window
    splash->showMaximized();

    MainWindow w;
    QTimer::singleShot(3500,splash,SLOT(close()));
    QTimer::singleShot(3500,&w,SLOT(show()));

   // w.show();

    return a.exec();
}
