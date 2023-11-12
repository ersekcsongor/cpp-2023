//
// Created by Csongor on 11/9/2023.
//
#include "Library.h"
#include "Book.h"


void Library::addBook(const Book book1) {
    library.push_back(book1);
}

void Library::printLibrary() {
    for (int i = 0; i < library.size(); ++i) {
        library[i].printBook(cout);
    }
}

const Book &Library::findBook(const string &searchTerm) {
    for (int i = 0; i < library.size(); ++i) {
        if ((library[i].getAuthor() == searchTerm) || (library[i].getTitle() == searchTerm))
            return library[i];
    }
    throw runtime_error("Nincs ilyen book a konyvtarban!");
}


const int Library::countBooksinLibrary(const string &searchTerm) {
    int count = 0;
    for (Book book: library) {
        if (book.getAuthor() == searchTerm) {
            count++;
        }
    }
    return count;
}

void Library::sortBooksByAuthorAndYear() {
    sort(library.begin(), library.end(), [](const Book book1, const Book book2) {
             if (book1.getAuthor() == book2.getAuthor()) {
                 return book1.getYear() > book2.getYear();
             }
             return book1.getAuthor() < book2.getAuthor();
         }
    );
}

void Library::deleteBookByTitle(const string &title) {
    auto it = remove_if(library.begin(), library.end(), [&](const Book book1) {
        return book1.getTitle() == title;
    });

    if (it != library.end()) {
        library.erase(it, library.end());
    }
}

void Library::deleteBookByTitle2(const string &title) {
    Book book1;
    int index = -1;
    for (int i = 0; i < library.size(); ++i) {
        if (library[i].getTitle() == title) {
            index = i;
        }
    }
    if (index != -1) {
        library.erase(library.begin() + index);
    } else {
        cout << "Nem talahato ilyen cimu alkotas\n";
        return;
    }
}


void Library::beolvasKonyveketFajlbol(const string &fajlnev) {
    ifstream file(fajlnev);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string author, title;
            int year, pages;
            getline(ss, author, ',');
            getline(ss, title, ',');
            // Eltávolítjuk a "-t a szerzőből
            author.erase(remove(author.begin(), author.end(), '\"'), author.end());

            // Eltávolítjuk a "-t a címből
            title.erase(remove(title.begin(), title.end(), '\"'), title.end());

            // Töröljük a cím elején lévő szóközt
            title.erase(0, title.find_first_not_of(" "));

            ss >> year;
            ss.ignore(2, ',');
            ss >> pages;
            library.push_back(Book(author, title, year, pages));
        }
        file.close();
    }
}

Book Library::findBookByKeyword(const string &keyword) {
    for (Book &book: library) {
        if (book.getTitle().find(keyword) != string::npos) {
            return book;
        }
    }
    throw runtime_error("Nincs ilyen cimu konyv!");
}

void Library::sortBooksByAuthorsAnyReverseYear() {
    sort(library.begin(), library.end(), [](const Book book1, const Book book2) {
             if (book1.getAuthor() == book2.getAuthor()) {
                 return book1.getYear() > book2.getYear();
             }
             return book1.getAuthor() < book2.getAuthor();
         }
    );
}

