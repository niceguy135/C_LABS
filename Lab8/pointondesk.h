#ifndef POINTONDESK_H
#define POINTONDESK_H
#include <vector>
#include <iostream>

template <typename t1>

class PointOnDesk
{
public:
    PointOnDesk(t1 x, t1 y) :
        x{x}, y{y}
    {}


    t1 x=0;
    t1 y=0;

    std::vector<t1> getCoords() {
        std::vector<t1> Vector2 = {x,y};
        return Vector2;
    }

    PointOnDesk operator+ (PointOnDesk p2){
        return PointOnDesk(this->x+p2.x,this->y+p2.y);
    }

    PointOnDesk operator+ (int p2){
        return PointOnDesk(this->x+p2,this->y+p2);
    }

    PointOnDesk operator/ (int p2){
        return PointOnDesk(this->x/p2,this->y/p2);
    }

};

template <typename t1>

std::ostream& operator<<(std::ostream& os, const PointOnDesk<t1> em)     {
    os << "X is: " << em.x << "; Y is: " << em.y << std::endl;
    return os;
}

#endif // POINTONDESK_H
