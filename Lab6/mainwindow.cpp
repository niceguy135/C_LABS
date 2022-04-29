#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::findEmployee() {

    bool flag = false;
    for (const auto &e: employes) {
        if (e.name == ui->editSearch->text()) {
            flag = true;
            ui->textBrowser->writeGreen("Работник был успешно найден!");
            ui->textBrowser->writeGreen("ID: " + QString::fromStdString(std::to_string(e.getNum())) + ", "
                                    + "Name: " + e.name + ", "
                                    + "Year of birth: " + QString::fromStdString(std::to_string(e.year)) + ", "
                                    + "Gender: " + (e.gender==0 ? "Male" : "Female") + "." );
        }
    }
    if(!flag)
        ui->textBrowser->writeRed("Employee doesn`t found!");
}

void MainWindow::addEmployee() {
                        // буду добавлять прямо из значений формы в объект
    auto name = ui->putName->text();

    auto year = ui->putYear->text().toUInt();
    auto gender = static_cast<Gender>(ui->genderBox->currentIndex());

    auto employee = new Employee(name,year,gender);

    employes.push_back(*employee);

    ui->textBrowser->append("Работник был успешно добален!\nСписок всех работников:");

    for (const auto &e: employes) {
            ui->textBrowser->append("ID: " + QString::fromStdString(std::to_string(e.getNum())) + ", "
                                    + "Name: " + e.name + ", "
                                    + "Year of birth: " + QString::fromStdString(std::to_string(e.year)) + ", "
                                    + "Gender: " + (e.gender==0 ? "Male" : "Female") + "." );
    }
    ui->textBrowser->append("\n");
}

void MainWindow::saveFile() {
    CSVWriter fout("C:\\Qt\\Programming\\Labs\\Lab6\\new_employee.txt");
    fout.writeIn(employes);
    ui->textBrowser->append("Изменения были успешно сохранены!\n");
}

void MainWindow::findFile() {
    QString filename = QFileDialog::getOpenFileName(this, tr("Open file"),
                                                    "\\Qt\\Programming\\Labs\\Lab6");

    std::cout << filename.toStdString();

    if(filename != "") {
        if(filename.toStdString().find("json") != -1) {
            JSONReader json(filename);
            MainWindow::readFunc(json);
            MainWindow::demonstrateJSON();
            ui->textBrowser->writeGreen("Прочитал текст из JSON файла!");


        }
        else if(filename.toStdString().find(".csv") != -1) {
                CSVReader csv(filename);
                MainWindow::readFunc(csv);
                MainWindow::demonstrateCSV();
                ui->textBrowser->writeGreen("Прочитал текст из CSV файла!");

        } else ui->textBrowser->writeRed("Вы выбрали не читаемые файлы!");

    } else {
        ui->textBrowser->writeRed("Вы не выбрали откуда читать текст!");
    }
}

void MainWindow::readFunc(AbstarctReader& file) {
    if (file) {
        Employee::class_num = 1;
        this->employes = file.readAll();
        MainWindow::sortEmployees(this->employes);
    } else {
        ui->textBrowser->writeGreen("Не смог открыть файл!");
    }
}

void MainWindow::sortEmployees(std::vector<Employee>& vector) {
    for (int i = 0; i < int(vector.size()); i++) {
        for (int j = 0; j < int(vector.size())-1; j++) {
          if (vector[j+1] < vector[j]) {
            auto b = vector[j]; // создали дополнительную переменную
            vector[j] = std::move(vector[j + 1]); // меняем местами
            vector[j + 1] = std::move(b); // значения элементов
          }
        }
      }
}

void MainWindow::demonstrateCSV(){
    CSVReader csvData("C:\\Qt\\Programming\\Labs\\Lab6\\employee.csv");
    Employee* employee = new Employee("",0,male);
    std::string last_name = "";
    std::cout << std::endl;

    while(csvData >> *employee){
        std::cout << *employee << std::endl;

        if (last_name == employee->name.toStdString()) {
            break;
        }

        last_name = employee->name.toStdString();
    }
}

void MainWindow::demonstrateJSON() {
    JSONReader jsonData("C:\\Qt\\Programming\\Labs\\Lab6\\jsonEmployee.json");
    Employee* employee = new Employee("",0,male);
    std::string last_name = "";
    std::cout << std::endl;

    while(jsonData >> *employee){
        std::cout << *employee << std::endl;

        if (last_name == employee->name.toStdString()) {
            break;
        }

        last_name = employee->name.toStdString();
    }
}
