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
    void writeIn(std::vector<Employee> workers); // теперь принимает const вектор

    CSVWriter(CSVWriter&& other); // конструктор перемещения
    CSVWriter& operator=(CSVWriter&& other); // оператор присваивания перемещением

private:
    CSVWriter(const CSVWriter&) = delete;
    void operator=(const CSVWriter&) = delete;
};

#endif // CSVWRITER_H
