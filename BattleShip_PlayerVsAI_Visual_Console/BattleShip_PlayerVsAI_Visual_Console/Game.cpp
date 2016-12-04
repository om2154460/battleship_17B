#include "stdafx.h"	//For Visual Studio
#include "Game.h"
#include <iostream>
#include <string>
#include <ctype.h>
#include "AI_Ship_Placer.h"

using namespace std;

//Constructor
Game::Game()
{
	int answer;
	cout << "Enter 1 for Player vs Player game." << endl
		<< "Enter 2 for Player vs Computer game." << endl
		<< "Default is Player vs Computer game..." << endl
		<< "Answer: ";
	cin >> answer;
	if (answer == 1){
		pvpGame = true; 
		pvcGame = false;
	}
	else{
		pvcGame = true;
		pvpGame = false;
	}

	debugging = true;
}
//Deconstructor
Game::~Game()
{
}
//Set player names
void Game::setPlayerNames(){
	string name;
	//Prompt player 1 for their
	cout << "Player 1, enter in your username: ";
	cin >> name;
	//Create instance of Player class for Player 1 with their username
	players.push_back(Player(name));

	if (pvpGame){	//Player vs Player game
		//Prompt player 2 for their
		cout << "Player 2, enter in your username: ";
		cin >> name;
		//Create instance of Player class for Player 2 with their username
		players.push_back(Player(name));
	}
	else{	//Player vs Computer game
		players.push_back(Player("Computer"));
	}

}
//Set player and Computer ships
void Game::setPlayerShips(){

	//+========= Need to add while loop for checking that ship coordinates are OK! =========+
	if (pvpGame){	//If Player vs. Player game, get ship coordinates and set the ships for each player
		shipPlacing(2);	
	}
	else if (pvcGame){
		//Get info and set player 1 Ships
		shipPlacing(1);	
		//Set AI (Computer) Ships
		aiShipPlacer();
	}
	
}
//Player vs. Player game
void Game::gamePVP(){

}
//Player vs. Computer game
void Game::gamePVC(){

}

