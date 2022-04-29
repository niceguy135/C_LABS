#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <chrono>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //открыть файл
    CSVReader csv("C:\\Qt\\Programming\\Lab2\\employee.txt"); //ставлю абсолютный путь. Нужно поменять, когда будете запускать на своем копьютере.
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
            ui->textBrowser->append("Number: " + QString::fromStdString(std::to_string(e.num)) + ", "
                                    + "Name: " + e.name + ", "
                                    + "Year of birth: " + QString::fromStdString(std::to_string(e.year)) + ", "
                                    + "Gender: " + (e.gender==0 ? "Male" : "Female") + "." );
        }
    }
    if(!flag)
        ui->textBrowser->append("Employee doesn`t found!");
}
