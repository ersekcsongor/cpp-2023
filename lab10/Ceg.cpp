//
// Created by Csongor on 11/28/2023.
//

#include <algorithm>
#include "Ceg.h"
#include "Manager.h"

void Ceg::hireEmployees(Alkalmazott *alkalmazott) {
    alkalmazottak.push_back(alkalmazott);

    Manager *manager = dynamic_cast<Manager*>(alkalmazott);
    if(manager)
    {
        const vector<Alkalmazott*> &managed = manager->getManagedEmployees();
        for(Alkalmazott* employee : managed)
        {
            alkalmazottak.push_back(employee);
        }
    }
}

void Ceg::fireEmployees(int id) {
    auto it = find_if(alkalmazottak.begin(),alkalmazottak.end(),[id](Alkalmazott* alkalmazott){
       return alkalmazott->getID() == id;
    });
    if(it != alkalmazottak.end())
    {
        alkalmazottak.erase(it);
//        delete *it;
    }
    else{
        cout << "Nincs ilyen azonositoju alkalmazott!"<< endl;
    }
}


void Ceg::printManagers(ostream& os) {
    os << "Ceg neve: " << name << endl;
    for(Alkalmazott* alkalmazott : alkalmazottak)
    {
        if(!(dynamic_cast<Manager*>(alkalmazott) == nullptr))
        alkalmazott->print(os);
    }
}

Ceg::Ceg(string name) : name (name){

}

void Ceg::printEmployees(ostream &os) {
    os << "Ceg neve: " << name << endl;
    for(Alkalmazott* alkalmazott : alkalmazottak)
    {
        if((dynamic_cast<Manager*>(alkalmazott) == nullptr))
            alkalmazott->print(os);
            os << endl;
    }
}








/*void Ceg::print(ostream os) {
    os << "Ceg" << name;
    for(Alkalmazott* alkalmazott : alkalmazottak)
    {
        alkalmazott->print(os);
    }
}*/


