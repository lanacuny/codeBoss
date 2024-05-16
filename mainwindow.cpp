#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "conditionalwindow.h"

#include "datatypeswindow.h"
#include<iostream>
using namespace std;

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

void MainWindow::on_pushButton_clicked()
{
    cout << "Test 1";
    DataTypesWindow dtypes;
    dtypes.setModal(true);
    dtypes.exec();
    cout << "Test 2";
}
