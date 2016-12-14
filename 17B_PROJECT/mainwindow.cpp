#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStyle>
#include <QPixmap>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->gridLayout->setHorizontalSpacing(0);
    ui->gridLayout->setVerticalSpacing(0);

ui->label->setStyleSheet("font-weight: bold");
ui->label->setText("Click Patrol Boat Coordinate");

QPixmap pix("C:/Users/User/17B_PROJECT/checkmark.jpg"); // NOT WORKING ******************
ui->label_3->setPixmap(pix);
ui->label_3->setScaledContents(true);
ui->label_3->setVisible(false);

    numDrops=0;
    ui->pushButton_101->setEnabled(false);

    cellArr[0] =ui->pushButton;
    cellArr[1] =ui->pushButton_2;
    cellArr[2] =ui->pushButton_3;
    cellArr[3] =ui->pushButton_4;
    cellArr[4] =ui->pushButton_5;
    cellArr[5] =ui->pushButton_6;
    cellArr[6] =ui->pushButton_7;
    cellArr[7] =ui->pushButton_8;
    cellArr[8] =ui->pushButton_9;
    cellArr[9] =ui->pushButton_10;
    cellArr[10] =ui->pushButton_11;
    cellArr[11] =ui->pushButton_12;
    cellArr[12] =ui->pushButton_13;
    cellArr[13] =ui->pushButton_14;
    cellArr[14] =ui->pushButton_15;
    cellArr[15] =ui->pushButton_16;
    cellArr[16] =ui->pushButton_17;
    cellArr[17] =ui->pushButton_18;
    cellArr[18] =ui->pushButton_19;
    cellArr[19] =ui->pushButton_20;
    cellArr[20] =ui->pushButton_21;
    cellArr[21] =ui->pushButton_22;
    cellArr[22] =ui->pushButton_23;
    cellArr[23] =ui->pushButton_24;
    cellArr[24] =ui->pushButton_25;
    cellArr[25] =ui->pushButton_26;
    cellArr[26] =ui->pushButton_27;
    cellArr[27] =ui->pushButton_28;
    cellArr[28] =ui->pushButton_29;
    cellArr[29] =ui->pushButton_30;
    cellArr[30] =ui->pushButton_31;
    cellArr[31] =ui->pushButton_32;
    cellArr[32] =ui->pushButton_33;
    cellArr[33] =ui->pushButton_34;
    cellArr[34] =ui->pushButton_35;
    cellArr[35] =ui->pushButton_36;
    cellArr[36] =ui->pushButton_37;
    cellArr[37] =ui->pushButton_38;
    cellArr[38] =ui->pushButton_39;
    cellArr[39] =ui->pushButton_40;
    cellArr[40] =ui->pushButton_41;
    cellArr[41] =ui->pushButton_42;
    cellArr[42] =ui->pushButton_43;
    cellArr[43] =ui->pushButton_44;
    cellArr[44] =ui->pushButton_45;
    cellArr[45] =ui->pushButton_46;
    cellArr[46] =ui->pushButton_47;
    cellArr[47] =ui->pushButton_48;
    cellArr[48] =ui->pushButton_49;
    cellArr[49] =ui->pushButton_50;
    cellArr[50] =ui->pushButton_51;
    cellArr[51] =ui->pushButton_52;
    cellArr[52] =ui->pushButton_53;
    cellArr[53] =ui->pushButton_54;
    cellArr[54] =ui->pushButton_55;
    cellArr[55] =ui->pushButton_56;
    cellArr[56] =ui->pushButton_57;
    cellArr[57] =ui->pushButton_58;
    cellArr[58] =ui->pushButton_59;
    cellArr[59] =ui->pushButton_60;
    cellArr[60] =ui->pushButton_61;
    cellArr[61] =ui->pushButton_62;
    cellArr[62] =ui->pushButton_63;
    cellArr[63] =ui->pushButton_64;
    cellArr[64] =ui->pushButton_65;
    cellArr[65] =ui->pushButton_66;
    cellArr[66] =ui->pushButton_67;
    cellArr[67] =ui->pushButton_68;
    cellArr[68] =ui->pushButton_69;
    cellArr[69] =ui->pushButton_70;
    cellArr[70] =ui->pushButton_71;
    cellArr[71] =ui->pushButton_72;
    cellArr[72] =ui->pushButton_73;
    cellArr[73] =ui->pushButton_74;
    cellArr[74] =ui->pushButton_75;
    cellArr[75] =ui->pushButton_76;
    cellArr[76] =ui->pushButton_77;
    cellArr[77] =ui->pushButton_78;
    cellArr[78] =ui->pushButton_79;
    cellArr[79] =ui->pushButton_80;
    cellArr[80] =ui->pushButton_81;
    cellArr[81] =ui->pushButton_82;
    cellArr[82] =ui->pushButton_83;
    cellArr[83] =ui->pushButton_84;
    cellArr[84] =ui->pushButton_85;
    cellArr[85] =ui->pushButton_86;
    cellArr[86] =ui->pushButton_87;
    cellArr[87] =ui->pushButton_88;
    cellArr[88] =ui->pushButton_89;
    cellArr[89] =ui->pushButton_90;
    cellArr[90] =ui->pushButton_91;
    cellArr[91] =ui->pushButton_92;
    cellArr[92] =ui->pushButton_93;
    cellArr[93] =ui->pushButton_94;
    cellArr[94] =ui->pushButton_95;
    cellArr[95] =ui->pushButton_96;
    cellArr[96] =ui->pushButton_97;
    cellArr[97] =ui->pushButton_98;
    cellArr[98] =ui->pushButton_99;
    cellArr[99] =ui->pushButton_100;


   // connect()

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked() {
    ui->pushButton->setStyleSheet("background-color: black");
    numDrops++;
   /* int temp=0;
    for(int i=0;i<100;i++) {
        if() {}
    }*/

    if(numDrops == 1) {
        ui->label->setText("Click Destroyer Coordinate");
        firstCoordArr[0] = 0;
    }
    else if(numDrops == 2) {
        ui->label->setText("Click Submarine Coordinate");
         firstCoordArr[2] = 0;
    }
    else if(numDrops == 3) {
        ui->label->setText("Click Battleship Coordinate");
         firstCoordArr[3] = 0;
    }
    else if(numDrops == 4) {
        ui->label->setText("Click Aircraft Carrier Coordinate");
         firstCoordArr[4] = 0;
    }
    else {ui->label_3->setVisible(true);
        ui->pushButton_101->setEnabled(true);}

}

void MainWindow::on_pushButton_2_clicked() {
    ui->pushButton_2->setStyleSheet("background-color: black");
    numDrops++;
    if(numDrops == 1) {
        ui->label->setText("Click Destroyer Coordinate");
        firstCoordArr[0] = 1;
    }
    else if(numDrops == 2) {
        ui->label->setText("Click Submarine Coordinate");
         firstCoordArr[2] = 1;
    }
    else if(numDrops == 3) {
        ui->label->setText("Click Battleship Coordinate");
         firstCoordArr[3] = 1;
    }
    else if(numDrops == 4) {
        ui->label->setText("Click Aircraft Carrier Coordinate");
         firstCoordArr[4] = 1;
    }
    else {ui->label_3->setVisible(true);
        ui->pushButton_101->setEnabled(true);}

}

void MainWindow::on_pushButton_3_clicked() {
    ui->pushButton_3->setStyleSheet("background-color: black");
    numDrops++;
    if(numDrops == 1) {
        ui->label->setText("Click Destroyer Coordinate");
        firstCoordArr[0] = 2;
    }
    else if(numDrops == 2) {
        ui->label->setText("Click Submarine Coordinate");
         firstCoordArr[2] = 2;
    }
    else if(numDrops == 3) {
        ui->label->setText("Click Battleship Coordinate");
         firstCoordArr[3] = 2;
    }
    else if(numDrops == 4) {
        ui->label->setText("Click Aircraft Carrier Coordinate");
         firstCoordArr[4] = 2;
    }
    else {ui->label_3->setVisible(true);
        ui->pushButton_101->setEnabled(true);}

}

void MainWindow::on_pushButton_4_clicked() {
    ui->pushButton_4->setStyleSheet("background-color: black");
    numDrops++;
    if(numDrops == 1) {
        ui->label->setText("Click Destroyer Coordinate");
        firstCoordArr[0] = 3;
    }
    else if(numDrops == 2) {
        ui->label->setText("Click Submarine Coordinate");
         firstCoordArr[2] = 3;
    }
    else if(numDrops == 3) {
        ui->label->setText("Click Battleship Coordinate");
         firstCoordArr[3] = 3;
    }
    else if(numDrops == 4) {
        ui->label->setText("Click Aircraft Carrier Coordinate");
         firstCoordArr[4] = 3;
    }
    else {ui->label_3->setVisible(true);
        ui->pushButton_101->setEnabled(true);}

}

