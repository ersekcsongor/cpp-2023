#include <iostream>
#include "Szemely.h"
#include "Alkalmazott.h"
#include "Manager.h"

int main() {
    Szemely szemely1("John", "Doe", 1990);
    szemely1.print(cout);
    cout << endl;
    cout <<  szemely1 << endl;
    Alkalmazott alkalmazott1("Kis","Csaba",1993,"programozo");
    Alkalmazott alkalmazott2("Madarasz","Adam",1987,"programozo");
    alkalmazott1.print(cout);
    cout << endl;
    cout << alkalmazott1 << endl;
    Manager manager1("Nagy","Pal",1995,"manager");
    manager1.addAlkalmazott(&alkalmazott1);
    manager1.addAlkalmazott(&alkalmazott2);
//    manager1.print(cout);
//    cout << endl;
    cout << manager1;
    cout << endl;
    manager1.deleteAlkalmazott(1);
    cout << manager1;
    cout << endl;
    cout << "Beosztottak szama: " << manager1.beosztottakSzama();
    cout << endl;
    cout << alkalmazott1.getID();
    cout << endl;
    cout << alkalmazott2.getID();
    return 0;
}