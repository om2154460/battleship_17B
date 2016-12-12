#ifndef CELL_H
#define CELL_H


#include <QGraphicsItem>
#include "color.h"
//#include "graphicsview.h"


QT_BEGIN_NAMESPACE
class QGraphicsSceneMouseEvent;
class QParallelAnimationGroup;
QT_END_NAMESPACE

//! [0]
class Cell : public QGraphicsObject {
   // friend class GraphicsView;
public:
    Cell(QGraphicsItem *parent = 0);
    ~Cell(){}

//signals:
  //  void dropSignal();

protected:
    void dragEnterEvent(QGraphicsSceneDragDropEvent *event) Q_DECL_OVERRIDE;
    void dragLeaveEvent(QGraphicsSceneDragDropEvent *event) Q_DECL_OVERRIDE;
    void dropEvent(QGraphicsSceneDragDropEvent *event) Q_DECL_OVERRIDE;

    QColor color;
    bool dragOver;
    int numDrops = 0;
};


class Square : public Cell {

public:
    Square(QGraphicsItem *parent = 0);
    ~Square(){}
    QRectF boundingRect() const Q_DECL_OVERRIDE;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0) Q_DECL_OVERRIDE;
    void setIndex(int i) {index = i;}
    int getIndex() {return index;}
    int getNumDrops() {return numDrops;}
    void clearPixMap() {pixmap.fill(Qt::lightGray);}

//signals:
   // bool dropSignal();

    //void colorCells(Square[],Color[]);

//public slots:
   // void colorNeighbor();

protected:
    void dragEnterEvent(QGraphicsSceneDragDropEvent *event);// Q_DECL_OVERRIDE;
    void dropEvent(QGraphicsSceneDragDropEvent *event); // Q_DECL_OVERRIDE
    //void colorNeighbor();

private:
    QPixmap pixmap;
    int index;
   // int numDrops = 0;
    int w=40,h=40,x=-30,y=-20;
    int coords; // for now: keep as int, later: make int array
};              // when making actual game board: make cells again the same way, just say
                // if(i == coords[j]) { bool shipAtThisCoord = true; // then make it a different color or something}

class BRect : public Cell {
public:
    BRect(QGraphicsItem *parent = 0);
~BRect(){}
    QRectF boundingRect() const Q_DECL_OVERRIDE;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0) Q_DECL_OVERRIDE;
};
//! [4]
#endif // CELL_H
