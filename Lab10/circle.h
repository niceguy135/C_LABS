#ifndef CIRCLE_H
#define CIRCLE_H

#include <figures.h>

class Circle : public Figures
{
public:
    Circle();
    Circle(QPointF point, float rad, QPen pen);

    bool inTheFigure(QPointF position) override;

    std::string getStatus() override {
        return "Центр окружности: Х= " + std::to_string(circlePoint.x()) + ";Y= " + std::to_string(float(circlePoint.y())) + "\n" +
                "Радиус: " + std::to_string(radius);
    }

    Shape getShape() override;

    QPointF circlePoint;
    float radius;
};

#endif // CIRCLE_H
