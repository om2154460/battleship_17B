#include "logmenu.h"
#include "ui_logmenu.h"
#include <QMessageBox>
#include <QString>
#include <QPixmap>
#include <QPalette>

logmenu::logmenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::logmenu)
{

    ui->setupUi(this);

    QPixmap bkgnd("C:/Users/Jose/Documents/BattleshipGUI/battleship2.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}

logmenu::~logmenu()
{
    delete ui;
}

void logmenu::on_quit_clicked()
{

    delete ui;
}

void logmenu::on_enter_clicked()
{
    QString userline = ui->userline->text();
    QString passline = ui->passline->text();

    if(userline == "test" && passline == "test")
    {
        QMessageBox::information(this, "Login", "Username and password is correct");
    }
        else
    {
        QMessageBox::warning(this, "Login", "Login is incorrect");
    }

}


