#include "stdafx.h"
#include "Player.h"

using namespace std;

//Constructor, new player
Player::Player(string name){
	playerName = name;
}
Player::Player(){}
//Destructor
Player::~Player(){
}
//Set Ship,Arguments for Ship Constructor, takes a string pointer to positioning coordinates
void Player::setShip(int length, string * positioning){
	ships[0].createShip(length, &positioning[0]);
}
//Set Ship,Arguments for Ship Constructor, takes a vector<string> filled with positioning coordinates
void Player::setShip(int length, vector<string> positioning){

}
//Set Ship,Arguments for Ship Constructor, takes a vector<string> filled with positioning coordinates
void Player::setShip(int length, vector<string> positioning, string shipName){
	ships[shipName2Index(shipName)].createShip(length, positioning);
}
//Set ship in Ship vector based on its name for indexing.
void Player::setShip(string name, int length, string * positioning){
	ships[shipName2Index(name)].createShip(length, &positioning[0]);
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
//Add Coordinate to Move List, check if the move has been made before.
bool Player::addMove(string coordinate){
	int pos = find(moveList.begin(), moveList.end(), coordinate) - moveList.begin();
	if (pos == moveList.size()){	//Move has already been made
		return false;	
	}
	else{	//Move has not been made
		moveList.push_back(coordinate);
		return true;
	}
}
