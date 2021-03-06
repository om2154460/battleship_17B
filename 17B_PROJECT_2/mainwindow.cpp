#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ai_ship_placer.h"
#include "logmenu.h"

#include <Qt>
#include <QStyle>
#include <QPixmap>
#include <QButtonGroup>
#include <QDebug>
#include <QMessageBox>
#include <vector>
#include <algorithm>
#include <QFont>
#include <QDialog>
using namespace std;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {

    ui->setupUi(this);
    this->setWindowTitle("BattleShip CIS17B");

    ui->label_3->setText("<font color='red'>Coordinates may not overlap, click Reset</font>");
    ui->label_3->setVisible(false);

    ui->btnEnterShip->setEnabled(false);

    QButtonGroup bg;
    bg.addButton(ui->rbtnHorizontal);
    bg.addButton(ui->rbtnVertical);

    numDrops=0;
    drops = 0;

    ui->btnPlay->setEnabled(false);

    QPixmap pix1("checkmark.jpg");
    ui->label->setPixmap(pix1);
    ui->label->setScaledContents(true);
    ui->label->setVisible(false);

    //Create Grids
    createPlayerGrid();
    createEnemyGrid();
    //Create Labels for grids
    createPlayerGridLabels();
    createEnemyGridLabels();


    time2Play = false;
    playerTurn = false;
    debugging = true;
    loggedIn = false;
    shipsPlaced = false;
    hold = true;

    //Setup menuBar
    setupMenu();

}

