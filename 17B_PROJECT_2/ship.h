#ifndef SHIP_H
#define SHIP_H
//Author Brandon Robinson 2016
#include <vector>
#include <QString>

using namespace std;

class Ship
{
public:
    Ship();
    Ship(int length, QString * positioning);	//Constructor, takes a QString pointer to positioning coordinates
    Ship(int length, vector<QString> positioning);	//Constructor, takes a vector<QString> filled with positioning coordinates
    ~Ship();	//Destructor
    QString setHit(QString coordinate);	//Check if coordinate of attack is on the ship, if so take away 1 health. Return if hit, miss, or sunk.
    bool getStatus();	//Returns whether the Ship is alive and floating
    void createShip(int length, QString * positioning);	//Set the ship size and coordiantes using a integer length and QString pointer to the coordinates.
    void createShip(int length, vector<QString> positioning);	//Set the ship size and coordiantes using a integer length and QString pointer to the coordinates.
    void createShip(vector<QString> positioning);	//Set the ship size and coordiantes using a vector<QString> and its size function
    void setBadPlacement(bool value);
    bool getBadPlacement();
    int getSize(){ return size; }
    vector<QString> getCoordinates(){ return coordinates; }

private:
    int health;	//Health left of Ship
    int size;	//Size of the Ship
    bool alive;	//Ship is either floating or sunk
    bool badPlacement;
    vector<QString> coordinates;	//Vector holds the coordinates of the Ship
    void setAlive();	////Sets alive boolean based on if health is greater than 0.
};



#endif // SHIP_H
