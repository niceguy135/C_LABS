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
    CSVWriter fout("C:\\Qt\\Programming\\Labs\\Lab4\\new_employee.txt");
    fout.writeIn(employes);
    ui->textBrowser->append("Изменения были успешно сохранены!\n");
}

void MainWindow::findFile() {
    QString filename = QFileDialog::getOpenFileName(this, tr("Open file"),
                                                    "\\Qt\\Programming\\Labs\\Lab5");

    std::cout << filename.toStdString();

    if(filename != "") {
        if(filename.toStdString().find(".csv") != -1) {
            CSVReader csv(filename);
            MainWindow::readFunc(csv);
            ui->textBrowser->writeGreen("Прочитал текст из CSV файла!");

        }
        else if(filename.toStdString().find(".json") != -1) {
            JSONReader json(filename);
            ui->textBrowser->writeGreen("Прочитал текст из JSON файла!");

        } else ui->textBrowser->writeRed("Вы выбрали не читаемые файлы!");

    } else {
        ui->textBrowser->writeRed("Вы не выбрали откуда читать текст!");
    }
}

void MainWindow::readFunc(AbstarctReader& file) {
    if (file.is_open()) {
        Employee::class_num = 1;
        this->employes = file.readAll();
    } else {
        ui->textBrowser->writeGreen("Не смог открыть файл!");
    }
}
