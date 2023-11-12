//
// Created by Csongor on 11/9/2023.
//
#include <iostream>
#include "Book.h"




void Book:: readBook(Book & book1, string title,string author,int year,int pages)
{
    book1.setTitle(title);
    book1.setAuthor(author);
    book1.setYear(year);
    book1.setPages(pages);
}

const string &Book::getAuthor() const {
    return author;
}

void Book::setAuthor(const string &author) {
    Book::author = author;
}

const string &Book::getTitle() const {
    return title;
}

void Book::setTitle(const string &title) {
    Book::title = title;
}

int Book::getYear() const {
    return year;
}

void Book::setYear(int year) {
    Book::year = year;
}

int Book::getPages() const {
    return pages;
}

void Book::setPages(int pages) {
    Book::pages = pages;
}

void Book:: printBook(ostream &stream) {
    stream << "--------------------" << endl;
    stream << "Szerzo: " << author << endl;
    stream << "Cim: " << title << endl;
    stream << "Kiadasi ev: " << year << endl;
    stream << "Oldalak szama: " << pages << endl;
}

ostream &operator<<(ostream &os, const Book &book) {
        os << "Szerzo: " << book.author << endl;
        os << "Cim: " << book.title << endl;
        os << "Kiadasi ev: " << book.year << endl;
        os << "Oldalak szama: " << book.pages << endl;
        return os;
}


