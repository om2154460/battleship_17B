#include "oneplgame.h"
#include "ui_oneplgame.h"

OnePlGame::OnePlGame(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OnePlGame)
{
    ui->setupUi(this);
}

OnePlGame::~OnePlGame()
{
    delete ui;
}
