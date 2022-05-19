#include "circle.h"

Circle::Circle()
{

}

Circle::Circle(QPointF point, float rad) :
    circlePoint{point}, radius{rad}
{shape = Figures::Circle;}

Figures::Shape Circle::getShape() {return shape;}
