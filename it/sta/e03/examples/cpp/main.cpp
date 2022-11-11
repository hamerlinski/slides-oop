#include <iostream>
#include "Author.h"
#include "ISBN.h"
#include "Title.h"
#include "Book.h"


int main() {
    ISBN isbn("0735619654");
    std::vector <Author> authors;
    Author auth1("David", "West");
    authors.push_back(auth1);
    Author auth2("Artur", "East");
    authors.push_back(auth2);
    Title title("Myślenie obiektowe", "Object Thinking");
    int pages = 368;
    Book objectThinking(isbn, authors, title, pages);
    std::cout << objectThinking.toJSON();
    return 0;
}
