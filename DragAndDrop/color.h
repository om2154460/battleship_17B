#ifndef COLOR_H
#define COLOR_H


#include <QGraphicsItem>

//! [0]
class Color : public QGraphicsItem
{
public:
    Color();
   /* Color(int wid,int h) {
        width = wid;
        height = h;
    }*/

    QRectF boundingRect() const Q_DECL_OVERRIDE;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) Q_DECL_OVERRIDE;
    void setHeight(int);
    void setWidth(int);
    void setShipSz(int);
    int getShipSz(){return shipSz;}
    int getWidth(){return width;}
    int getHeight(){return height;}

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) Q_DECL_OVERRIDE;

private:
    QColor color;
    int width,height, shipSz;
};
//! [0]

#endif // COLOR_H
