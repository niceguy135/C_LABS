#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <employee.h>
#include <csvreader.h>
#include <csvwriter.h>

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


private:
    Ui::MainWindow *ui;

    std::vector<Employee> employes;
};
#endif // MAINWINDOW_H
