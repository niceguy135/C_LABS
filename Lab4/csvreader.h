#ifndef CSVREADER_H
#define CSVREADER_H


#include <QString>
#include <iostream>
#include <fstream>
#include <vector>
#include <employee.h>


class CSVReader
{
    std::ifstream fin;


public:
    CSVReader(const QString& filename );
    ~CSVReader();

    bool is_open() const {return this->fin.is_open();}
    static std::vector<std::string> split(const std::string& str, char delim);

    std::vector<Employee> readAll();

    CSVReader(CSVReader&& other); // конструктор перемещения
    CSVReader& operator=(CSVReader&& other); // оператор присваивания перемещением


private:
    CSVReader(const CSVReader&) = delete;
    void operator=(const CSVReader&) = delete;
};

#endif // CSVREADER_H
