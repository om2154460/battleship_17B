#include "dialog_3.h"
#include "ui_dialog_3.h"

Dialog_3::Dialog_3(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_3)
{
    ui->setupUi(this);

    ui->horizontalSlider->setVisible(false);
    ui->label_2->setVisible(false);
    ui->spinBox->setVisible(false);

    ui->label_4->setVisible(false);
    ui->label_5->setVisible(false);
    ui->label_6->setVisible(false);
    ui->label_7->setVisible(false);
    ui->label_8->setVisible(false);
    ui->label_9->setVisible(false);

    QWidget::setWindowTitle("Miscellaneous Factors");

    ui->horizontalSlider->setRange(0,30);
    ui->spinBox->setRange(1,30);
    ui->spinBox_2->setRange(3,12);



    connect(ui->spinBox, SIGNAL(valueChanged(int)),
            ui->horizontalSlider, SLOT(setValue(int)));

    connect(ui->horizontalSlider, SIGNAL(valueChanged(int)),
            ui->spinBox, SLOT(setValue(int)));

    connect(ui->checkBox_2, SIGNAL(clicked(bool)),
            ui->horizontalSlider, SLOT(setVisible(bool)));

    connect(ui->checkBox_2, SIGNAL(clicked(bool)),
            ui->label_2, SLOT(setVisible(bool)));

    connect(ui->checkBox_2, SIGNAL(clicked(bool)),
            ui->spinBox, SLOT(setVisible(bool)));

     // setting boolean variables
    connect(ui->checkBox, SIGNAL(clicked(bool)),
            this, SLOT(handleCB1(bool)));

    connect(ui->checkBox_2, SIGNAL(clicked(bool)),
            this, SLOT(handleCB2(bool)));

    connect(ui->checkBox_3, SIGNAL(clicked(bool)),
            this, SLOT(handleCB3(bool)));

    connect(ui->checkBox_4, SIGNAL(clicked(bool)),
            this, SLOT(handleCB4(bool)));

// spinboxes: marijuana and hours of sleep
    connect(ui->spinBox, SIGNAL(valueChanged(int)), this, SLOT(handleSpinBox(int)));
    connect(ui->spinBox_2, SIGNAL(valueChanged(int)), this, SLOT(handleSpinBox_2(int)));

}

void Dialog_3::handleCB1(bool tf) { // home
    if(ui->checkBox->checkState() == Qt::Checked) {
       liveAtHome = true;
    }
    else {
       liveAtHome = false;
    }
    int temp;
    if(liveAtHome == true) {temp = 1;}
    if(liveAtHome == false) {temp = 0;}
   // ui->label_4->setText(QString::number(temp)); // test purposes only
   // ui->label_4->setVisible(true);
}

void Dialog_3::handleCB2(bool tf) { // smoke
    if(ui->checkBox_2->checkState() == Qt::Checked) {
        marijuana = true;
    }
    else {
        marijuana = false;
    }
    int temp=0;
    if(marijuana == true) {temp = 1;}
    if(marijuana == false) {temp = 0;}

    //ui->label_5->setText(QString::number(temp)); // test purposes only
    //ui->label_5->setVisible(true);
}

void Dialog_3::handleCB3(bool tf) { // pet
    if(ui->checkBox_3->checkState() == Qt::Checked) {
    pets = true;
    }
    else {
        pets = false;
    }
    int temp=0;
    if(pets == true) {temp = 1;}
    if(pets == false) {temp = 0;}
   // ui->label_6->setText(QString::number(temp)); // test purposes only
   // ui->label_6->setVisible(true);
}

void Dialog_3::handleCB4(bool tf) { // music

    if(ui->checkBox_4->checkState() == Qt::Checked) {
    music = true;
    }
    else {
        music = false;
    }
    int temp=0;
    if(music == true) {temp = 1;}
    if(music == false) {temp = 0;}
   // ui->label_7->setText(QString::number(temp)); // test purposes only
    //ui->label_7->setVisible(true);
}

 void Dialog_3::handleSpinBox_2(int i) { // hrsSleep
      hrsSleep = ui->spinBox_2->value();
       //ui->label_8->setText(QString::number(hrsSleep)); // test purposes only
       //ui->label_8->setVisible(true);
 }

 void Dialog_3::handleSpinBox(int i) { // marijuana
      nUses = ui->spinBox->value();
      // ui->label_9->setText(QString::number(nUses)); // test purposes only
      // ui->label_9->setVisible(true);
 }


Dialog_3::~Dialog_3() {
    delete ui;
}

void Dialog_3::on_pushButton_clicked() {
    this->close();
}
