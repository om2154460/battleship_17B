#include "stdafx.h"		//For Visual Studio
#include "AI_Attack_Algorithm.h"


#include <string>		//std::string
#include <iostream>		//std::cout
#include <algorithm>    // std::random_shuffle
#include <vector>       // std::vector
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand
#include <string>       //std::to_string()
using namespace std;


//Constructor, creates a new AI Attack Algorithm instance
AI_Attack_Algorithm::AI_Attack_Algorithm() {
	//Set key to zero, random attacking
	key = 0;
	//Initialize MOVE vector with possMovesLeft, 10 x 10 grid = 100 possible moves
	possMoves.resize(100);
	//Fill possMoves with all possible moves in order
	fillMoves();
	//Randomize move possible move list
	randomizeMoves();
	//Set debugging to true for debugging output
	debugging = true;

}
//Destructor
AI_Attack_Algorithm::~AI_Attack_Algorithm()
{
}
//Create the move list in order
void AI_Attack_Algorithm::fillMoves(){
	for (int i = 0; i < 10; i++){
		for (int x = 0; x < 10; x++){
			//Add move to vector (Row letter + Column number)
			possMoves[(i * 10) + x] = num2Letter(i) + intNum2StrNum(x + 1);    //Must convert integer to a string
		}
	}
	if (debugging){
		//Print possible moves in grid view 10x10 (not randomized)
		for (int i = 0; i < possMoves.size(); i++){
			cout << possMoves[i] << " ";
			if (i % 10 == 9)
				cout << endl;
		}
	}
}
//Randomize the Possible Move List
void AI_Attack_Algorithm::randomizeMoves(){
	//Create temporary move vector and copy vectors
	vector<string> tempMoves(possMoves);
	//Array of numbers the size of the total deck to be randomized.
	int randArray[100];	//Visual Studio does not like [possMoves.size()]
	//int randArray[possMoves.size()];
	//Fill randArray from 0 to totalPossiblemoves - 1
	for (int i = 0; i < possMoves.size(); i++){
		randArray[i] = i;
	}
	//Randomize the randArray
	std::srand(unsigned(std::time(NULL)));   //So that cards are actually random for every game.
	std::random_shuffle(&randArray[0], &randArray[possMoves.size() - 1]);
	//Randomize Possible Moves Vector using the randomized array
	for (int i = 0; i < possMoves.size(); i++){
		possMoves[i] = tempMoves[randArray[i]];
	}

	//Switch last coordinate in Possible Move List with another coordinate based on randomNum that was generated.
	//This is needed because the random_shuffle function does not change the last instance of array
	//Initialize the random seed
	std::srand(unsigned(std::time(NULL)));
	//Generate a random number between 0 and 99
	int randomNum = rand() % 99 + 0;
	//Do the swap!
	string temp = possMoves[possMoves.size() - 1];
	possMoves.at(possMoves.size() - 1) = possMoves.at(randomNum);
	possMoves.at(randomNum) = temp;


	if (debugging){
		//Print possible moves in grid view (randomized)
		cout << endl;
		for (int i = 0; i < possMoves.size(); i++){
			cout << possMoves[i] << " ";
			if (i % 10 == 9)
				cout << endl;
		}
	}

}
//Pop of Move from the back of the Possible Move List (Random Move))
string AI_Attack_Algorithm::randomFire(){
	string temp;
	//Take move from the back of the vector
	temp = possMoves.at(possMoves.size() - 1);
	possMoves.pop_back();
	lastMove = temp;
	if (debugging){
		cout << "AI fires at: " << temp << endl;
	}
	return temp;
}
//Fire function for specific cell, not random, remove Move from Possible Move List
string AI_Attack_Algorithm::fire(string position){
	string temp;
	//Find the index of the move
	int pos = find(possMoves.begin(), possMoves.end(), position) - possMoves.begin();
	//If Move has coordinate has already been shot.....
	if (pos == possMoves.size()){
		return "Unavailable";
	}
	//Take move from the back of the vector
	temp = possMoves.at(pos);
	possMoves.erase(possMoves.begin() + pos);
	lastMove = temp;

	if (debugging){
		cout << "AI fires at: " << temp << endl;
	}

	return temp;
}
//Confirmation of a ship sinking has been received, remove coordinates from Possible Ship List
void AI_Attack_Algorithm::sunkShip(int shipSize){
	//Code has not been checked to work yet.
	bool directOK = true;
	//Get current direction and reverse it.
	char checkDirection = switchDirection(direction);
	//Check if last n amount of moves were in the same direction
	int size = possShip.size();    //For debugging
	string value1 = "", value2 = "";
	int n = 1;
	int bound = possShip.size() - shipSize;
	int startPos = (possShip.size() - 2);
	for (int i = startPos; i >= bound; i--){
		value1 = possShip.at(i);
		value2 = nextPosition(checkDirection, possShip.at(possShip.size() - n));
		n++;
		if (debugging){ cout << "Comparing: " << value1 << " & " << value2 << endl; }
		if (value1 != value2)
			directOK = false;
	}

	if (directOK){   //Last n amount of hit moves were in the same direction, remove those.
		if (debugging){
			cout << "Last " << shipSize << " hits were in a row" << endl;
			cout << "Removed: ";
		}
		for (int i = 0; i < shipSize; i++){
			if (debugging){ cout << possShip.at(possShip.size() - 1) << " "; }
			possShip.pop_back();
		}
		if (debugging){ cout << endl; }
	}
	else{ //Remove first hit move and last shipSize - 1 hit moves
		if (debugging){
			cout << "Last " << shipSize << " hits were NOT in a row\n";
			cout << "Removed: " << possShip.at(0) << " ";
			for (int i = 0; i < shipSize - 1; i++){
				cout << possShip.at(possShip.size() - 1 - i) << " ";
			}
			cout << endl;
		}
		possShip.erase(possShip.begin());
		for (int i = 0; i < shipSize - 1; i++){
			possShip.pop_back();
		}
	}

	if (possShip.size() == 0){   //All possible ship hits have been removed from the list
		key = 0;    //Start random firing again.
		if (debugging){ cout << "key: " << key << endl; }
	}
	else{
		randomDirect(); //Randomize Direction List
		lastMove = possShip.at(0);  //Set lastMove to the first coordinate left in the Possible Ship List
		key = 1;    //key = 1 => randomly fire around the coordinate
		if (debugging){ cout << "key: " << key << endl; }
	}
}
//Create a new random Direct list
void AI_Attack_Algorithm::randomDirect(){
	//Randomly choose UP(U), DOWN(D), LEFT(L), RIGHT(R)
	char randArray[4];
	randArray[0] = 'U';
	randArray[1] = 'D';
	randArray[2] = 'L';
	randArray[3] = 'R';
	//Randomize the randArray
	int time = std::time(NULL);
	std::srand(unsigned(std::time(NULL)));   //So that cards are actually random for every game.
	//std::iterator g(srand);
	//std::srand ( unsigned ( std::time(NULL)));   //So that cards are actually random for every game.
	std::random_shuffle(&randArray[0], &randArray[3]);
	//Initialize Possible Direction vector with 4 possible directions
	possDirect.resize(4);
	//Copy randArray into possible Direction vector
	for (int i = 0; i < 4; i++){
		possDirect[i] = randArray[i];
	}
	//Switch last direction in Possible Direction List with another direction based on randomNum that was generated.
	//This is needed because the random_shuffle function does not change the last instance of array
	//Initialize the random seed
	std::srand(unsigned(std::time(NULL)));
	//Generate a random number between 0 and 3
	int randomNum = rand() % 3 + 0;
	//Do the swap!
	char temp = possDirect[possDirect.size() - 1];
	possDirect.at(possDirect.size() - 1) = possDirect.at(randomNum);
	possDirect.at(randomNum) = temp;

	if (debugging){
		//For debugging: Print possDirection
		for (int i = 0; i < 4; i++){
			cout << possDirect[i] << " ";
		}
		cout << endl;
	}
}
//Returns the next coordinate based on the last Hit and set direction
string AI_Attack_Algorithm::nextPosition(char direction, string lastHit){
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
//Switch direction of Possible Direction
char AI_Attack_Algorithm::switchDirection(char direction){
	switch (direction){
	case 'U': return 'D';
	case 'D': return 'U';
	case 'L': return 'R';
	case 'R': return 'L';
	}
}
//AI's Attacking Algorithm
string AI_Attack_Algorithm::moveAI(){
	string holdFire = "";
	switch (key){
	case 0:{    //No ships coordinates found yet
		//Fire off random coordinates. popping off from the possible move vector
		randomFire();
		break;
	}
	case 1:{    //New Ship found, create direction list
		//Set direction to popped off direction from possible direction vector
		direction = possDirect.back();
		if (debugging){ cout << "Direction: " << direction << endl; }
		//Remove direction from possible direction list
		possDirect.pop_back();
		if (debugging){
			int size = possDirect.size();
			cout << "Possible Directions Left in List: ";
			for (int i = 0; i < possDirect.size(); i++){
				cout << possDirect.at(i) << " ";
			}
			cout << endl;
		}
		//Fire at one space over in set direction
		holdFire = nextPosition(direction, possShip[0]);
		if (holdFire == "Out"){
			moveAI();
		}
		else{
			if (fire(holdFire) == "Unavailable"){
				if (debugging){ cout << holdFire << " is Unavailable" << endl; }
				moveAI();
			}
		}
		//string check = fire(nextPosition(direction, lastMove));
		//}
		//fire(nextPosition(direction, lastMove));
		//key = 2; cout << "key: " << key << endl;     
		break;
	}
	case 2:{    //Continue attacking in set Direction
		//Fire at one space over in set direction
		holdFire = nextPosition(direction, lastMove);
		if (holdFire == "Out"){
			key = 1;
			if (debugging){ cout << "key: " << key << endl; }
			moveAI();
		}
		else{
			fire(holdFire);
		}
		break;
	}
	case 3:{    //Direction has been set, but last move missed. Go in opposite direction starting at first hit
		direction = switchDirection(direction);
		if (debugging){ cout << "Direction: " << direction << endl; }
		//Remove direction from possible direction list
		//Find the index of the move
		int pos = find(possDirect.begin(), possDirect.end(), direction) - possDirect.begin();
		//Removed direction from possible direction list
		possDirect.erase(possDirect.begin() + pos);
		if (debugging){
			int size = possDirect.size();
			cout << "Possible Directions Left in List: ";
			for (int i = 0; i < possDirect.size(); i++){
				cout << possDirect.at(i) << " ";
			}
			cout << endl;
		}
		fire(nextPosition(direction, possShip.at(0)));
		key = 2;
		if (debugging){ cout << "key: " << key << endl; }
		break;
	}
	case 4:{    //Direction has been set, but last move missed. Go in opposite direction starting at first hit
		direction = switchDirection(direction);
		cout << "Direction: " << direction << endl;
		//Remove direction from possible direction list
		//Find the index of the move
		int pos = find(possDirect.begin(), possDirect.end(), direction) - possDirect.begin();
		//Removed direction from possible direction list
		possDirect.erase(possDirect.begin() + pos);
		if (debugging){
			int size = possDirect.size();
			cout << "Possible Directions Left in List: ";
			for (int i = 0; i < possDirect.size(); i++){
				cout << possDirect.at(i) << " ";
			}
			cout << endl;
		}
		fire(nextPosition(direction, possShip.at(0)));
		key = 2;
		if (debugging){ cout << "key: " << key << endl; }
		break;
	}
	}
	return lastMove;
}
//Take the result of Last Move and set necessary flags
void AI_Attack_Algorithm::moveResult(bool hit, bool sunk, int shipSize){
	if (hit){    //Ship was hit
		//Add coordinate to possible ship list
		possShip.push_back(lastMove);
		hits.push_back(lastMove);
		if (debugging){ cout << lastMove << " added to Possible Ship List. List Size = " << possShip.size() << endl; }
		if (possShip.size() == 1){   //No active ships found
			//Create random direction list
			randomDirect();
			//New Ship has been found flag
			newShipFound = true;
			//Go to next step in AI flow chart
			key = 1; 
			if (debugging){ cout << "key: " << key << endl; }
		}
		else if (sunk){
			sunkShip(shipSize);

		}
		else if (key == 1){
			key = 2;
			if (debugging){ cout << "key: " << key << endl; }
		}


	}
	//else if (key == 3){    //Direction was set, but last move missed, switch directions
	else if (key == 2){    //Direction was set, but last move missed, switch directions
		//key = 4;
		key = 3;
		if (debugging){ cout << "key: " << key << endl; }
		if (debugging){ cout << lastMove << " is a MISS!" << endl; }
	}
	else if (key == 1){
		key = 1;
		if (debugging){ cout << "key: " << key << endl; }
		if (debugging){ cout << lastMove << " is a MISS!" << endl; }
	}
	else{
		key = 0;
		if (debugging){ cout << "key: " << key << endl; }
		if (debugging){ cout << lastMove << " is a MISS!" << endl; }
	}
}


//Converting Functions

//Convert a string letter to an integer number (A-J => 0-9)
int AI_Attack_Algorithm::strLetter2Num(string letter){
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
//Convert a string number to an integer number (0-10)
int AI_Attack_Algorithm::strNum2Num(string num){
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
//Convert an integer number to a string letter (0-9 => A-J)
string AI_Attack_Algorithm::num2StrLetter(int x){
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
//Convert integer number to string number (0-10)
string AI_Attack_Algorithm::intNum2StrNum(int num){
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
//Convert integer number to char letter (0-9 => A-J)
char AI_Attack_Algorithm::num2Letter(int x){
	//0-9 == A-J
	switch (x){
	case 0: return 'A';
	case 1: return 'B';
	case 2: return 'C';
	case 3: return 'D';
	case 4: return 'E';
	case 5: return 'F';
	case 6: return 'G';
	case 7: return 'H';
	case 8: return 'I';
	case 9: return 'J';
	}
}


