#include "circle.h"

Circle::Circle()
{

}

Circle::Circle(QPointF point, float rad, QPen pen) :
    circlePoint{point}, radius{rad}
{
    shape = Figures::Circle;
    this->pen = pen;
    this->oldPen = pen;
}

Figures::Shape Circle::getShape() {return shape;}

bool Circle::inTheFigure(QPointF position) {
    if (sqrt(pow(circlePoint.x()-position.x(),2)+pow(circlePoint.y()-position.y(),2)) <= radius) return true;
    else return false;
}
