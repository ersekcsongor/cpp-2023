//
// Created by Csongor on 10/23/2023.
//

#ifndef LAB3_QUIZ_H
#define LAB3_QUIZ_H

#include "Question.h"

class Quiz {
private:
    string name;
    vector<Question> questions;

public:
    Quiz(const string &name,const string &filename);

    const Question &getQuestion(int index) const;

    int getNumQuestions() const{
        return questions.size();
    };
};
#endif //LAB3_QUIZ_H
