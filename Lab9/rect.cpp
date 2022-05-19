#include "rect.h"

Square::Square()
{

}

Square::Square(QPointF point, float w, float h) :
    leftUpPoint{point}, wigth{w}, height{h}
{
    shape = Figures::Square;
}

Figures::Shape Square::getShape() {return shape;}
