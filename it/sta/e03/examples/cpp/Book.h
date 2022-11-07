#include <string>
#include <sstream>
#include "Authors.h"

#ifndef CPP_BOOK_H
#define CPP_BOOK_H


class Book {
private:
    ISBN isbn;
    Authors authors;
    Title title;
    int pages;

public:
    std::string toJSON() {
        std::ostringstream oss;
        oss << "{\"isbn\":\"" << isbn.isbnValue() << "\", \"authors\":\"" << authors.names() << "\", \"title\":\""
            << title.value("ENG") << "\", \"pages\":" << pages << "}";
        return oss.str();
    }

    Book(ISBN isbn, Authors authors, Title title, int pages) {
        this->isbn = isbn;
        this->authors = authors;
        this->title = title;
        this->pages = pages;
    }
};


#endif //CPP_BOOK_H
