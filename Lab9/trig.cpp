#include "trig.h"

Trig::Trig()
{

}

Trig::Trig(QPointF point1, QPointF point2, QPointF point3) :
    upPoint{point1}, leftPoint{point2}, rightPoint{point3}
{shape = Figures::Trig;}

Figures::Shape Trig::getShape() {return shape;}
