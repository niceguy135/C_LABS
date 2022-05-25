#include "trig.h"

Trig::Trig()
{

}

Trig::Trig(QPointF point1, QPointF point2, QPointF point3, QPen pen) :
    upPoint{point1}, leftPoint{point2}, rightPoint{point3}
{
    shape = Figures::Trig;
    this->pen = pen;
    this->oldPen = pen;
}

Figures::Shape Trig::getShape() {return shape;}


bool Trig::inTheFigure(QPointF position) {
    QPointF point1 = upPoint;
    QPointF point2 = leftPoint;
    QPointF point3 = rightPoint;

    auto res1 = (point1.x()-position.x())*(point2.y()-point1.y())-(point2.x()-point1.x())*(point1.y()-position.y());
    auto res2 = (point2.x()-position.x())*(point3.y()-point2.y())-(point3.x()-point2.x())*(point2.y()-position.y());
    auto res3 = (point3.x()-position.x())*(point1.y()-point3.y())-(point1.x()-point3.x())*(point3.y()-position.y());

    if (((res1 >= 0) && (res2 >= 0) && (res3 >= 0)) ||
            ((res1 <= 0) && (res2 <= 0) && (res3 <= 0))
            ) return true;
    else return false;
}
