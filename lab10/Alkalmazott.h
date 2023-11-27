//
// Created by Csongor on 11/27/2023.
//

#ifndef LAB10_ALKALMAZOTT_H
#define LAB10_ALKALMAZOTT_H
#include <iostream>
#include "Szemely.h"

using namespace std;
class Alkalmazott:public Szemely{
private:
    string munkaKor;

protected:
    int id;

public:
    Alkalmazott(const string &vezetekNev, const string &keresztNev, int szuletesiEv, const string &munkaKor);
    virtual void print(ostream& os) const override;
    const int getID();
};
#endif //LAB10_ALKALMAZOTT_H
