#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ai_ship_placer.h"

#include <QStyle>
#include <QPixmap>
#include <QButtonGroup>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {

    ui->setupUi(this);
    this->setWindowTitle("Scramble Your Fleet");

    ui->label_3->setText("<font color='red'>Coordinates may not overlap, click Reset</font>");
    ui->label_3->setVisible(false);

    ui->btnEnterShip->setEnabled(false);

    QButtonGroup bg;
    bg.addButton(ui->rbtnHorizontal);
    bg.addButton(ui->rbtnVertical);

    numDrops=0;

    ui->btnPlay->setEnabled(false);

    QPixmap pix1("C:/Users/User/17B_PROJECT_2/checkmark.jpg");
    ui->label->setPixmap(pix1);
    ui->label->setScaledContents(true);
    ui->label->setVisible(false);

    //play 1

    createPlayerGrid();
    createEnemyGrid();

    debugging = true;

}

void MainWindow::handlePlayerButton() {
    ((QPushButton*)sender())->setStyleSheet("background-color: black");
    numDrops++;

    int cnt=0;
    while(playerCells[cnt]->objectName() != ((QPushButton*)sender())->objectName()) {
        cnt++;
    }

qDebug() << "count: " << cnt;

    if(numDrops == 1) {
        firstCoordArr[0] = cnt;
    }
    else if(numDrops == 2) {
         firstCoordArr[1] = cnt;
    }
    else if(numDrops == 3) {
         firstCoordArr[2] = cnt;
    }
    else if(numDrops == 4) {
         firstCoordArr[3] = cnt;
    }
    else if(numDrops == 5) {
         firstCoordArr[4] = cnt;
    }

    for(int i=0;i<100;i++) {
        playerCells[i]->setEnabled(false);
    }
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_btnPlay_clicked() { // Play button

    /*qDebug() << firstCoordArr[0] << " "  << firstCoordArr[1] << " "  << firstCoordArr[2] << " "  << firstCoordArr[3] << " " << firstCoordArr[4];
    qDebug() << patrol[0] << " " << patrol[1];
    qDebug() << destroyer[0] << " " << destroyer[1] << " " << destroyer[2];
    qDebug() << submarine[0] << " " << submarine[1] << " " << submarine[2];
    qDebug() << battleship[0] << " " << battleship[1] << " " << battleship[2] << " " << battleship[3];
    qDebug() << aircraftCarrier[0] << " " << aircraftCarrier[1] << " " << aircraftCarrier[2] << " " << aircraftCarrier[3] << " " << aircraftCarrier[4];
*/

    for(int i = 0; i < 100; i++){
        playerCells[i]->setStyleSheet("");
        enemyCells[i]->setEnabled(true);
        enemyCells[i]->setStyleSheet("");
        enemyCells[i]->setVisible(true);
    }

ui->btnPlay->setVisible(false);
ui->btnReset->setVisible(false);
ui->btnEnterShip->setVisible(false);
ui->rbtnHorizontal->setVisible(false);
ui->rbtnVertical->setVisible(false);
ui->label->setVisible(false);
ui->label_2->setVisible(false);
ui->label_4->setVisible(true);






    AIShipPlacement();

}

void MainWindow::on_btnReset_clicked() { // Reset button
    for(int i=0;i<100;i++) {
        playerCells[i]->setStyleSheet("");
        playerCells[i]->setEnabled(true);
    }
    numDrops=0;
    ui->label->setVisible(false);
    ui->label_2->setText("Click Your Patrol Boat (2)");
    ui->label_3->setVisible(false);
    ui->rbtnHorizontal->setEnabled(true);
    ui->rbtnVertical->setEnabled(true);
   // patrol[0] = 0;
   // patrol[1] = 0;

}

void MainWindow::on_btnEnterShip_clicked() { // 1 at a time
/////////////////////////// FILL SHIP COORDINATE ARRAYS -> ///////////////////////
overlap = false;

QVector<QString> tempCoordinates;
Ship tempShip;

    if(numDrops == 1) {

         patrol[0] = firstCoordArr[0];

        if(ui->rbtnHorizontal->isChecked()) { // Horizontal
            if(firstCoordArr[0]%10 >=9) {patrol[1] = firstCoordArr[0]-1; } // check if coordinates are possible
            else { patrol[1] = firstCoordArr[0]+1; }

        }
        else {                             // Vertical
           if(firstCoordArr[0] >= 90) {patrol[1] = firstCoordArr[0]-10; }
            else { patrol[1] = firstCoordArr[0]+10; }
        }

        playerCells[patrol[1]]->setStyleSheet("background-color: black");

        coordTestVec.push_back(patrol[0]);
        coordTestVec.push_back(patrol[1]);

        //tempShip.createShip(coordTestVec);
        //player.setShip(cf.shipName2Size(cf.index2ShipName(4)), tempShip.getCoordinates(), cf.index2ShipName(4));


    }

        if(numDrops == 2) {
            destroyer[0] = firstCoordArr[1];
            if(ui->rbtnHorizontal->isChecked()) { // Horizontal
                 if(firstCoordArr[1]%10 == 9) { destroyer[1] = firstCoordArr[1]-1;
                     destroyer[2] = firstCoordArr[1]-2; }
                 else {destroyer[1] = firstCoordArr[1]+1;
                     destroyer[2] = firstCoordArr[1]+2; }


        }
        else {                             // Vertical
            if(firstCoordArr[1] >= 80) {destroyer[1] = firstCoordArr[1]-10;
                destroyer[2] = firstCoordArr[1]-20;}
            else {destroyer[1] = firstCoordArr[1]+10;
                destroyer[2] = firstCoordArr[1]+20; }
        }
            playerCells[destroyer[1]]->setStyleSheet("background-color: black");
            playerCells[destroyer[2]]->setStyleSheet("background-color: black");

            for(int i=0;i<signed(coordTestVec.size());i++) {
                if(coordTestVec[i] == destroyer[0] || coordTestVec[i] == destroyer[1] || coordTestVec[i] == destroyer[2]) {
                 overlap = true;
                }
            }


            coordTestVec.push_back(destroyer[0]);
            coordTestVec.push_back(destroyer[1]);
            coordTestVec.push_back(destroyer[2]);

           // tempCoordinates.push_back(destroyer[0]);
            //tempCoordinates.push_back(destroyer[1]);
            //tempCoordinates.push_back(destroyer[2]);
            //player.setShip(cf.shipName2Size(cf.index2ShipName(3)), tempCoordinates[i].getCoordinates(), cf.index2ShipName(3));



        }



      if(overlap == false) {

        if(numDrops == 3) {
            submarine[0] = firstCoordArr[2];
            if(ui->rbtnHorizontal->isChecked()) { // Horizontal
                if(firstCoordArr[2]%10 >= 8) { submarine[1] = firstCoordArr[2]-1;
                    submarine[2] = firstCoordArr[2]-2; }
                else {submarine[1] = firstCoordArr[2]+1;
                    submarine[2] = firstCoordArr[2]+2; }

        }
        else {                                    // Vertical
                if(firstCoordArr[2] >= 79) {submarine[1] = firstCoordArr[2]-10;
                    submarine[2] = firstCoordArr[2]-20;}
                else {submarine[1] = firstCoordArr[2]+10;
                       submarine[2] = firstCoordArr[2]+20; }
        }
            playerCells[submarine[1]]->setStyleSheet("background-color: black");
            playerCells[submarine[2]]->setStyleSheet("background-color: black");

            for(int i=0;i<signed(coordTestVec.size());i++) {
                if(coordTestVec[i] == submarine[0] || coordTestVec[i] == submarine[1] || coordTestVec[i] == submarine[2]) {
                 overlap = true;
                }
            }


            coordTestVec.push_back(submarine[0]);
            coordTestVec.push_back(submarine[1]);
            coordTestVec.push_back(submarine[2]);

        }

}

if(overlap == false) {

    if(numDrops == 4) {

        battleship[0] = firstCoordArr[3];

        if(ui->rbtnHorizontal->isChecked()) { // Horizontal
            if(firstCoordArr[3]%10 > 6) { battleship[1] = firstCoordArr[3]-1;
                battleship[2] = firstCoordArr[3]-2;
                battleship[3] = firstCoordArr[3]-3;}
            else {battleship[1] = firstCoordArr[3]+1;
                battleship[2] = firstCoordArr[3]+2;
                battleship[3] = firstCoordArr[3]+3;}

        }
        else {                            // Vertical
            if(firstCoordArr[3] >= 69) {battleship[1] = firstCoordArr[3]-10;
                battleship[2] = firstCoordArr[3]-20;
                 battleship[3] = firstCoordArr[3]-30;}
            else { battleship[1] = firstCoordArr[3]+10;
                   battleship[2] = firstCoordArr[3]+20;
                   battleship[3] = firstCoordArr[3]+30;}
        }
        playerCells[battleship[1]]->setStyleSheet("background-color: black");
        playerCells[battleship[2]]->setStyleSheet("background-color: black");
        playerCells[battleship[3]]->setStyleSheet("background-color: black");

        for(int i=0;i<signed(coordTestVec.size());i++) {
            if(coordTestVec[i] == battleship[0] || coordTestVec[i] == battleship[1]
                    || coordTestVec[i] == battleship[2] || coordTestVec[i] == battleship[3]) {
             overlap = true;
            }
        }

        coordTestVec.push_back(battleship[0]);
        coordTestVec.push_back(battleship[1]);
        coordTestVec.push_back(battleship[2]);
        coordTestVec.push_back(battleship[3]);

    }

}

if(overlap == false) {
    if(numDrops == 5) {

         aircraftCarrier[0] = firstCoordArr[4];

        if(ui->rbtnHorizontal->isChecked()) { // Horizontal
            if(firstCoordArr[4]%10 >= 5 ) { aircraftCarrier[1] = firstCoordArr[4]-1;
                aircraftCarrier[2] = firstCoordArr[4]-2;
                aircraftCarrier[3] = firstCoordArr[4]-3;
                aircraftCarrier[4] = firstCoordArr[4]-4;
            }
            else {aircraftCarrier[1] = firstCoordArr[4]+1;
                aircraftCarrier[2] = firstCoordArr[4]+2;
                aircraftCarrier[3] = firstCoordArr[4]+3;
                aircraftCarrier[4] = firstCoordArr[4]+4;
            }
        }
        else {                             // Vertical
            if(firstCoordArr[4] >= 49) {aircraftCarrier[1] = firstCoordArr[4]-10;
                            aircraftCarrier[2] = firstCoordArr[4]-20;
                            aircraftCarrier[3] = firstCoordArr[4]-30;
                            aircraftCarrier[4] = firstCoordArr[4]-40;
                        }
                        else {aircraftCarrier[1] = firstCoordArr[4]+10;
                            aircraftCarrier[2] = firstCoordArr[4]+20;
                            aircraftCarrier[3] = firstCoordArr[4]+30;
                            aircraftCarrier[4] = firstCoordArr[4]+40;
                        }
        }

        playerCells[aircraftCarrier[1]]->setStyleSheet("background-color: black");
        playerCells[aircraftCarrier[2]]->setStyleSheet("background-color: black");
        playerCells[aircraftCarrier[3]]->setStyleSheet("background-color: black");
        playerCells[aircraftCarrier[4]]->setStyleSheet("background-color: black");

        for(int i=0;i<signed(coordTestVec.size());i++) {
            if(coordTestVec[i] == aircraftCarrier[0] || coordTestVec[i] == aircraftCarrier[1]
                    || coordTestVec[i] == aircraftCarrier[2] || coordTestVec[i] == aircraftCarrier[3]
                    || coordTestVec[i] == aircraftCarrier[4]) {
             overlap = true;
            }
        }

        coordTestVec.push_back(aircraftCarrier[0]);
        coordTestVec.push_back(aircraftCarrier[1]);
        coordTestVec.push_back(aircraftCarrier[2]);
        coordTestVec.push_back(aircraftCarrier[3]);
        coordTestVec.push_back(aircraftCarrier[4]);

        //player.setShip(cf.shipName2Size(cf.index2ShipName(5)), coordTestVec[i].getCoordinates(), cf.index2ShipName(5));
    }

}

if(overlap == true) {
    ui->label_3->setVisible(true);
    ui->rbtnHorizontal->setEnabled(false);
    ui->rbtnVertical->setEnabled(false);
    for(int i=0;i<100;i++) {
        playerCells[i]->setEnabled(false);
    }
}
///////////////////////////  <- END FILL SHIP COORDINATE ARRAYS ///////////////////////


    ui->rbtnHorizontal->setAutoExclusive(false);
    ui->rbtnVertical->setAutoExclusive(false);
    ui->rbtnHorizontal->setChecked(false);
    ui->rbtnVertical->setChecked(false);
    ui->rbtnHorizontal->setAutoExclusive(true);
    ui->rbtnVertical->setAutoExclusive(true);

    if(overlap == false) {
         for(int i=0;i<100;i++) {
            playerCells[i]->setEnabled(true);
        }
    }

    if(numDrops == 1) {
        ui->label_2->setText("Click Submarine Coordinate (3)");
    }
    else if(numDrops == 2) {
        ui->label_2->setText("Click Cruiser Coordinate (3)");
    }
    else if(numDrops == 3) {
        ui->label_2->setText("Click Battleship Coordinate (4)");
    }
    else if(numDrops == 4) {
        ui->label_2->setText("Click Carrier Coordinate (5)");
    }
    else if(numDrops == 5) {
        ui->label_2->setText("Ships Have Been Set");
        ui->rbtnHorizontal->setEnabled(false);
        ui->rbtnVertical->setEnabled(false);
        for(int i=0;i<100;i++) {
            playerCells[i]->setEnabled(false);
        }
    }

    if(numDrops>=5) {
        ui->btnPlay->setEnabled(true);
        ui->label->setVisible(true);

        /*for (int i = 0; i < 5; i++){
            player.setShip(cf.shipName2Size(cf.index2ShipName(i)), tempShips[i].getCoordinates(), cf.index2ShipName(i));
            if (debugging){
                vector<QString> tempCoordinates = tempShips[i].getCoordinates();
                qDebug() << "AI placed " << cf.index2ShipName(i) << " at: ";
                QString temp;
                for (int x = 0; x < signed(tempShips[i].getSize()); x++){
                    temp.append(tempCoordinates[x]);
                    temp.append(" ");
                }
                qDebug() << temp;
            }
        }*/



    }
ui->btnEnterShip->setEnabled(false);

}

void MainWindow::on_rbtnHorizontal_clicked() {
    ui->btnEnterShip->setEnabled(true);
}

void MainWindow::on_rbtnVertical_clicked() {
    ui->btnEnterShip->setEnabled(true);
}

//Add the cells to the Player Grid
void MainWindow::createPlayerGrid(){
    int index = 0;
    int dim = 10;
    for(int col = 0; col < 10; col++) {
        for(int row = 0; row < 10; row++) {
            index = (row * 10) + col;
            //Create QPushButton
            playerCells[index] = new QPushButton;
            //Set Newly created QPushButton's Object name to the index in the QPushButton Array
            playerCells[index]->setObjectName(QString::number(index));
            //Set QPushButton's size
            playerCells[index]->setFixedSize(35, 35);
            //Add the QPushButton to the GridLayout
            ui->playerGrid->addWidget(playerCells[(row*10)+col],row,col);
            //Connect the QPushButton's released signal to the handleButton function
            QObject::connect(playerCells[index],SIGNAL(released()),this,SLOT(handlePlayerButton()));
        }
    }

    //Set spacing to zero so that there is "no" space between cells
    ui->playerGrid->setSpacing(0);
    // Vertical spacers
    ui->playerGrid->addItem(new QSpacerItem(20,40,QSizePolicy::Minimum,QSizePolicy::Expanding), 0, 0, 1, dim + 2);
    ui->playerGrid->addItem(new QSpacerItem(20,40,QSizePolicy::Minimum,QSizePolicy::Expanding), dim + 1, 0, 1, dim + 2);

    // Horizontal spacers
    ui->playerGrid->addItem(new QSpacerItem(40,20,QSizePolicy::Expanding,QSizePolicy::Minimum), 1, 0, dim, 1);
    ui->playerGrid->addItem(new QSpacerItem(40,20,QSizePolicy::Expanding,QSizePolicy::Minimum), 1, dim + 1, dim, 1);


}
//Add the cells to the Enemy Grid
void MainWindow::createEnemyGrid(){
    int index=0;
    int dim = 10;

    for(int col = 0; col < 10; col++) {
        for(int row = 0 ;row < 10; row++) {
            index = (row * 10) + col;
            //Create QPushButton
            enemyCells[index] = new QPushButton;
            //Set Newly created QPushButton's Object name to the index in the QPushButton Array
            enemyCells[index]->setObjectName(QString::number(index));
            //Set QPushButton's size
            enemyCells[index]->setFixedSize(35, 35);
            //Add the QPushButton to the GridLayout
            ui->enemyGrid->addWidget(enemyCells[(row*10)+col],row,col);
            enemyCells[index]->setVisible(false);
            //Connect the QPushButton's released signal to the handleButton function
            //QObject::connect(enemyCells[index],SIGNAL(released()),this,SLOT(handleButton()));
        }
    }

    // Vertical spacers
    ui->enemyGrid->addItem(new QSpacerItem(20,40,QSizePolicy::Minimum,QSizePolicy::Expanding),0,0,1,dim+2);
    ui->enemyGrid->addItem(new QSpacerItem(20,40,QSizePolicy::Minimum,QSizePolicy::Expanding),dim+1,0,1,dim+2);

    // Horizontal spacers
    ui->enemyGrid->addItem(new QSpacerItem(40,20,QSizePolicy::Expanding,QSizePolicy::Minimum),1,0,dim,1);
    ui->enemyGrid->addItem(new QSpacerItem(40,20,QSizePolicy::Expanding,QSizePolicy::Minimum),1,dim+1,dim,1);
    //Set spacing to zero so that there is "no" space between cells
    ui->enemyGrid->setSpacing(0);

}

void MainWindow::AIShipPlacement(){
    AI_Ship_Placer placeAIShips;
    vector<Ship> tempShips;

    //Use the AI_Ship_Placer class to create ships with valid coordinates.
    tempShips = placeAIShips.setShips3();
    //Assign the created ships to the Player 2 Ships (Computer)
    for (int i = 0; i < 5; i++){
        enemy.setShip(cf.shipName2Size(cf.index2ShipName(i)), tempShips[i].getCoordinates(), cf.index2ShipName(i));
        if (debugging){
            vector<QString> tempCoordinates = tempShips[i].getCoordinates();
            qDebug() << "AI placed " << cf.index2ShipName(i) << " at: ";
            QString temp;
            for (int x = 0; x < signed(tempShips[i].getSize()); x++){
                temp.append(tempCoordinates[x]);
                temp.append(" ");
            }
            qDebug() << temp;
        }
    }
}


