// questions.cpp
#include "questions.h"
#include <iostream>
using namespace std;

Questions::Questions(QObject *parent) : QObject(parent), correct(0), bestScore(0) {}

Questions::~Questions() {}

void Questions::askQuestion(QString question, QString a, QString b, QString c, QString d, QChar correctAnswer) {
    emit questionAsked(question, a, b, c, d); // Emit signal with question and answer options
    // You can store correctAnswer and perform validation when user submits answer
}


//reads highest recorded score from a file moved
/*void Questions::readHighScore(){
    ifstream inputFile("best_score.txt");
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
void Questions::writeHighScore(){
    ofstream outputFile("best_score.txt");
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

*/
