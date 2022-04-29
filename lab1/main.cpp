#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <clocale>
#include <algorithm>

enum Gender{male=0,female=1};

struct Employee{
    int num;
    std::string name;
    unsigned int year;
    Gender gender;
};

std::vector<std::string> split(const std::string& str, char delim)
{
    std::vector<std::string> tokens;

    if (!str.empty())
    {
        size_t start = 0, end;
        do {
            end = str.find(delim, start); // поменял местами метод push_back и присвоение новой велечины end
            tokens.push_back(str.substr(start, (end - start)));
            start = end + 1;
        } while (end != std::string::npos);
    }

    return tokens;
}

int main()
{
    setlocale(LC_ALL,"Russian");
    std::fstream file("C:\\Qt\\Programming\\lab1\\employee.csv");
    std::fstream n_file("C:\\Qt\\Programming\\lab1\\new_employee.csv");
    std::vector<Employee> workers;

    if(file.is_open()) {
        std::string line;
        while(getline(file,line) ) {
            auto worker = split(line,';');

            Employee employee;
            employee.num = stoi(worker[0]);

            employee.name = worker[1];

            employee.year = stoi(worker[2]);
            employee.gender = static_cast<Gender>(stoi(worker[3]));

            workers.push_back(employee);
        }

        std::sort(workers.begin(),workers.end(), [](const Employee &a, const Employee &b) {
            return a.year < b.year;
        });

    }
    file.close();


    if(n_file.is_open()) {
        for( auto worker:workers ) {
            if ((2022 - worker.year) >= 31) std::cout << worker.num << ';' << worker.name << ';' << worker.year << ';' << worker.gender << std::endl;
            n_file << worker.num << ';' << worker.name << ';' << worker.year << ';' << worker.gender << std::endl;

        }
    }
    n_file.close();

    return 0;
}
