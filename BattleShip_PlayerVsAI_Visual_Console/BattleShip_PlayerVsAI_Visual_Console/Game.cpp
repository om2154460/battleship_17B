#include "stdafx.h"	//For Visual Studio
#include "Game.h"
#include <iostream>
#include <string>
#include <ctype.h>
#include "AI_Ship_Placer.h"
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand
#include <regex>

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

	debugging = false;
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
	playerTurn = chooseTurn();
	gameOver = false;
	string attack;
	Ship tempShip;
	string temp;
	string result;
	string shipName;

	playerTurn = chooseTurn();
	if (playerTurn == 0)
		playerNotTurn = 1;
	else
		playerNotTurn = 0;

	while (!gameOver){
		//Get Player attack
		attack = getPlayerAttack(playerTurn);
		//Check if hit or miss or sunk
		temp = players[playerNotTurn].checkAttack(attack);
		result = temp.substr(0,1);
		//Tell the player what the result of his/her attack was
		if (result == "0"){	//Miss
			cout << attack << " was a miss." << endl;
		}
		else if (result == "1"){	//Ship was hit
			cout << attack << " was a hit!" << endl;
		}
		else if (result == "2"){	//Ship was hit and sunk
			shipName = temp.substr(1, temp.size() - 1);
			cout << attack << " was a hit! " << shipName <<" was sunk!" << endl;
		}

		if (players[playerNotTurn].getShipsAlive() == 0){	//Other play no longer has any afloat ships
			gameOver = true;	//Set GameOver to true to break out of while loop
			continue;	//Skip turn switching, go to validation checking of the while loop
		}
			
		//Switch turns
		if (playerTurn == 0){
			playerTurn = 1;
			playerNotTurn = 0;
		}
			
		else{
			playerTurn = 0;
			playerNotTurn = 1;
		}
			
	}
	cout << players[playerTurn].getName() << " won! Game Over." << endl;

}
//Player vs. Computer game
void Game::gamePVC(){
	playerTurn = chooseTurn();
	gameOver = false;
	string attack;
	Ship tempShip;
	string temp;
	string result;
	string shipName;
	AI_Attack_Algorithm AI;

	playerTurn = chooseTurn();
	if (playerTurn == 0)
		playerNotTurn = 1;
	else
		playerNotTurn = 0;

	while (!gameOver){
		result = "0";
		if (playerTurn == 0){
			//Get Player attack
			attack = getPlayerAttack(playerTurn);
			//Check if hit or miss or sunk
			temp = players[playerNotTurn].checkAttack(attack);
			result = temp.substr(0, 1);
			//Tell the player what the result of his/her attack was
			if (result == "0"){	//Miss
				cout << attack << " was a miss." << endl;
			}
			else if (result == "1"){	//Ship was hit
				cout << attack << " was a hit!" << endl;
			}
			else if (result == "2"){	//Ship was hit and sunk
				shipName = temp.substr(1, temp.size() - 1);
				cout << attack << " was a hit! " << shipName << " was sunk!" << endl;
			}
			if (players[playerNotTurn].getShipsAlive() == 0){	//Other play no longer has any afloat ships
				gameOver = true;	//Set GameOver to true to break out of while loop
				continue;	//Skip turn switching, go to validation checking of the while loop
			}
		}
		else{
			//Get Computer attack
			attack = AI.moveAI();
			cout << players[1].getName() << " fires at: " << attack << endl;
			//Check if hit or miss or sunk
			temp = players[playerNotTurn].checkAttack(attack);
			//Break apart string for 0, 1, or 2 for miss, hit, sunk respectively
			result = temp.substr(0, 1);
			if (result == "0"){	//Miss
				cout << attack << " was a miss." << endl;
				AI.moveResult(false, false, 0);
			}
			else if (result == "1"){	//Ship was hit
				cout << attack << " was a hit!" << endl;
				AI.moveResult(true, false, 0);
			}
			else if (result == "2"){	//Ship was hit and sunk
				shipName = temp.substr(1, temp.size() - 1);
				cout << attack << " was a hit! " << shipName << " was sunk!" << endl;
				AI.moveResult(true, true, shipName2Size(shipName));
			}
		}


		//Switch turns
		if (playerTurn == 0){
			playerTurn = 1;
			playerNotTurn = 0;
		}

		else{
			playerTurn = 0;
			playerNotTurn = 1;
		}

	}
	cout << players[playerTurn].getName() << " won! Game Over." << endl;

}
//Play the game
void Game::playGame(){
	if (pvpGame){
		gamePVP();
	}
	else if (pvcGame){
		gamePVC();
	}
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
			if (debugging)
			holdStr = fillShipsCoorDebug(i);
			else
				cin >> holdStr;
			if (!checkCoordinate(holdStr)){
				cout << "Coordinate is not in the proper format. Ex: A1. Try Again..." << endl;
				continue;
			}
			cout << "Enter the direction (D or R) for your " << index2ShipName(i) << " (" << shipName2Size(index2ShipName(i)) << "): ";
			if (debugging)
				holdChar = fillShipsDirectDebug();
			else
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
//Randomly choose a player to start the game (returns 0 or 1)
int Game::chooseTurn(){
	//Initialize the random seed
	std::srand(unsigned(std::time(NULL)));
	//Generate a random number between 0 and 1
	int randomNum = rand() % 100 + 1;
	int remainder = randomNum % 2;
	//Convert random Number into a direction
	if (remainder == 0){
		return 0;	//Player One is choosen
	}
	else{
		return 1;	//Player 2 is choosen
	}
}
//Get player attack Coordinate
string Game::getPlayerAttack(int index){
	string attack;
	bool attackOK = false;
	regex reg("^\s*([A-J])(([1][0])|([1-9]))\s*$");	//Regualr expression!!!
	smatch match;
	while (!attackOK){
		//Get the coordiante that the player wishes to attack
		cout << players[index].getName() << " enter your attack: ";
		cin >> attack;
		//Check that the coordinate is in the proper format Ex: A10
		if (checkCoordinate(attack)){
			//Add the coordinate to the player's move list
			attackOK = players[index].addMove(attack);
		}
		else{
			cout << attack << " is not in the proper format. Try Again.." << endl;
			continue;
		}
		//If the move is valid break out of loop
		if (!attackOK){
			cout << attack << " has already been used. Try a different coordinate" << endl;
		}

	}

	return attack;
}
//Uses regular expressions to check that the coordinate is in the proper format.
bool Game::checkCoordinate(string coordinate){
	regex reg("^\s*([A-J])(([1][0])|([1-9]))\s*$");
	if (regex_search(coordinate, reg)){
		//Add the coordinate to the player's move list
		return true;
	}
	else{
		return false;
	}
}
string Game::fillShipsCoorDebug(int index){
	switch (index){
	case 0: return "A1";
	case 1: return "B1";
	case 2: return "C1";
	case 3: return "D1";
	case 4: return "E1";
	}
}
char Game::fillShipsDirectDebug(){
	return 'R';
}
