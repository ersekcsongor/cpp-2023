#include <iostream>
#include "Szemely.h"
#include "Alkalmazott.h"
#include "Manager.h"
#include "Ceg.h"

int main() {
   /* Szemely szemely1("John", "Doe", 1990);
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
    cout << endl;
    Ceg ceg1("3ss");
    Manager manager2("Dezso","Elemer",1985,"manager");
    manager2.addAlkalmazott(&alkalmazott1);
    ceg1.hireEmployees(&manager2);
    ceg1.hireEmployees(&manager1);
    ceg1.print(cout);
    ceg1.fireEmployees(4);
    ceg1.print(cout);
    manager1.deleteAlkalmazott(2);
    ceg1.print(cout);*/
    Ceg ceg1("Lynx Solutions");
    Alkalmazott alkalmazott1("Kis", "Csaba", 1993, "programozo");
    Alkalmazott alkalmazott2("Madarasz", "Adam", 1987, "programozo");
    Alkalmazott alkalmazott3("Nagy", "Anna", 1990, "tervezo");
    Alkalmazott alkalmazott4("Kovacs", "Bela", 1985, "tesztelo");
    Alkalmazott alkalmazott5("Toth", "Eva", 1980, "HR");
    Alkalmazott alkalmazott6("Szabo", "Gabor", 1982, "projektvezeto");
    Alkalmazott alkalmazott7("Varga", "Judit", 1995, "analitikus");

    Manager manager1("Kovacs", "Gabor", 1987, "team leader");
    Manager manager2("Toth", "Erika", 1990, "project manager");
    Manager manager3("Szabo", "Peter", 1982, "department head");

    ceg1.hireEmployees(&alkalmazott1);
    ceg1.hireEmployees(&alkalmazott2);
    ceg1.hireEmployees(&alkalmazott3);
    ceg1.hireEmployees(&alkalmazott4);
    ceg1.hireEmployees(&alkalmazott5);
    ceg1.hireEmployees(&alkalmazott6);
    ceg1.hireEmployees(&alkalmazott7);

    ceg1.printEmployees(cout);

    manager1.addAlkalmazott(&alkalmazott1);
    manager1.addAlkalmazott(&alkalmazott2);
    manager2.addAlkalmazott(&alkalmazott3);
    manager2.addAlkalmazott(&alkalmazott4);
    manager2.addAlkalmazott(&alkalmazott5);
    manager3.addAlkalmazott(&alkalmazott6);
    manager3.addAlkalmazott(&alkalmazott7);

    ceg1.hireEmployees(&manager1);
    ceg1.hireEmployees(&manager2);
    ceg1.hireEmployees(&manager3);

    cout << endl;

    ceg1.printManagers(cout);

    manager1.deleteAlkalmazott(1);
    manager2.addAlkalmazott(&alkalmazott1);

    ceg1.printManagers(cout);
    return 0;
}