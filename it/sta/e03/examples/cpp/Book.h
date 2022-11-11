#include <string>
#include <sstream>
#include <vector>
#ifndef CPP_BOOK_H
#define CPP_BOOK_H


class Book {
private:
    ISBN isbn;
    std::vector <Author> authors;
    Title title;
    int pages;


public:
    std::string toJSON() {
        std::ostringstream oss;

        oss << R"({"isbn":")" << isbn.isbnValue() << R"(", "authors":{)";
        for(int i=0; i<authors.size();i++){oss << R"(")" << authors[i].name();
        if(i<authors.size()-1){oss << R"(",)";}
        else(oss << R"(")");}
        oss << R"(},"title":")" << title.value("ENG") << R"(", "pages":)" << pages << "}";
        return oss.str();
    }

    Book(ISBN isbn, std::vector <Author> authors, Title title, int pages) {
        this->isbn = isbn;
        this->authors = authors;
        this->title = title;
        this->pages = pages;
    }
};


#endif //CPP_BOOK_H
