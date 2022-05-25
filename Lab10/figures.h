#ifndef FIGURES_H
#define FIGURES_H

#include <QPen>
#include <QBrush>
#include <QPointF>
#include <cmath>
#include <string>
#include <iostream>

class Figures
{
public:
    enum Shape {Square, Circle, Trig};

    Figures();
    Figures(Shape shape);

    virtual bool inTheFigure(QPointF position) = 0;
    virtual std::string getStatus() = 0;

    virtual Shape getShape() = 0;

    Shape shape;
    QPen pen;

    QPen getOldPen() {return oldPen;}
protected:
    QPen oldPen;
};

#endif // FIGURES_H
