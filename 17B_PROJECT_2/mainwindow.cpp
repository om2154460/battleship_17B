#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <game.h>

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

    ui->pushButton_3->setEnabled(false);

    QButtonGroup bg;
    bg.addButton(ui->radioButton);
    bg.addButton(ui->radioButton_2);

numDrops=0;
int dim = 10;

ui->pushButton->setEnabled(false);

QPixmap pix1("C:/Users/User/17B_PROJECT_2/checkmark.jpg");
ui->label->setPixmap(pix1);
ui->label->setScaledContents(true);
ui->label->setVisible(false);

//play 1

    int index=0;

    for(int col=0;col<10;col++) {
        for(int row=0;row<10;row++) {
            index = (row*10)+col;
            cells[index] = new QPushButton;
            cells[index]->setObjectName(QString::number(index));
            ui->gridLayout->addWidget(cells[(row*10)+col],row,col);
            QObject::connect(cells[index],SIGNAL(released()),this,SLOT(handleButton()));
        }
    }

    ui->gridLayout->setSpacing(0);

    // Vertical spacers
    ui->gridLayout->addItem(new QSpacerItem(20,40,QSizePolicy::Minimum,QSizePolicy::Expanding),0,0,1,dim+2);
    ui->gridLayout->addItem(new QSpacerItem(20,40,QSizePolicy::Minimum,QSizePolicy::Expanding),dim+1,0,1,dim+2);

    // Horizontal spacers
    ui->gridLayout->addItem(new QSpacerItem(40,20,QSizePolicy::Expanding,QSizePolicy::Minimum),1,0,dim,1);
    ui->gridLayout->addItem(new QSpacerItem(40,20,QSizePolicy::Expanding,QSizePolicy::Minimum),1,dim+1,dim,1);


}