void MainWindow::on_pushButton_5_clicked() {
    ui->pushButton_5->setStyleSheet("background-color: black");
    numDrops++;
    if(numDrops == 1) {
        ui->label->setText("Click Destroyer Coordinate");
        firstCoordArr[0] = 4;
    }
    else if(numDrops == 2) {
        ui->label->setText("Click Submarine Coordinate");
         firstCoordArr[2] = 4;
    }
    else if(numDrops == 3) {
        ui->label->setText("Click Battleship Coordinate");
         firstCoordArr[3] = 4;
    }
    else if(numDrops == 4) {
        ui->label->setText("Click Aircraft Carrier Coordinate");
         firstCoordArr[4] = 4;
    }
    else {ui->label_3->setVisible(true);
        ui->pushButton_101->setEnabled(true);}

}

void MainWindow::on_pushButton_6_clicked() {
    ui->pushButton_6->setStyleSheet("background-color: black");
    numDrops++;
    if(numDrops == 1) {
        ui->label->setText("Click Destroyer Coordinate");
        firstCoordArr[0] = 5;
    }
    else if(numDrops == 2) {
        ui->label->setText("Click Submarine Coordinate");
         firstCoordArr[2] = 5;
    }
    else if(numDrops == 3) {
        ui->label->setText("Click Battleship Coordinate");
         firstCoordArr[3] = 5;
    }
    else if(numDrops == 4) {
        ui->label->setText("Click Aircraft Carrier Coordinate");
         firstCoordArr[4] = 5;
    }
    else {ui->label_3->setVisible(true);
        ui->pushButton_101->setEnabled(true);}

}

void MainWindow::on_pushButton_7_clicked() {
    ui->pushButton_7->setStyleSheet("background-color: black");
    numDrops++;
    if(numDrops == 1) {
        ui->label->setText("Click Destroyer Coordinate");
        firstCoordArr[0] = 6;
    }
    else if(numDrops == 2) {
        ui->label->setText("Click Submarine Coordinate");
         firstCoordArr[2] = 6;
    }
    else if(numDrops == 3) {
        ui->label->setText("Click Battleship Coordinate");
         firstCoordArr[3] = 6;
    }
    else if(numDrops == 4) {
        ui->label->setText("Click Aircraft Carrier Coordinate");
         firstCoordArr[4] = 6;
    }
    else {ui->label_3->setVisible(true);
        ui->pushButton_101->setEnabled(true);}

}

void MainWindow::on_pushButton_8_clicked() {
    ui->pushButton_8->setStyleSheet("background-color: black");
    numDrops++;
    if(numDrops == 1) {
        ui->label->setText("Click Destroyer Coordinate");
        firstCoordArr[0] = 7;
    }
    else if(numDrops == 2) {
        ui->label->setText("Click Submarine Coordinate");
         firstCoordArr[2] = 7;
    }
    else if(numDrops == 3) {
        ui->label->setText("Click Battleship Coordinate");
         firstCoordArr[3] = 7;
    }
    else if(numDrops == 4) {
        ui->label->setText("Click Aircraft Carrier Coordinate");
         firstCoordArr[4] = 7;
    }
    else {ui->label_3->setVisible(true);
        ui->pushButton_101->setEnabled(true);}

}

void MainWindow::on_pushButton_9_clicked() {
    ui->pushButton_9->setStyleSheet("background-color: black");
    numDrops++;
    if(numDrops == 1) {
        ui->label->setText("Click Destroyer Coordinate");
        firstCoordArr[0] = 8;
    }
    else if(numDrops == 2) {
        ui->label->setText("Click Submarine Coordinate");
         firstCoordArr[2] = 8;
    }
    else if(numDrops == 3) {
        ui->label->setText("Click Battleship Coordinate");
         firstCoordArr[3] = 8;
    }
    else if(numDrops == 4) {
        ui->label->setText("Click Aircraft Carrier Coordinate");
         firstCoordArr[4] = 8;
    }
    else {ui->label_3->setVisible(true);
        ui->pushButton_101->setEnabled(true);}

}

void MainWindow::on_pushButton_10_clicked() {
    ui->pushButton_10->setStyleSheet("background-color: black");
    numDrops++;
    if(numDrops == 1) {
        ui->label->setText("Click Destroyer Coordinate");
        firstCoordArr[0] = 9;
    }
    else if(numDrops == 2) {
        ui->label->setText("Click Submarine Coordinate");
         firstCoordArr[2] = 9;
    }
    else if(numDrops == 3) {
        ui->label->setText("Click Battleship Coordinate");
         firstCoordArr[3] = 9;
    }
    else if(numDrops == 4) {
        ui->label->setText("Click Aircraft Carrier Coordinate");
         firstCoordArr[4] = 9;
    }
    else {ui->label_3->setVisible(true);
        ui->pushButton_101->setEnabled(true);}

}
void MainWindow::on_pushButton_11_clicked() {
    ui->pushButton_11->setStyleSheet("background-color: black");
    numDrops++;
    if(numDrops == 1) {
        ui->label->setText("Click Destroyer Coordinate");
        firstCoordArr[0] = 10;
    }
    else if(numDrops == 2) {
        ui->label->setText("Click Submarine Coordinate");
         firstCoordArr[2] = 10;
    }
    else if(numDrops == 3) {
        ui->label->setText("Click Battleship Coordinate");
         firstCoordArr[3] = 10;
    }
    else if(numDrops == 4) {
        ui->label->setText("Click Aircraft Carrier Coordinate");
         firstCoordArr[4] = 10;
    }
    else {ui->label_3->setVisible(true);
        ui->pushButton_101->setEnabled(true);}
}

void MainWindow::on_pushButton_12_clicked() {
    ui->pushButton_12->setStyleSheet("background-color: black");
    numDrops++;
    if(numDrops == 1) {
        ui->label->setText("Click Destroyer Coordinate");
        firstCoordArr[0] = 11;
    }
    else if(numDrops == 2) {
        ui->label->setText("Click Submarine Coordinate");
         firstCoordArr[2] = 11;
    }
    else if(numDrops == 3) {
        ui->label->setText("Click Battleship Coordinate");
         firstCoordArr[3] = 11;
    }
    else if(numDrops == 4) {
        ui->label->setText("Click Aircraft Carrier Coordinate");
         firstCoordArr[4] = 11;
    }
    else {ui->label_3->setVisible(true);
        ui->pushButton_101->setEnabled(true);}
}

void MainWindow::on_pushButton_13_clicked()
{
    ui->pushButton_13->setStyleSheet("background-color: black");
    numDrops++;
    if(numDrops == 1) {
        ui->label->setText("Click Destroyer Coordinate");
        firstCoordArr[0] = 12;
    }
    else if(numDrops == 2) {
        ui->label->setText("Click Submarine Coordinate");
         firstCoordArr[2] = 12;
    }
    else if(numDrops == 3) {
        ui->label->setText("Click Battleship Coordinate");
         firstCoordArr[3] = 12;
    }
    else if(numDrops == 4) {
        ui->label->setText("Click Aircraft Carrier Coordinate");
         firstCoordArr[4] = 12;
    }
    else {ui->label_3->setVisible(true);
        ui->pushButton_101->setEnabled(true);}
}

void MainWindow::on_pushButton_14_clicked() {
    ui->pushButton_14->setStyleSheet("background-color: black");
    numDrops++;
    if(numDrops == 1) {
        ui->label->setText("Click Destroyer Coordinate");
        firstCoordArr[0] = 13;
    }
    else if(numDrops == 2) {
        ui->label->setText("Click Submarine Coordinate");
         firstCoordArr[2] = 13;
    }
    else if(numDrops == 3) {
        ui->label->setText("Click Battleship Coordinate");
         firstCoordArr[3] = 13;
    }
    else if(numDrops == 4) {
        ui->label->setText("Click Aircraft Carrier Coordinate");
         firstCoordArr[4] = 13;
    }
    else {ui->label_3->setVisible(true);
        ui->pushButton_101->setEnabled(true);}
}

void MainWindow::on_pushButton_15_clicked() {
    ui->pushButton_15->setStyleSheet("background-color: black");
    numDrops++;
    if(numDrops == 1) {
        ui->label->setText("Click Destroyer Coordinate");
        firstCoordArr[0] = 14;
    }
    else if(numDrops == 2) {
        ui->label->setText("Click Submarine Coordinate");
         firstCoordArr[2] = 14;
    }
    else if(numDrops == 3) {
        ui->label->setText("Click Battleship Coordinate");
         firstCoordArr[3] = 14;
    }
    else if(numDrops == 4) {
        ui->label->setText("Click Aircraft Carrier Coordinate");
         firstCoordArr[4] = 14;
    }
    else {ui->label_3->setVisible(true);
        ui->pushButton_101->setEnabled(true);}
}

void MainWindow::on_pushButton_16_clicked() {
    ui->pushButton_16->setStyleSheet("background-color: black");
    numDrops++;
    if(numDrops == 1) {
        ui->label->setText("Click Destroyer Coordinate");
        firstCoordArr[0] = 15;
    }
    else if(numDrops == 2) {
        ui->label->setText("Click Submarine Coordinate");
         firstCoordArr[2] = 15;
    }
    else if(numDrops == 3) {
        ui->label->setText("Click Battleship Coordinate");
         firstCoordArr[3] = 15;
    }
    else if(numDrops == 4) {
        ui->label->setText("Click Aircraft Carrier Coordinate");
         firstCoordArr[4] = 15;
    }
    else {ui->label_3->setVisible(true);
        ui->pushButton_101->setEnabled(true);}
}

