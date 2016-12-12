#ifndef AI_ATTACK_ALGORITHM_H
#define AI_ATTACK_ALGORITHM_H

#include <vector>
#include <string>

using namespace std;

class AI_Attack_Algorithm
{
public:
    AI_Attack_Algorithm();
    ~AI_Attack_Algorithm();
    string randomFire();
    string fire(string position);	//Mainly used for debugging
    string moveAI();
    string getLastMove(){ return lastMove; }
    void moveResult(bool hit, bool sunk, int shipSize);

private:

    bool debugging; //Used to display results while debugging

    vector<string> possMoves;	//Possible moves
    vector<string> possShip;	//Possible ship coordinates
    vector<char> possDirect;	//Possible direction of the ship
    vector<string> hits;		//Stores all hits made, may be unneeded

    string lastMove;			//Stores the last move that was made (last attack)
    string newShipFound;		//Location that the new ship was found
    char direction;				//UP(U), DOWN(D), LEFT(L), RIGHT(R)
    int key;

    void randomizeMoves();
    void fillMoves();
    void randomDirect();
    void sunkShip(int shipSize);
    string nextPosition(char direction, string lastHit);
    char switchDirection(char direction);

    //Conversion Functions
    int strLetter2Num(string letter);
    int strNum2Num(string num);
    string num2StrLetter(int x);
    string intNum2StrNum(int num);
    char num2Letter(int x);
};

#endif // AI_ATTACK_ALGORITHM_H
