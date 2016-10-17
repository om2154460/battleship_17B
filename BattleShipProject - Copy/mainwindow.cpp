#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "onenamedb.h"
#include "twonamesdb.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    if(ui->radioButton->isChecked()) {
        numPlayers = false; // 1 player
        OneNameDB ondb;
        ondb.setModal(true);
        ondb.exec();
        this->close();
    }
    else if(ui->radioButton_2->isChecked()) {
        numPlayers = true; // 2 player
        TwoNamesDB tndb;
        tndb.setModal(true);
        tndb.exec();
        this->close();
    }
    else {
        ui->label_2->setText("<font color = 'red'>You must select a number of players before proceding</font>");
        //"<font color='red'>Some text</font>"
    }
}

bool MainWindow::getNumPlayers() {
   return numPlayers;
}
