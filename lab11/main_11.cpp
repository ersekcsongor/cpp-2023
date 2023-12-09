#include <iostream>
#include <vector>
#include "Student.h"
#include "GraduationDao.h"
#include "StudentService.h"
#include "StudentServiceImpl.h"

int main() {
    std::cout << "Hello, Lab_11" << std::endl;
   /* Student student1(1, "Nagy", "Elemer");
    cout << student1.getFirstName() << endl;
    cout << student1.getLastName() << endl;
    student1.addGrade("math", 5);
    student1.addGrade("hungarian", 5);
    student1.addGrade("romanian", 5);
    cout << student1.getGrade("math") << endl;
    cout << student1.getGrade("hungarian") << endl;
    cout << student1.getGrade("romanian") << endl;
    cout << "******" << endl;
    try {
        cout << student1.getGrade("foldrajz") << endl;
    } catch (out_of_range &e) {
        cout << "Nem letezo tantargy\n";
    }

    map<string, double> jegyek = student1.getGrades();
    for (auto &item: jegyek) {
        cout << item.first << " " << item.second << endl;
    }
    student1.computeAverage();
    cout << "average: " << student1.getAverage() << endl;
    cout << student1 << endl;
    GraduationDao graduationDao1(2021);
    graduationDao1.enrollStudents("names.txt");
    graduationDao1.saveGradesForSubject("math", "math.txt");
    graduationDao1.saveGradesForSubject("hungarian", "hungarian.txt");
    graduationDao1.saveGradesForSubject("romanian", "romanian.txt");
    graduationDao1.computeAverage();
    cout << "Enrolled students number: " << graduationDao1.numEnrolled() << endl;
    cout << "Passed students number: " << graduationDao1.numPassed() << endl;
//    graduationDao1.printStudents(cout);
    try {
        cout << graduationDao1.findById(5435) << endl;
    } catch (out_of_range &e) {
        cout << "Non existent id!" << endl;
    }
    cout << graduationDao1.getAverageBySubject("math") << endl;
    cout << graduationDao1.getAverageBySubject("romanian") << endl;
    cout << graduationDao1.getAverageBySubject("hungarian") << endl;*/
   vector <string> subjects = {"hungarian","romanian","math"};
   int numSubjects = subjects.size();
   GraduationDao dao(2023);
    dao.enrollStudents("names.txt");
    cout << "Number of enrolled students: " << dao.numEnrolled() << endl;
    for (int i = 0; i < numSubjects; ++i) {
        dao.saveGradesForSubject(subjects[i], subjects[i] + ".txt");
    }
    dao.computeAverage();
    cout <<"Number of passed students: " << dao.numPassed() << endl;

    StudentService* service = new StudentServiceImpl(&dao);
    cout << "Individual results: " << endl;
    int id = 0;
    while (id != -1) {
        cout << "Enter ID (-1 for EXIT): ";
        cin >> id;
        if (id == -1) {
            break;
        }
        if (!service->isEnrolled(id)) {
            cout << "Student id=" << id << " not found" << endl;
            continue;
        }
        cout << "Student id=" << id << " results: " << endl;
        bool passed = service->isPassed(id);
        cout << "\tpassed: " << (passed ? "yes" : "no") << endl;
        if (!passed) {
            continue;
        }
        vector<string> subjects = service->getSubjects(id);
        for (int i = 0; i < subjects.size(); ++i) {
            cout << "\t" << subjects[i] << ": " <<
                 service->getResultBySubject(id, subjects[i]) << endl;
        }
        cout << "\taverage: " << service->getAverage(id) << endl;
    }
    delete service;
    return 0;
}