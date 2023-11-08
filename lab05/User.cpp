//
// Created by Csongor on 2023. 10. 23..
//

#include "User.h"
User::User(const string &name) {
    int counter = 0;
    this->id = counter++;
    this->name = name;
}
