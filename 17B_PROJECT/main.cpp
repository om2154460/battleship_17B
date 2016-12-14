#include "mainwindow.h"
#include <QApplication>
#include <QSplashScreen>
#include <QTimer>
#include <QPixmap>
#include <QMultimedia>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QMediaControl>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QMediaPlaylist *playlist = new QMediaPlaylist();
    playlist->addMedia(QUrl("C:/Users/User/17B_PROJECT/Army Men- Sarge's Heroes - Attack.mp3"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);

    QMediaPlayer *music = new QMediaPlayer();
    music->setPlaylist(playlist);
    music->play();

     QSplashScreen *splash = new QSplashScreen;
     splash->setPixmap(QPixmap("C:/Users/User/17B_PROJECT/battleship.jpg"));
     splash->showMaximized();

     MainWindow w;

     QTimer::singleShot(5500,splash,SLOT(close())); // NOT WAITINT LONG ENOUGH
     QTimer::singleShot(5500,&w,SLOT(show()));

     w.setStyleSheet("background-image: url(C:/Users/User/17B_PROJECT/radar.jpg");
     // background: url(:/path/to-your-resource.png)
    w.showMaximized();

    return a.exec();
}
