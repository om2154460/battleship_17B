// BattleShip_PlayerVsAI_Visual_Console.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"	//Remove if not using Visual Studio
#include <cstdlib>
#include "AI_Attack_Algorithm.h"
#include "Player.h"
#include "Game.h"
#include <iostream>

using namespace std;

void testAIAttack();
void testGame();

int _tmain(int argc, _TCHAR* argv[])
{
	

	//testAIAttack();
	testGame();

	string hold;
	cout << endl << "Enter anything to exit the program...";
	cin >> hold;

	return 0;
}

void testAIAttack(){
	AI_Attack_Algorithm testAI = AI_Attack_Algorithm();

	int shipSize = 3;
	int count = 0;
	string move = "";
	string ship[3];
	ship[0] = "D7";
	ship[1] = "E7";
	ship[2] = "F7";
	//ship[3] = "D1";
	bool shipNotSunk = true;


	int shipSize1 = 4;
	int count1 = 0;
	string ship1[4];
	ship1[0] = "E3";
	ship1[1] = "E4";
	ship1[2] = "E5";
	ship1[3] = "E6";
	bool shipNotSunk1 = true;

	int shipSize2 = 5;
	int count2 = 0;
	string ship2[5];
	ship2[0] = "D2";
	ship2[1] = "E2";
	ship2[2] = "F2";
	ship2[3] = "G2";
	ship2[4] = "H2";
	bool shipNotSunk2 = true;

	bool hit = false;
	bool exit = false;

	testAI.fire("E3");  //Initial Fire
	testAI.moveResult(true, false, shipSize);
	count1++;
	while (!exit){

		if (!shipNotSunk && !shipNotSunk1 && !shipNotSunk2){
			exit = true;
			continue;
		}


		move = "";
		hit = false;
		move = testAI.moveAI();

		//Check if ship is hit
		for (int i = 0; i < shipSize; i++){
			if (move == ship[i]){
				hit = true;
				count++;
			}
		}

		//Check if ship1 is hit
		for (int i = 0; i < shipSize1; i++){
			if (move == ship1[i]){
				hit = true;
				count1++;
			}
		}

		//Check if ship2 is hit
		for (int i = 0; i < shipSize2; i++){
			if (move == ship2[i]){
				hit = true;
				count2++;
			}
		}

		if (count == shipSize && shipNotSunk){
			testAI.moveResult(hit, true, shipSize);
			shipNotSunk = false;
			continue;
		}


		if (count1 == shipSize1 && shipNotSunk1){
			testAI.moveResult(hit, true, shipSize1);
			shipNotSunk1 = false;
			continue;
		}

		if (count2 == shipSize2 && shipNotSunk2){
			testAI.moveResult(hit, true, shipSize2);
			shipNotSunk2 = false;
			continue;
		}

		testAI.moveResult(hit, false, shipSize);


	}

	string stop;
	cout << endl << "Press Enter to exit";
	cin >> stop;
}

void testGame(){
	Game game;
	game.setPlayerNames();
	game.setPlayerShips();
}
