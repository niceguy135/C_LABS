#ifndef CSVREADER_H
#define CSVREADER_H


#include <QString>
#include <iostream>
#include <fstream>
#include <vector>
#include <employee.h>
#include <split.h> //та самая функция сплит


class CSVReader
{
    std::ifstream fin;


public:
    CSVReader(const QString& filename );
    ~CSVReader();

    bool is_open() const {return this->fin.is_open();}

    std::vector<Employee> readAll();
};

std::vector<std::string> split(const std::string& str, char delim);

#endif // CSVREADER_H
