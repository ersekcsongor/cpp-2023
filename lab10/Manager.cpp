//
// Created by Csongor on 11/27/2023.
//

#include "Manager.h"

const string Manager::MANAGER_MUNKAKOR = "manager";

Manager::Manager(const string &vezetekNev, const string &keresztNev, int szuletesiEv, const string &munkaKor)
        : Alkalmazott(vezetekNev, keresztNev, szuletesiEv, munkaKor) {}

void Manager::addAlkalmazott(Alkalmazott *alkalmazott) {
    beosztottak.push_back(alkalmazott);
}

/*void Manager::deleteAlkalmazott(Alkalmazott* alkalmazott) {
    auto it = find_if(beosztottak.begin(), beosztottak.end(), [alkalmazott](const Alkalmazott& emp) {
        return &emp == alkalmazott;
    });

    if (it !  beosztottak.end()) {
        beosztottak.erase(it);
    }
}*/

void Manager::deleteAlkalmazott(int id){
    auto it = find_if(beosztottak.begin(), beosztottak.end(), [id](Alkalmazott* alkalmazott) {
        return alkalmazott->getID() == id;
    });

    if (it != beosztottak.end()) {
        beosztottak.erase(it);
    }
}

void Manager::print(ostream &os) const {
    os << "Manager: "<< id <<" ";
    Szemely::print(os);
    os << " ";
    os << "beosztottjai: \n";
    for(auto beosztott : beosztottak)
    {
        os <<"\t";
        beosztott->print(os);
        os << endl;
    }
}

int Manager::beosztottakSzama() {
    return (int)beosztottak.size();
}

const vector<Alkalmazott *> &Manager::getManagedEmployees() const {
    return beosztottak;
}

/*Manager::~Manager() {
    for(Alkalmazott* alkalmazott : beosztottak)
    {
        delete alkalmazott;
    }
    beosztottak.clear();
}*/

