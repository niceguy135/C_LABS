#ifndef RECT_H
#define RECT_H

#include <figures.h>

class Square : public Figures
{
public:
    Square();
    Square(QPointF point, float w, float h, QPen pen);

    bool inTheFigure(QPointF position) override;

    std::string getStatus() override {
        return "Левая правая точка: Х= " + std::to_string(leftUpPoint.x()) + ";Y= " + std::to_string(float(leftUpPoint.y())) + "\n" +
                "Ширина: " + std::to_string(wigth) + "; Высота: " + std::to_string(height);
    }

    Shape getShape() override;

    void takeNewPos(QPointF diff) override {
        leftUpPoint += diff;
    }

    QPointF leftUpPoint;
    float wigth;
    float height;

};

#endif // RECT_H