void MainWindow::on_pushButton_17_clicked() {
    ui->pushButton_17->setStyleSheet("background-color: black");
    numDrops++;
    if(numDrops == 1) {
        ui->label->setText("Click Destroyer Coordinate");
        firstCoordArr[0] = 16;
    }
    else if(numDrops == 2) {
        ui->label->setText("Click Submarine Coordinate");
         firstCoordArr[2] = 16;
    }
    else if(numDrops == 3) {
        ui->label->setText("Click Battleship Coordinate");
         firstCoordArr[3] = 16;
    }
    else if(numDrops == 4) {
        ui->label->setText("Click Aircraft Carrier Coordinate");
         firstCoordArr[4] = 16;
    }
    else {ui->label_3->setVisible(true);
        ui->pushButton_101->setEnabled(true);}
}

void MainWindow::on_pushButton_18_clicked() {
    ui->pushButton_18->setStyleSheet("background-color: black");
    numDrops++;
    if(numDrops == 1) {
        ui->label->setText("Click Destroyer Coordinate");
        firstCoordArr[0] = 17;
    }
    else if(numDrops == 2) {
        ui->label->setText("Click Submarine Coordinate");
         firstCoordArr[2] = 17;
    }
    else if(numDrops == 3) {
        ui->label->setText("Click Battleship Coordinate");
         firstCoordArr[3] = 17;
    }
    else if(numDrops == 4) {
        ui->label->setText("Click Aircraft Carrier Coordinate");
         firstCoordArr[4] = 17;
    }
    else {ui->label_3->setVisible(true);
        ui->pushButton_101->setEnabled(true);}
}

void MainWindow::on_pushButton_19_clicked() {
    ui->pushButton_19->setStyleSheet("background-color: black");
    numDrops++;
    if(numDrops == 1) {
        ui->label->setText("Click Destroyer Coordinate");
        firstCoordArr[0] = 18;
    }
    else if(numDrops == 2) {
        ui->label->setText("Click Submarine Coordinate");
         firstCoordArr[2] = 18;
    }
    else if(numDrops == 3) {
        ui->label->setText("Click Battleship Coordinate");
         firstCoordArr[3] = 18;
    }
    else if(numDrops == 4) {
        ui->label->setText("Click Aircraft Carrier Coordinate");
         firstCoordArr[4] = 18;
    }
    else {ui->label_3->setVisible(true);
        ui->pushButton_101->setEnabled(true);}
}

void MainWindow::on_pushButton_20_clicked() {
    ui->pushButton_20->setStyleSheet("background-color: black");
    numDrops++;
    if(numDrops == 1) {
        ui->label->setText("Click Destroyer Coordinate");
        firstCoordArr[0] = 19;
    }
    else if(numDrops == 2) {
        ui->label->setText("Click Submarine Coordinate");
         firstCoordArr[2] = 19;
    }
    else if(numDrops == 3) {
        ui->label->setText("Click Battleship Coordinate");
         firstCoordArr[3] = 19;
    }
    else if(numDrops == 4) {
        ui->label->setText("Click Aircraft Carrier Coordinate");
         firstCoordArr[4] = 19;
    }
    else {ui->label_3->setVisible(true);
        ui->pushButton_101->setEnabled(true);}
}
void MainWindow::on_pushButton_21_clicked() {
    ui->pushButton_21->setStyleSheet("background-color: black");
    numDrops++;
    if(numDrops == 1) {
        ui->label->setText("Click Destroyer Coordinate");
        firstCoordArr[0] = 20;
    }
    else if(numDrops == 2) {
        ui->label->setText("Click Submarine Coordinate");
         firstCoordArr[2] = 20;
    }
    else if(numDrops == 3) {
        ui->label->setText("Click Battleship Coordinate");
         firstCoordArr[3] = 20;
    }
    else if(numDrops == 4) {
        ui->label->setText("Click Aircraft Carrier Coordinate");
         firstCoordArr[4] = 20;
    }
    else {ui->label_3->setVisible(true);
        ui->pushButton_101->setEnabled(true);}
}

void MainWindow::on_pushButton_22_clicked() {
    ui->pushButton_22->setStyleSheet("background-color: black");
    numDrops++;
    if(numDrops == 1) {
        ui->label->setText("Click Destroyer Coordinate");
    }
    else if(numDrops == 2) {
        ui->label->setText("Click Submarine Coordinate");
    }
    else if(numDrops == 3) {
        ui->label->setText("Click Battleship Coordinate");
    }
    else if(numDrops == 4) {
        ui->label->setText("Click Aircraft Carrier Coordinate");
    }
    else {ui->label_3->setVisible(true);
        ui->pushButton_101->setEnabled(true);}
}

void MainWindow::on_pushButton_23_clicked() {
    ui->pushButton_23->setStyleSheet("background-color: black");
    numDrops++;
    if(numDrops == 1) {
        ui->label->setText("Click Destroyer Coordinate");
    }
    else if(numDrops == 2) {
        ui->label->setText("Click Submarine Coordinate");
    }
    else if(numDrops == 3) {
        ui->label->setText("Click Battleship Coordinate");
    }
    else if(numDrops == 4) {
        ui->label->setText("Click Aircraft Carrier Coordinate");
    }
    else {ui->label_3->setVisible(true);
        ui->pushButton_101->setEnabled(true);}
}

void MainWindow::on_pushButton_24_clicked() {
    ui->pushButton_24->setStyleSheet("background-color: black");
    numDrops++;
    if(numDrops == 1) {
        ui->label->setText("Click Destroyer Coordinate");
    }
    else if(numDrops == 2) {
        ui->label->setText("Click Submarine Coordinate");
    }
    else if(numDrops == 3) {
        ui->label->setText("Click Battleship Coordinate");
    }
    else if(numDrops == 4) {
        ui->label->setText("Click Aircraft Carrier Coordinate");
    }
    else {ui->label_3->setVisible(true);
        ui->pushButton_101->setEnabled(true);}
}

void MainWindow::on_pushButton_25_clicked() {
    ui->pushButton_25->setStyleSheet("background-color: black");
    numDrops++;
    if(numDrops == 1) {
        ui->label->setText("Click Destroyer Coordinate");
    }
    else if(numDrops == 2) {
        ui->label->setText("Click Submarine Coordinate");
    }
    else if(numDrops == 3) {
        ui->label->setText("Click Battleship Coordinate");
    }
    else if(numDrops == 4) {
        ui->label->setText("Click Aircraft Carrier Coordinate");
    }
    else {ui->label_3->setVisible(true);
        ui->pushButton_101->setEnabled(true);}
}

void MainWindow::on_pushButton_26_clicked() {
    ui->pushButton_26->setStyleSheet("background-color: black");
    numDrops++;
    if(numDrops == 1) {
        ui->label->setText("Click Destroyer Coordinate");
    }
    else if(numDrops == 2) {
        ui->label->setText("Click Submarine Coordinate");
    }
    else if(numDrops == 3) {
        ui->label->setText("Click Battleship Coordinate");
    }
    else if(numDrops == 4) {
        ui->label->setText("Click Aircraft Carrier Coordinate");
    }
    else {ui->label_3->setVisible(true);
        ui->pushButton_101->setEnabled(true);}
}

void MainWindow::on_pushButton_27_clicked() {
    ui->pushButton_27->setStyleSheet("background-color: black");
    numDrops++;
    if(numDrops == 1) {
        ui->label->setText("Click Destroyer Coordinate");
    }
    else if(numDrops == 2) {
        ui->label->setText("Click Submarine Coordinate");
    }
    else if(numDrops == 3) {
        ui->label->setText("Click Battleship Coordinate");
    }
    else if(numDrops == 4) {
        ui->label->setText("Click Aircraft Carrier Coordinate");
    }
    else {ui->label_3->setVisible(true);
        ui->pushButton_101->setEnabled(true);}
}

void MainWindow::on_pushButton_28_clicked() {
    ui->pushButton_28->setStyleSheet("background-color: black");
    numDrops++;
    if(numDrops == 1) {
        ui->label->setText("Click Destroyer Coordinate");
    }
    else if(numDrops == 2) {
        ui->label->setText("Click Submarine Coordinate");
    }
    else if(numDrops == 3) {
        ui->label->setText("Click Battleship Coordinate");
    }
    else if(numDrops == 4) {
        ui->label->setText("Click Aircraft Carrier Coordinate");
    }
    else {ui->label_3->setVisible(true);
        ui->pushButton_101->setEnabled(true);}
}

void MainWindow::on_pushButton_29_clicked() {
    ui->pushButton_29->setStyleSheet("background-color: black");
    numDrops++;
    if(numDrops == 1) {
        ui->label->setText("Click Destroyer Coordinate");
    }
    else if(numDrops == 2) {
        ui->label->setText("Click Submarine Coordinate");
    }
    else if(numDrops == 3) {
        ui->label->setText("Click Battleship Coordinate");
    }
    else if(numDrops == 4) {
        ui->label->setText("Click Aircraft Carrier Coordinate");
    }
    else {ui->label_3->setVisible(true);
        ui->pushButton_101->setEnabled(true);}
}

