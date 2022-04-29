#ifndef JSONREADER_H
#define JSONREADER_H

#include "json.hpp"
#include <abstarctreader.h>
#include <QString>
#include <vector>
#include <employee.h>
#include <fstream>

using json = nlohmann::json;

class JSONReader : public AbstarctReader
{
    std::ifstream fin;

public:
    JSONReader(const QString& filename );
    ~JSONReader();

    virtual bool is_open() const;
    virtual std::vector<Employee> readAll();

private:
    json MyJSON;
};

#endif // JSONREADER_H
