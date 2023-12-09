//
// Created by Csongor on 12/8/2023.
//

#include "StudentServiceImpl.h"

bool StudentServiceImpl::isEnrolled(int id) const {
    try{
        dao->findById(id);
        return true;
    }catch (const out_of_range&)
    {
        return false;
    }
}

vector<string> StudentServiceImpl::getSubjects(int id) const {
    vector<string>subjects;
    auto& grades = dao->findById(id).getGrades();
    for(auto &pair : grades)
    {
        subjects.push_back(pair.first);
    }
    return subjects;
}

double StudentServiceImpl::getResultBySubject(int id, const string &subject) const {
    return dao->findById(id).getGrade(subject);
}

double StudentServiceImpl::getAverage(int id) const {
    return dao->findById(id).getAverage();
}

bool StudentServiceImpl::isPassed(int id) const {
    return dao->findById(id).getAverage() >= 6.0;
}
