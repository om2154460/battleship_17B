#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include <QRegExp>
#include <QValidator>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QWidget::setWindowTitle("Accademic Success Survey");

    ui->label_3->setText("<font color='red'>Date format invalid</font>");
    ui->label_4->setText("<font color='red'>Name field required</font>");
    ui->label_5->setText("<font color='red'>Date field required</font>");

    ui->label_3->setVisible(false);
    ui->label_4->setVisible(false);
    ui->label_5->setVisible(false);

    connect(ui->lineEdit, SIGNAL(textChanged(const QString &)), this, SLOT(handleLineEdit(QString)));
    connect(ui->lineEdit_2, SIGNAL(textChanged(const QString &)), this, SLOT(handleLineEdit_1(QString)));
}


void MainWindow::handleLineEdit(QString str) {
    name = ui->lineEdit->text();
}

void MainWindow::handleLineEdit_1(QString str) {

     dob = ui->lineEdit_2->text();
}



MainWindow::~MainWindow() {
    delete ui;
}



void MainWindow::on_pushButton_clicked() {

    QRegExp rx("^[0-9]{2}-[0-9]{2}-[0-9]{4}$");
    bool temp;
    temp = rx.exactMatch(dob);


        if(name != "" && dob != "" && temp == true) {
            Dialog d;
            d.setModal(true);
            d.exec();
            this->close();
        }
        else  {
            if(temp == false) {ui->label_3->setVisible(true);}
            if (name == "") { ui->label_4->setVisible(true);}
            if (dob == "") { ui->label_5->setVisible(true);}
        }


}
