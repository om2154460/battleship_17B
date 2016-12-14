#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStyle>
#include <QPixmap>
#include <QButtonGroup>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {

    ui->setupUi(this);
    this->setWindowTitle("Scramble Your Fleet");

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
            cells[index]->setObjectName("p" + QString::number(index));
            ui->gridLayout->addWidget(cells[(row*10)+col],row,col);
            QObject::connect(cells[index],SIGNAL(released()),this,SLOT(handleButton()));
        }
    }

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

void MainWindow::on_pushButton_clicked() {
    qDebug() << firstCoordArr[0] << " "  << firstCoordArr[1] << " "  << firstCoordArr[2] << " "  << firstCoordArr[3] << " " << firstCoordArr[4];
    qDebug() << patrol[0] << " " << patrol[1];
    qDebug() << destroyer[0] << " " << destroyer[1] << " " << destroyer[2];
    qDebug() << submarine[0] << " " << submarine[1] << " " << submarine[2];
    qDebug() << battleship[0] << " " << battleship[1] << " " << battleship[2] << " " << battleship[3];
    qDebug() << aircraftCarrier[0] << " " << aircraftCarrier[1] << " " << aircraftCarrier[2] << " " << aircraftCarrier[3] << " " << aircraftCarrier[4];



    //this->close(); // will open game window later
}

void MainWindow::on_pushButton_2_clicked() {
    for(int i=0;i<100;i++) {
        cells[i]->setStyleSheet("");
    }
    numDrops=0;
    ui->label->setVisible(false);
    ui->pushButton->setEnabled(false);
    ui->label_2->setText("Click Your Patrol Boat");
}

void MainWindow::on_pushButton_3_clicked() {



/////////////////////////// FILL SHIP COORDINATE ARRAYS -> ///////////////////////

    if(numDrops == 1) {

         patrol[0] = firstCoordArr[0];

        if(ui->radioButton->isChecked()) { // Horizontal
            /*if() { // check if coordinates are possible

            }*/
            patrol[1] = firstCoordArr[0]+1;
        }
        else {                             // Vertical
            patrol[1] = firstCoordArr[0]+10;
        }

    }
    if(numDrops == 2 || numDrops == 3) {

        if(numDrops == 2) {
        destroyer[0] = firstCoordArr[1];
            if(ui->radioButton->isChecked()) { // Horizontal
                /* if() { // check if coordinates are possible

                }*/
                destroyer[1] = firstCoordArr[1]+1;
                destroyer[2] = firstCoordArr[1]+2;
        }
        else {                             // Vertical
            destroyer[1] = firstCoordArr[1]+10;
            destroyer[2] = firstCoordArr[1]+20;
        }
        }
        if(numDrops == 3) {
            submarine[0] = firstCoordArr[2];
            if(ui->radioButton->isChecked()) { // Horizontal
                /* if() { // check if coordinates are possible

                }*/
                submarine[1] = firstCoordArr[2]+1;
                submarine[2] = firstCoordArr[2]+2;
        }
        else {                             // Vertical
            submarine[1] = firstCoordArr[2]+10;
            submarine[2] = firstCoordArr[2]+20;
        }
        }



    }

    if(numDrops == 4) {

        battleship[0] = firstCoordArr[3];

        if(ui->radioButton->isChecked()) { // Horizontal
           /* if() { // check if coordinates are  possible

            }*/
            battleship[1] = firstCoordArr[3]+1;
            battleship[2] = firstCoordArr[3]+2;
            battleship[3] = firstCoordArr[3]+3;

        }
        else {                             // Vertical
            battleship[1] = firstCoordArr[3]+10;
            battleship[2] = firstCoordArr[3]+20;
            battleship[3] = firstCoordArr[3]+30;
        }


    }
    if(numDrops == 5) {

         aircraftCarrier[0] = firstCoordArr[4];

        if(ui->radioButton->isChecked()) { // Horizontal
           /* if() { // check if coordinates are  possible

            }*/
           aircraftCarrier[1] = firstCoordArr[4]+1;
           aircraftCarrier[2] = firstCoordArr[4]+2;
           aircraftCarrier[3] = firstCoordArr[4]+3;
           aircraftCarrier[4] = firstCoordArr[4]+4;
        }
        else {                             // Vertical
            aircraftCarrier[1] = firstCoordArr[4]+10;
            aircraftCarrier[2] = firstCoordArr[4]+20;
            aircraftCarrier[3] = firstCoordArr[4]+30;
            aircraftCarrier[4] = firstCoordArr[4]+40;
        }


    }
///////////////////////////  <- END FILL SHIP COORDINATE ARRAYS ///////////////////////


    ui->radioButton->setAutoExclusive(false);
    ui->radioButton_2->setAutoExclusive(false);
    ui->radioButton->setChecked(false);
    ui->radioButton_2->setChecked(false);
    ui->radioButton->setAutoExclusive(true);
    ui->radioButton_2->setAutoExclusive(true);

    for(int i=0;i<100;i++) {
        cells[i]->setEnabled(true);
    }

    if(numDrops == 1) {
        ui->label_2->setText("Click Destroyer Coordinate");
    }
    else if(numDrops == 2) {
        ui->label_2->setText("Click Submarine Coordinate");
    }
    else if(numDrops == 3) {
        ui->label_2->setText("Click Battleship Coordinate");
    }
    else if(numDrops == 4) {
        ui->label_2->setText("Click Aircraft Carrier Coordinate");
    }
    else if(numDrops == 5) {
        ui->label_2->setText("Ships Have Been Set");
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
