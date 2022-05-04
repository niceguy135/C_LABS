#include <QCoreApplication>
#include <iostream>
#include <vector>
#include <pointondesk.h>

template <class T>

float AvrSum(std::vector<T> Array) {
    auto Sum = 0;
    for(auto a : Array) {
        Sum += a;
    }
    return float(Sum) / float(Array.size());
}

int main()
{
    std::vector<int> testInt = {1,2,3,4,5,6};
    std::vector<float> testFloat = {1.2,22.4,-6};

    PointOnDesk<int> testClass(1,2);

    std::cout << AvrSum(testInt) << std::endl;
    std::cout << AvrSum(testFloat) << std::endl;
    std::cout << AvrSum(testClass.getCoords()) << std::endl;

    return 0;
}
