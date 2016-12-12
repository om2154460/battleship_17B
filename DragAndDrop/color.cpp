
#include <QtWidgets>

#include "Color.h"

//! [0]
Color::Color()
    : color(qrand() % 256, qrand() % 256, qrand() % 256)
{
    setToolTip(QString("QColor(%1, %2, %3)\n%4")
              .arg(color.black()).arg(color.black()).arg(color.black())
              .arg("Click and drag this ship onto the board!"));
    setCursor(Qt::OpenHandCursor);
    setAcceptedMouseButtons(Qt::LeftButton);
}

QRectF Color::boundingRect() const {
    //return QRectF(-15.5, -15.5, 34, 34);
    return QRectF(-15.5, -15.5, width*shipSz, height); // each cell has its own bounding rect
}     // when dropped, have it take up more spaces

void Color::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setPen(Qt::NoPen);
   // painter->setBrush(Qt::darkGray);     // SHADOW // MAYBE REMOVE BOX ONCE DRAGGED BUT LEAVE SHADOW
   // painter->drawRect(-12, -12, 30, 30); // SHADOW
    painter->setPen(QPen(Qt::black, 1));
    painter->setBrush(QBrush(color.black()));

    painter->drawRect(-15, -15, width, height);  // (x1,y1,w,h)

}

void Color::setShipSz(int s) {
    shipSz = s;
}

void Color::mousePressEvent(QGraphicsSceneMouseEvent *)
{
    setCursor(Qt::ClosedHandCursor);
}


void Color::setHeight(int h) {
    height = h;
}

void Color::setWidth(int w) {
    width = w;
}


void Color::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (QLineF(event->screenPos(), event->buttonDownScreenPos(Qt::LeftButton))
        .length() < QApplication::startDragDistance()) {
        return;
    }

    QDrag *drag = new QDrag(event->widget());
    QMimeData *mime = new QMimeData;
    drag->setMimeData(mime);


    static int n = 0;
    if (n++ > 2 && (qrand() % 3) == 0) {  // CHANGES ROBOT's COLOR, MAKE IT DO THAT TO A GRID**************
        QImage image(":/images/head.png");  // ***************************************************************/
        mime->setImageData(image);

        drag->setPixmap(QPixmap::fromImage(image).scaled(30, 40));
        //drag->setPixmap(QPixmap::fromImage(image).scaled(width, height));
        drag->setHotSpot(QPoint(15, 30)); // how far away object is from cursor while dragging
       // drag->setHotSpot(QPoint(width, height));

    } else {
        mime->setColorData(color);
        mime->setText(QString("#%1%2%3")
                      .arg(color.black(), 2, 16, QLatin1Char('0'))
                      .arg(color.black(), 2, 16, QLatin1Char('0'))
                      .arg(color.black(), 2, 16, QLatin1Char('0')));

        QPixmap pixmap(34, 34);
        pixmap.fill(Qt::white);

        QPainter painter(&pixmap);
        painter.translate(15, 15);
        painter.setRenderHint(QPainter::Antialiasing);
        paint(&painter, 0, 0);
        painter.end();

        pixmap.setMask(pixmap.createHeuristicMask());

        drag->setPixmap(pixmap);
        drag->setHotSpot(QPoint(15, 20)); // how far away object is from cursor while dragging
    }
//! [7]

//! [8]
    drag->exec();
    setCursor(Qt::OpenHandCursor);
}
//! [8]

//! [4]
void Color::mouseReleaseEvent(QGraphicsSceneMouseEvent *)
{
    setCursor(Qt::OpenHandCursor);
}
//! [4]

