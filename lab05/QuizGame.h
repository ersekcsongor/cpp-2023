//
// Created by Csongor on 2023. 10. 23..
//

#ifndef CPP_2022_QUIZGAME_H
#define CPP_2022_QUIZGAME_H

#include "Quiz.h"
#include "User.h"

class QuizGame {
private:
    User& user;
    const Quiz& quiz;
    double score = 0;
public:
    QuizGame(User& user, const Quiz &quiz) : user(user), quiz(quiz){}
    void play();
    double getScore() const { return score; }
    User getUser() const { return user; }
    Quiz getQuiz() const { return quiz; }
};

#endif //CPP_2022_QUIZGAME_H
