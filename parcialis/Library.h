//
// Created by Csongor on 11/8/2023.
//

#ifndef PARCIALIS_LIBRARY_H
#define PARCIALIS_LIBRARY_H
#include "Book.h"
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <sstream>

class Library {
public:
    void addBook(const Book book1);
    void printLibrary();
    const Book &findBook(const string &searchTerm);
    const int countBooksinLibrary(const string &searchTerm);
    void sortBooksByAuthorAndYear();
    void deleteBookByTitle(const string &title);
    void deleteBookByTitle2(const string &title);
    void beolvasKonyveketFajlbol(const string &fajlnev);
    Book findBookByKeyword(const string &keyword);
    void sortBooksByAuthorsAnyReverseYear();
private:
    vector<Book> library;
};
#endif //PARCIALIS_LIBRARY_H
