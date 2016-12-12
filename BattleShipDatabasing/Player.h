#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "Ship.h"

using namespace std;

class Player
{
public:
    Player(string name);
    Player();
    ~Player();
    void setShip(int length, string * positioning);	//Set Ship,Arguments for Ship Constructor, takes a string pointer to positioning coordinates
    void setShip(int length, vector<string> positioning);	//Set Ship,Arguments for Ship Constructor, takes a vector<string> filled with positioning coordinates
    void setShip(string name, int length, string * positioning);
    void setShip(string name, int length, vector<string> positioning);
    void setShip(int length, vector<string> positioning, string shipName);
    bool addMove(string coordinate);
    string getName(){ return playerName; }
    void setName(string name){ playerName = name; }
    string checkAttack(string attack);
    int getShipsAlive(){ return shipsAlive; }
private:
    vector<Ship> ships1;	//Every player has 5 ships
    vector<string> moveList;
    Ship ships[5];
    int shipsAlive;
    string playerName;
    int shipName2Index(string name);
    string index2ShipName(int index);
};



#endif // PLAYER_H
