#include "cell.h"
#include "ui_cell.h"

Cell::Cell(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Cell)
{
    ui->setupUi(this);


    ui->gridLayout->setHorizontalSpacing(0);
    ui->gridLayout->setVerticalSpacing(0);

    Square *s;
s = new Square[100];



int index=0;

    for(int col=0;col<10;col++) {
        for(int row=0;row<10;row++) {
            index = (row*10)+col;
            //cells[index] = new QPushButton; // (index2Cell(index))

            ui->gridLayout->addWidget(s[index].button,row,col);

            //connect(cells[index],SIGNAL(clicked(bool)),this,SLOT(handleCell(&cells[index])));
           // connect(s[index], SIGNAL (clicked()), this, SLOT (handleButton(int)));
        }
    }
     /*  if we did it this way, we would have the objects in an array,      */



    /*int index=0;

    for(int col=0;col<10;col++) {
        for(int row=0;row<10;row++) {
            index = (row*10)+col;
            cells[index] = new QPushButton; // (index2Cell(index))
            ui->gridLayout->addWidget(cells[(row*10)+col],row,col);
          //setCellIndex(index);
            //connect(cells[index],SIGNAL(clicked(bool)),this,SLOT(handleCell(&cells[index])));
            connect(cells[index], SIGNAL (clicked()), this, SLOT (handleButton(int)));
        }
    }*/





}

Cell::~Cell()
{
    delete ui;
}
