#ifndef AI_ATTACK_ALGORITHM_H
#define AI_ATTACK_ALGORITHM_H
//Author Brandon Robinson 2016
#include <vector>
#include <string>
#include <QString>
#include <QChar>

using namespace std;

class AI_Attack_Algorithm
{
public:
    AI_Attack_Algorithm();
    ~AI_Attack_Algorithm();
    QString randomFire();
    QString fire(QString position);	//Mainly used for debugging
    QString moveAI();
    QString getLastMove(){ return lastMove; }
    void moveResult(bool hit, bool sunk, int shipSize);

private:

    bool debugging; //Used to display results while debugging

    vector<QString> possMoves;	//Possible moves
    vector<QString> possShip;	//Possible ship coordinates
    vector<QChar> possDirect;	//Possible direction of the ship
    vector<QString> hits;		//Stores all hits made, may be unneeded

    QString lastMove;			//Stores the last move that was made (last attack)
    QString newShipFound;		//Location that the new ship was found
    QChar direction;				//UP(U), DOWN(D), LEFT(L), RIGHT(R)
    int key;

    void randomizeMoves();
    void fillMoves();
    void randomDirect();
    void sunkShip(int shipSize);
    QString nextPosition(QChar direction, QString lastHit);
    QChar switchDirection(QChar direction);

    //Conversion Functions
    int strLetter2Num(QString letter);
    int strNum2Num(QString num);
    QString num2StrLetter(int x);
    QString intNum2StrNum(int num);
    QChar num2Letter(int x);
};

#endif // AI_ATTACK_ALGORITHM_H
