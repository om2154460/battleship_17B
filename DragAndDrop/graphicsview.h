#ifndef GRAPHICSVIEW_H
#define GRAPHICSVIEW_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsProxyWidget>
#include <QStyle>
#include <QPushButton>
#include <QLabel>
#include <QResizeEvent>
#include "cell.h"

class GraphicsView : public QGraphicsView {
    friend class Square;
public:
    GraphicsView(QGraphicsScene *scene) : QGraphicsView(scene) {
        pb = new QPushButton("Play");
        QGraphicsProxyWidget *pw1 = new QGraphicsProxyWidget;
        pw1->setWidget(pb);
        scene->addItem(pw1);
        pb->move(600,50);

        rb = new QPushButton("reset");
        QGraphicsProxyWidget *pw2 = new QGraphicsProxyWidget;
        pw2->setWidget(rb);
        scene->addItem(pw2);
        rb->move(700,50);

        l = new QLabel(" or ");
        QGraphicsProxyWidget *pw3 = new QGraphicsProxyWidget;
        pw3->setWidget(l);
        scene->addItem(pw3);
        l->setStyleSheet("font-weight: bold");
        l->setGeometry(678,50,15,20);

      // pb->blockSignals(true);
        pb->setEnabled(false);


//connect(s,SIGNAL(s.dropSignal(),pb,SLOT(setEnabled(bool))); // in dropEvent: if(dropCnt == 5) {emit dropSignal}

        connect(pb, SIGNAL(clicked(bool)),this,SLOT(close()));


    }
    //QPushButton *pb;
    GraphicsView(){}
//public slots:

   //void clearBoard(Square * rt);

    /*void handleRB(GraphicsView * widget){
        widget->close();
    }*/

protected:
    virtual void resizeEvent(QResizeEvent *) Q_DECL_OVERRIDE {
    }

    QPushButton *pb;
    QPushButton *rb;
    QLabel *l;

};


#endif // GRAPHICSVIEW_H
