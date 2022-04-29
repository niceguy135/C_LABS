#include "csvwriter.h"

CSVWriter::CSVWriter(const std::string& filename)
{
     this->fout.open(filename);
}

CSVWriter::~CSVWriter()
{
     this->fout.close();
}

void CSVWriter::writeIn(std::vector<Employee> workers) {
    if(this->fout.is_open()) {
            for( auto worker:workers ) {
                this->fout << worker.getNum() << ';' << worker.name.toStdString() << ';' << worker.year << ';' << worker.gender << std::endl;

            }
        }
}
