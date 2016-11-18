#include "mainwindow.h"
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QBoxLayout>
#include <QGraphicsView>
#include <QMouseEvent>
#include <QMouseEventTransition>
#include <QLabel>
#include <QPainter>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>


class Cell: public QWidget {

public:
    Cell();
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    void setIndex(int);

    int getIndex() {return index;}

    ~Cell(){}
private:
    QPushButton *button;
    std::vector<int> coordsAttacked;
    int *shipCoords;
    int index;

private slots:
    void handleButton();
    void recordAttack();
};



class AICell: public QWidget {

public:
    AICell();
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    void setAICell();

    ~AICell(){}
private:
    QPushButton *AIbutton;
private slots:
    void handleAIButton();
};

class AI { // : public AICell

private:
    int AIshipSize;
    std::string AIname;
    bool AIstatus;
    int *AIcoords;
    char *aiCellSymbol;
public:
    AI(int s,std::string n,bool st) {
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
    std::string getName() {return AIname;}
    ~AI(){}

};


/*class BRect : public Cell {
public:
    BRect(QGraphicsItem *parent = 0);
~BRect(){}
    QRectF boundingRect(); //  const Q_DECL_OVERRIDE
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0); // Q_DECL_OVERRIDE;
};*/




class GraphicsView : public QGraphicsView {
public:
    GraphicsView(QGraphicsScene *scene) : QGraphicsView(scene) {
    }

protected:
    virtual void resizeEvent(QResizeEvent *) Q_DECL_OVERRIDE {
    }
};




/*void MainWindow::handleButton() {

button->setStyleSheet("background-color: red");

}*/

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);


 QGraphicsScene scene(-20, -20, 250, 300); // (-200, -200, 400, 400);


QLabel *l;
l = new QLabel[2];
 l[0].setText("Player's Board");
 l[1].setText("Opponent's Board");

 l[0].setGeometry(200,100,100,25);
 l[1].setGeometry(800,100,100,25);

 scene.addWidget(&l[0]);
 scene.addWidget(&l[1]);

    Cell *c;
    c = new Cell[100];


int x=0;
int y=1;

    for(int i=0;i<100;i++) {
        if(i %10 == 0) {
           x = 0;
           y++;
        }
    c[i].setGeometry(50+(50*x),50+(50*y),100,100);
    c[i].setIndex(i);
    c[i].setAutoFillBackground(true);
    scene.addWidget(&c[i]);
    x++;

}


    srand(time(NULL));



    AI ai[5] = { AI(2,"Patrol Boat",false), AI(3,"Destroyer",false),
         AI(3,"Submarine",false), AI(4,"Battleship",false),
         AI(5,"Aircraft Carrier",false)};

    int aiCoords[5];
    bool overlap = true;
   // int x,y;

      while(overlap == true) {

            for(int i=0;i<5;i++) { // ship1
                if(i == 0) { // HORIZONTAL: restrict x
                     y = (rand()%9)*10;
                     x = rand()%8; //
                    aiCoords[i] = y+x;
                }
                else if(i==1) { // VERTICAL: restrict y
                     y = (rand()%7)*10;
                     x = rand()%9;
                    aiCoords[i] = x+y;
                }
                else if(i==2) { // HORIZONTAL
                    y = (rand()%9)*10;
                     x = rand()%7;
                    aiCoords[i] = x+y;
                }
                else if(i==3) { // VERTICAL
                    y = (rand()%6)*10;
                    x = rand()%9;
                    aiCoords[i] = x+y;
                }
                else if(i==4) { // HORIZONTAL
                     y = (rand()%9)*10;
                     x = rand()%4+1;
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

         // REDO IF OVERLAP FOUND

        ///////////// PUT ALL SHIP COORDS INTO 1 ARRAY ///////////////
             int tCount = 0, p=0;;
             int overlapTestArr[17];

             for(int i=0; i<17; i++) {
                if(i == 2 || i == 5 || i == 8 || i == 12) {
                    tCount++;
                    p=0;
                }
                overlapTestArr[i] = ai[tCount].getAICoords(p);
                p++;
             }

            int* end = overlapTestArr + 17;
            std::sort(overlapTestArr, end);
            overlap = (std::unique(overlapTestArr, end) != end);
         ///////////////////////////////////////////////////////////////
        }

    AICell *AIc;
    AIc = new AICell[100];


   x=0;
   y=1;

    for(int i=0;i<100;i++) {
        if(i %10 == 0) {
           x = 0;
           y++;
        }
    AIc[i].setGeometry(750+(50*x),50+(50*y),50,50);
    AIc[i].setAutoFillBackground(true);
    scene.addWidget(&AIc[i]);



    int j=0,z=0;

       for(int cnt=0;cnt<17;cnt++) {

           if(cnt == 2 || cnt == 5 || cnt == 8 || cnt == 12) { // ship 1's elements

               j++;
               z=0;
           }
          if (ai[j].getAICoords(z) ==  i) {
             AIc[i].setAICell();
          }
           z++;
       }


    x++;

}




    GraphicsView view(&scene);
    view.setWindowTitle("Set Ship Coordinates");
    view.setRenderHint(QPainter::Antialiasing);


    view.showMaximized();

    return a.exec();
}

Cell::Cell() {
    button = new QPushButton(this),
    connect(button, SIGNAL (released()), this, SLOT (handleButton()));
   // connect(button, SIGNAL (released()), this, SLOT (recordAttack(index)));
}

void Cell::handleButton() {
    button->setStyleSheet("background-color: red");

}
 void Cell::recordAttack() {
     int temp = getIndex();
     coordsAttacked.push_back(temp);
 }
  void Cell::setIndex(int temp) {
      index = temp;
  }

void Cell::mousePressEvent(QMouseEvent *e) {
    update();
}


void Cell::mouseReleaseEvent(QMouseEvent *e) {
   // palette.setColor(QPalette::Base,Qt::blue);
    //this->setPalette(palette);
button->setStyleSheet("background-color: red");
}


void AI::setAICoords(int coordCnt, int value) {
     AIcoords[coordCnt] = value;
  }


  int AI::getAICoords(int i) {
      return AIcoords[i];
  }



AICell::AICell() {
    AIbutton = new QPushButton(this),
    connect(AIbutton, SIGNAL (released()), this, SLOT (handleButton()));
}

void AICell::handleAIButton() {
    AIbutton->setStyleSheet("background-color: red");
}

void AICell::mousePressEvent(QMouseEvent *e) {
    update();
}


void AICell::mouseReleaseEvent(QMouseEvent *e) {
   // palette.setColor(QPalette::Base,Qt::blue);
    //this->setPalette(palette);
AIbutton->setStyleSheet("background-color: red");
}

void AICell::setAICell() {
AIbutton->setStyleSheet("background-color: red");
}

