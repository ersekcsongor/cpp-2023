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
    Book(const string author, const string title, int year, int pages) {
        this->author = author;
        this->title = title;
        this->year = year;
        this->pages = pages;
    }

    Book readBook(Book &book1,string title, string author, int year, int pages)
    {
        book1.setTitle(title);
        book1.setAuthor(author);
        book1.setYear(year);
        book1.setPages(pages);
        return book1;
    }

    const string &getAuthor() const {
        return author;
    }

    const string &getTitle() const {
        return title;
    }

    int getYear() const {
        return year;
    }

    int getPages() const {
        return pages;
    }

    void setAuthor(const string &author) {
        Book::author = author;
    }

    void setTitle(const string &title){
        Book::title = title;
    }

    void setYear(int year) {
        Book::year = year;
    }

    void setPages(int pages){
        Book::pages = pages;
    }

    void printBook(ostream &stream)
    {
        stream << "--------------------" << endl;
        stream << "Szerzo: " << author << endl;
        stream << "Cim: " << title << endl;
        stream << "Kiadasi ev: " << year << endl;
        stream << "Oldalak szama: " << pages << endl;
    }

    friend std::ostream& operator<<(ostream& os,const Book &book1)
    {
        os << "Szerzo: " << book1.author << endl;
        os << "Cim: " << book1.title << endl;
        os << "Kiadasi ev: " << book1.year << endl;
        os << "Oldalak szama: " << book1.pages << endl;
        return os;
    }
private:
    string author;
    string title;
    int year;
    int pages;
};
#endif //PARCIALIS_BOOK_H
