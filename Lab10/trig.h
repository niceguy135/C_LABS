#ifndef TRIG_H
#define TRIG_H

#include <figures.h>

class Trig : public Figures
{
public:
    Trig();
    Trig(QPointF point1, QPointF point2, QPointF point3, QPen pen);

    bool inTheFigure(QPointF position) override;

    std::string getStatus() override {
        return "Верхняя точка точка: Х= " + std::to_string(upPoint.x()) + ";Y= " + std::to_string(float(upPoint.y())) + "\n" +
                "Левая точка точка: Х= " + std::to_string(leftPoint.x()) + ";Y= " + std::to_string(float(leftPoint.y())) + "\n" +
                "Правая точка точка: Х= " + std::to_string(rightPoint.x()) + ";Y= " + std::to_string(float(rightPoint.y()));
    }

    Shape getShape() override;

    QPointF upPoint;
    QPointF leftPoint;
    QPointF rightPoint;

};

#endif // TRIG_H