void MainWindow::handleButton(){

    if(!hold){
        QString coordinate;
        char direct;
        vector<Ship> ships;
        Ship tempShip;


        //((QPushButton*)sender())->setStyleSheet("background-color: black");
        //numDrops++;

        int index=0;
        while(playerCells[index]->objectName() != ((QPushButton*)sender())->objectName()) {
            index++;
        }
        coordinate = cf.convertIndex2Cell(index);
        direct = direction;


        //Fill a temporay ship instance
        QString name = cf.index2ShipName(drops);    //For debugging
        tempShip = fillShip(name, coordinate, direct);
        //Check that the ship was placed okay
        if (tempShip.getBadPlacement()){
            qDebug() << "Placement of the " << cf.index2ShipName(drops) << " was off the grid. Try again!";
            return;	//Ship placement was bad, go back to the asking the player for new coordinates.
        }
        //Get the coordinates of the temporary ship to be checked for collision with other ships that have been placed.
        vector<QString> tempCoordinates = tempShip.getCoordinates();
        //Varibales to be used for the comparison code. May be put into a function.
        std::vector<QString>::iterator it;
        //Check the ship to be placed will be on top of another other.
        if (coordinates.size() > 0){
            for (int w = 0; w < signed(tempCoordinates.size()); w++){
                it = std::find(coordinates.begin() + w, coordinates.end(), tempCoordinates.at(w));
                if (it != coordinates.end()){	//A coordinate of the temporary Ship has matched a coordinate from another ship.
                    qDebug() << "Placement of the " + cf.index2ShipName(drops) + " was on top of another ship. Try again!";
                    return;
                }
            }
        }

        //Add coordinates of the temporary ship the the coordinate vector for comparing.
        for (int j = 0; j < signed(tempCoordinates.size()); j++){
            coordinates.push_back(tempCoordinates[j]);
        }
        //Fill the player's ship with the temporary ship cooprdinates.
        //player.setShip(cf.shipName2Size(cf.index2ShipName(drops)), tempShip.getCoordinates(), cf.index2ShipName(drops));
        if(debugging){
            //Display where the Ship was placed
            QString name = cf.index2ShipName(drops);
            qDebug() << name << " placed on coordinates: ";
            QString temp;
            for (int f = 0; f < signed(tempCoordinates.size()); f++){
                temp.append(tempCoordinates[f]);
                temp.append(" ");
            }
            qDebug() << temp;
        }

        //Change grid color;
        for(int x = 0; x < signed(tempCoordinates.size()); x++){
            int tempInt = cf.convertCellr2Index(tempCoordinates[x]);
            playerCells[tempInt]->setStyleSheet("background-color: black");
        }
        //Hold the index for saving the ship
        holdIndex = index;
        //Place a hold on placing any other ships;
        hold = true;
    }


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

    for(int i = 0; i < 100; i++){
        enemyCells[i]->setEnabled(true);
        enemyCells[i]->setStyleSheet("");
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

    time2Play = true;
    playerTurn = true;

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

void MainWindow::on_btnEnterShip_clicked(){
    addShip();
    hold = false;
}
/*
void on_btnEnterShip_clicked2() { // 1 at a time
/////////////////////////// FILL SHIP COORDINATE ARRAYS -> ///////////////////////
overlap = false;

vector<QString> tempCoordinates;
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
        tempCoordinates.push_back(cf.convertIndex2Cell(patrol[0]));
        tempCoordinates.push_back(cf.convertIndex2Cell(patrol[1]));

        tempShip.createShip(tempCoordinates);
        int size = cf.shipName2Size(cf.index2ShipName(4));
        player.setShip(size, tempCoordinates, cf.index2ShipName(4));


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

            tempCoordinates.push_back(cf.convertIndex2Cell(destroyer[0]));
            tempCoordinates.push_back(cf.convertIndex2Cell(destroyer[1]));
            tempCoordinates.push_back(cf.convertIndex2Cell(destroyer[2]));
            player.setShip(cf.shipName2Size(cf.index2ShipName(3)), tempCoordinates, cf.index2ShipName(3));



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
            tempCoordinates.push_back(cf.convertIndex2Cell(submarine[0]));
            tempCoordinates.push_back(cf.convertIndex2Cell(submarine[1]));
            tempCoordinates.push_back(cf.convertIndex2Cell(submarine[2]));
            player.setShip(cf.shipName2Size(cf.index2ShipName(2)), tempCoordinates, cf.index2ShipName(2));

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
        tempCoordinates.push_back(cf.convertIndex2Cell(battleship[0]));
        tempCoordinates.push_back(cf.convertIndex2Cell(battleship[1]));
        tempCoordinates.push_back(cf.convertIndex2Cell(battleship[2]));
        tempCoordinates.push_back(cf.convertIndex2Cell(battleship[3]));
        player.setShip(cf.shipName2Size(cf.index2ShipName(1)), tempCoordinates, cf.index2ShipName(1));

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

        tempCoordinates.push_back(cf.convertIndex2Cell(aircraftCarrier[0]));
        tempCoordinates.push_back(cf.convertIndex2Cell(aircraftCarrier[1]));
        tempCoordinates.push_back(cf.convertIndex2Cell(aircraftCarrier[2]));
        tempCoordinates.push_back(cf.convertIndex2Cell(aircraftCarrier[3]));
        tempCoordinates.push_back(cf.convertIndex2Cell(aircraftCarrier[4]));
        player.setShip(cf.shipName2Size(cf.index2ShipName(0)), tempCoordinates, cf.index2ShipName(0));
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
        }



    }
ui->btnEnterShip->setEnabled(false);

}
*/
void MainWindow::on_rbtnHorizontal_clicked() {
    ui->btnEnterShip->setEnabled(true);
    direction = 'R';
    hold = false;
}

void MainWindow::on_rbtnVertical_clicked() {
    ui->btnEnterShip->setEnabled(true);
    direction = 'D';
    hold = false;
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
            QObject::connect(playerCells[index],SIGNAL(released()),this,SLOT(handleButton()));
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
            enemyCells[index]->setEnabled(false);
            //Connect the QPushButton's released signal to the gamePlay() function
            QObject::connect(enemyCells[index],SIGNAL(released()),this,SLOT(gamePlay()));
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
//Add player grid row and column labels
void MainWindow::createPlayerGridLabels(){
    //Set the font to be used for the Labels
    QFont serifFont("Times", 10, QFont::Bold);
    //Add the Row labels
    for(int i = 0; i < 10; i++){
        prowLabels[i] = new QLabel(cf.index2Row(i));
        prowLabels[i]->setFont(serifFont);
        prowLabels[i]->setAlignment(Qt::AlignCenter);
        ui->playerRowLayout->addWidget(prowLabels[i], i, 0);
    }
    //Set spacing to zero so that there is "no" space between cells
    ui->playerRowLayout->setSpacing(0);
    //Add the column Labels
    for(int i = 1; i < 11; i++){
        pcolLabels[i] = new QLabel(QString::number(i));
        pcolLabels[i]->setFont(serifFont);
        pcolLabels[i]->setAlignment(Qt::AlignCenter);
        ui->playerColLayout->addWidget(pcolLabels[i], 0, i);
    }
    //Set spacing to zero so that there is "no" space between cells
    ui->playerColLayout->setSpacing(0);
}
//Add player grid row and column labels
void MainWindow::createEnemyGridLabels(){
    //Set the font to be used for the Labels
    QFont serifFont("Times", 10, QFont::Bold);
    //Add the Row labels
    for(int i = 0; i < 10; i++){
        erowLabels[i] = new QLabel(cf.index2Row(i));
        erowLabels[i]->setFont(serifFont);
        erowLabels[i]->setAlignment(Qt::AlignCenter);
        ui->enemyRowLayout->addWidget(erowLabels[i], i, 0);
    }
    //Set spacing to zero so that there is "no" space between cells
    ui->enemyRowLayout->setSpacing(0);
    //Add the column Labels
    for(int i = 1; i < 11; i++){
        ecolLabels[i] = new QLabel(QString::number(i));
        ecolLabels[i]->setFont(serifFont);
        ecolLabels[i]->setAlignment(Qt::AlignCenter);
        ui->enemyColLayout->addWidget(ecolLabels[i], 0, i);
    }
    //Set spacing to zero so that there is "no" space between cells
    ui->enemyColLayout->setSpacing(0);
}
//Randomly place the ships for the Computer AI
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
//Game Logic
void MainWindow::gamePlay(){
    if(time2Play){
        bool attackOK = false;
        bool gameOver;
        QString temp;
        QString result;
        QString shipName;
        QString attack;
        //if(playerTurn){
            int count = 0;
            QString name = ((QPushButton*)sender())->objectName();
            while(enemyCells[count]->objectName() != ((QPushButton*)sender())->objectName()) {
                count++;
            }

            attack = cf.convertIndex2Cell(count);
            //Add the coordinate to the player's move list
            attackOK = player.addMove(attack);
            if(attackOK){
                //Check if hit or miss or sunk
                temp = enemy.checkAttack(attack);
                //result = temp.substr(0, 1);
                result = temp.mid(0, 1); //QT way
                qDebug() << "Player Result" + result;
                //Tell the player what the result of his/her attack was
                if (result == "0"){	//Miss
                    qDebug() << attack << " was a miss.";
                    enemyCells[count]->setStyleSheet("background-color: blue");
                }
                else if (result == "1"){	//Ship was hit
                    qDebug() << attack << " was a hit!";
                    enemyCells[count]->setStyleSheet("background-color: red");
                }
                else if (result == "2"){	//Ship was hit and sunk
                    shipName = temp.mid(1, temp.size() - 1); //QT way
                    qDebug() << attack << " was a hit! " << shipName << " was sunk!";
                    enemyCells[count]->setStyleSheet("background-color: red");
                    qDebug() << "Enemy ships left: " + QString::number(enemy.getShipsAlive());
                }
                if (enemy.getShipsAlive() == 0){	//Other play no longer has any afloat ships
                    gameOver = true;	//Set GameOver to true to break out of while loop
                    playerWon = true;
                }
                //Change coordinate and set it to disabled
                enemyCells[count]->setCheckable(false);

            }else{
                qDebug() << attack + " has already been used. Try a different coordinate";
            }

            //Enemy Turn
            attackOK = false;
            while(!attackOK){
                //Get AI attack
                attack = aiAttack.moveAI();
                int index = cf.convertCellr2Index(attack);
                //Add the coordinate to the player's move list
                attackOK = enemy.addMove(attack);
                if(attackOK){
                    //Check if hit or miss or sunk
                    temp = player.checkAttack(attack);
                    //result = temp.substr(0, 1);
                    result = temp.mid(0, 1); //QT way
                    qDebug() << "Cell: " + attack + "   Enemy Result" + result + "  Index: " + QString::number(index);
                    //Tell the player what the result of his/her attack was
                    if (result == "0"){	//Miss
                        qDebug() << attack << " was a miss.";
                        playerCells[index]->setStyleSheet("background-color: blue");
                        aiAttack.moveResult(false, false, 0);
                    }
                    else if (result == "1"){	//Ship was hit
                        qDebug() << attack << " was a hit!";
                        playerCells[index]->setStyleSheet("background-color: red");
                        aiAttack.moveResult(true, false, 0);
                    }
                    else if (result == "2"){	//Ship was hit and sunk
                        shipName = temp.mid(1, temp.size() - 1); //QT way
                        qDebug() << attack << " was a hit! " << shipName << " was sunk!";
                        playerCells[index]->setStyleSheet("background-color: red");
                        aiAttack.moveResult(true, true, cf.shipName2Size(shipName));
                        qDebug() << "Player ships left: " + QString::number(player.getShipsAlive());
                    }
                    if (player.getShipsAlive() == 0){	//Other play no longer has any afloat ships
                        gameOver = true;	//Set GameOver to true to break out of while loop
                        playerWon = false;
                    }
                }
            }


            if(gameOver){
                 ui->playerGrid->setEnabled(false);
                 ui->enemyGrid->setEnabled(false);

                 QMessageBox msgBox;
                 if(playerWon){
                     msgBox.setText("Game Over! Player Won");
                 } else{
                     msgBox.setText("Game Over! You Lost! AI is a beast!");
                 }
                 msgBox.exec();


            }
        //}
    }
}
//Return a filled ship based on ship name, starting coordiante, and direction
Ship MainWindow::fillShip(QString shipName, QString coordinate, QChar direction){
    Ship ship;
    vector<QString> tempCoordinates;
    QString temp;
    int shipSize = cf.shipName2Size(shipName);

    //Based on the name of the ship, deduce the size of the ship and the index of the ship  
    tempCoordinates.push_back(coordinate);
    //Minus 1 because the first coordinate has already been choosen.
    for (int i = 0; i < shipSize - 1; i++){
        temp = nextPosition(direction, tempCoordinates.at(tempCoordinates.size() - 1));
        if (temp == "Out"){
            ship.setBadPlacement(true);	//Next coordinate was off the grid.
            return ship;	//Return a ship with badPlacement boolean set to true.
        }
        else{
            tempCoordinates.push_back(temp);
        }
    }
    //Assign coordinates to the ship
    ship.createShip(shipSize, tempCoordinates);

    return ship;
}
//Get the next coordinate position based on direction
QString MainWindow::nextPosition(QChar direction, QString lastHit){
    QString nextPos;
    int temp = 0;   //Only needed for debugging. After code works can combine two lines into one in the switch statement.
    //Break last hit apart into a row and column QStrings
    //QString row = lastHit.substr(0, 1); //Letter
    //QString column = lastHit.substr(1, lastHit.size());  //Number
    QString row = lastHit.mid(0, 1); //Letter QT way
    QString column = lastHit.mid(1, lastHit.size()); //Number QT way


    switch (direction.toLatin1()){
    case 'U':{
        //Move up one, manipulating the letter... Ex: C5 => B5
        if (cf.strLetter2Num(row) == 0) //Row A (Top of grid))
            return "Out";
        else{
            temp = cf.strLetter2Num(row) - 1;
            row = cf.num2StrLetter(temp);
        }
        break;
    }
    case 'D':{
        //Move down one, manipulating the letter... Ex: C5 => D5
        if (cf.strLetter2Num(row) == 9) //Row J (Bottom of grid))
            return "Out";
        else{
            temp = cf.strLetter2Num(row) + 1;
            row = cf.num2StrLetter(temp);
        }
        break;
    }
    case 'L':{
        //Move left one, manipulating the number... Ex: C5 => C4
        if (cf.strNum2Num(column) == 1) //Column 1 (Left of grid)
            return "Out";
        else{
            temp = cf.strNum2Num(column) - 1;
            column = cf.intNum2StrNum(temp);
        }
        break;
    }
    case 'R':{
        //Move right one, manipulating the number... Ex: C5 => C6
        if (cf.strNum2Num(column) == 10) //Column 10 (Right of grid)
            return "Out";
        else{
            temp = cf.strNum2Num(column) + 1;
            column = cf.intNum2StrNum(temp);
        }
        break;
    }
    }

    nextPos += row;
    nextPos += column;

    return nextPos;
}
//Setup MenuBar for the mainwindow
void MainWindow::setupMenu(){
    //menu = new QMenuBar();
    createMenuActions();
    createMenus();
}
//Create the actions for the items in the menu
void MainWindow::createMenuActions(){
    newAct = new QAction(tr("&New"), this);
    newAct->setShortcuts(QKeySequence::New);
    newAct->setStatusTip(tr("Create a new Game"));
    connect(newAct, &QAction::triggered, this, &MainWindow::newGame);

    loadAct = new QAction(tr("&Load"), this);
    loadAct->setShortcut(tr("Ctrl+L"));
    loadAct->setStatusTip(tr("Load a previous Game"));
    connect(loadAct, &QAction::triggered, this, &MainWindow::loadGame);

    aboutAct = new QAction(tr("&About"), this);
    loadAct->setShortcut(tr("Ctrl+A"));
    aboutAct->setStatusTip(tr("About the creation of BattleShip CIS17B"));
    connect(aboutAct, &QAction::triggered, this, &MainWindow::aboutScreen);


    helpAct = new QAction(tr("&Help"), this);
    helpAct->setStatusTip(tr("Help playing the Game"));
    connect(helpAct, &QAction::triggered, this, &MainWindow::helpScreen);

    loginAct = new QAction(tr("&Login"), this);
    loadAct->setShortcut(tr("Ctrl+H"));
    loginAct->setStatusTip(tr("Login Screen"));
    connect(loginAct, &QAction::triggered, this, &MainWindow::loginScreen);

    resetAct = new QAction(tr("&Reset"), this);
    resetAct->setStatusTip(tr("Reset Ships"));
    loadAct->setShortcut(tr("Ctrl+R"));
    connect(resetAct, &QAction::triggered, this, &MainWindow::resetShips);
}
//Add the items to the menu
void MainWindow::createMenus(){

    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(newAct);
    fileMenu->addSeparator();
    fileMenu->addAction(loadAct);
    fileMenu->addSeparator();
    fileMenu->addAction(loginAct);

    editMenu = menuBar()->addMenu(tr("&Edit"));
    editMenu->addAction(resetAct);

    helpMenu = menuBar()->addMenu(tr("&Help"));
    helpMenu->addAction(aboutAct);
    helpMenu->addAction(helpAct);

}
//Open New Game QDialog and start new ship placement
void MainWindow::newGame(){
    //Needs work...
    /*
    //Clear all the temporary ships
    tempShips.erase(tempShips.begin(), tempShips.end());
    //Reset the grid colors
    for(int i = 0; i < 100; i++){
        playerCells[i]->setStyleSheet("background-color: grey");
        enemyCells[i]->setStyleSheet("background-color: grey");
    }
    //Make placement buttons visible again
    ui->btnPlay->setVisible(false);
    ui->btnReset->setVisible(false);
    ui->btnEnterShip->setVisible(false);
    ui->rbtnHorizontal->setVisible(false);
    ui->rbtnVertical->setVisible(false);
    */
}
//Open Load Game QDialog and load a game from the database
void MainWindow::loadGame(){
    QMessageBox msgBox;
    msgBox.setText("Load Game not setup...");
    msgBox.exec();

    //Need code for displaying games to choose from
    //Then need to ad code for repopulating ships and grid.
}
//Open the about MessageBox
void MainWindow::aboutScreen(){
    QMessageBox msgBox;
    msgBox.setText("About QDialog not setup...");
    msgBox.exec();
}
//Open the Help Screen QDialog
void MainWindow::helpScreen(){
    QMessageBox msgBox;
    msgBox.setText("Help QDialog not setup...");
    msgBox.exec();
}
//Open the login QDialog
void MainWindow::loginScreen(){
    // show modal window event loop and wait for button clicks

    int accepted = 1;

    //Initialize Login Screen
    logmenu lm(this);
    //Pass in current login credintials
    lm.setUser(userName);
    lm.setUser(password);
    //Open Login Screen, returning accept or not
    if(lm.exec() == accepted){
        userName = lm.getUser();
        password = lm.getPass();
        loggedIn = true;
    }

    if(debugging){
        qDebug() << "UserName: " + userName;
        qDebug() << "Password: " + password;
    }

    //Need to add code to


}
//Reset the currently placed ships
void MainWindow::resetShips(){
    //Should only work while setting up ships, not when the game as started.

    //Clear all the temporary ships
    tempShips.erase(tempShips.begin(), tempShips.end());
    //Clear the temp coordinates vector
    coordinates.erase(coordinates.begin(), coordinates.end());
    //Reset the player grid
    for(int i = 0; i < 100; i++){
        playerCells[i]->setStyleSheet("background-color: grey");
    }
    //Clear holdIndex
    holdIndex = 0;
    hold = false;

}
//Commit ship placement to the Player's ships
void MainWindow::addShip(){

    if(drops < 5){
        vector<QString> tempCoordinates;
        Ship tempShip;
        tempShip = fillShip(cf.index2ShipName(drops), cf.convertIndex2Cell(holdIndex), direction);
        player.setShip(tempShip.getSize(),tempShip.getCoordinates(),cf.index2ShipName(drops));
        drops++;
        holdIndex = 0;
        hold = false;

        if(drops == 5){
            //Clicking on the Player grid will no longer do anything
            hold = true;
            shipsPlaced = true;
            ui->btnPlay->setEnabled(true);

            QMessageBox msgBox;
            msgBox.setText("Ships Successfully Placed. Press Play!");
            msgBox.exec();
        }
    }
}
