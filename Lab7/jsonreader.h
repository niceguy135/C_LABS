#ifndef JSONREADER_H
#define JSONREADER_H

#include "json.hpp"
#include <abstarctreader.h>
#include <QString>
#include <vector>
#include <employee.h>
#include <stdexcept>
#include <fstream>

using json = nlohmann::json;

class JSONReader : public AbstarctReader
{
    std::ifstream fin;

public:
    JSONReader(const QString& filename );
    ~JSONReader();

    int cur_index=1; // для правильной работы перегрузки >>

    virtual bool is_open() const;
    virtual std::vector<Employee> readAll();

    virtual operator bool() { // перегрузка оператора bool
            if(this->fin.is_open()) return true;
            return false;
    };

    virtual JSONReader& operator>> (Employee &emp); // перегрузка оператора >>
private:
    json MyJSON;
};

#endif // JSONREADER_H
