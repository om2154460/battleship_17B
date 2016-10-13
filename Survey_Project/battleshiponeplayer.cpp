#include "battleshiponeplayer.h"
#include "ui_battleshiponeplayer.h"

BattleShipOnePlayer::BattleShipOnePlayer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BattleShipOnePlayer)
{
    ui->setupUi(this);
}

BattleShipOnePlayer::~BattleShipOnePlayer()
{
    delete ui;
}
