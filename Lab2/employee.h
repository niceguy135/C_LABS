#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <QString>
#include <ctime>

enum Gender {male = 0, female};


struct Employee
{
    int num;
    QString name;
    int year;
    Gender gender;
    int age = 2022 - year;

};

#endif // EMPLOYEE_H
