#ifndef FIGURES_H
#define FIGURES_H

#include <QPen>
#include <QBrush>
#include <QPointF>

class Figures
{
public:
    enum Shape {Square, Circle, Trig};

    Figures();
    Figures(Shape shape);

    virtual Shape getShape() = 0;

    Shape shape;
};

#endif // FIGURES_H
