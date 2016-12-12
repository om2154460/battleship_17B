#ifndef SHIP_H
#define SHIP_H

#include <vector>
#include <string>

using namespace std;

class Ship
{
public:
    Ship();
    Ship(int length, string * positioning);	//Constructor, takes a string pointer to positioning coordinates
    Ship(int length, vector<string> positioning);	//Constructor, takes a vector<string> filled with positioning coordinates
    ~Ship();	//Destructor
    string setHit(string coordinate);	//Check if coordinate of attack is on the ship, if so take away 1 health. Return if hit, miss, or sunk.
    bool getStatus();	//Returns whether the Ship is alive and floating
    void createShip(int length, string * positioning);	//Set the ship size and coordiantes using a integer length and string pointer to the coordinates.
    void createShip(int length, vector<string> positioning);	//Set the ship size and coordiantes using a integer length and string pointer to the coordinates.
    void createShip(vector<string> positioning);	//Set the ship size and coordiantes using a vector<string> and its size function
    void setBadPlacement(bool value);
    bool getBadPlacement();
    int getSize(){ return size; }
    vector<string> getCoordinates(){ return coordinates; }

private:
    int health;	//Health left of Ship
    int size;	//Size of the Ship
    bool alive;	//Ship is either floating or sunk
    bool badPlacement;
    vector<string> coordinates;	//Vector holds the coordinates of the Ship
    void setAlive();	////Sets alive boolean based on if health is greater than 0.
};



#endif // SHIP_H