void MainWindow::handleButton() {
    ((QPushButton*)sender())->setStyleSheet("background-color: black");
    numDrops++;

    int cnt=0;
    while(cells[cnt]->objectName() != ((QPushButton*)sender())->objectName()) {
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
        cells[i]->setEnabled(false);
    }
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_pushButton_clicked() { // Play button
   Game g;
    g.setModal(true);
    g.exec();
    this->close();

    /*qDebug() << firstCoordArr[0] << " "  << firstCoordArr[1] << " "  << firstCoordArr[2] << " "  << firstCoordArr[3] << " " << firstCoordArr[4];
    qDebug() << patrol[0] << " " << patrol[1];
    qDebug() << destroyer[0] << " " << destroyer[1] << " " << destroyer[2];
    qDebug() << submarine[0] << " " << submarine[1] << " " << submarine[2];
    qDebug() << battleship[0] << " " << battleship[1] << " " << battleship[2] << " " << battleship[3];
    qDebug() << aircraftCarrier[0] << " " << aircraftCarrier[1] << " " << aircraftCarrier[2] << " " << aircraftCarrier[3] << " " << aircraftCarrier[4];
*/

}

void MainWindow::on_pushButton_2_clicked() { // Reset button
    for(int i=0;i<100;i++) {
        cells[i]->setStyleSheet("");
        cells[i]->setEnabled(true);
    }
    numDrops=0;
    ui->label->setVisible(false);
    ui->label_2->setText("Click Your Patrol Boat (2)");
    ui->label_3->setVisible(false);
    ui->radioButton->setEnabled(true);
    ui->radioButton_2->setEnabled(true);
   // patrol[0] = 0;
   // patrol[1] = 0;

}

void MainWindow::on_pushButton_3_clicked() { // 1 at a time
/////////////////////////// FILL SHIP COORDINATE ARRAYS -> ///////////////////////
overlap = false;

    if(numDrops == 1) {

         patrol[0] = firstCoordArr[0];

        if(ui->radioButton->isChecked()) { // Horizontal
            if(firstCoordArr[0]%10 >=9) {patrol[1] = firstCoordArr[0]-1; } // check if coordinates are possible
            else { patrol[1] = firstCoordArr[0]+1; }

        }
        else {                             // Vertical
           if(firstCoordArr[0] >= 90) {patrol[1] = firstCoordArr[0]-10; }
            else { patrol[1] = firstCoordArr[0]+10; }
        }

        cells[patrol[1]]->setStyleSheet("background-color: black");

        coordTestVec.push_back(patrol[0]);
        coordTestVec.push_back(patrol[1]);

    }

        if(numDrops == 2) {
            destroyer[0] = firstCoordArr[1];
            if(ui->radioButton->isChecked()) { // Horizontal
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
            cells[destroyer[1]]->setStyleSheet("background-color: black");
            cells[destroyer[2]]->setStyleSheet("background-color: black");

            for(int i=0;i<signed(coordTestVec.size());i++) {
                if(coordTestVec[i] == destroyer[0] || coordTestVec[i] == destroyer[1] || coordTestVec[i] == destroyer[2]) {
                 overlap = true;
                }
            }


            coordTestVec.push_back(destroyer[0]);
            coordTestVec.push_back(destroyer[1]);
            coordTestVec.push_back(destroyer[2]);



        }



      if(overlap == false) {

        if(numDrops == 3) {
            submarine[0] = firstCoordArr[2];
            if(ui->radioButton->isChecked()) { // Horizontal
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
            cells[submarine[1]]->setStyleSheet("background-color: black");
            cells[submarine[2]]->setStyleSheet("background-color: black");

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

        if(ui->radioButton->isChecked()) { // Horizontal
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
        cells[battleship[1]]->setStyleSheet("background-color: black");
        cells[battleship[2]]->setStyleSheet("background-color: black");
        cells[battleship[3]]->setStyleSheet("background-color: black");

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

        if(ui->radioButton->isChecked()) { // Horizontal
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

        cells[aircraftCarrier[1]]->setStyleSheet("background-color: black");
        cells[aircraftCarrier[2]]->setStyleSheet("background-color: black");
        cells[aircraftCarrier[3]]->setStyleSheet("background-color: black");
        cells[aircraftCarrier[4]]->setStyleSheet("background-color: black");

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
    }

}

if(overlap == true) {
    ui->label_3->setVisible(true);
    ui->radioButton->setEnabled(false);
    ui->radioButton_2->setEnabled(false);
    for(int i=0;i<100;i++) {
        cells[i]->setEnabled(false);
    }
}
///////////////////////////  <- END FILL SHIP COORDINATE ARRAYS ///////////////////////


    ui->radioButton->setAutoExclusive(false);
    ui->radioButton_2->setAutoExclusive(false);
    ui->radioButton->setChecked(false);
    ui->radioButton_2->setChecked(false);
    ui->radioButton->setAutoExclusive(true);
    ui->radioButton_2->setAutoExclusive(true);

    if(overlap == false) {
         for(int i=0;i<100;i++) {
            cells[i]->setEnabled(true);
        }
    }

    if(numDrops == 1) {
        ui->label_2->setText("Click Destroyer Coordinate (3)");
    }
    else if(numDrops == 2) {
        ui->label_2->setText("Click Submarine Coordinate (3)");
    }
    else if(numDrops == 3) {
        ui->label_2->setText("Click Battleship Coordinate (4)");
    }
    else if(numDrops == 4) {
        ui->label_2->setText("Click Aircraft Carrier Coordinate (5)");
    }
    else if(numDrops == 5) {
        ui->label_2->setText("Ships Have Been Set");
        ui->radioButton->setEnabled(false);
        ui->radioButton_2->setEnabled(false);
        for(int i=0;i<100;i++) {
            cells[i]->setEnabled(false);
        }
    }

    if(numDrops>=5) {
        ui->pushButton->setEnabled(true);
        ui->label->setVisible(true);
    }
ui->pushButton_3->setEnabled(false);

}

void MainWindow::on_radioButton_clicked() {
    ui->pushButton_3->setEnabled(true);
}

void MainWindow::on_radioButton_2_clicked() {
    ui->pushButton_3->setEnabled(true);
}
