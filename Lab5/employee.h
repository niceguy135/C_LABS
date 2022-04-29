#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <QString>
#include <string>



enum Gender {male = 0, female};


class Employee
{


public:
    QString name;
    int year;
    Gender gender;
    int age = 2022 - year;
    static int class_num; //это типо счетчик

private:
    int num;

public:
    Employee(QString name, int year, Gender gender); // конструктор объекта
    ~Employee(); // деконструктор

    Employee(const Employee & worker); // конструктор копирования

    Employee(Employee&& other) // конструктор перемещения
       : name(other.name)
       , year(other.year)
       , gender(other.gender)
       , age(other.age)
    {
        other.name = nullptr;
        other.year = 0;
        other.gender = male;
        other.age = 0;
    }

    Employee& operator=(Employee&& worker); // оператор присваивания

    int getNum() const {
        return this->num;
    }

    std::string to_string();

private:
    int newNumForObject();

};

class Student : public Employee{
public:
    QString group;
    QString faculty;

    std::string to_string();
};

class Sotrudnik : public Employee{
public:
    QString position;
    int salary;

    std::string to_string();
};

class Educator : public Employee{
public:
    QString object;
    int experience;

    std::string to_string();
};


#endif // EMPLOYEE_H
