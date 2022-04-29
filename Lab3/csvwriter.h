#ifndef CSVWRITER_H
#define CSVWRITER_H

#include <QString>
#include <iostream>
#include <fstream>
#include <vector>
#include <employee.h>

class CSVWriter
{
    std::fstream fout;
public:
    CSVWriter(const std::string& filename );
    ~CSVWriter();
    bool is_open() const {return this->fout.is_open();}
    void writeIn(const std::vector<Employee>& workers); // теперь принимает const вектор
};

#endif // CSVWRITER_H
