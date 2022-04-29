#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <abstarctreader.h>
#include <employee.h>
#include <csvreader.h>
#include <csvwriter.h>
#include <jsonreader.h>
#include <QFileDialog>
#include <iostream>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void findEmployee();
    void addEmployee();
    void saveFile();
    void findFile();
    void readFunc(AbstarctReader& csv);
    void sortEmployees(std::vector<Employee>& vector);
    void demonstrateCSV();
    void demonstrateJSON();


private:
    Ui::MainWindow *ui;

    std::vector<Employee> employes;
    bool is_CSV;
};
#endif // MAINWINDOW_H
