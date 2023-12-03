//
// Created by Csongor on 11/28/2023.
//

#ifndef LAB10_CEG_H
#define LAB10_CEG_H

#include <vector>
#include "Alkalmazott.h"
#include "Manager.h"
using namespace std;
class Ceg {
private:
    string name;
    vector<Alkalmazott*> alkalmazottak;
public:
    Ceg(string name);
    void hireEmployees(Alkalmazott* alkalmazott);
    void fireEmployees(int id);
    void printManagers(ostream& os);
    void printEmployees(ostream& os);
//    void addEmployeetToManager(Alkalmazott *alkalmazott,Manager* manager);
};
#endif //LAB10_CEG_H
