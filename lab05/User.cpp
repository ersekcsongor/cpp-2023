//
// Created by Csongor on 2023. 11. 06..
//

#include "User.h"

int User::counter = 1;

User::User(const string &name) {
    this->id = counter++;
    this->name = name;
}

int User::getId() const {
    return this->id;
}

const string &User::getName() const {
    return this->name;
}

void User::addScore(const string &quizName, double score) {
    this->scores[quizName] = score;
}

double User::getScore(const string &quizName) const {
    return this->scores.at(quizName);
}

void User::print(ostream &os) const {
    os << "User " << this->id << ": " << this->name << endl;
    for(auto& score : this->scores){
        os << score.first << ": " << score.second << endl;
    }
}

ostream &operator<<(ostream &os, const User &user) {
    user.print(os);
    return os;
}
