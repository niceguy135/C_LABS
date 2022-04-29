#ifndef ABSTARCTREADER_H
#define ABSTARCTREADER_H

#include <vector>
#include <employee.h>

class AbstarctReader
{
public:
    virtual bool is_open() const = 0;
    virtual std::vector<Employee> readAll() = 0;

    virtual operator bool() = 0;
    virtual AbstarctReader& operator>>(Employee& smth) = 0;
};

#endif // ABSTARCTREADER_H
