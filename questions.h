// questions.h
#ifndef QUESTIONS_H
#define QUESTIONS_H

#include <QObject> // Include QObject for signals and slots
#include <string>
#include <fstream>

class Questions : public QObject {
    Q_OBJECT // Required for signals and slots support

public:
    explicit Questions(QObject *parent = nullptr);
    ~Questions();

    void askQuestion(QString question, QString a, QString b, QString c, QString d, QChar correctAnswer);
    void readHighScore();
    void writeHighScore();

signals:
    void questionAsked(QString question, QString a, QString b, QString c, QString d); // Signal to emit question to UI
    void feedbackMessage(QString message); // Signal to emit feedback message to UI

private:
    int correct;
    int bestScore;
};

#endif // QUESTIONS_H
