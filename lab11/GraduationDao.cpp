//
// Created by Csongor on 12/4/2023.
//

#include "GraduationDao.h"

void GraduationDao::enrollStudents(const string &filename) {
    ifstream file(filename);
    if(file.is_open()){
        string line;
        while(getline(file,line))
        {
            istringstream iss(line);
            int id;
            string firstName,lastName;
            iss >> id >> firstName >> lastName;

            Student newStudent(id,firstName,lastName);

            students[id] = newStudent;
        }
        file.close();
    } else
    {
        cout << "Unable to open file!" << endl;
        return;
    }
}

void GraduationDao::saveGradesForSubject(const string &subject, const string &filename) {
    ifstream file(filename);
    cout << "Grades saved for subject: " << subject << endl;
    if (file.is_open()) {
        int id;
        double grade;
        while (file >> id >> grade) {
            if (students.find(id) != students.end()) {
                students[id].addGrade(subject, grade);
            }
        }
        file.close();
    } else {
        cout << "Unable to open file! " << filename << endl;
        return;
    }
}


void GraduationDao::computeAverage() {
    for ( auto &studentPair : students)
    {
        studentPair.second.computeAverage();
    }
}

int GraduationDao::numEnrolled() const {
    students.size();
}

void GraduationDao::printStudents(ostream &os) {
    for(auto &student :students)
    {
        os << student.second << endl;
    }
}

int GraduationDao::numPassed() const {
    int numPassed = 0;
    for(auto &student : students)
    {
        if(student.second.getAverage() != 0)
        {
            numPassed++;
        }
    }
    return numPassed;
}

Student GraduationDao::findById(int id) const {
    auto it = students.find(id);
    if(it != students.end())
    {
        return it->second;
    }
    else throw out_of_range("Non existent Student!");
}

double GraduationDao::getAverageBySubject(const string &subject) const {
    double sum = 0;
    for(auto &student : students)
    {
        auto grades = student.second.getGrades();
        for(auto grade : grades)
        {
            if(subject == grade.first)
            {
                sum += grade.second;
            }
        }
    }
    return sum/students.size();
}



