#ifndef POINTONDESK_H
#define POINTONDESK_H
#include <vector>

template <typename t1>

class PointOnDesk
{
public:
    PointOnDesk(t1 x, t1 y) {
        this->x = x;
        this->y = y;
    }

    t1 x;
    t1 y;

    std::vector<t1> getCoords() {
        std::vector<t1> Vector2 = {x,y};
        return Vector2;
    }

};

#endif // POINTONDESK_H
