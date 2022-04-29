#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //открыть файл
    CSVReader csv("C:\\Qt\\Programming\\Labs\\Lab4\\employee.txt"); //ставлю абсолютный путь. Нужно поменять, когда будете запускать на своем копьютере.
    if (csv.is_open()) {
    //Прочитать из файла вектор
        employes = csv.readAll();
    }


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
    CSVWriter fout("C:\\Qt\\Programming\\Labs\\Lab4\\new_employee.txt");
    fout.writeIn(employes);
    ui->textBrowser->append("Изменения были успешно сохранены!\n");
}


