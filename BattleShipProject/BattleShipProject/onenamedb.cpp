#include "onenamedb.h"
#include "ui_onenamedb.h"
#include "oneplgame.h"

OneNameDB::OneNameDB(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OneNameDB)
{
    ui->setupUi(this);
}

OneNameDB::~OneNameDB()
{
    delete ui;
}

void OneNameDB::on_pushButton_clicked()
{
   OnePlGame opg;
    opg.setModal(true);
    opg.exec();
    this->close();
}
