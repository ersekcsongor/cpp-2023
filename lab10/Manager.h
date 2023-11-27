//
// Created by Csongor on 11/27/2023.
//

#ifndef LAB10_MANAGER_H
#define LAB10_MANAGER_H
#include <iostream>
#include <vector>
#include "Alkalmazott.h"
#include <algorithm>
using namespace std;
class Manager:public Alkalmazott{
private:
    vector<Alkalmazott>beosztottak;

public:
    Manager(const string &vezetekNev, const string &keresztNev, int szuletesiEv, const string &munkaKor);
    void addAlkalmazott(Alkalmazott* alkalmazott);
    void deleteAlkalmazott(int id);
    virtual void print(ostream& os) const override;
    int beosztottakSzama();
};

#endif //LAB10_MANAGER_H
