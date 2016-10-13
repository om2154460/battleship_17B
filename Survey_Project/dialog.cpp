#include "dialog.h"
#include "ui_dialog.h"
#include "battleshiponeplayer.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    BattleShipOnePlayer b1;
    b1.setModal(true);
    b1.exec();
   this->close();
}
