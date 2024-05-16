#include "mainwindow.h"
#include <iostream>
#include <random>
#include <ctime>
#include <string>

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();

}
