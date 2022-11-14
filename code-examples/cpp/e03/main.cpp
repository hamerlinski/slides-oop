#include <iostream>
#include "Author.h"
#include "ISBN.h"
#include "Title.h"
#include "Book.h"


int main() {
    ISBN isbn("9780321714114");
    std::vector <Author> authors;
    Author auth1("Stanley","Lippman);
    authors.push_back(auth1);
    Author auth2("Josée","Lajoie");
    authors.push_back(auth2);
    Author auth3("Barbara E. Moo");
    authors.push_back(auth3);
    Title title("C++ Primer", "C++ Primer");
    int pages = 1399;
    Book objectThinking(isbn, authors, title, pages);
    std::cout << objectThinking.toJSON();
    return 0;
}