void MainWindow::on_pushButton_30_clicked() {
    ui->pushButton_30->setStyleSheet("background-color: black");
    numDrops++;
    if(numDrops == 1) {
        ui->label->setText("Click Destroyer Coordinate");
    }
    else if(numDrops == 2) {
        ui->label->setText("Click Submarine Coordinate");
    }
    else if(numDrops == 3) {
        ui->label->setText("Click Battleship Coordinate");
    }
    else if(numDrops == 4) {
        ui->label->setText("Click Aircraft Carrier Coordinate");
    }
    else {ui->label_3->setVisible(true);
        ui->pushButton_101->setEnabled(true);}
}
void MainWindow::on_pushButton_31_clicked() {
    ui->pushButton_31->setStyleSheet("background-color: black");
    numDrops++;
    if(numDrops == 1) {
        ui->label->setText("Click Destroyer Coordinate");
    }
    else if(numDrops == 2) {
        ui->label->setText("Click Submarine Coordinate");
    }
    else if(numDrops == 3) {
        ui->label->setText("Click Battleship Coordinate");
    }
    else if(numDrops == 4) {
        ui->label->setText("Click Aircraft Carrier Coordinate");
    }
    else {ui->label_3->setVisible(true);
        ui->pushButton_101->setEnabled(true);}
}

void MainWindow::on_pushButton_32_clicked() {
    ui->pushButton_32->setStyleSheet("background-color: black");
    numDrops++;
    if(numDrops == 1) {
        ui->label->setText("Click Destroyer Coordinate");
    }
    else if(numDrops == 2) {
        ui->label->setText("Click Submarine Coordinate");
    }
    else if(numDrops == 3) {
        ui->label->setText("Click Battleship Coordinate");
    }
    else if(numDrops == 4) {
        ui->label->setText("Click Aircraft Carrier Coordinate");
    }
    else {ui->label_3->setVisible(true);
        ui->pushButton_101->setEnabled(true);}
}

void MainWindow::on_pushButton_33_clicked() {
    ui->pushButton_33->setStyleSheet("background-color: black");
    numDrops++;
    if(numDrops == 1) {
        ui->label->setText("Click Destroyer Coordinate");
    }
    else if(numDrops == 2) {
        ui->label->setText("Click Submarine Coordinate");
    }
    else if(numDrops == 3) {
        ui->label->setText("Click Battleship Coordinate");
    }
    else if(numDrops == 4) {
        ui->label->setText("Click Aircraft Carrier Coordinate");
    }
    else {ui->label_3->setVisible(true);
        ui->pushButton_101->setEnabled(true);}
}

void MainWindow::on_pushButton_34_clicked() {
    ui->pushButton_34->setStyleSheet("background-color: black");
    numDrops++;
    if(numDrops == 1) {
        ui->label->setText("Click Destroyer Coordinate");
    }
    else if(numDrops == 2) {
        ui->label->setText("Click Submarine Coordinate");
    }
    else if(numDrops == 3) {
        ui->label->setText("Click Battleship Coordinate");
    }
    else if(numDrops == 4) {
        ui->label->setText("Click Aircraft Carrier Coordinate");
    }
    else {ui->label_3->setVisible(true);
        ui->pushButton_101->setEnabled(true);}
}

void MainWindow::on_pushButton_35_clicked() {
    ui->pushButton_35->setStyleSheet("background-color: black");
    numDrops++;
    if(numDrops == 1) {
        ui->label->setText("Click Destroyer Coordinate");
    }
    else if(numDrops == 2) {
        ui->label->setText("Click Submarine Coordinate");
    }
    else if(numDrops == 3) {
        ui->label->setText("Click Battleship Coordinate");
    }
    else if(numDrops == 4) {
        ui->label->setText("Click Aircraft Carrier Coordinate");
    }
    else {ui->label_3->setVisible(true);
        ui->pushButton_101->setEnabled(true);}
}

void MainWindow::on_pushButton_36_clicked() {
    ui->pushButton_36->setStyleSheet("background-color: black");
    numDrops++;
    if(numDrops == 1) {
        ui->label->setText("Click Destroyer Coordinate");
    }
    else if(numDrops == 2) {
        ui->label->setText("Click Submarine Coordinate");
    }
    else if(numDrops == 3) {
        ui->label->setText("Click Battleship Coordinate");
    }
    else if(numDrops == 4) {
        ui->label->setText("Click Aircraft Carrier Coordinate");
    }
    else {ui->label_3->setVisible(true);
        ui->pushButton_101->setEnabled(true);}
}

void MainWindow::on_pushButton_37_clicked() {
    ui->pushButton_37->setStyleSheet("background-color: black");
    numDrops++;
    if(numDrops == 1) {
        ui->label->setText("Click Destroyer Coordinate");
    }
    else if(numDrops == 2) {
        ui->label->setText("Click Submarine Coordinate");
    }
    else if(numDrops == 3) {
        ui->label->setText("Click Battleship Coordinate");
    }
    else if(numDrops == 4) {
        ui->label->setText("Click Aircraft Carrier Coordinate");
    }
    else {ui->label_3->setVisible(true);
        ui->pushButton_101->setEnabled(true);}
}

void MainWindow::on_pushButton_38_clicked() {
    ui->pushButton_38->setStyleSheet("background-color: black");
    numDrops++;
    if(numDrops == 1) {
        ui->label->setText("Click Destroyer Coordinate");
    }
    else if(numDrops == 2) {
        ui->label->setText("Click Submarine Coordinate");
    }
    else if(numDrops == 3) {
        ui->label->setText("Click Battleship Coordinate");
    }
    else if(numDrops == 4) {
        ui->label->setText("Click Aircraft Carrier Coordinate");
    }
    else {ui->label_3->setVisible(true);
        ui->pushButton_101->setEnabled(true);}
}

void MainWindow::on_pushButton_39_clicked() {
    ui->pushButton_39->setStyleSheet("background-color: black");
    numDrops++;
    if(numDrops == 1) {
        ui->label->setText("Click Destroyer Coordinate");
    }
    else if(numDrops == 2) {
        ui->label->setText("Click Submarine Coordinate");
    }
    else if(numDrops == 3) {
        ui->label->setText("Click Battleship Coordinate");
    }
    else if(numDrops == 4) {
        ui->label->setText("Click Aircraft Carrier Coordinate");
    }
    else {ui->label_3->setVisible(true);
        ui->pushButton_101->setEnabled(true);}
}

void MainWindow::on_pushButton_40_clicked() {
    ui->pushButton_40->setStyleSheet("background-color: black");
    numDrops++;
    if(numDrops == 1) {
        ui->label->setText("Click Destroyer Coordinate");
    }
    else if(numDrops == 2) {
        ui->label->setText("Click Submarine Coordinate");
    }
    else if(numDrops == 3) {
        ui->label->setText("Click Battleship Coordinate");
    }
    else if(numDrops == 4) {
        ui->label->setText("Click Aircraft Carrier Coordinate");
    }
    else {ui->label_3->setVisible(true);
        ui->pushButton_101->setEnabled(true);}
}
void MainWindow::on_pushButton_41_clicked() {
    ui->pushButton_41->setStyleSheet("background-color: black");
    numDrops++;
    if(numDrops == 1) {
        ui->label->setText("Click Destroyer Coordinate");
    }
    else if(numDrops == 2) {
        ui->label->setText("Click Submarine Coordinate");
    }
    else if(numDrops == 3) {
        ui->label->setText("Click Battleship Coordinate");
    }
    else if(numDrops == 4) {
        ui->label->setText("Click Aircraft Carrier Coordinate");
    }
    else {ui->label_3->setVisible(true);
        ui->pushButton_101->setEnabled(true);}
}

void MainWindow::on_pushButton_42_clicked() {
    ui->pushButton_42->setStyleSheet("background-color: black");
    numDrops++;
    if(numDrops == 1) {
        ui->label->setText("Click Destroyer Coordinate");
    }
    else if(numDrops == 2) {
        ui->label->setText("Click Submarine Coordinate");
    }
    else if(numDrops == 3) {
        ui->label->setText("Click Battleship Coordinate");
    }
    else if(numDrops == 4) {
        ui->label->setText("Click Aircraft Carrier Coordinate");
    }
    else {ui->label_3->setVisible(true);
        ui->pushButton_101->setEnabled(true);}
}

void MainWindow::on_pushButton_43_clicked() {
    ui->pushButton_43->setStyleSheet("background-color: black");
    numDrops++;
    if(numDrops == 1) {
        ui->label->setText("Click Destroyer Coordinate");
    }
    else if(numDrops == 2) {
        ui->label->setText("Click Submarine Coordinate");
    }
    else if(numDrops == 3) {
        ui->label->setText("Click Battleship Coordinate");
    }
    else if(numDrops == 4) {
        ui->label->setText("Click Aircraft Carrier Coordinate");
    }
    else {ui->label_3->setVisible(true);
        ui->pushButton_101->setEnabled(true);}
}

