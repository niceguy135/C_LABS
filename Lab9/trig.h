#ifndef TRIG_H
#define TRIG_H

#include <figures.h>

class Trig : public Figures
{
public:
    Trig();
    Trig(QPointF point1, QPointF point2, QPointF point3);

    Shape getShape();

    QPointF upPoint;
    QPointF leftPoint;
    QPointF rightPoint;

};

#endif // TRIG_H
