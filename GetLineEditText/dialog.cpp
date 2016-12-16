#include "dialog.h"
#include "ui_dialog.h"
#include "dialog_2.h"
#include <mainwindow.h>


Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    QWidget::setWindowTitle("Study Habbits");

    ui->spinBox_2->setRange(1,10);
    ui->spinBox_3->setRange(0,100);
    ui->horizontalSlider_2->setRange(0,100);

    ui->label_7->setText("<font color='red'>hours is not a realistic amount of time to spend on college courses</font> ");
    ui->label_8->setText("<font color='red'>more units required to be candidate for this survey</font>");
    ui->label_10->setText("<font color='red'>GPD entry required</font>");

    ui->label_4->setVisible(false);
    ui->label_5->setVisible(false);
    ui->label_6->setVisible(false);
    ui->label_7->setVisible(false);
    ui->label_8->setVisible(false);
    ui->label_10->setVisible(false);

    ui->horizontalSlider->setRange(1,25);
    ui->spinBox->setRange(1,25);

  connect(ui->spinBox, SIGNAL(valueChanged(int)),
          ui->horizontalSlider, SLOT(setValue(int)));

  connect(ui->horizontalSlider, SIGNAL(valueChanged(int)),
          ui->spinBox, SLOT(setValue(int)));

  connect(ui->spinBox_3, SIGNAL(valueChanged(int)),
          ui->horizontalSlider_2, SLOT(setValue(int)));

  connect(ui->horizontalSlider_2, SIGNAL(valueChanged(int)),
          ui->spinBox_3, SLOT(setValue(int)));


  connect(ui->spinBox, SIGNAL(valueChanged(int)), this, SLOT(handleSpinBox(int)));
  connect(ui->spinBox_2, SIGNAL(valueChanged(int)), this, SLOT(handleSpinBox_2(int)));
  connect(ui->spinBox_3, SIGNAL(valueChanged(int)), this, SLOT(handleSpinBox_3(int)));
  connect(ui->lineEdit, SIGNAL(textChanged(const QString &)), this, SLOT(handleLineEdit(QString)));




}

Dialog::~Dialog() {
    delete ui;
}

void Dialog::handleLineEdit(QString str) {
   GPA = ui->lineEdit->text().toFloat();
  // ui->label_10->setText(QString::number(GPA)); // test purposes only
  // ui->label_10->setVisible(true); // // test purposes only
}


void Dialog::handleSpinBox(int i) { //
    if(ui->spinBox->value() >= ui->horizontalSlider->value()) {
    units = ui->spinBox->value();
   // ui->label_6->setText(QString::number(units)); // test purposes only
   // ui->label_6->setVisible(true); // test purposes only
    }
    else {
        units = ui->horizontalSlider->value();
       // ui->label_6->setText(QString::number(units)); // test purposes only
       // ui->label_6->setVisible(true); // test purposes only
    }
}

void Dialog::handleSpinBox_2(int i) {
    year = ui->spinBox_2->value();
   // ui->label_5->setText(QString::number(year)); // test purposes only
   // ui->label_5->setVisible(true); // test purposes only
}

void Dialog::handleSpinBox_3(int i) { //
    if(ui->spinBox_3->value() >= ui->horizontalSlider_2->value()) {
    hours = ui->spinBox_3->value();
   // ui->label_4->setText(QString::number(hours)); // test purposes only
   //ui->label_4->setVisible(true); // test purposes only
    }
    else {
        hours = ui->horizontalSlider_2->value();
       // ui->label_4->setText(QString::number(hours)); // test purposes only
       //ui->label_4->setVisible(true); // test purposes only
    }
}



void Dialog::on_pushButton_clicked() {

    if(hours != 0 && units != 1 && GPA != 0.00) {

        Dialog_2 d2;
           d2.setModal(true);
           d2.exec();
           this->close();
    }
    else  {
        if (hours == 0) { ui->label_7->setVisible(true);}
        if (units == 1) { ui->label_8->setVisible(true);}
        if (GPA == 0.00) {ui->label_10->setVisible(true);}
    }

}
