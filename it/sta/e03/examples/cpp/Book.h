#include <string>
#include <sstream>

#ifndef CPP_BOOK_H
#define CPP_BOOK_H


class Book {
private:
    ISBN isbn;
    Author author;
    Title title;
    int pages;


public:
    std::string toJSON() {
        std::ostringstream oss;
        oss << "{\"isbn\":\"" << isbn.isbnValue() << "\", \"author\":\"" << author.name() << "\", \"title\":\""
            << title.value("ENG") << "\", \"pages\":" << pages << "}";
        return oss.str();
    }

    Book(ISBN isbn, Author author, Title title, int pages) {
        this->isbn = isbn;
        this->author = author;
        this->title = title;
        this->pages = pages;
    }
};


#endif //CPP_BOOK_H
