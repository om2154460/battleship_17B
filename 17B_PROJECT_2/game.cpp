#include "game.h"
#include "ui_game.h"

Game::Game(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Game)
{
    ui->setupUi(this);




    int index=0;

    for(int col=0;col<10;col++) {
        for(int row=0;row<10;row++) {
            index = (row*10)+col;
            playerCells[index] = new QPushButton;
            playerCells[index]->setObjectName("p" + QString::number(index));
            ui->gridLayout->addWidget(playerCells[(row*10)+col],row,col);
            QObject::connect(playerCells[index],SIGNAL(released()),this,SLOT(handleButton()));
        }
    }

    int dim = 10;

    // Vertical spacers
    ui->gridLayout->addItem(new QSpacerItem(20,40,QSizePolicy::Minimum,QSizePolicy::Expanding),0,0,1,dim+2);
    ui->gridLayout->addItem(new QSpacerItem(20,40,QSizePolicy::Minimum,QSizePolicy::Expanding),dim+1,0,1,dim+2);

    // Horizontal spacers
    ui->gridLayout->addItem(new QSpacerItem(40,20,QSizePolicy::Expanding,QSizePolicy::Minimum),1,0,dim,1);
    ui->gridLayout->addItem(new QSpacerItem(40,20,QSizePolicy::Expanding,QSizePolicy::Minimum),1,dim+1,dim,1);

       index=0;

     for(int col=0;col<10;col++) {
           for(int row=0;row<10;row++) {
                index = (row*10)+col;
                aiCells[index] = new QPushButton;
                aiCells[index]->setObjectName("p" + QString::number(index));
                ui->gridLayout_2->addWidget(aiCells[(row*10)+col],row,col);
                QObject::connect(aiCells[index],SIGNAL(released()),this,SLOT(handleButton()));
                        }
                  }

                 // Vertical spacers
                 ui->gridLayout_2->addItem(new QSpacerItem(20,40,QSizePolicy::Minimum,QSizePolicy::Expanding),0,0,1,dim+2);
                 ui->gridLayout_2->addItem(new QSpacerItem(20,40,QSizePolicy::Minimum,QSizePolicy::Expanding),dim+1,0,1,dim+2);

                 // Horizontal spacers
                 ui->gridLayout_2->addItem(new QSpacerItem(40,20,QSizePolicy::Expanding,QSizePolicy::Minimum),1,0,dim,1);
                 ui->gridLayout_2->addItem(new QSpacerItem(40,20,QSizePolicy::Expanding,QSizePolicy::Minimum),1,dim+1,dim,1);



}



void Game::handleButton() {
    ((QPushButton*)sender())->setStyleSheet("background-color: black");

}

 void Game::setShips() {
     MainWindow mw;
     patrol[0] = mw.patrol[0];
     patrol[1] = mw.patrol[1];
     destroyer[0] = mw.destroyer[0];
     destroyer[1] = mw.destroyer[1];
     destroyer[2] = mw.destroyer[2];
     submarine[0] = mw.submarine[0];
     submarine[1] = mw.submarine[1];
     submarine[2] = mw.submarine[2];
     battleship[0] = mw.battleship[0];
     battleship[1] = mw.battleship[1];
     battleship[2] = mw.battleship[2];
     battleship[3] = mw.battleship[3];
     aircraftCarrier[0] = mw.aircraftCarrier[0];
     aircraftCarrier[1] = mw.aircraftCarrier[1];
     aircraftCarrier[2] = mw.aircraftCarrier[2];
     aircraftCarrier[3] = mw.aircraftCarrier[3];
     aircraftCarrier[4] = mw.aircraftCarrier[4];

 }


Game::~Game()
{
    delete ui;
}
