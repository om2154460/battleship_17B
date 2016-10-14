#include "twonamesdb.h"
#include "ui_twonamesdb.h"
#include "twoplgame.h"

TwoNamesDB::TwoNamesDB(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TwoNamesDB) {
    ui->setupUi(this);
}

TwoNamesDB::~TwoNamesDB() {
    delete ui;
}

void TwoNamesDB::on_pushButton_clicked() {
    TwoPlGame tpg;
     tpg.setModal(true);
     tpg.exec();
     this->close();
}
