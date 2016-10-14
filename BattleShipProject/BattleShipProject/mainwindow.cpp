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

    OneNameDB ondb;
    ondb.setModal(true);
    ondb.exec();
    this->close();
    }
    else if(ui->radioButton_2->isChecked()) {

     TwoNamesDB tndb;
     tndb.setModal(true);
     tndb.exec();
    this->close();
    }
}
