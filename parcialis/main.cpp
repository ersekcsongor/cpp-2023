#include <iostream>
#include "Book.h"
#include "Library.h"
#include <string>

void feladat1();
void feladat2();


int main() {
//    feladat1();
    feladat2();
    return 0;
}

void feladat1()
{
    Book *book1 = new Book ("Elek","Macskasag",2012,68);
    Book *book2 = new Book ("J. K. Rowling","Harry Potter es a bolcsek kove",2003,234);
    Book *book3 = new Book ("Elek","Kutyuska",2013,88);
    book1->printBook(cout);
    cout <<"\n--------------------------\n";
    cout << *book1;
    cout <<"\n--------------------------\n";
    Library konyvtar;
    konyvtar.addBook(*book1);
    konyvtar.addBook(*book2);
    konyvtar.addBook(*book3);
    konyvtar.printLibrary();
    cout <<"\n--------------------------\n";
    try {
        Book foundBook = konyvtar.findBook("Macskasag");
        cout << foundBook;
    }catch (const runtime_error &e){
        cout << e.what() << endl;
    }
    cout << konyvtar.countBooksinLibrary("Elek");
    cout <<"\n--------------------------\n";
    cout <<"\n--------------------------\n";
    cout <<"\n--------------------------\n";
    konyvtar.printLibrary();
    cout <<"\n--------------------------\n";
    cout <<"\n--------------------------\n";
    cout <<"\n--------------------------\n";
    konyvtar.sortBooksByAuthorAndYear();
    konyvtar.printLibrary();
    konyvtar.deleteBookByTitle2("Macskasag");
    konyvtar.deleteBookByTitle2("Kutyuska");
    cout <<"\n--------------------------\n";
    konyvtar.printLibrary();
}


void feladat2()
{
    Library library1;
    library1.beolvasKonyveketFajlbol("konyvek.txt");
    cout << "A konyvtar kiiratasa: " << endl;
    library1.printLibrary();
    int count = library1.countBooksinLibrary("Murakami Haruki");
    cout << endl <<"A megadott szerzo konyveinek szama: " << count << endl << endl;
    Book keyBook;
    string keyword;
    cout << "Ird be a kivant cim kulcsszavat!" ;
    getline(cin,keyword);
    cout << endl;
    try{
    keyBook = library1.findBookByKeyword(keyword);
    }catch (const runtime_error &e){
        cout << e.what() << endl;
    }
    cout << keyBook << endl;
    cout << "A szerzok szerint abc sorrendben es a kiadasi ev szerint csokkeno sorrendben!" << endl;
    library1.sortBooksByAuthorsAnyReverseYear();
    cout <<"\n--------------------------\n";
    library1.printLibrary();
    cout << "Ird be a kivant cimet amit torolni szeretne!" ;
    string keyword2;
    getline(cin,keyword2);
    cout << endl;
    library1.deleteBookByTitle2(keyword2);
    cout <<"\n--------------------------\n";
    cout <<"\n--------------------------\n";
    cout <<"\n--------------------------\n";
    cout << "A meglevo konyvek kiratasa: " << endl;
    library1.printLibrary();
}