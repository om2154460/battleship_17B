#include "instructions.h"
#include "ui_instructions.h"

instructions::instructions(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::instructions)
{
    ui->setupUi(this);
}

instructions::~instructions()
{
    delete ui;
}



void instructions::on_toolButton_clicked()
{
    close();
}
