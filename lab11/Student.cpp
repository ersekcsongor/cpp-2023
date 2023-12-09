//
// Created by Csongor on 12/4/2023.
//

#include "Student.h"

Student::Student(int id, const string &firstName, const string &lastName):id(id),firstName(firstName),lastName(lastName) {
}

int Student::getId() const {
    return id;
}

void Student::setId(int id) {
    this->id = id;
}

const string &Student::getFirstName() const {
    return firstName;
}

const string &Student::getLastName() const {
    return lastName;
}

void Student::addGrade(const string &subject, double grade) {
    grades[subject] = grade;
}

double Student::getGrade(const string &subject) {
    return grades.at(subject);
}

const map<string, double> &Student::getGrades() const {
    return grades;
}

void Student::computeAverage() {
    double sum = 0;
    for(auto &item : grades)
    {
        if(item.second < 5)
            return;
        sum += item.second;
    }
    double avg = sum/grades.size();
    if(avg >= 6)
    {
        this->average = avg;
    }

}

double Student::getAverage() const {
    return average;
}

ostream &operator<<(ostream &os, const Student &student) {
    os << "FirstName: " << student.firstName << endl;
    os << "LastName: " << student.lastName << endl;
    os << "ID: " << student.id << endl;
    os << "Grades:" << endl;
    map<string,double> jegyek = student.getGrades();
    for(auto &item : jegyek)
    {
        cout << "\t"<< item.first << " " << item.second << endl;
    }
    os << "Average: " << student.getAverage();
    return os;
}
