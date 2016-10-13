#include "dialognames.h"
#include "ui_dialognames.h"
#include "dialog2.h"

DialogNames::DialogNames(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogNames)
{
    ui->setupUi(this);
}

DialogNames::~DialogNames()
{
    delete ui;
}

void DialogNames::on_pushButton_clicked()
{
    Dialog2 d2;
    d2.setModal(true);
    d2.exec();
    this->close();
}
