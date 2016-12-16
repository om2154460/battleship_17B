#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <vector>
#include <QVector>
#include <QMenuBar>
#include <QAction>
#include <QLabel>
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

    void addShip();


public slots:


private slots:
    void on_btnPlay_clicked();
    void on_btnReset_clicked();
    void on_btnEnterShip_clicked();
    void on_rbtnHorizontal_clicked();
    void on_rbtnVertical_clicked();

    void handleButton();    //Brandon
    void handlePlayerButton();  //Conner
    void gamePlay();
    void AIShipPlacement();
    void newGame();
    void loadGame();
    void aboutScreen();
    void helpScreen();
    void loginScreen();
    void resetShips();

private:
    Ui::MainWindow *ui;

    int numDrops;
    int firstCoordArr[5];
    //int coordTestArr[17];
    std::vector<int> coordTestVec;
    bool overlap;
    QPushButton * playerCells[100];
    QPushButton * enemyCells[100];
    QLabel * prowLabels[10];
    QLabel * pcolLabels[10];
    QLabel * erowLabels[10];
    QLabel * ecolLabels[10];
    ConversionFunctions cf;
    AI_Attack_Algorithm aiAttack;

    void createPlayerGrid();
    void createEnemyGrid();
    void createPlayerGridLabels();
    void createEnemyGridLabels();

    Ship fillShip(QString shipName, QString coordinate, QChar direction);
    QString nextPosition(QChar direction, QString lastHit);


    QVector<Ship> enemyShips;
    QVector<Ship> tempShips;
     vector<QString> coordinates;
    int holdIndex;
    char direction;
    int drops;
    bool hold;
    bool shipsPlaced;

    Player player;
    Player enemy;

    QString userName;
    QString password;
    bool loggedIn;

    bool time2Play;
    bool playerTurn;
    bool playerWon;
    bool debugging;

    void setupMenu();
    void createMenuActions();
    void createMenus();
    QMenuBar menu;
    QMenu * fileMenu;
    QMenu * editMenu;
    QMenu * helpMenu;
    QAction * newAct;
    QAction * loadAct;
    QAction * loginAct;
    QAction * aboutAct;
    QAction * helpAct;
    QAction * resetAct;

};

#endif // MAINWINDOW_H