int Game::shipName2Index(string name){
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
//Convert a indexed number into a ship name
string Game::index2ShipName(int index){
	switch (index){
	case 0:	return "CARRIER";
	case 1:	return "BATTLESHIP";
	case 2:	return "CRUISER";
	case 3:	return "SUBMARINE";
	case 4:	return "DESTROYER";
	}
}
//Convert a ship name into a size
int Game::shipName2Size(string name){
	if (name == "CARRIER")	//Size 5
		return 5;
	if (name == "BATTLESHIP")	//Size 4
		return 4;
	if (name == "CRUISER")	//Size 3
		return 3;
	if (name == "SUBMARINE")	//Size 3
		return 3;
	if (name == "DESTROYER")	//Size 2
		return 2;
}
//Place the ships given the provided starting coordinates and directions
vector<Ship> Game::placeShips(vector<string> coordinates, vector<char> directions){
	vector<Ship> ships;
	vector<string> allCoordiantes;
	vector<string> tempCoordinates;
	bool startOver = false;
	bool ok = false;
	std::vector<string>::iterator it;

	//Loop until all ships are placed on valid coordinates and not on top of each other.
	while (!ok){
		//Fill ships with thier coordinates
		for (int i = 0; i < 5; i++){
			ships[i] = fillShip(index2ShipName(i), coordinates[i], directions[i]);
			if (ships[i].getBadPlacement()){
				startOver = true;
				break;	//Break out of the for loop
			}
			//Add the ship coordinates to the all coordinate vector
			tempCoordinates = ships[i].getCoordinates();
			for (int x = 0; x < ships[i].getSize(); x++){
				allCoordiantes.push_back(tempCoordinates[x]);
			}
		}
		//If coordinates go off the map loop back and start over
		if (startOver){
			//Clear allCoordinates vector
			allCoordiantes.erase(allCoordiantes.begin(), allCoordiantes.end());
			startOver = false;
			continue;	//Go back to the beginnning of the while loop
		}
		//Check if ships are on top of each other
		for (int i = 0; i < allCoordiantes.size(); i++){
			it = find(allCoordiantes.begin() + i + 1, allCoordiantes.end(), allCoordiantes.at(i));
			if (it != allCoordiantes.end()){
				startOver = true;
				break;	//Break out of the for loop
			}
		}
		//If one or more coordiantes match each other, start loop over
		if (startOver){
			//Clear allCoordinates vector
			allCoordiantes.erase(allCoordiantes.begin(), allCoordiantes.end());
			startOver = false;
			continue;	//Go back to the beginnning of the while loop
		}

		//Ships are on valid coordinates and not on top of each other. Break out of this while loop. Lets do this!
		ok = true;
	}

	return ships;
}
//Fill Ship based on name, starting coordiante, and direction. Return a filled ship
Ship Game::fillShip(string shipName, string coordinate, char direction){
	Ship ship;
	vector<string> tempCoordinates;
	string temp;
	int shipSize = shipName2Size(shipName) - 1;	//Minus 1 because the first coordinate has already been choosen.

	//Based on the name of the ship, deduce the size of the ship and the index of the ship
	tempCoordinates.push_back(coordinate);
	for (int i = 0; i < shipSize; i++){
		temp = nextPosition(direction, tempCoordinates.at(tempCoordinates.size() - 1));
		if (temp == "Out"){
			ship.setBadPlacement(true);	//Next coordinate was off the grid.
			return ship;	//Return a ship with badPlacement boolean set to true.
		}
		else{
			tempCoordinates.push_back(temp);
		}
	}
	//Assign coordinates to the ship
	ship.createShip(shipSize, tempCoordinates);

	return ship;
}
string Game::nextPosition(char direction, string lastHit){
	string nextPos;
	int temp = 0;   //Only needed for debugging. After code works can combine two lines into one in the switch statement.
	//Break last hit apart into a row and column strings
	string row = lastHit.substr(0, 1); //Letter
	string column = lastHit.substr(1, lastHit.size());  //Number

	switch (direction){
	case 'U':{
		//Move up one, manipulating the letter... Ex: C5 => B5
		if (strLetter2Num(row) == 0) //Row A (Top of grid))
			return "Out";
		else{
			temp = strLetter2Num(row) - 1;
			row = num2StrLetter(temp);
		}
		break;
	}
	case 'D':{
		//Move down one, manipulating the letter... Ex: C5 => D5
		if (strLetter2Num(row) == 9) //Row J (Bottom of grid))
			return "Out";
		else{
			temp = strLetter2Num(row) + 1;
			row = num2StrLetter(temp);
		}
		break;
	}
	case 'L':{
		//Move left one, manipulating the number... Ex: C5 => C4
		if (strNum2Num(column) == 1) //Column 1 (Left of grid)
			return "Out";
		else{
			temp = strNum2Num(column) - 1;
			column = intNum2StrNum(temp);
		}
		break;
	}
	case 'R':{
		//Move right one, manipulating the number... Ex: C5 => C6
		if (strNum2Num(column) == 10) //Column 10 (Right of grid)
			return "Out";
		else{
			temp = strNum2Num(column) + 1;
			column = intNum2StrNum(temp);
		}
		break;
	}
	}

	//nextPos = row + column;   //Does not work. Adds the decimal Unicode instead of the combining the characters
	nextPos += row;
	nextPos += column;

	return nextPos;
}
//Convert a string letter to an integer number (A-J => 0-9)
int Game::strLetter2Num(string letter){
	char cLetter = letter[0];
	switch (cLetter){
	case 'A': return 0;
	case 'B': return 1;
	case 'C': return 2;
	case 'D': return 3;
	case 'E': return 4;
	case 'F': return 5;
	case 'G': return 6;
	case 'H': return 7;
	case 'I': return 8;
	case 'J': return 9;
	}
}
//Convert an integer number to a string letter (0-9 => A-J)
string Game::num2StrLetter(int x){
	//0-9 == A-J
	switch (x){
	case 0: return "A";
	case 1: return "B";
	case 2: return "C";
	case 3: return "D";
	case 4: return "E";
	case 5: return "F";
	case 6: return "G";
	case 7: return "H";
	case 8: return "I";
	case 9: return "J";
	}
}
//Convert a string number to an integer number (0-10)
int Game::strNum2Num(string num){
	char cNum;
	if (num == "10")
		return 10;
	else
		cNum = num[0];
	switch (cNum){
	case '0': return 0;
	case '1': return 1;
	case '2': return 2;
	case '3': return 3;
	case '4': return 4;
	case '5': return 5;
	case '6': return 6;
	case '7': return 7;
	case '8': return 8;
	case '9': return 9;
	}
}
//Convert integer number to string number (0-10)
string Game::intNum2StrNum(int num){
	switch (num){
	case 0: return "0";
	case 1: return "1";
	case 2: return "2";
	case 3: return "3";
	case 4: return "4";
	case 5: return "5";
	case 6: return "6";
	case 7: return "7";
	case 8: return "8";
	case 9: return "9";
	case 10: return "10";
	}
}
//Get info from Player(s) to set ships
void Game::shipPlacing(int numOfPlayers){
	string holdStr;
	char holdChar;
	vector<string> coordinates;
	vector<Ship> ships;
	Ship tempShip;

	for (int x = 0; x < numOfPlayers; x++){
		cout << players[x].getName() << " set your ships!" << endl;
		int i = 0;
		while (i != 5){
			cout << "Enter starting coordinate for your " << index2ShipName(i) << " (" << shipName2Size(index2ShipName(i)) << "): ";
			cin >> holdStr;
			cout << "Enter the direction (D or R) for your " << index2ShipName(i) << " (" << shipName2Size(index2ShipName(i)) << "): ";
			cin >> holdChar;
			//Fill a temporay ship instance
			tempShip = fillShip(index2ShipName(i), holdStr, holdChar);
			//Check that the ship was placed okay
			if (tempShip.getBadPlacement()){
				cout << "Placement of the " << index2ShipName(i) << " was off the grid. Try again!" << endl;
				continue;	//Ship placement was bad, go back to the asking the player for new coordinates.
			}
			//Get the coordinates of the temporary ship to be checked for collision with other ships that have been placed.
			vector<string> tempCoordinates = tempShip.getCoordinates();
			//Varibales to be used for the comparison code. May be put into a function.
			bool rePlaceShip = false;
			std::vector<string>::iterator it;
			//Check the ship to be placed will be on top of another other.
			if (coordinates.size() > 0){
				for (int w = 0; w < tempCoordinates.size(); w++){
					it = find(coordinates.begin() + w, coordinates.end(), tempCoordinates.at(w));
					if (it != coordinates.end()){	//A coordinate of the temporary Ship has matched a coordinate from another ship.
						rePlaceShip = true;	//Set Re-Place flag to true
						break;
					}
				}
				if (rePlaceShip){
					cout << "Placement of the " << index2ShipName(i) << " was on top of another ship. Try again!" << endl;
					continue;	//The temporary ship was placed on top of another ship, go back to the asking the player for new coordinates.
				}
			}

			//Add coordinates of the temporary ship the the coordinate vector for comparing.
			for (int j = 0; j < tempCoordinates.size(); j++){
				coordinates.push_back(tempCoordinates[j]);
			}
			//Fill the player's ship with the temporary ship cooprdinates.
			players[x].setShip(shipName2Size(index2ShipName(i)), tempShip.getCoordinates(), index2ShipName(i));
			//Display where the Ship was placed
			cout << index2ShipName(i) << " placed on coordinates: ";
			for (int f = 0; f < tempCoordinates.size(); f++){
				cout << tempCoordinates[f] << " ";
			}
			cout << endl;

			//Increase the iterator to go to next ship placement.
			i++;
		}
		//Reset hold vectors
		coordinates.erase(coordinates.begin(), coordinates.end());
		ships.erase(ships.begin(), ships.end());
	}
}
void Game::aiShipPlacer(){
	AI_Ship_Placer placeAIShips;
	vector<Ship> tempShips;

	//Use the AI_Ship_Placer class to create ships with valid coordinates.
	tempShips = placeAIShips.setShips3();
	//Assign the created ships to the Player 2 Ships (Computer)
	for (int i = 0; i < 5; i++){
		players[1].setShip(shipName2Size(index2ShipName(i)), tempShips[i].getCoordinates(), index2ShipName(i));
		if (debugging){
			vector<string> tempCoordinates = tempShips[i].getCoordinates();
			cout << "AI placed " << index2ShipName(i) << " at: ";
			for (int x = 0; x < tempShips[i].getSize(); x++){
				cout << tempCoordinates[x] << " ";
			}
			cout << endl;
		}
	}

}
