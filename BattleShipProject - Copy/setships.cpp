#include "setships.h"
#include "ui_setships.h"
#include "mainwindow.h"
#include "twoplgame.h"
#include "oneplgame.h"

SetShips::SetShips(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SetShips)
{
    ui->setupUi(this);
}

SetShips::~SetShips()
{
    delete ui;
}

void SetShips::on_pushButton_clicked() {
    MainWindow w;
   if( !w.getNumPlayers() ) { // CANT FIGURE OUT HOW TO CALL W.GETNUMPLAYERS
      OnePlGame opg;          // need to pass into constructor and stuff
       opg.setModal(true);
       opg.exec();
       this->close();
   }
   else {
       TwoPlGame tpg;
       tpg.setModal(true);
       tpg.exec();
       this->close();
   }
}
