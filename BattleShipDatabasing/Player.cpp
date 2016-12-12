#include "Player.h"
#include <algorithm>    // std::random_shuffle
#include <cstdlib>      // std::rand, std::srand

using namespace std;

//Constructor, new player
Player::Player(string name){
    playerName = name;
    shipsAlive = 0;
}
Player::Player(){}
//Destructor
Player::~Player(){
}
//Set Ship,Arguments for Ship Constructor, takes a string pointer to positioning coordinates
void Player::setShip(int length, string * positioning){
    ships[0].createShip(length, &positioning[0]);
    shipsAlive++;
}
//Set Ship,Arguments for Ship Constructor, takes a vector<string> filled with positioning coordinates
void Player::setShip(int length, vector<string> positioning){

}
//Set Ship,Arguments for Ship Constructor, takes a vector<string> filled with positioning coordinates
void Player::setShip(int length, vector<string> positioning, string shipName){
    ships[shipName2Index(shipName)].createShip(length, positioning);
    shipsAlive++;
}
//Set ship in Ship vector based on its name for indexing.
void Player::setShip(string name, int length, string * positioning){
    ships[shipName2Index(name)].createShip(length, &positioning[0]);
    shipsAlive++;
}
//Convert a ship name into a indexed number
int Player::shipName2Index(string name){
    if (name == "CARRIER")	//Size 5
        return 0;
    if (name == "BATTLESHIP")	//Size 4
        return 1;
    if (name == "CRUISER")	//Size 3
        return 2;
    if (name == "SUBMARINE")	//Size 3
        return 3;
    if (name == "DESTROYER")	//Size 2
        return 4;
}
//Add Coordinate to Move List, check if the move has not been made before.
bool Player::addMove(string coordinate){
    /*if (moveList.size() == 0){
        moveList.push_back(coordinate);
        return true;
    }*/

    std::vector<string>::iterator it;
    it = find(moveList.begin(), moveList.end(), coordinate);
    if (it != moveList.end())
        return false;	//Move was found in the move list
    else{
        moveList.push_back(coordinate);
        return true;	//Move was NOT found in the move list
    }
}
//Take in a string attack coordinate and check if a ship is at that coordinate
string Player::checkAttack(string attack){
    vector<string> coordinates;
    std::vector<string>::iterator it;
    string result = "0";	//0 = Miss, 1 = Hit, 2 = Sunk
    bool found = false;
    //Check only ships that are still floating
    for (int i = 0; i < 5; i++){
        coordinates = ships[i].getCoordinates();
        for (int x = 0; x < coordinates.size(); x++){
            it = find(coordinates.begin(), coordinates.end(), attack);
            if (it != coordinates.end()){	//The attack coordinate was found in a ship
                //result = 1;
                found = true;
                break;
            }
        }
        //If attack was a hit
        if (found){
            //Set hit on Ship
            ships[i].setHit(attack);
            //Check if ship is sunk
            if (ships[i].getStatus()){
                result = "1";
            }
            else{
                result = "2" + index2ShipName(i);
                shipsAlive--;
            }
            break;
        }
    }
    return result;
}
//Convert a indexed number into a ship name
string Player::index2ShipName(int index){
    switch (index){
    case 0:	return "CARRIER";
    case 1:	return "BATTLESHIP";
    case 2:	return "CRUISER";
    case 3:	return "SUBMARINE";
    case 4:	return "DESTROYER";
    }
}
