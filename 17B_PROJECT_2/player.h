#ifndef PLAYER_H
#define PLAYER_H
//Author Brandon Robinson 2016
#include <QString>
#include <vector>
#include "ship.h"

using namespace std;

class Player
{
public:
    Player(QString name);
    Player();
    ~Player();
    void setShip(int length, QString * positioning);	//Set Ship,Arguments for Ship Constructor, takes a string pointer to positioning coordinates
    //void setShip(int length, vector<QString> positioning);	//Set Ship,Arguments for Ship Constructor, takes a vector<string> filled with positioning coordinates
    void setShip(QString name, int length, QString * positioning);
    void setShip(QString name, int length, vector<QString> positioning);
    void setShip(int length, vector<QString> positioning, QString shipName);
    bool addMove(QString coordinate);
    QString getName(){ return playerName; }
    void setName(QString name){ playerName = name; }
    QString checkAttack(QString attack);
    int getShipsAlive(){ return shipsAlive; }
private:
    vector<Ship> ships1;	//Every player has 5 ships
    vector<QString> moveList;
    Ship ships[5];
    int shipsAlive;
    QString playerName;
    int shipName2Index(QString name);
    QString index2ShipName(int index);
};



#endif // PLAYER_H
