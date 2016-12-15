#ifndef AI_SHIP_PLACER_H
#define AI_SHIP_PLACER_H

//Author Brandon Robinson 2016
#include <algorithm>
#include <QString>
#include "ship.h"

using namespace std;

class AI_Ship_Placer
{
public:
    AI_Ship_Placer();
    ~AI_Ship_Placer();
    vector<Ship> setShips();
    vector<Ship> setShips2();
    vector<Ship> setShips3();
private:
    bool debugging;

    vector<QString> getRandomCoordinates();
    QString getRandomCoordinate();
    QString num2Coordinate(int number);
    vector<char> getRandomDirections();
    char getRandomDirection();
    QString nextPosition(char direction, QString lastHit);
    int strLetter2Num(QString letter);
    QString num2StrLetter(int x);
    int strNum2Num(QString num);
    QString intNum2StrNum(int num);
    Ship fillShip(QString shipName, QString coordiante, char direction);
    int shipName2Index(QString name);	//Convert a ship name into a indexed number
    QString index2ShipName(int index);
    int shipName2Size(QString name);
    vector<Ship> placeAllShips(vector<QString> coordinates, vector<char> directions);
    vector<Ship> placeShips2(vector<QString> coordinates, vector<char> directions);
    vector<QString> randomCoordinates();
    char num2Letter(int x);


};



#endif // AI_SHIP_PLACER_H
