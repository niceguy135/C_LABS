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

          auto name = QString::fromStdString(worker[1]);

          auto year = stoi(worker[2]);
          auto gender = static_cast<Gender>(stoi(worker[3]));

          Employee* employee = new Employee(name,year,gender);


          workers.push_back(*employee);
    }
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

CSVReader& CSVReader::operator=(CSVReader&& other){
    this->fin = std::move(other.fin);

    return *this;
}


CSVReader::CSVReader(CSVReader&& other) {
    this->fin = std::move(other.fin);
}
