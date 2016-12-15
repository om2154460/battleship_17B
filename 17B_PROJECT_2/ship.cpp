//Author Brandon Robinson 2016
#include "Ship.h"
#include <algorithm>    // std::random_shuffle, and find function

using namespace std;

Ship::Ship(){
    //Set alive boolean to true. The ship is now afloat!
    alive = false;
    badPlacement = false;
}
//Constructor, takes a QString pointer to positioning coordinates
Ship::Ship(int length, QString * positioning){
    //Set Ship size equal to length parameter
    size = length;
    //Set ship health equal to the size of the ship
    health = size;
    //Resize the coordinate vector
    coordinates.resize(size);
    //Fill the coordinate vector with the parametered posistion pointer
    for (int i = 0; i < size; i++){
        //Add position to coordinate vector
        coordinates.push_back(*positioning);
        //Increment positioning pointer
        positioning++;
    }
    //Set alive boolean to true. The ship is now afloat!
    alive = true;
}
//Constructor, takes a vector<QString> filled with positioning coordinates
Ship::Ship(int length, vector<QString> positioning){
    //Set Ship size equal to length parameter
    size = length;
    //Set ship health equal to the size of the ship
    health = size;
    //Resize the coordinate vector
    coordinates.resize(size);
    //Fill the coordinate vector with the parametered posistion pointer
    for (int i = 0; i < size; i++){
        //Add position to coordinate vector
        coordinates.push_back(positioning[i]);
    }
    //Set alive boolean to true. The ship is now afloat!
    alive = true;
}
//Destructor
Ship::~Ship()
{
}
//Check if coordinate of attack is on the ship, if so take away 1 health. Return if hit, miss, or sunk.
QString Ship::setHit(QString coordinate){
    int pos = find(coordinates.begin(), coordinates.end(), coordinate) - coordinates.begin();
    if (pos == size){
        return "MISS";	//Coordinate was NOT FOUND in the coordinate vector
    }
    else{
        //Subtract 1 health from ship
        health--;
        //Set alive boolean based on if health is greater than 1
        setAlive();
        //Determine if Ship is just hit or sunk.
        if (getStatus())
            return "HIT";	//Coordinate was FOUND in the coordinate vector, ship hit.
        else
            return "SUNK";	//Coordinate was FOUND in the coordinate vector, ship is now sunk.
    }



}
//Returns whether the Ship is alive and floating
bool Ship::getStatus(){
    return alive;
}
//Sets alive boolean based on if health is greater than 0.
void Ship::setAlive(){
    if (health <= 0){
        alive = false;
    }
    else{
        alive = true;
    }
}
//Set the ship size and coordiantes using a integer length and QString pointer to the coordinates.
void Ship::createShip(int length, QString * positioning){
    //Set Ship size equal to length parameter
    size = length;
    //Set ship health equal to the size of the ship
    health = size;
    //Fill the coordinate vector with the parametered posistion pointer
    for (int i = 0; i < size; i++){
        //Add position to coordinate vector
        coordinates.push_back(*positioning);
        //Increment positioning pointer
        positioning++;
    }
    //Set alive boolean to true. The ship is now afloat!
    alive = true;
}
//Set the ship size and coordiantes using a integer length and QString pointer to the coordinates.
void Ship::createShip(int length, vector<QString> positioning){
    //Set Ship size equal to length parameter
    size = length;
    //Set ship health equal to the size of the ship
    health = size;
    //Fill the coordinate vector with the parametered position vector
    coordinates = positioning;
    //Set alive boolean to true. The ship is now afloat!
    alive = true;
}
//Set the ship size and coordiantes using a vector<QString> and its size function
void Ship::createShip(vector<QString> positioning){
    //Set Ship size equal to length parameter
    size = positioning.size();
    //Set ship health equal to the size of the ship
    health = size;
    //Fill the coordinate vector with the parametered position vector
    coordinates = positioning;
    //Set alive boolean to true. The ship is now afloat!
    alive = true;
}
//Set Bad Placement boolean
void Ship::setBadPlacement(bool value){
    badPlacement = value;
}
bool Ship::getBadPlacement(){
    return badPlacement;
}

//TODO:
/*
*Create alternative constructor for resumming a game.
*
*
*/
