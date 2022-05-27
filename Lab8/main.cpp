#include <QCoreApplication>
#include <iostream>
#include <vector>
#include <pointondesk.h>

template <class T>

T AvrSum(std::vector<T> Array) {
    T Sum;
    for(auto a : Array) {
        Sum = Sum + a;
    }
    return Sum / Array.size();
}

int main()
{
    std::vector<int> testInt = {1,2,3,4,5,6};
    std::vector<float> testFloat = {1.2,22.4,-6};
    std::vector<PointOnDesk<double>> ArrayOfPoints;

    for (auto i = 0; i < 10; i++) {
        ArrayOfPoints.push_back(PointOnDesk(4.0+i, 5.0+i));
    }

    std::cout << AvrSum(testInt) << std::endl;
    std::cout << AvrSum(testFloat) << std::endl;
    std::cout << AvrSum(ArrayOfPoints) << std::endl;

    return 0;
}
