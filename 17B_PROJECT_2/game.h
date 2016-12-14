#ifndef GAME_H
#define GAME_H

#include <QDialog>
#include <QPushButton>
#include <mainwindow.h>

namespace Ui {
class Game;
}

class Game : public QDialog
{
    Q_OBJECT
    friend class MainWindow;

public:
    explicit Game(QWidget *parent = 0);
    void setShips();
    ~Game();

public slots:
    void handleButton();

private:
    Ui::Game *ui;
    QPushButton *playerCells[100];
    QPushButton *aiCells[100];

    int patrol[2],destroyer[3],submarine[3];
    int battleship[4], aircraftCarrier[5];
};

#endif // GAME_H
