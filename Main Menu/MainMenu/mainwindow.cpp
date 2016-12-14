#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "instructions.h"
#include <QtGui>

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

void MainWindow::on_actionInstructions_triggered()
{
    i = new instructions(this);
    i->resize(2000,1500);
    i->show();

}


