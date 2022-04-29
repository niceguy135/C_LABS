#include "employee.h"

int Employee::class_num = 1;

int Employee::newNumForObject() {
    int newNum = this->class_num;
    this->class_num += 1;
    return newNum;
};

Employee::Employee(QString name, int year, Gender gender) {
    this->name = name;
    this->year = year;
    this->gender = gender;
    this->num = newNumForObject();
};

Employee::Employee(const Employee & worker) {
    name = worker.name;
    year = worker.year;
    gender = worker.gender;
    num = worker.getNum();
};

Employee& Employee::operator=(Employee&& worker){
    this->name = worker.name;
    this->year = worker.year;
    this->gender = worker.gender;
    this->num = worker.getNum();

    worker.name = nullptr;
    worker.year = 0;
    worker.gender = male;
    worker.age = 0;

    return *this;
};

Employee::~Employee() {

};

std::string Employee::to_string() { //to_string родительский
    std::string result = "";

    result += ("№: " + std::to_string(num) + "; Name: " + name.toStdString() + "; Year of birth: "
               + std::to_string(year) + "; Gender: " + (gender==0 ? "Male" : "Female"));

    return result;
}

std::string Student::to_string() { //to_string для студента
    std::string result = "";

    result = Employee::to_string();
    result += ("Group: " + group.toStdString() + "; Faculty:" + faculty.toStdString());

    return result;
}

std::string Sotrudnik::to_string() { //to_string для рабочего
    std::string result = "";

    result = Employee::to_string();
    result += ("; Position: " + position.toStdString() + "; Faculty:" + std::to_string(salary));

    return result;
}

std::string Educator::to_string() { //to_string для препода
    std::string result = "";

    result = Employee::to_string();
    result += ("; Object: " + object.toStdString() + "; Experience:" + std::to_string(experience));

    return result;
}
