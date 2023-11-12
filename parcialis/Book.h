//
// Created by Csongor on 11/8/2023.
//

#ifndef PARCIALIS_BOOK_H
#define PARCIALIS_BOOK_H
#include <iostream>
#include <string>

using namespace std;
class Book{
public:

    Book(const string author = " ", const string title = " ", int year = 0, int pages = 0) {
        this->author = author;
        this->title = title;
        this->year = year;
        this->pages = pages;
    }

    void readBook(Book & book1, string title,string author,int year,int pages);

    const string &getAuthor() const;

    void setAuthor(const string &author);

    const string &getTitle() const;

    void setTitle(const string &title);

    int getYear() const;

    void setYear(int year);

    int getPages() const;

    void setPages(int pages);

    void printBook(ostream &stream);

    friend ostream &operator<<(ostream &stream, const Book &book);


private:
    string author;
    string title;
    int year;
    int pages;
};
#endif //PARCIALIS_BOOK_H