void MainWindow::on_pushButton_44_clicked() {
    ui->pushButton_44->setStyleSheet("background-color: black");
    numDrops++;
    if(numDrops == 1) {
        ui->label->setText("Click Destroyer Coordinate");
    }
    else if(numDrops == 2) {
        ui->label->setText("Click Submarine Coordinate");
    }
    else if(numDrops == 3) {
        ui->label->setText("Click Battleship Coordinate");
    }
    else if(numDrops == 4) {
        ui->label->setText("Click Aircraft Carrier Coordinate");
    }
    else {ui->label_3->setVisible(true);
        ui->pushButton_101->setEnabled(true);}
}

void MainWindow::on_pushButton_45_clicked() {
    ui->pushButton_45->setStyleSheet("background-color: black");
    numDrops++;
    if(numDrops == 1) {
        ui->label->setText("Click Destroyer Coordinate");
    }
    else if(numDrops == 2) {
        ui->label->setText("Click Submarine Coordinate");
    }
    else if(numDrops == 3) {
        ui->label->setText("Click Battleship Coordinate");
    }
    else if(numDrops == 4) {
        ui->label->setText("Click Aircraft Carrier Coordinate");
    }
    else {ui->label_3->setVisible(true);
        ui->pushButton_101->setEnabled(true);}
}

void MainWindow::on_pushButton_46_clicked() {
    ui->pushButton_46->setStyleSheet("background-color: black");
    numDrops++;
    if(numDrops == 1) {
        ui->label->setText("Click Destroyer Coordinate");
    }
    else if(numDrops == 2) {
        ui->label->setText("Click Submarine Coordinate");
    }
    else if(numDrops == 3) {
        ui->label->setText("Click Battleship Coordinate");
    }
    else if(numDrops == 4) {
        ui->label->setText("Click Aircraft Carrier Coordinate");
    }
    else {ui->label_3->setVisible(true);
        ui->pushButton_101->setEnabled(true);}
}

void MainWindow::on_pushButton_47_clicked() {
    ui->pushButton_47->setStyleSheet("background-color: black");
    numDrops++;
    if(numDrops == 1) {
        ui->label->setText("Click Destroyer Coordinate");
    }
    else if(numDrops == 2) {
        ui->label->setText("Click Submarine Coordinate");
    }
    else if(numDrops == 3) {
        ui->label->setText("Click Battleship Coordinate");
    }
    else if(numDrops == 4) {
        ui->label->setText("Click Aircraft Carrier Coordinate");
    }
    else {ui->label_3->setVisible(true);
        ui->pushButton_101->setEnabled(true);}
}

void MainWindow::on_pushButton_48_clicked() {
    ui->pushButton_48->setStyleSheet("background-color: black");
    numDrops++;
    if(numDrops == 1) {
        ui->label->setText("Click Destroyer Coordinate");
    }
    else if(numDrops == 2) {
        ui->label->setText("Click Submarine Coordinate");
    }
    else if(numDrops == 3) {
        ui->label->setText("Click Battleship Coordinate");
    }
    else if(numDrops == 4) {
        ui->label->setText("Click Aircraft Carrier Coordinate");
    }
    else {ui->label_3->setVisible(true);
        ui->pushButton_101->setEnabled(true);}
}

void MainWindow::on_pushButton_49_clicked() {
    ui->pushButton_49->setStyleSheet("background-color: black");
    numDrops++;
    if(numDrops == 1) {
        ui->label->setText("Click Destroyer Coordinate");
    }
    else if(numDrops == 2) {
        ui->label->setText("Click Submarine Coordinate");
    }
    else if(numDrops == 3) {
        ui->label->setText("Click Battleship Coordinate");
    }
    else if(numDrops == 4) {
        ui->label->setText("Click Aircraft Carrier Coordinate");
    }
    else {ui->label_3->setVisible(true);
        ui->pushButton_101->setEnabled(true);}
}

void MainWindow::on_pushButton_50_clicked() {
    ui->pushButton_50->setStyleSheet("background-color: black");
    numDrops++;
    if(numDrops == 1) {
        ui->label->setText("Click Destroyer Coordinate");
    }
    else if(numDrops == 2) {
        ui->label->setText("Click Submarine Coordinate");
    }
    else if(numDrops == 3) {
        ui->label->setText("Click Battleship Coordinate");
    }
    else if(numDrops == 4) {
        ui->label->setText("Click Aircraft Carrier Coordinate");
    }
    else {ui->label_3->setVisible(true);
        ui->pushButton_101->setEnabled(true);}
}
void MainWindow::on_pushButton_51_clicked() {
    ui->pushButton_51->setStyleSheet("background-color: black");
    numDrops++;
    if(numDrops == 1) {
        ui->label->setText("Click Destroyer Coordinate");
    }
    else if(numDrops == 2) {
        ui->label->setText("Click Submarine Coordinate");
    }
    else if(numDrops == 3) {
        ui->label->setText("Click Battleship Coordinate");
    }
    else if(numDrops == 4) {
        ui->label->setText("Click Aircraft Carrier Coordinate");
    }
    else {ui->label_3->setVisible(true);
        ui->pushButton_101->setEnabled(true);}
}

void MainWindow::on_pushButton_52_clicked() {
    ui->pushButton_52->setStyleSheet("background-color: black");
    numDrops++;
    if(numDrops == 1) {
        ui->label->setText("Click Destroyer Coordinate");
    }
    else if(numDrops == 2) {
        ui->label->setText("Click Submarine Coordinate");
    }
    else if(numDrops == 3) {
        ui->label->setText("Click Battleship Coordinate");
    }
    else if(numDrops == 4) {
        ui->label->setText("Click Aircraft Carrier Coordinate");
    }
    else {ui->label_3->setVisible(true);
        ui->pushButton_101->setEnabled(true);}
}

void MainWindow::on_pushButton_53_clicked() {
    ui->pushButton_53->setStyleSheet("background-color: black");
    numDrops++;
    if(numDrops == 1) {
        ui->label->setText("Click Destroyer Coordinate");
    }
    else if(numDrops == 2) {
        ui->label->setText("Click Submarine Coordinate");
    }
    else if(numDrops == 3) {
        ui->label->setText("Click Battleship Coordinate");
    }
    else if(numDrops == 4) {
        ui->label->setText("Click Aircraft Carrier Coordinate");
    }
    else {ui->label_3->setVisible(true);
        ui->pushButton_101->setEnabled(true);}
}

void MainWindow::on_pushButton_54_clicked() {
    ui->pushButton_54->setStyleSheet("background-color: black");
    numDrops++;
    if(numDrops == 1) {
        ui->label->setText("Click Destroyer Coordinate");
    }
    else if(numDrops == 2) {
        ui->label->setText("Click Submarine Coordinate");
    }
    else if(numDrops == 3) {
        ui->label->setText("Click Battleship Coordinate");
    }
    else if(numDrops == 4) {
        ui->label->setText("Click Aircraft Carrier Coordinate");
    }
    else {ui->label_3->setVisible(true);
        ui->pushButton_101->setEnabled(true);}
}

void MainWindow::on_pushButton_55_clicked() {
    ui->pushButton_55->setStyleSheet("background-color: black");
    numDrops++;
    if(numDrops == 1) {
        ui->label->setText("Click Destroyer Coordinate");
    }
    else if(numDrops == 2) {
        ui->label->setText("Click Submarine Coordinate");
    }
    else if(numDrops == 3) {
        ui->label->setText("Click Battleship Coordinate");
    }
    else if(numDrops == 4) {
        ui->label->setText("Click Aircraft Carrier Coordinate");
    }
    else {ui->label_3->setVisible(true);
        ui->pushButton_101->setEnabled(true);}
}

void MainWindow::on_pushButton_56_clicked() {
    ui->pushButton_56->setStyleSheet("background-color: black");
    numDrops++;
    if(numDrops == 1) {
        ui->label->setText("Click Destroyer Coordinate");
    }
    else if(numDrops == 2) {
        ui->label->setText("Click Submarine Coordinate");
    }
    else if(numDrops == 3) {
        ui->label->setText("Click Battleship Coordinate");
    }
    else if(numDrops == 4) {
        ui->label->setText("Click Aircraft Carrier Coordinate");
    }
    else {ui->label_3->setVisible(true);
        ui->pushButton_101->setEnabled(true);}
}

void MainWindow::on_pushButton_57_clicked() {
    ui->pushButton_57->setStyleSheet("background-color: black");
    numDrops++;
    if(numDrops == 1) {
        ui->label->setText("Click Destroyer Coordinate");
    }
    else if(numDrops == 2) {
        ui->label->setText("Click Submarine Coordinate");
    }
    else if(numDrops == 3) {
        ui->label->setText("Click Battleship Coordinate");
    }
    else if(numDrops == 4) {
        ui->label->setText("Click Aircraft Carrier Coordinate");
    }
    else {ui->label_3->setVisible(true);
        ui->pushButton_101->setEnabled(true);}
}

void MainWindow::on_pushButton_58_clicked() {
    ui->pushButton_58->setStyleSheet("background-color: black");
    numDrops++;
    if(numDrops == 1) {
        ui->label->setText("Click Destroyer Coordinate");
    }
    else if(numDrops == 2) {
        ui->label->setText("Click Submarine Coordinate");
    }
    else if(numDrops == 3) {
        ui->label->setText("Click Battleship Coordinate");
    }
    else if(numDrops == 4) {
        ui->label->setText("Click Aircraft Carrier Coordinate");
    }
    else {ui->label_3->setVisible(true);
        ui->pushButton_101->setEnabled(true);}
}

