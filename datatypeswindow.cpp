// datatypeswindow.cpp
#include "datatypeswindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <fstream>
#include <iostream>
using namespace std;
DataTypesWindow::DataTypesWindow(QWidget *parent)
    : QDialog(parent)
{
    // Initialize Questions object
    questions = new Questions(this);

    // Create QLabel widgets for question and answer options
    questionLabel = new QLabel(this);
    optionALabel = new QLabel(this);
    optionBLabel = new QLabel(this);
    optionCLabel = new QLabel(this);
    optionDLabel = new QLabel(this);

    // Create QLineEdit widget for user input
    answerLineEdit = new QLineEdit(this);

    // Create QPushButton widgets for submit and next buttons
    submitButton = new QPushButton("Submit", this);
    nextButton = new QPushButton("Next", this);

    // Create QLabel widget for feedback message
    feedbackLabel = new QLabel(this);

    // Connect buttons to slots
    connect(submitButton, &QPushButton::clicked, this, &DataTypesWindow::on_submitButton_clicked);
    connect(nextButton, &QPushButton::clicked, this, &DataTypesWindow::on_nextButton_clicked);

    // Defines the layout
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(questionLabel);
    layout->addWidget(optionALabel);
    layout->addWidget(optionBLabel);
    layout->addWidget(optionCLabel);
    layout->addWidget(optionDLabel);
    layout->addWidget(answerLineEdit);
    layout->addWidget(submitButton);
    layout->addWidget(nextButton);
    layout->addWidget(feedbackLabel);

    setLayout(layout);


     // Displays the initial question as part of the constructor
    displayQuestion("What is not a fundamental data type in C++?",
                    "int", "char", "float", "string", "4");

}

DataTypesWindow::~DataTypesWindow() {
    delete questions;
}

void DataTypesWindow::on_nextButton_clicked() {
    clickCount++;
    answerLineEdit->clear();
    displayFeedback("");
    // Call function to get the next question from Questions object
    // For example:
   // questions->getNextQuestion();
    if (clickCount == 1)
    displayQuestion("Which data type is used to store single characters in C++?", /*a*/ "int", /*b*/ "char",
                    /*c*/ "double", /*d*/ "float", "2");
    if (clickCount == 2)
    displayQuestion("Which data type is used to store true or false values in C++?", /*a*/ "int", /*b*/ "char", /*c*/ "bool", /*d*/ "double", "3");
    if (clickCount == 3)
        displayQuestion("What is the main difference between 'float' and 'double' data types in C++?", /*a*/ "'float'"
        "has higher precision than 'double'.", /*b*/ " 'double' has higher precision than 'float'.", /*c*/ "They have the "
        "same precision but different ranges.", /*d*/ "There is no difference; they are interchangeable.", "2");
    if (clickCount == 4)
        displayQuestion("Which of the following is not a valid way to declare a variable in C++?", /*a*/ "int x;", /*b*/ "int x = 5;", /*c*/ "bool on = true;", /*d*/ "float;", "4");
    if (clickCount == 5){
        readHighScore();
        writeHighScore();
        readHighScore();
        questionLabel->setText("Good work!");
        optionALabel->setText(" ");
        optionBLabel->setText("You scored " + QString::number(correct) + " out of 5"); //PRINT HIGH SCORE HERE
        if (correct > bestScore) {
            optionCLabel->setText("Congratulations, you have the new high score! ");
        }
        else if (correct < bestScore) {
            optionCLabel->setText("Nice job, but you can do better!");
        }
        else if (correct == bestScore) {
            optionCLabel->setText("You matched your high score!");
            }
        optionDLabel->setText("Your high score is " + QString::number(bestScore));
        displayFeedback("");
    }
}

void DataTypesWindow::on_submitButton_clicked() {
    QString userInput = answerLineEdit->text().trimmed().toLower(); // Get user's input as a string
    QString correctAnswer = this->correctAnswer.toLower(); // Get correct answer as a string

    // Check if the user's answer matches the correct answer
    if (userInput == correctAnswer) {
        // Display "Correct" message on the feedbackLabel
        displayFeedback("Correct!");
        correct++;
    } else {
        // Display "Incorrect" message on the feedbackLabel
        displayFeedback("Incorrect");
    }
}
void DataTypesWindow::displayQuestion(QString question, QString a, QString b, QString c, QString d, QString answer) {
    questionLabel->setText(question);
    optionALabel->setText("1. " + a);
    optionBLabel->setText("2. " + b);
    optionCLabel->setText("3. " + c);
    optionDLabel->setText("4. " + d);

    correctAnswer = answer;
}

void DataTypesWindow::displayFeedback(QString message) {
    feedbackLabel->setText(message);
}

//reads highest recorded score from a file
void DataTypesWindow::readHighScore(){
    cout << "read working " << endl;
    ifstream inputFile("high_score.txt");
    if (inputFile.is_open()) {
        inputFile >> bestScore;
        inputFile.close();
    }
    else {
        //bestScore = 0;
        cout << "Couldn't open file" << endl;
    }
}
//updates high score if applicable
void DataTypesWindow::writeHighScore(){
    ofstream outputFile("high_score.txt");
    if (outputFile.is_open()) {
        if (correct > bestScore) {
            outputFile << correct;
            cout << "Congratulations, you have the new high score!" << endl;
        }
        if (correct == bestScore) {
            cout << "You tied with your high score! Keep up the good work." << endl;
        }
        outputFile.close();
    }
    else {
        outputFile << bestScore;
        cout << "Couldnt open file " << endl;
    }
}
