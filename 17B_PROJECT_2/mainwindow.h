#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <vector>
#include <QVector>
#include "ship.h"
#include "player.h"
#include "conversionfunctions.h"
#include "ai_attack_algorithm.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
friend class Game;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    int patrol[2],destroyer[3],submarine[3];
    int battleship[4], aircraftCarrier[5];



public slots:
    void handlePlayerButton();
    void AIShipPlacement();

private slots:
    void on_btnPlay_clicked();

    void on_btnReset_clicked();

    void on_btnEnterShip_clicked();

    void on_rbtnHorizontal_clicked();

    void on_rbtnVertical_clicked();

    void gamePlay();

private:
    Ui::MainWindow *ui;
    int numDrops;
    int firstCoordArr[5];
    //int coordTestArr[17];
    std::vector<int> coordTestVec;
    bool overlap;
    QPushButton * playerCells[100];
    QPushButton * enemyCells[100];
    ConversionFunctions cf;
    AI_Attack_Algorithm aiAttack;

    void createPlayerGrid();
    void createEnemyGrid();

    QVector<Ship> enemyShips;

    Player player;
    Player enemy;

    bool time2Play;
    bool playerTurn;
    bool debugging;

};

#endif // MAINWINDOW_H