void MainWindow::on_pushButton_59_clicked() {
    ui->pushButton_59->setStyleSheet("background-color: black");
    numDrops++;
    if(numDrops == 1) {
        ui->label->setText("Click Destroyer Coordinate");
    }
    else if(numDrops == 2) {
        ui->label->setText("Click Submarine Coordinate");
    }
    else if(numDrops == 3) {
        ui->label->setText("Click Battleship Coordinate");
    }
    else if(numDrops == 4) {
        ui->label->setText("Click Aircraft Carrier Coordinate");
    }
    else {ui->label_3->setVisible(true);
        ui->pushButton_101->setEnabled(true);}
}

void MainWindow::on_pushButton_60_clicked() {
    ui->pushButton_60->setStyleSheet("background-color: black");
    numDrops++;
    if(numDrops == 1) {
        ui->label->setText("Click Destroyer Coordinate");
    }
    else if(numDrops == 2) {
        ui->label->setText("Click Submarine Coordinate");
    }
    else if(numDrops == 3) {
        ui->label->setText("Click Battleship Coordinate");
    }
    else if(numDrops == 4) {
        ui->label->setText("Click Aircraft Carrier Coordinate");
    }
    else {ui->label_3->setVisible(true);
        ui->pushButton_101->setEnabled(true);}
}
void MainWindow::on_pushButton_61_clicked() {
    ui->pushButton_61->setStyleSheet("background-color: black");
    numDrops++;
    if(numDrops == 1) {
        ui->label->setText("Click Destroyer Coordinate");
    }
    else if(numDrops == 2) {
        ui->label->setText("Click Submarine Coordinate");
    }
    else if(numDrops == 3) {
        ui->label->setText("Click Battleship Coordinate");
    }
    else if(numDrops == 4) {
        ui->label->setText("Click Aircraft Carrier Coordinate");
    }
    else {ui->label_3->setVisible(true);
        ui->pushButton_101->setEnabled(true);}
}

void MainWindow::on_pushButton_62_clicked() {
    ui->pushButton_62->setStyleSheet("background-color: black");
    numDrops++;
    if(numDrops == 1) {
        ui->label->setText("Click Destroyer Coordinate");
    }
    else if(numDrops == 2) {
        ui->label->setText("Click Submarine Coordinate");
    }
    else if(numDrops == 3) {
        ui->label->setText("Click Battleship Coordinate");
    }
    else if(numDrops == 4) {
        ui->label->setText("Click Aircraft Carrier Coordinate");
    }
    else {ui->label_3->setVisible(true);
        ui->pushButton_101->setEnabled(true);}
}

void MainWindow::on_pushButton_63_clicked() {
    ui->pushButton_63->setStyleSheet("background-color: black");
    numDrops++;
    if(numDrops == 1) {
        ui->label->setText("Click Destroyer Coordinate");
    }
    else if(numDrops == 2) {
        ui->label->setText("Click Submarine Coordinate");
    }
    else if(numDrops == 3) {
        ui->label->setText("Click Battleship Coordinate");
    }
    else if(numDrops == 4) {
        ui->label->setText("Click Aircraft Carrier Coordinate");
    }
    else {ui->label_3->setVisible(true);
        ui->pushButton_101->setEnabled(true);}
}

void MainWindow::on_pushButton_64_clicked() {
    ui->pushButton_64->setStyleSheet("background-color: black");
    numDrops++;
    if(numDrops == 1) {
        ui->label->setText("Click Destroyer Coordinate");
    }
    else if(numDrops == 2) {
        ui->label->setText("Click Submarine Coordinate");
    }
    else if(numDrops == 3) {
        ui->label->setText("Click Battleship Coordinate");
    }
    else if(numDrops == 4) {
        ui->label->setText("Click Aircraft Carrier Coordinate");
    }
    else {ui->label_3->setVisible(true);
        ui->pushButton_101->setEnabled(true);}
}

void MainWindow::on_pushButton_65_clicked() {
    ui->pushButton_65->setStyleSheet("background-color: black");
    numDrops++;
    if(numDrops == 1) {
        ui->label->setText("Click Destroyer Coordinate");
    }
    else if(numDrops == 2) {
        ui->label->setText("Click Submarine Coordinate");
    }
    else if(numDrops == 3) {
        ui->label->setText("Click Battleship Coordinate");
    }
    else if(numDrops == 4) {
        ui->label->setText("Click Aircraft Carrier Coordinate");
    }
    else {ui->label_3->setVisible(true);
        ui->pushButton_101->setEnabled(true);}
}

void MainWindow::on_pushButton_66_clicked() {
    ui->pushButton_66->setStyleSheet("background-color: black");
    numDrops++;
    if(numDrops == 1) {
        ui->label->setText("Click Destroyer Coordinate");
    }
    else if(numDrops == 2) {
        ui->label->setText("Click Submarine Coordinate");
    }
    else if(numDrops == 3) {
        ui->label->setText("Click Battleship Coordinate");
    }
    else if(numDrops == 4) {
        ui->label->setText("Click Aircraft Carrier Coordinate");
    }
    else {ui->label_3->setVisible(true);
        ui->pushButton_101->setEnabled(true);}
}

void MainWindow::on_pushButton_67_clicked() {
    ui->pushButton_67->setStyleSheet("background-color: black");
    numDrops++;
    if(numDrops == 1) {
        ui->label->setText("Click Destroyer Coordinate");
    }
    else if(numDrops == 2) {
        ui->label->setText("Click Submarine Coordinate");
    }
    else if(numDrops == 3) {
        ui->label->setText("Click Battleship Coordinate");
    }
    else if(numDrops == 4) {
        ui->label->setText("Click Aircraft Carrier Coordinate");
    }
    else {ui->label_3->setVisible(true);
        ui->pushButton_101->setEnabled(true);}
}

void MainWindow::on_pushButton_68_clicked() {
    ui->pushButton_68->setStyleSheet("background-color: black");
    numDrops++;
    if(numDrops == 1) {
        ui->label->setText("Click Destroyer Coordinate");
    }
    else if(numDrops == 2) {
        ui->label->setText("Click Submarine Coordinate");
    }
    else if(numDrops == 3) {
        ui->label->setText("Click Battleship Coordinate");
    }
    else if(numDrops == 4) {
        ui->label->setText("Click Aircraft Carrier Coordinate");
    }
    else {ui->label_3->setVisible(true);
        ui->pushButton_101->setEnabled(true);}
}

void MainWindow::on_pushButton_69_clicked() {
    ui->pushButton_69->setStyleSheet("background-color: black");
    numDrops++;
    if(numDrops == 1) {
        ui->label->setText("Click Destroyer Coordinate");
    }
    else if(numDrops == 2) {
        ui->label->setText("Click Submarine Coordinate");
    }
    else if(numDrops == 3) {
        ui->label->setText("Click Battleship Coordinate");
    }
    else if(numDrops == 4) {
        ui->label->setText("Click Aircraft Carrier Coordinate");
    }
    else {ui->label_3->setVisible(true);
        ui->pushButton_101->setEnabled(true);}
}

void MainWindow::on_pushButton_70_clicked() {
    ui->pushButton_70->setStyleSheet("background-color: black");
    numDrops++;
    if(numDrops == 1) {
        ui->label->setText("Click Destroyer Coordinate");
    }
    else if(numDrops == 2) {
        ui->label->setText("Click Submarine Coordinate");
    }
    else if(numDrops == 3) {
        ui->label->setText("Click Battleship Coordinate");
    }
    else if(numDrops == 4) {
        ui->label->setText("Click Aircraft Carrier Coordinate");
    }
    else {ui->label_3->setVisible(true);
        ui->pushButton_101->setEnabled(true);}
}
void MainWindow::on_pushButton_71_clicked() {
    ui->pushButton_71->setStyleSheet("background-color: black");
    numDrops++;
    if(numDrops == 1) {
        ui->label->setText("Click Destroyer Coordinate");
    }
    else if(numDrops == 2) {
        ui->label->setText("Click Submarine Coordinate");
    }
    else if(numDrops == 3) {
        ui->label->setText("Click Battleship Coordinate");
    }
    else if(numDrops == 4) {
        ui->label->setText("Click Aircraft Carrier Coordinate");
    }
    else {ui->label_3->setVisible(true);
        ui->pushButton_101->setEnabled(true);}
}

void MainWindow::on_pushButton_72_clicked() {
    ui->pushButton_72->setStyleSheet("background-color: black");
    numDrops++;
    if(numDrops == 1) {
        ui->label->setText("Click Destroyer Coordinate");
    }
    else if(numDrops == 2) {
        ui->label->setText("Click Submarine Coordinate");
    }
    else if(numDrops == 3) {
        ui->label->setText("Click Battleship Coordinate");
    }
    else if(numDrops == 4) {
        ui->label->setText("Click Aircraft Carrier Coordinate");
    }
    else {ui->label_3->setVisible(true);
        ui->pushButton_101->setEnabled(true);}
}

