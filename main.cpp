/* 
 * File:   main.cpp
 * Author: User
 *
 * Created on November 2, 2016, 7:39 PM
 */

#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;

class AI {
 
private:
    int AIshipSize;
    string AIname;
    bool AIstatus;
    int *AIcoords;
    char *aiCellSymbol;
public:
    AI(int s,string n,bool st) {
    AIshipSize = s;
    AIname = n;
    AIstatus = st;
    AIcoords = new int[s];
    }
    //AI(){}
    void setAICoords(int,int);
    int getAICoords(int);
    void setAIBoard();
    void printAIBoard();
    void adjAISymbol(int,bool);
    bool getAIStatus() {return AIstatus;}
    string getName() {return AIname;}
    ~AI(){}
    
};


int main(int argc, char** argv) {
    
    
    AI ai[5] = { AI(2,"Patrol Boat",false), AI(3,"Destroyer",false),
     AI(3,"Submarine",false), AI(4,"Battleship",false),
     AI(5,"Aircraft Carrier",false)}; 
    
    srand(time(NULL));
    
   int aiCoords[5];
   
   // DOESNT PREVENT SHIPS FROM OVERLAPPING, JUST FROM GOING OFF OF BOARD
   
        for(int i=0;i<5;i++) { 
            if(i == 0) { // HORIZONTAL: restrict x
                int y = (rand()%9)*10; 
                int x = rand()%8; //       
                aiCoords[i] = y+x;
            }
            else if(i==1) { // VERTICAL: restrict y
                int y = (rand()%7)*10; 
                int x = rand()%9;       
                aiCoords[i] = x+y;
            }
            else if(i==2) { // HORIZONTAL
                int y = (rand()%9)*10; 
                int x = rand()%7;      
                aiCoords[i] = x+y;
            }
            else if(i==3) { // VERTICAL
                int y = (rand()%6)*10; 
                int x = rand()%9;       
                aiCoords[i] = x+y;
            }
            else if(i==4) { // HORIZONTAL
                int y = (rand()%9)*10; 
                int x = rand()%4+1;      
                aiCoords[i] = y+x;
             }
        }
     
   // fills in rest of the coordinates of the ship 
     ai[0].setAICoords(0,aiCoords[0]); 
     ai[0].setAICoords(1,aiCoords[0]+1); 
     ai[1].setAICoords(0,aiCoords[1]);
     ai[1].setAICoords(1,aiCoords[1]+10); 
     ai[1].setAICoords(2,aiCoords[1]+20); 
     ai[2].setAICoords(0,aiCoords[2]);    
     ai[2].setAICoords(1,aiCoords[2]+1);
     ai[2].setAICoords(2,aiCoords[2]+2);
     ai[3].setAICoords(0,aiCoords[3]);
     ai[3].setAICoords(1,aiCoords[3]+10);
     ai[3].setAICoords(2,aiCoords[3]+20);
     ai[3].setAICoords(3,aiCoords[3]+30);
     ai[4].setAICoords(0,aiCoords[4]);
     ai[4].setAICoords(1,aiCoords[4]+1);
     ai[4].setAICoords(2,aiCoords[4]+2);
     ai[4].setAICoords(3,aiCoords[4]+3);
     ai[4].setAICoords(4,aiCoords[4]+4);
     
     
    
    int testArr[17];
     int j=0,z=0;
     
     for(int i=0;i<17;i++) {
         
         if(i == 0 || i == 2 || i == 5 || i == 8 || i == 12) { // ship 1's elements
             cout << endl;
             cout << ai[j].getName() << " ";
             j++; 
             z=0;
         }
         cout << ai[j].getAICoords(z) << " ";
         z++;
     }
     
     cout << endl;
     cout << "- program randomly generates 4 numbers." << endl;
     cout << "- these numbers be the first coordinate (left-most or top-most) of each ship" << endl;
     cout << "- the vertical ships coordinates will be 10 apart, horizontal coordinates will be 1 apart" << endl;
     cout << "- 2 will always be vertical and the other 3 will always be horizontal." << endl;
     cout << "- the Patrol Boat and the Submarine are vertical" << endl;
     cout << endl;
     
     
     
    return 0;
}

void AI::setAICoords(int coordCnt, int value) {
     AIcoords[coordCnt] = value; 
  }

 
  int AI::getAICoords(int i) {
      return AIcoords[i];
  }
  
  