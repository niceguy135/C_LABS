#ifndef RECT_H
#define RECT_H

#include <figures.h>

class Square : public Figures
{
public:
    Square();
    Square(QPointF point, float w, float h);

    Shape getShape();

    QPointF leftUpPoint;
    float wigth;
    float height;
};

#endif // RECT_H
