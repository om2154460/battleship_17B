#ifndef CELL_H
#define CELL_H


#include <QGraphicsItem>

QT_BEGIN_NAMESPACE
class QGraphicsSceneMouseEvent;
class QParallelAnimationGroup;
QT_END_NAMESPACE

//! [0]
class Cell : public QGraphicsObject
{
public:
    Cell(QGraphicsItem *parent = 0);
    ~Cell(){}
protected:
    void dragEnterEvent(QGraphicsSceneDragDropEvent *event) Q_DECL_OVERRIDE;
    void dragLeaveEvent(QGraphicsSceneDragDropEvent *event) Q_DECL_OVERRIDE;
    void dropEvent(QGraphicsSceneDragDropEvent *event) Q_DECL_OVERRIDE;

    QColor color;
    bool dragOver;
};


class Square : public Cell {

public:
    Square(QGraphicsItem *parent = 0);
    ~Square(){}
    QRectF boundingRect() const Q_DECL_OVERRIDE;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0) Q_DECL_OVERRIDE;

protected:
    void dragEnterEvent(QGraphicsSceneDragDropEvent *event) Q_DECL_OVERRIDE;
    void dropEvent(QGraphicsSceneDragDropEvent *event) Q_DECL_OVERRIDE;

private:
    QPixmap pixmap;
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
