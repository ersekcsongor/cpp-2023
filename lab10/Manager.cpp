//
// Created by Csongor on 11/27/2023.
//

#include "Manager.h"

Manager::Manager(const string &vezetekNev, const string &keresztNev, int szuletesiEv, const string &munkaKor)
        : Alkalmazott(vezetekNev, keresztNev, szuletesiEv, munkaKor) {}

void Manager::addAlkalmazott(Alkalmazott *alkalmazott) {
    beosztottak.push_back(*alkalmazott);
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
    auto it = find_if(beosztottak.begin(), beosztottak.end(), [id](Alkalmazott& alkalmazott) {
        return alkalmazott.getID() == id;
    });

    if (it != beosztottak.end()) {
        beosztottak.erase(it);
    }
}

void Manager::print(ostream &os) const {
    os << "Manager neve: ";
    Alkalmazott::print(os);
    os << endl;
    os << "Beosztottak: \n";
    for(auto beosztott : beosztottak)
    {
        beosztott.print(os);
        os << endl;
    }
}

int Manager::beosztottakSzama() {
    return (int)beosztottak.size();
}

