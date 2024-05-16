#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "conditionalwindow.h"
#include <iostream>
#include "questions.h"
#include <random>
#include <ctime>
#include <string>

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_ConLogButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
