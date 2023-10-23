//
// Created by Csongor on 10/23/2023.
//

#ifndef LAB3_QUESTION_H
#define LAB3_QUESTION_H
#include "string.h"
#include "Answer.h"
#include <vector>
#include <string>

using namespace std;

class Question{
private:
    string text;
    vector<Answer> answers;
public:
   Question() = default;
   const string &getText() const {
       return text;
   }
   const vector<Answer> &getAnswers() const {
       return answers;
   }
   void setText(const string &text) {
       Question::text = text;
   }
   void setAnswers(const vector<Answer> &answers) {
       Question::answers = answers;
   }
    };

#endif //LAB3_QUESTION_H
