#pragma once

#include <algorithm>
#include <string>
#include "Ship.h"

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

	vector<string> getRandomCoordinates();
	string getRandomCoordinate();
	string num2Coordinate(int number);
	vector<char> getRandomDirections();
	char AI_Ship_Placer::getRandomDirection();
	string nextPosition(char direction, string lastHit);
	int strLetter2Num(string letter);
	string num2StrLetter(int x);
	int strNum2Num(string num);
	string intNum2StrNum(int num);
	Ship fillShip(string shipName, string coordiante, char direction);
	int shipName2Index(string name);	//Convert a ship name into a indexed number
	string index2ShipName(int index);
	int shipName2Size(string name);
	vector<Ship> placeAllShips(vector<string> coordinates, vector<char> directions);
	vector<Ship> placeShips2(vector<string> coordinates, vector<char> directions);
	vector<string> randomCoordinates();
	char num2Letter(int x);

	
};

