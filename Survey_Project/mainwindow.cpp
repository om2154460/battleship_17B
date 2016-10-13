#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialognames.h"
#include "dialog.h"

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

void MainWindow::on_pushButton_clicked()
{
    if(ui->radioButton->isChecked()) {

    Dialog d;
    d.setModal(true);
    d.exec();
    this->close();
    }
    else if(ui->radioButton_2->isChecked()) {

     DialogNames dn;
     dn.setModal(true);
     dn.exec();
    this->close();
    }
    else {
this->close();
    }

}
