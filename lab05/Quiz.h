//
// Created by Csongor on 2023. 10. 23..
//

#ifndef CPP_2022_QUIZ_H
#define CPP_2022_QUIZ_H

#include "Question.h"

class Quiz {
private:
    string name;
    vector<Question> questions;
public:
    Quiz(const string &name, const string &filename);
    const Question &getQuestion(int index) const;
    int getNumQuestions() const{
        return questions.size();
    }
    const string &getName() const {
        return name;
    }
};

#endif //CPP_2022_QUIZ_H
