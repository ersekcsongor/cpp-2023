//
// Created by Csongor on 11/27/2023.
//

#include "Szemely.h"
void Szemely::print(ostream &os) const {
    os << this->vezetekNev << " " << this->keresztNev << " " << this->szuletesiEv;
}
Szemely::Szemely(const string &vezetekNev, const string &keresztNev, int szuletesiEv) {
    this->vezetekNev = vezetekNev;
    this->keresztNev = keresztNev;
    this->szuletesiEv = szuletesiEv;
}

ostream &operator<<(ostream &os, const Szemely &sz) {
    sz.print(os);
}
