//
// Created by Csongor on 11/27/2023.
//

#include "Alkalmazott.h"


void Alkalmazott::print(ostream &os) const {
    os << id <<" ";
    Szemely::print(os);
    os << " " << munkaKor;
}

Alkalmazott::Alkalmazott(const string &vezetekNev, const string &keresztNev, int szuletesiEv, const string &munkaKor)
        : Szemely(vezetekNev, keresztNev, szuletesiEv), munkaKor(munkaKor) ,id(0){
            static int nextID = 1;
            id = nextID++;
}

const int Alkalmazott::getID() {
    return id;
}
