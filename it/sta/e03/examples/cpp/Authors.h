//
// Created by PC on 07.11.2022.
//
#include <string>
#include "Author.h"

using namespace std;
#ifndef LAB3_STAR_AUTHORS_H
#define LAB3_STAR_AUTHORS_H

class Authors {
private:
    int num_of_authors = 0;
    int authors_limit;
    Author *authors;
public:
    Authors(int limit) {
        this->authors_limit = limit;
        authors = new Author[limit];
    }

    Authors() {}

    void addAuthor(string firstName, string lastName) {
        if (num_of_authors < authors_limit) {
            Author a = Author(firstName, lastName);
            authors[num_of_authors++] = a;
        }
    }

    string names() {
        string out = "";
        for (int i = 0; i < num_of_authors - 1; ++i) {
            Author a = authors[i];
            out += a.name() + ", ";
        }
        out += authors[num_of_authors - 1].name();
        return out;
    }
};

#endif //LAB3_STAR_AUTHORS_H
