#include "logmenu.h"
#include "ui_logmenu.h"
#include <QMessageBox>
#include <QString>
#include <QPixmap>
#include <QPalette>
#include "mainwindow.h"

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
    MainWindow mw;
    mw.setModal(true);
    mw.exec();
    mw.show();
    this->close();
}

/*void logmenu::on_enter_clicked()
{
    QString username = ui->logmenu_userline->text();
    QString password = ui->logmenu_passline->text();

    if(username == "test" && password == "test")
    {
        QMessageBox::information(this, "Login", "Username and password is correct");
    }
        else
    {
        QMessageBox::warning(this, "Login", "Login is incorrect");
    }

}
*/
