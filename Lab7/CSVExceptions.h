#ifndef CSVEXCEPTIONS_H
#define CSVEXCEPTIONS_H

#include <stdexcept>

class CSVExceptions : public std::exception { //класс обработки ошибок для CSVReader
public:
    CSVExceptions(std::string mes, int num) {
        this->message = mes;
        this-> num_stroki = num;
    }
    std::string what() {
        std::string result = "Problem: " + message +
                "\nIn line number: " + std::to_string(num_stroki);
        return result;
    }
private:
    std::string message;
    int num_stroki;
};

#endif // CSVEXCEPTIONS_H
