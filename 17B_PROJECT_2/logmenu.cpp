#include "mainwindow.h"
#include "logmenu.h"
#include "ui_logmenu.h"
#include <QMessageBox>
#include <QString>
#include <QPixmap>
#include <QPalette>
#include "database.h"

logmenu::logmenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::logmenu)
{

    ui->setupUi(this);

    QPixmap bkgnd("C:/BattleShip_Pictures/battleship.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

    //ui->enter->
}

logmenu::~logmenu()
{
    delete ui;
}

void logmenu::on_quit_clicked()
{
    reject();
    //delete ui;
}

void logmenu::on_enter_clicked()
{
    QString username;
    QString password;
    username = ui->userline->text();
    password = ui->passline->text();

    this->userName = username;
    this->password = password;

    /*if(username == "test" && password == "test")
    {
        QMessageBox::information(this, "Login", "Username and password is correct");
    }
        else
    {
        QMessageBox::warning(this, "Login", "Login is incorrect");
    }*/


    accept();
    //this->close();

}

void logmenu::setUser(QString user){
    this->userName = user;
}

void logmenu::setPass(QString pass){
    this->password = pass;
}


