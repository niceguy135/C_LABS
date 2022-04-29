#include "csvreader.h"

CSVReader::CSVReader(const QString& filename)
{
    this->fin.open(filename.toLatin1().data());
}

CSVReader::~CSVReader(){
    this->fin.close();
}

std::vector<Employee> CSVReader::readAll() {
    std::vector<Employee> workers;
    std::string line;
    while(getline(this->fin,line) ) {
          auto worker = split(line,';');

          Employee employee;
          employee.num = stoi(worker[0]);

          employee.name = QString::fromStdString(worker[1]);

          employee.year = stoi(worker[2]);
          employee.gender = static_cast<Gender>(stoi(worker[3]));

          workers.push_back(employee);
    }
    return workers;
}
