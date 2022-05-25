#include "rect.h"

Square::Square()
{

}

Square::Square(QPointF point, float w, float h, QPen pen) :
    leftUpPoint{point}, wigth{w}, height{h}
{
    shape = Figures::Square;
    this->pen = pen;
    this->oldPen = pen;
}

Figures::Shape Square::getShape() {return shape;}

bool Square::inTheFigure(QPointF position) {
    QPointF point1 = leftUpPoint;
    QPointF point2 = QPointF(leftUpPoint.x()+wigth,leftUpPoint.y());
    QPointF point3 = QPointF(leftUpPoint.x(),leftUpPoint.y()+height);
    QPointF point4 = QPointF(leftUpPoint.x()+wigth,leftUpPoint.y()+height);

    if (position.x() >= point1.x() && position.y() >= point1.y() &&
            position.x() <= point2.x() && position.y() >= point2.y() &&
            position.x() >= point3.x() && position.y() <= point3.y() &&
            position.x() <= point4.x() && position.y() <= point4.y()
            ) return true;
    else return false;
}
