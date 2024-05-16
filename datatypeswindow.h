// datatypeswindow.h
#ifndef DATATYPESWINDOW_H
#define DATATYPESWINDOW_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include "questions.h"

class DataTypesWindow : public QDialog {
    Q_OBJECT

public:
    explicit DataTypesWindow(QWidget *parent = nullptr);
    ~DataTypesWindow();


private slots:
    void on_nextButton_clicked();
    void on_submitButton_clicked();
    void displayQuestion(QString question, QString a, QString b, QString c, QString d, QString answer);
    void displayFeedback(QString message);

private:
    Questions *questions;
    QLabel *questionLabel;
    QLabel *optionALabel;
    QLabel *optionBLabel;
    QLabel *optionCLabel;
    QLabel *optionDLabel;
    QLineEdit *answerLineEdit;
    QPushButton *submitButton;
    QPushButton *nextButton;
    QLabel *feedbackLabel;
    QString correctAnswer;
    int clickCount = 0;
    void readHighScore();
    void writeHighScore();
    int bestScore = 0;
    int correct = 0;
};

#endif // DATATYPESWINDOW_H