void MainWindow::on_pushButton_73_clicked() {
    ui->pushButton_73->setStyleSheet("background-color: black");
    numDrops++;
    if(numDrops == 1) {
        ui->label->setText("Click Destroyer Coordinate");
    }
    else if(numDrops == 2) {
        ui->label->setText("Click Submarine Coordinate");
    }
    else if(numDrops == 3) {
        ui->label->setText("Click Battleship Coordinate");
    }
    else if(numDrops == 4) {
        ui->label->setText("Click Aircraft Carrier Coordinate");
    }
    else {ui->label_3->setVisible(true);
        ui->pushButton_101->setEnabled(true);}
}

void MainWindow::on_pushButton_74_clicked() {
    ui->pushButton_74->setStyleSheet("background-color: black");
    numDrops++;
    if(numDrops == 1) {
        ui->label->setText("Click Destroyer Coordinate");
    }
    else if(numDrops == 2) {
        ui->label->setText("Click Submarine Coordinate");
    }
    else if(numDrops == 3) {
        ui->label->setText("Click Battleship Coordinate");
    }
    else if(numDrops == 4) {
        ui->label->setText("Click Aircraft Carrier Coordinate");
    }
    else { ui->label_3->setVisible(true);
        ui->pushButton_101->setEnabled(true);}
}

void MainWindow::on_pushButton_75_clicked() {
    ui->pushButton_75->setStyleSheet("background-color: black");
    numDrops++;
    if(numDrops == 1) {
        ui->label->setText("Click Destroyer Coordinate");
    }
    else if(numDrops == 2) {
        ui->label->setText("Click Submarine Coordinate");
    }
    else if(numDrops == 3) {
        ui->label->setText("Click Battleship Coordinate");
    }
    else if(numDrops == 4) {
        ui->label->setText("Click Aircraft Carrier Coordinate");
    }
    else { ui->label_3->setVisible(true);
        ui->pushButton_101->setEnabled(true);}
}

void MainWindow::on_pushButton_76_clicked() {
    ui->pushButton_76->setStyleSheet("background-color: black");
    numDrops++;
    if(numDrops == 1) {
        ui->label->setText("Click Destroyer Coordinate");
    }
    else if(numDrops == 2) {
        ui->label->setText("Click Submarine Coordinate");
    }
    else if(numDrops == 3) {
        ui->label->setText("Click Battleship Coordinate");
    }
    else if(numDrops == 4) {
        ui->label->setText("Click Aircraft Carrier Coordinate");
    }
    else { ui->label_3->setVisible(true);
        ui->pushButton_101->setEnabled(true);}
}

void MainWindow::on_pushButton_77_clicked() {
    ui->pushButton_77->setStyleSheet("background-color: black");
    numDrops++;
    if(numDrops == 1) {
        ui->label->setText("Click Destroyer Coordinate");
    }
    else if(numDrops == 2) {
        ui->label->setText("Click Submarine Coordinate");
    }
    else if(numDrops == 3) {
        ui->label->setText("Click Battleship Coordinate");
    }
    else if(numDrops == 4) {
        ui->label->setText("Click Aircraft Carrier Coordinate");
    }
    else { ui->label_3->setVisible(true);
        ui->pushButton_101->setEnabled(true);}
}

void MainWindow::on_pushButton_78_clicked() {
    ui->pushButton_78->setStyleSheet("background-color: black");
    numDrops++;
    if(numDrops == 1) {
        ui->label->setText("Click Destroyer Coordinate");
    }
    else if(numDrops == 2) {
        ui->label->setText("Click Submarine Coordinate");
    }
    else if(numDrops == 3) {
        ui->label->setText("Click Battleship Coordinate");
    }
    else if(numDrops == 4) {
        ui->label->setText("Click Aircraft Carrier Coordinate");
    }
    else { ui->label_3->setVisible(true);
        ui->pushButton_101->setEnabled(true);}
}

void MainWindow::on_pushButton_79_clicked() {
    ui->pushButton_79->setStyleSheet("background-color: black");
    numDrops++;
    if(numDrops == 1) {
        ui->label->setText("Click Destroyer Coordinate");
    }
    else if(numDrops == 2) {
        ui->label->setText("Click Submarine Coordinate");
    }
    else if(numDrops == 3) {
        ui->label->setText("Click Battleship Coordinate");
    }
    else if(numDrops == 4) {
        ui->label->setText("Click Aircraft Carrier Coordinate");
    }
    else { ui->label_3->setVisible(true);
        ui->pushButton_101->setEnabled(true);}
}

void MainWindow::on_pushButton_80_clicked() {
    ui->pushButton_80->setStyleSheet("background-color: black");
    numDrops++;
    if(numDrops == 1) {
        ui->label->setText("Click Destroyer Coordinate");
    }
    else if(numDrops == 2) {
        ui->label->setText("Click Submarine Coordinate");
    }
    else if(numDrops == 3) {
        ui->label->setText("Click Battleship Coordinate");
    }
    else if(numDrops == 4) {
        ui->label->setText("Click Aircraft Carrier Coordinate");
    }
    else { ui->label_3->setVisible(true);
        ui->pushButton_101->setEnabled(true);}
}

void MainWindow::on_pushButton_81_clicked() {
    ui->pushButton_81->setStyleSheet("background-color: black");
    numDrops++;
    if(numDrops == 1) {
        ui->label->setText("Click Destroyer Coordinate");
    }
    else if(numDrops == 2) {
        ui->label->setText("Click Submarine Coordinate");
    }
    else if(numDrops == 3) {
        ui->label->setText("Click Battleship Coordinate");
    }
    else if(numDrops == 4) {
        ui->label->setText("Click Aircraft Carrier Coordinate");
    }
    else { ui->label_3->setVisible(true);
        ui->pushButton_101->setEnabled(true);}
}

void MainWindow::on_pushButton_82_clicked() {
    ui->pushButton_82->setStyleSheet("background-color: black");
    numDrops++;
    if(numDrops == 1) {
        ui->label->setText("Click Destroyer Coordinate");
    }
    else if(numDrops == 2) {
        ui->label->setText("Click Submarine Coordinate");
    }
    else if(numDrops == 3) {
        ui->label->setText("Click Battleship Coordinate");
    }
    else if(numDrops == 4) {
        ui->label->setText("Click Aircraft Carrier Coordinate");
    }
    else { ui->label_3->setVisible(true);
        ui->pushButton_101->setEnabled(true);}
}

void MainWindow::on_pushButton_83_clicked() {
    ui->pushButton_83->setStyleSheet("background-color: black");
    numDrops++;
    if(numDrops == 1) {
        ui->label->setText("Click Destroyer Coordinate");
    }
    else if(numDrops == 2) {
        ui->label->setText("Click Submarine Coordinate");
    }
    else if(numDrops == 3) {
        ui->label->setText("Click Battleship Coordinate");
    }
    else if(numDrops == 4) {
        ui->label->setText("Click Aircraft Carrier Coordinate");
    }
    else { ui->label_3->setVisible(true);
        ui->pushButton_101->setEnabled(true);}
}

void MainWindow::on_pushButton_84_clicked() {
    ui->pushButton_84->setStyleSheet("background-color: black");
    numDrops++;
    if(numDrops == 1) {
        ui->label->setText("Click Destroyer Coordinate");
    }
    else if(numDrops == 2) {
        ui->label->setText("Click Submarine Coordinate");
    }
    else if(numDrops == 3) {
        ui->label->setText("Click Battleship Coordinate");
    }
    else if(numDrops == 4) {
        ui->label->setText("Click Aircraft Carrier Coordinate");
    }
    else { ui->label_3->setVisible(true);
        ui->pushButton_101->setEnabled(true);}
}

void MainWindow::on_pushButton_85_clicked() {
    ui->pushButton_85->setStyleSheet("background-color: black");
    numDrops++;
    if(numDrops == 1) {
        ui->label->setText("Click Destroyer Coordinate");
    }
    else if(numDrops == 2) {
        ui->label->setText("Click Submarine Coordinate");
    }
    else if(numDrops == 3) {
        ui->label->setText("Click Battleship Coordinate");
    }
    else if(numDrops == 4) {
        ui->label->setText("Click Aircraft Carrier Coordinate");
    }
    else { ui->label_3->setVisible(true);
        ui->pushButton_101->setEnabled(true);}
}

void MainWindow::on_pushButton_86_clicked() {
    ui->pushButton_86->setStyleSheet("background-color: black");
    numDrops++;
    if(numDrops == 1) {
        ui->label->setText("Click Destroyer Coordinate");
    }
    else if(numDrops == 2) {
        ui->label->setText("Click Submarine Coordinate");
    }
    else if(numDrops == 3) {
        ui->label->setText("Click Battleship Coordinate");
    }
    else if(numDrops == 4) {
        ui->label->setText("Click Aircraft Carrier Coordinate");
    }
    else { ui->label_3->setVisible(true);
        ui->pushButton_101->setEnabled(true);}
}

