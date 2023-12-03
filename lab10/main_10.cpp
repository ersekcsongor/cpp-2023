#include <iostream>
#include "Szemely.h"
#include "Alkalmazott.h"
#include "Manager.h"
#include "Ceg.h"

int main() {

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