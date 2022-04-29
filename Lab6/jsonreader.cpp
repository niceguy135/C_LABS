#include "jsonreader.h"

JSONReader::JSONReader(const QString& filename)
{
    this->fin.open(filename.toLatin1().data());
    std::string line;
    std::string jsonText = "";
    while(getline(this->fin,line) ) {
          jsonText += line;
    }

    this->MyJSON = json::parse(jsonText);

}

bool JSONReader::is_open() const{
    return fin.is_open();
}

JSONReader::~JSONReader() {
    fin.close();
}

std::vector<Employee> JSONReader::readAll() {
    std::vector<Employee> workers;
    for(long long unsigned i = 1; i <= MyJSON.size(); i++) {
          auto worker = *(MyJSON.find(std::to_string(i)));

          std::string name = *(worker.find("name"));

          int year = *(worker.find("year"));
          Gender gender = static_cast<Gender>(*(worker.find("gender")));

          Employee* employee = new Employee(QString::fromLatin1(name),year,gender);


          workers.push_back(*employee);
    }
    return workers;
}

JSONReader& JSONReader::operator>> (Employee &emp) {
    if (!MyJSON.count(std::to_string(cur_index))) return *this;

    auto worker = *(MyJSON.find(std::to_string(cur_index)));


    emp.name = QString::fromStdString(*(worker.find("name")));

    emp.year = *(worker.find("year"));
    emp.gender = static_cast<Gender>(*(worker.find("gender")));

    cur_index++;

    return  *this;
}
