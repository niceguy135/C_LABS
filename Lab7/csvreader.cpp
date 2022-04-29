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
          auto worker = CSVReader::split(line,';');

          QString name;
          try {
          name = QString::fromStdString(worker[1]);
          } catch(...) {
              throw CSVExceptions("Bad working of QString::fromStdString",number_of_line);
          }

          int year;

          try {
                year = std::stoi(worker[2]);
          } catch (const std::invalid_argument& err) {
                throw CSVExceptions("Bad working of std::stoi",number_of_line);
          }

          auto gender = static_cast<Gender>(stoi(worker[3]));

          Employee* employee = new Employee(name,year,gender);


          workers.push_back(*employee);

          number_of_line++;
    }
    number_of_line=1;
    return workers;
}

std::vector<std::string> CSVReader::split(const std::string& str, char delim)
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

CSVReader& CSVReader::operator >>(Employee &emp) {
        std::string str;
        getline(this->fin,str);

        if (str=="") return *this;

        auto worker = CSVReader::split(str,';');

        emp.name = QString::fromStdString(worker[1]);

        try {
              emp.year = std::stoi(worker[2]);
        } catch (...) {
              throw CSVExceptions("Bad working of \"std::stoi\" on year",number_of_line);
        }

        emp.gender = static_cast<Gender>(stoi(worker[3]));

        number_of_line++;
        return  *this;
};
