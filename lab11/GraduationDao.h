//
// Created by Csongor on 12/4/2023.
//

#ifndef LAB11_GRADUATIONDAO_H
#define LAB11_GRADUATIONDAO_H
#include "Student.h"
#include <fstream>
#include <sstream>
class GraduationDao {
    int year{2023};
    map<int, Student> students;
public:
    explicit GraduationDao(int year) : year(year) {}
    void enrollStudents(const string &filename);
    void saveGradesForSubject(const string &subject, const string &filename);
    void computeAverage();
    int numEnrolled() const;
    int numPassed() const;
// throws out_of_range exception for nonexistent id
    Student findById(int id) const;
    double getAverageBySubject(const string &subject) const;
    void printStudents(ostream &os);
};
#endif //LAB11_GRADUATIONDAO_H
