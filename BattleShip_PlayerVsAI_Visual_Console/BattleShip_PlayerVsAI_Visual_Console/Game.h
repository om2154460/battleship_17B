#include "Player.h"
#include "AI_Attack_Algorithm.h"
#include "Ship.h"
#include <string>
#include <vector>

using namespace std;

#pragma once
class Game
{
public:
	Game();
	~Game();
	void setPlayerNames();	//Set player names
	void setPlayerShips();	//Set player and Computer ships
	void gamePVP();	//Player vs. Player game
	void gamePVC();	//Player vs. Computer game


private:
	bool debugging;
	vector<Player> players;
	bool pvpGame;
	bool pvcGame;
	AI_Attack_Algorithm AI;

	int shipName2Index(string name);
	string index2ShipName(int index);
	int shipName2Size(string name);
	//For placing ships
	vector<Ship> placeShips(vector<string> coordinates, vector<char> directions);
	Ship placeShip(string coordinates, char directions);
	Ship fillShip(string shipName, string coordinate, char direction);
	string nextPosition(char direction, string lastHit);
	int strLetter2Num(string letter);
	string num2StrLetter(int x);
	int strNum2Num(string num);
	string intNum2StrNum(int num);
	void shipPlacing(int numOfPlayers);
	void aiShipPlacer();
};

