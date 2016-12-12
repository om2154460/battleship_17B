// system libraries

#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QLabel>
#include <QTransform>
#include <QBoxLayout>
#include <QPushButton>
#include <QGraphicsProxyWidget>
#include <QGraphicsItem>
#include <QLabel>
#include <QCheckBox>
#include <QSplashScreen>
#include <QTimer>
#include <QPalette>


// user libraries
#include "mainwindow.h"
#include "cell.h"
#include "color.h"
#include "graphicsview.h"


// function prototypes
//void colorShip(Square[], int);


int main(int argc, char *argv[]) {   // GET WHICH BOX IS LIT UP*************
    QApplication a(argc, argv);       // first see about doing this without new class, otherwise, make handler class and pass in
                                       // cell/square array

    QGraphicsScene scene(-20, -20, 500, 500); // (-200, -200, 400, 400);

  /*  QPixmap bkgnd("C:/Users/User/DragAndDrop/radar.jpg");
    bkgnd = bkgnd.scaled(500,500, Qt::IgnoreAspectRatio);
    //bkgnd.sc
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
   // scene.setPalette(palette); // sets widgets this color
*/
    Color *item;
    item = new Color[5];

    // SHIP ICON SIZES
    /////////////////////////////////////////////////////////
for(int i=0;i<5;i++) {
    if(i == 0) {
        item[i].setWidth(30);
    item[i].setShipSz(2);

    }
    if(i == 1 || i == 2) {
        item[i].setWidth(60);
     item[i].setShipSz(3);
    }
    if(i == 3) {
        item[i].setWidth(90);
        item[i].setShipSz(4);
    }
    if(i == 4) {
        item[i].setWidth(120);
         item[i].setShipSz(5);
    }
    item[i].setHeight(30);
}
    /////////////////////////////////////////////////////////

 // initial ship icon positions
 item[0].setPos(15,40);
 item[1].setPos(15,120);
 item[2].setPos(15,200);
 item[3].setPos(15,280);
 item[4].setPos(15,360);



// SET LABEL ATTRIBUTES
 QLabel *lab;
 lab = new QLabel[5];

 lab[0].setText("Patrol Boat: ");
 lab[0].setGeometry(0,10,120,12); // (x,y,w,h)
 lab[1].setText("Destroyer: ");
 lab[1].setGeometry(0,90,120,12); // (x,y,w,h)
 lab[2].setText("Submarine: ");
 lab[2].setGeometry(0,170,80,12); // (x,y,w,h)
 lab[3].setText("Battleship: ");
 lab[3].setGeometry(0,250,80,12); // (x,y,w,h)
 lab[4].setText("Aircraft Carrier: ");
 lab[4].setGeometry(0,330,120,12); // (x,y,w,h)

 /////////////////////////// BOARD INITIALIZING BEGINS HERE ///////////////////////////

        Square *rt;
        rt = new Square[100];
        int x=450,y=100; // , j=1;



 // INITIALIZE CELLS
int xcnt=0, ycnt=0;
        for(int i =0; i<100; i++) {      // JUST ADDED SET_INDEX FUNCTION!!!!!!!!!
            if(i%10 == 0) {              // NOW LIGHT UP OTHER CELLS BASED ON SIZE OF SHIP
                xcnt = 1;
                ycnt+=48;
            }
            rt[i].setTransform(QTransform::fromScale(1.2, 1.2), true); // line to add each cell to layout
            rt[i].setPos(x+(48*xcnt), y+ycnt);
            rt[i].setIndex(i);
            //if(i > 0) {
            //  connect(rt[i],SIGNAL(toggled(bool)),rt[i-1],SLOT(colorNeighbor()));
            //}
            scene.addItem(&rt[i]);

            xcnt++;
        }

/////////////////////////// BOARD INITIALIZING ENDS HERE ///////////////////////////

        QLabel *playLab = new QLabel;
        playLab->setText("Click once ships are set: ");
        playLab->setGeometry(450,50,130,20);

      QCheckBox *cb1 = new QCheckBox("vertical");
        QCheckBox *cb2 = new QCheckBox("vertical");
        QCheckBox *cb3 = new QCheckBox("vertical");
        QCheckBox *cb4 = new QCheckBox("vertical");
        QCheckBox *cb5 = new QCheckBox("vertical");

      cb1->setGeometry(50,35,20,25);
      cb2->setGeometry(100,115,20,25);
      cb3->setGeometry(100,195,20,25);
      cb4->setGeometry(150,275,20,25);
      cb5->setGeometry(200,355,20,25);

   /* cb[0].setText("vertical");
    cb[1].setText("vertical");
    cb[2].setText("vertical");
    cb[3].setText("vertical");
    cb[4].setText("vertical");*/

     /* for(int i=0;i<5;i++) {
         // cb[i].setText("vertical");
          scene.addWidget(&cb[i]);
      }*/

      scene.addWidget(cb1);
      scene.addWidget(cb2);
      scene.addWidget(cb3);
      scene.addWidget(cb4);
      scene.addWidget(cb5);

        // add ship labels
       scene.addWidget(&lab[0]);
       scene.addWidget(&lab[1]);
       scene.addWidget(&lab[2]);
       scene.addWidget(&lab[3]);
       scene.addWidget(&lab[4]);

       scene.addWidget(playLab);

        // add ship rectangles
        scene.addItem(&item[0]);
        scene.addItem(&item[1]);
        scene.addItem(&item[2]);
        scene.addItem(&item[3]);
        scene.addItem(&item[4]);

        QSplashScreen *splash = new QSplashScreen;
        splash->setPixmap(QPixmap("C:/Users/User/DragAndDrop/battleship.jpg"));
        splash->showMaximized();


       // QTimer::singleShot(1500,splash,SLOT(close()));
        //QTimer::singleShot(1500,&w,SLOT(show()));

    GraphicsView view(&scene);
   // view.setStyleSheet("background-image: C:/Users/User/DragAndDrop/radar.jpg");
   // view.setPalette(palette);
   // view.window()->setPalette(palette);
   // view.setPalette(palette);
    view.setWindowTitle("Set Ship Coordinates");
    view.setRenderHint(QPainter::Antialiasing);



    QTimer::singleShot(1500,splash,SLOT(close()));
    QTimer::singleShot(1500,&view,SLOT(showMaximized()));



   // view.showMaximized();
    //view.show();


    return a.exec();
}

//void GraphicsView::clearBoard(Square * rt) {
  //  rt->clearPixMap();
/* for(int i=0;i<100;i++) {
     rt[i].clearPixMap();
     *rt++;
 }*/
//}
