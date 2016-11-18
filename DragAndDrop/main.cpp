#include "mainwindow.h"
#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QLabel>
#include <QTransform>
#include <QBoxLayout>
#include <QPushButton>

#include "cell.h"
#include "color.h"


class GraphicsView : public QGraphicsView {
public:
    GraphicsView(QGraphicsScene *scene) : QGraphicsView(scene) {
    }

protected:
    virtual void resizeEvent(QResizeEvent *) Q_DECL_OVERRIDE {
    }
};

int main(int argc, char *argv[]) {   // GET WHICH BOX IS LIT UP*************
    QApplication a(argc, argv);       // first see about doing this without new class, otherwise, make handler class and pass in
                                       // cell/square array
   /* QWidget *Form = new QWidget;
    QVBoxLayout *verticalLayout = new QVBoxLayout;
    QHBoxLayout *horizontalLayout = new QHBoxLayout; // ADD LAYOUT LATER TO SET WIDGETS RESIZABLE WITH WINDOW
    QVBoxLayout *mainLayout = new QVBoxLayout;*/     // WILL NEED TO MAKE 5 DIFFERENT LABLES INSTEAD OF continually reprinting


    QGraphicsScene scene(-20, -20, 500, 500); // (-200, -200, 400, 400);


    Color *item;
    item = new Color[5];

    // ship sizes
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
 // initial ship positions
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


 /*Color *item;
 item = new Color[17];

 for(int i=0;i<17;i++) {
  item[i].setWidth(30);
  item[i].setHeight(30);
 }

 // SET ITEMS OF
 item[0].setPos(15,40);
  item[1].setPos(45,40);
  item[2].setPos(15,120);
  item[3].setPos(45,120);
  item[4].setPos(75,120);
  item[5].setPos(15,200);
  item[6].setPos(45,200);
  item[7].setPos(75,200);
  item[8].setPos(15,280);
  item[9].setPos(45,280);
  item[10].setPos(75,280);
  item[11].setPos(105,280);
  item[12].setPos(15,360);
  item[13].setPos(45,360);
  item[14].setPos(75,360);
  item[15].setPos(105,360);
  item[16].setPos(135,360);*/

       /* verticalLayout->addWidget(pushButton_A);
        verticalLayout->addWidget(pushButton_B);
        horizontalLayout->addWidget(pushButton_C);
        horizontalLayout->addLayout(verticalLayout);
        mainLayout->addLayout(horizontalLayout); */

        Square *rt;
        rt = new Square[30];
        int x=400,y=200; // , j=1;

        // LOOP WONT WORK< INITIALIZE BY HAND FOR NOW
        rt[0].setTransform(QTransform::fromScale(1.2, 1.2), true);
        rt[0].setPos(x, y);
        scene.addItem(&rt[0]);
        rt[1].setTransform(QTransform::fromScale(1.2, 1.2), true);
        rt[1].setPos(x+40, y);
        scene.addItem(&rt[1]);
        rt[2].setTransform(QTransform::fromScale(1.2, 1.2), true);
        rt[2].setPos(x+(40*2), y);
        scene.addItem(&rt[2]);
        rt[3].setTransform(QTransform::fromScale(1.2, 1.2), true);
        rt[3].setPos(x+(40*3), y);
        scene.addItem(&rt[3]);
        rt[4].setTransform(QTransform::fromScale(1.2, 1.2), true);
        rt[4].setPos(x+(40*4), y);
        scene.addItem(&rt[4]);
        rt[5].setTransform(QTransform::fromScale(1.2, 1.2), true);
        rt[5].setPos(x, y+40);
        scene.addItem(&rt[5]);
        rt[6].setTransform(QTransform::fromScale(1.2, 1.2), true);
        rt[6].setPos(x+40, y+40);
        scene.addItem(&rt[6]);
        rt[7].setTransform(QTransform::fromScale(1.2, 1.2), true);
        rt[7].setPos(x+(40*2), y+40);
        scene.addItem(&rt[7]);
        rt[8].setTransform(QTransform::fromScale(1.2, 1.2), true);
        rt[8].setPos(x+(40*3), y+40);
        scene.addItem(&rt[8]);
        rt[9].setTransform(QTransform::fromScale(1.2, 1.2), true);
        rt[9].setPos(x+(40*4), y+40);
        scene.addItem(&rt[9]);

        rt[10].setTransform(QTransform::fromScale(1.2, 1.2), true);
        rt[10].setPos(x, y+(40*2));
        scene.addItem(&rt[10]);
        rt[11].setTransform(QTransform::fromScale(1.2, 1.2), true);
        rt[11].setPos(x+40, y+(40*2));
        scene.addItem(&rt[11]);
        rt[12].setTransform(QTransform::fromScale(1.2, 1.2), true);
        rt[12].setPos(x+(40*2), y+(40*2));
        scene.addItem(&rt[12]);
        rt[13].setTransform(QTransform::fromScale(1.2, 1.2), true);
        rt[13].setPos(x+(40*3), y+(40*2));
        scene.addItem(&rt[13]);
        rt[14].setTransform(QTransform::fromScale(1.2, 1.2), true);
        rt[14].setPos(x+(40*4), y+(40*2));
        scene.addItem(&rt[14]);
        rt[15].setTransform(QTransform::fromScale(1.2, 1.2), true);
        rt[15].setPos(x, y+(40*3));
        scene.addItem(&rt[15]);
        rt[16].setTransform(QTransform::fromScale(1.2, 1.2), true);
        rt[16].setPos(x+40, y+(40*3));
        scene.addItem(&rt[16]);
        rt[17].setTransform(QTransform::fromScale(1.2, 1.2), true);
        rt[17].setPos(x+(40*2), y+(40*3));
        scene.addItem(&rt[17]);
        rt[18].setTransform(QTransform::fromScale(1.2, 1.2), true);
        rt[18].setPos(x+(40*3), y+(40*3));
        scene.addItem(&rt[18]);
        rt[19].setTransform(QTransform::fromScale(1.2, 1.2), true);
        rt[19].setPos(x+(40*4), y+(40*3));
        scene.addItem(&rt[19]);

        rt[20].setTransform(QTransform::fromScale(1.2, 1.2), true);
        rt[20].setPos(x, y+(40*3));
        scene.addItem(&rt[20]);
        rt[21].setTransform(QTransform::fromScale(1.2, 1.2), true);
        rt[21].setPos(x+40, y+(40*3));
        scene.addItem(&rt[21]);
        rt[22].setTransform(QTransform::fromScale(1.2, 1.2), true);
        rt[22].setPos(x+(40*2), y+(40*3));
        scene.addItem(&rt[22]);
        rt[23].setTransform(QTransform::fromScale(1.2, 1.2), true);
        rt[23].setPos(x+(40*3), y+(40*3));
        scene.addItem(&rt[23]);
        rt[24].setTransform(QTransform::fromScale(1.2, 1.2), true);
        rt[24].setPos(x+(40*4), y+(40*3));
        scene.addItem(&rt[24]);
        rt[25].setTransform(QTransform::fromScale(1.2, 1.2), true);
        rt[25].setPos(x, y+(40*4));
        scene.addItem(&rt[25]);
        rt[26].setTransform(QTransform::fromScale(1.2, 1.2), true);
        rt[26].setPos(x+40, y+(40*4));
        scene.addItem(&rt[26]);
        rt[27].setTransform(QTransform::fromScale(1.2, 1.2), true);
        rt[27].setPos(x+(40*2), y+(40*4));
        scene.addItem(&rt[27]);
        rt[28].setTransform(QTransform::fromScale(1.2, 1.2), true);
        rt[28].setPos(x+(40*3), y+(40*4));
        scene.addItem(&rt[28]);
        rt[29].setTransform(QTransform::fromScale(1.2, 1.2), true);
        rt[29].setPos(x+(40*4), y+(40*4));
        scene.addItem(&rt[29]);

/*int j=0;
        for(int i =1; i<=20; i++) {
            if(i%10 == 0) {
                j = 1;
                y+=40;
            }
        rt[i].setTransform(QTransform::fromScale(1.2, 1.2), true); // line to add each cell to layout
        rt[i].setPos(x+(40*j), y);
        scene.addItem(&rt[i]);
        j++;
}*/
        // add and place PushButton
        QPushButton *pb = new QPushButton("Play");
        pb->move(500,500);
        scene.addWidget(pb);
        // add ship labels
       scene.addWidget(&lab[0]);
       scene.addWidget(&lab[1]);
       scene.addWidget(&lab[2]);
       scene.addWidget(&lab[3]);
       scene.addWidget(&lab[4]);
        // add ship rectangles
        scene.addItem(&item[0]);
        scene.addItem(&item[1]);
        scene.addItem(&item[2]);
        scene.addItem(&item[3]);
        scene.addItem(&item[4]);

        // if 17 different objects
       /* scene.addItem(&item[5]);
        scene.addItem(&item[6]);
        scene.addItem(&item[7]);
        scene.addItem(&item[8]);
        scene.addItem(&item[9]);
        scene.addItem(&item[10]);
        scene.addItem(&item[11]);
        scene.addItem(&item[12]);
        scene.addItem(&item[13]);
        scene.addItem(&item[14]);
        scene.addItem(&item[15]);
        scene.addItem(&item[16]);*/


    //} // END LOOP

    // scene->setLayout(mainLayout);
    GraphicsView view(&scene);
    view.setWindowTitle("Set Ship Coordinates");
    view.setRenderHint(QPainter::Antialiasing);
    view.showMaximized();
    //view.show();
   // MainWindow w;
    //w.show();

    return a.exec();
}
