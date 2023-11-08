//
// Created by Csongor on 2023. 10. 23..
//

#include "QuizGame.h"
#include <iostream>
#include <sstream>

void QuizGame::play() {
    for(int i = 0; i < quiz.getNumQuestions(); i++){
        cout << quiz.getQuestion(i).getText() << endl;
        for(int j = 0; j < quiz.getQuestion(i).getAnswers().size(); j++){
            cout << j + 1 << ". " << quiz.getQuestion(i).getAnswers()[j].getText() << endl;
        }
        int answer;
        cin >> answer;
        if(quiz.getQuestion(i).getAnswers()[answer - 1].isCorrect()){
            score++;
            cout << "Correct!" << endl;
        }
        else{
            cout << "Wrong!" << endl;
            cout << "The correct answer is number ";
            for(int j = 0; j < quiz.getQuestion(i).getAnswers().size(); j++){
                if(quiz.getQuestion(i).getAnswers()[j].isCorrect()){
                    cout << j + 1 << ' ';
                }
            }
            cout << endl;
        }
    }
    cout << "Your score is " << score << endl;
}
