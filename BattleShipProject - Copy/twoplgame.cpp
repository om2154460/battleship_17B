#include "twoplgame.h"
#include "ui_twoplgame.h"

TwoPlGame::TwoPlGame(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TwoPlGame)
{
    ui->setupUi(this);
}

TwoPlGame::~TwoPlGame()
{
    delete ui;
}
