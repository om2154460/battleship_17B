
#include <QtWidgets>
#include <QGraphicsItem>
#include <QStyle>
#include <iostream>
#include <QDebug>

#include "cell.h"
#include "color.h"


Cell::Cell(QGraphicsItem *parent)
    : QGraphicsObject(parent), color(Qt::lightGray), dragOver(false)
{
   // GraphicsView gv;
    setAcceptDrops(true);

}

void Cell::dragEnterEvent(QGraphicsSceneDragDropEvent *event) {

    if (event->mimeData()->hasColor()) {
        event->setAccepted(true);
        dragOver = true;
        update();
    } else {
        event->setAccepted(false);
    }
}

void Cell::dragLeaveEvent(QGraphicsSceneDragDropEvent *event) {
    Q_UNUSED(event);
    dragOver = false;
    update();

}


void Cell::dropEvent(QGraphicsSceneDragDropEvent *event) {
    dragOver = false;
    if (event->mimeData()->hasColor())
        color = qvariant_cast<QColor>(event->mimeData()->colorData());
    numDrops++;
    qDebug() << "numDrops " << numDrops;
  //  emit dropSignal();
        update();
}


void Square::paint(QPainter *painter,
           const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);

    if (pixmap.isNull()) {
        painter->setBrush(dragOver ? color.light(130) : color);
        painter->drawRect(x,y,w,h);
}
    else {
        painter->scale(.2272, .2824);
        painter->drawPixmap(QPointF(-15 * 4.4, -50 * 3.54), pixmap);
    }
}



void Square::dragEnterEvent(QGraphicsSceneDragDropEvent *event) {
    int cnt = 0;

    if (event->mimeData()->hasImage()) {
            event->setAccepted(true);
            dragOver = true;
            update();
            cnt++;
            index++;

    } else {
        Cell::dragEnterEvent(event);
    }
}


//void Square::colorNeighbor() { // ...........................
//this->pixmap.fill(Qt::blue);
//}

void Square::dropEvent(QGraphicsSceneDragDropEvent *event) {

        if (event->mimeData()->hasImage()) {
            dragOver = false;
            pixmap = qvariant_cast<QPixmap>(event->mimeData()->imageData());
            update();
           // numDrops++;
            //qDebug() << "numDrops " << numDrops;
        } else {
            Cell::dropEvent(event);
        }

}
//! [8]

 /*void Square::colorCells(Square s[],Color item[]) {
     //if(item[0])
     int temp = getIndex();
     s[temp].dropEvent(QGraphicsSceneEvent::accept());
 }*/


Square::Square(QGraphicsItem *parent)
    : Cell(parent)
{
   // connect(this,SIGNAL(childrenChanged()),
}


QRectF Square::boundingRect() const  {
    return QRectF(x, y, w, h); // 5*5
}


QRectF BRect::boundingRect() const {
    return QRectF();
}

void BRect::paint(QPainter *painter,
                  const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(painter);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}
