#ifndef CSVREADER_H
#define CSVREADER_H

#include <abstarctreader.h>
#include <CSVExceptions.h>
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

    virtual operator bool() { // перегрузка оператора bool
            if(this->fin.is_open()) return true;
            return false;
    };

    virtual CSVReader& operator>> (Employee &emp); // перегрузка оператора >>

    static std::vector<std::string> split(const std::string& str, char delim);

    CSVReader(CSVReader&& other) = default; // конструктор перемещения
    void operator=(CSVReader&& other); // оператор присваивания перемещением


private:
    CSVReader(const CSVReader&) = delete;
    void operator=(const CSVReader&) = delete;

    int number_of_line = 1; //для работы CSVExceptions
};

#endif // CSVREADER_H
