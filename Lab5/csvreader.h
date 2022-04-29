#ifndef CSVREADER_H
#define CSVREADER_H

#include <abstarctreader.h>
#include <QString>
#include <iostream>
#include <fstream>
#include <vector>
#include <employee.h>


class CSVReader : public AbstarctReader
{
    std::ifstream fin;


public:
    CSVReader(const QString& filename );
    ~CSVReader();

    virtual bool is_open() const {return this->fin.is_open();}
    virtual std::vector<Employee> readAll();

    static std::vector<std::string> split(const std::string& str, char delim);

    CSVReader(CSVReader&& other) = default; // конструктор перемещения
    void operator=(CSVReader&& other); // оператор присваивания перемещением


private:
    CSVReader(const CSVReader&) = delete;
    void operator=(const CSVReader&) = delete;
};

#endif // CSVREADER_H
