#ifndef CIRCLE_H
#define CIRCLE_H

#include <figures.h>

class Circle : public Figures
{
public:
    Circle();
    Circle(QPointF point, float rad);

    Shape getShape();

    QPointF circlePoint;
    float radius;
};

#endif // CIRCLE_H