void MainWindow::on_pushButton_87_clicked() {
    ui->pushButton_87->setStyleSheet("background-color: black");
    numDrops++;
    if(numDrops == 1) {
        ui->label->setText("Click Destroyer Coordinate");
    }
    else if(numDrops == 2) {
        ui->label->setText("Click Submarine Coordinate");
    }
    else if(numDrops == 3) {
        ui->label->setText("Click Battleship Coordinate");
    }
    else if(numDrops == 4) {
        ui->label->setText("Click Aircraft Carrier Coordinate");
    }
    else { ui->label_3->setVisible(true);
        ui->pushButton_101->setEnabled(true);}
}

void MainWindow::on_pushButton_88_clicked() {
    ui->pushButton_88->setStyleSheet("background-color: black");
    numDrops++;
    if(numDrops == 1) {
        ui->label->setText("Click Destroyer Coordinate");
    }
    else if(numDrops == 2) {
        ui->label->setText("Click Submarine Coordinate");
    }
    else if(numDrops == 3) {
        ui->label->setText("Click Battleship Coordinate");
    }
    else if(numDrops == 4) {
        ui->label->setText("Click Aircraft Carrier Coordinate");
    }
    else { ui->label_3->setVisible(true);
        ui->pushButton_101->setEnabled(true);}
}

void MainWindow::on_pushButton_89_clicked() {
    ui->pushButton_89->setStyleSheet("background-color: black");
    numDrops++;
    if(numDrops == 1) {
        ui->label->setText("Click Destroyer Coordinate");
    }
    else if(numDrops == 2) {
        ui->label->setText("Click Submarine Coordinate");
    }
    else if(numDrops == 3) {
        ui->label->setText("Click Battleship Coordinate");
    }
    else if(numDrops == 4) {
        ui->label->setText("Click Aircraft Carrier Coordinate");
    }
    else { ui->label_3->setVisible(true);
        ui->pushButton_101->setEnabled(true);}
}

void MainWindow::on_pushButton_90_clicked() {
    ui->pushButton_90->setStyleSheet("background-color: black");
    numDrops++;
    if(numDrops == 1) {
        ui->label->setText("Click Destroyer Coordinate");
    }
    else if(numDrops == 2) {
        ui->label->setText("Click Submarine Coordinate");
    }
    else if(numDrops == 3) {
        ui->label->setText("Click Battleship Coordinate");
    }
    else if(numDrops == 4) {
        ui->label->setText("Click Aircraft Carrier Coordinate");
    }
    else { ui->label_3->setVisible(true);
        ui->pushButton_101->setEnabled(true);}
}
void MainWindow::on_pushButton_91_clicked() {
    ui->pushButton_91->setStyleSheet("background-color: black");
    numDrops++;
    if(numDrops == 1) {
        ui->label->setText("Click Destroyer Coordinate");
    }
    else if(numDrops == 2) {
        ui->label->setText("Click Submarine Coordinate");
    }
    else if(numDrops == 3) {
        ui->label->setText("Click Battleship Coordinate");
    }
    else if(numDrops == 4) {
        ui->label->setText("Click Aircraft Carrier Coordinate");
    }
    else { ui->label_3->setVisible(true);
        ui->pushButton_101->setEnabled(true);}
}

void MainWindow::on_pushButton_92_clicked() {
    ui->pushButton_92->setStyleSheet("background-color: black");
    numDrops++;
    if(numDrops == 1) {
        ui->label->setText("Click Destroyer Coordinate");
    }
    else if(numDrops == 2) {
        ui->label->setText("Click Submarine Coordinate");
    }
    else if(numDrops == 3) {
        ui->label->setText("Click Battleship Coordinate");
    }
    else if(numDrops == 4) {
        ui->label->setText("Click Aircraft Carrier Coordinate");
    }
    else { ui->label_3->setVisible(true);
        ui->pushButton_101->setEnabled(true);}
}

void MainWindow::on_pushButton_93_clicked() {
    ui->pushButton_93->setStyleSheet("background-color: black");
    numDrops++;
    if(numDrops == 1) {
        ui->label->setText("Click Destroyer Coordinate");
    }
    else if(numDrops == 2) {
        ui->label->setText("Click Submarine Coordinate");
    }
    else if(numDrops == 3) {
        ui->label->setText("Click Battleship Coordinate");
    }
    else if(numDrops == 4) {
        ui->label->setText("Click Aircraft Carrier Coordinate");
    }
    else { ui->label_3->setVisible(true);
        ui->pushButton_101->setEnabled(true);}
}

void MainWindow::on_pushButton_94_clicked() {
    ui->pushButton_94->setStyleSheet("background-color: black");
    numDrops++;
    if(numDrops == 1) {
        ui->label->setText("Click Destroyer Coordinate");
    }
    else if(numDrops == 2) {
        ui->label->setText("Click Submarine Coordinate");
    }
    else if(numDrops == 3) {
        ui->label->setText("Click Battleship Coordinate");
    }
    else if(numDrops == 4) {
        ui->label->setText("Click Aircraft Carrier Coordinate");
    }
    else { ui->label_3->setVisible(true);
        ui->pushButton_101->setEnabled(true);}
}

void MainWindow::on_pushButton_95_clicked() {
    ui->pushButton_95->setStyleSheet("background-color: black");
    numDrops++;
    if(numDrops == 1) {
        ui->label->setText("Click Destroyer Coordinate");
    }
    else if(numDrops == 2) {
        ui->label->setText("Click Submarine Coordinate");
    }
    else if(numDrops == 3) {
        ui->label->setText("Click Battleship Coordinate");
    }
    else if(numDrops == 4) {
        ui->label->setText("Click Aircraft Carrier Coordinate");
    }
    else { ui->label_3->setVisible(true);
        ui->pushButton_101->setEnabled(true);}
}

void MainWindow::on_pushButton_96_clicked() {
    ui->pushButton_96->setStyleSheet("background-color: black");
    numDrops++;
    if(numDrops == 1) {
        ui->label->setText("Click Destroyer Coordinate");
    }
    else if(numDrops == 2) {
        ui->label->setText("Click Submarine Coordinate");
    }
    else if(numDrops == 3) {
        ui->label->setText("Click Battleship Coordinate");
    }
    else if(numDrops == 4) {
        ui->label->setText("Click Aircraft Carrier Coordinate");
    }
    else { ui->label_3->setVisible(true);
        ui->pushButton_101->setEnabled(true);}
}

void MainWindow::on_pushButton_97_clicked() {
    ui->pushButton_97->setStyleSheet("background-color: black");
    numDrops++;
    if(numDrops == 1) {
        ui->label->setText("Click Destroyer Coordinate");
    }
    else if(numDrops == 2) {
        ui->label->setText("Click Submarine Coordinate");
    }
    else if(numDrops == 3) {
        ui->label->setText("Click Battleship Coordinate");
    }
    else if(numDrops == 4) {
        ui->label->setText("Click Aircraft Carrier Coordinate");
    }
    else { ui->label_3->setVisible(true);
        ui->pushButton_101->setEnabled(true);}
}

void MainWindow::on_pushButton_98_clicked() {
    ui->pushButton_98->setStyleSheet("background-color: black");
    numDrops++;
    if(numDrops == 1) {
        ui->label->setText("Click Destroyer Coordinate");
    }
    else if(numDrops == 2) {
        ui->label->setText("Click Submarine Coordinate");
    }
    else if(numDrops == 3) {
        ui->label->setText("Click Battleship Coordinate");
    }
    else if(numDrops == 4) {
        ui->label->setText("Click Aircraft Carrier Coordinate");
    }
    else { ui->label_3->setVisible(true);
        ui->pushButton_101->setEnabled(true);}
}

void MainWindow::on_pushButton_99_clicked() {
    ui->pushButton_99->setStyleSheet("background-color: black");
    numDrops++;
    if(numDrops == 1) {
        ui->label->setText("Click Destroyer Coordinate");
    }
    else if(numDrops == 2) {
        ui->label->setText("Click Submarine Coordinate");
    }
    else if(numDrops == 3) {
        ui->label->setText("Click Battleship Coordinate");
    }
    else if(numDrops == 4) {
        ui->label->setText("Click Aircraft Carrier Coordinate");
    }
    else { ui->label_3->setVisible(true);
        ui->pushButton_101->setEnabled(true);}
}

void MainWindow::on_pushButton_100_clicked() {
    ui->pushButton_100->setStyleSheet("background-color: black");
    numDrops++;
    if(numDrops == 1) {
        ui->label->setText("Click Destroyer Coordinate");
    }
    else if(numDrops == 2) {
        ui->label->setText("Click Submarine Coordinate");
    }
    else if(numDrops == 3) {
        ui->label->setText("Click Battleship Coordinate");
    }
    else if(numDrops == 4) {
        ui->label->setText("Click Aircraft Carrier Coordinate");
    }
    else {ui->label_3->setVisible(true);
        ui->pushButton_101->setEnabled(true);}
}

void MainWindow::on_pushButton_102_clicked() {
  for(int i=0;i<100;i++) {
      cellArr[i]->setStyleSheet("");
  }
  for(int i=0;i<5;i++) {
      firstCoordArr[i] = 0;
  }
  numDrops = 0;

  ui->pushButton_101->setEnabled(false);
}

void MainWindow::on_pushButton_101_clicked() {

    this->close();
}
