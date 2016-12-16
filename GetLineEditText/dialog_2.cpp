#include "dialog_2.h"
#include "ui_dialog_2.h"
#include "dialog_3.h"

Dialog_2::Dialog_2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_2)
{
    ui->setupUi(this);

    QWidget::setWindowTitle("Demographics");
    ui->spinBox->setRange(0,10);


    ui->label_4->setText("<font color='red'>response required</font>");
    ui->label_5->setText("<font color='red'>response required</font>");
    ui->label_4->setVisible(false);
    ui->label_5->setVisible(false);
    ui->label_6->setVisible(false);

   // connect(this , SIGNAL(currentIndexChanged(int)),this,SLOT(handleSelectionChanged(int)));

    connect(ui->comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(handleComboBox(int)));
    connect(ui->comboBox_2, SIGNAL(currentIndexChanged(int)), this, SLOT(handleComboBox_1(int)));
    connect(ui->spinBox, SIGNAL(valueChanged(int)), this, SLOT(handleSpinBox(int)));

}

Dialog_2::~Dialog_2() {
    delete ui;
}


void Dialog_2::handleSpinBox(int index) {
    nSiblings = ui->spinBox->value();
   // ui->label_6->setText(QString::number(nSiblings)); // test: works
    //ui->label_6->setVisible(true);
}

void Dialog_2::handleComboBox(int index) {
    ethnicity = ui->comboBox->currentText();
   // ui->label_6->setText(ethnicity); // tests ethnicity qstring: gets filled

                                         }
void Dialog_2::handleComboBox_1(int index) {
  religion = ui->comboBox_2->currentText();
   // ui->label_7->setText(religion);  // tests religion qstring: gets filled
}



void Dialog_2::on_pushButton_clicked() {  // PUT RESPONSES FROM COMBO-BOXES INTO PRIVATE VARIABLES

    if(ethnicity != "" && religion != "") { // DOESNT ADVANCE TO NEXT WINDOW SO QStrings not getting filled!!!!!!!!!!!

        Dialog_3 d3;
        d3.setModal(true);
        d3.exec();
        this->close();
    }
    else  {
        if (ethnicity == "") { ui->label_4->setVisible(true);}
        if (religion == "") { ui->label_5->setVisible(true);}
    }

}
