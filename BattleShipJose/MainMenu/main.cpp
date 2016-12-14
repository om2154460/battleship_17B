#include "mainwindow.h"
#include "instructions.h"
#include "sfx.h"
#include <QApplication>
#include <QMediaPlayer>
#include <QMediaPlaylist>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    //w.resize(2500,1700);  // x = width, y = height
    w.show();


    //play background music

    QMediaPlaylist *playlist = new QMediaPlaylist();
    playlist->addMedia(QUrl::fromLocalFile("C:/Users/Jose/Desktop/battleship_17B-master/MainMenu/Sounds/BGM.mp3"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);

    QMediaPlayer *music = new QMediaPlayer();
    music->setPlaylist(playlist);
    music->play();


    return a.exec();
}
