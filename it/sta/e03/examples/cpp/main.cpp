#include <iostream>
#include "Author.h"
#include "ISBN.h"
#include "Title.h"
#include "Book.h"


int main() {
    ISBN isbn("0735619654");
    Authors authors = Authors(2);
    authors.addAuthor("David", "West");
    authors.addAuthor("Bruce","Eckel");
    Title title("Myślenie obiektowe", "Object Thinking");
    int pages = 368;
    Book objectThinking(isbn, authors, title, pages);
    std::cout << objectThinking.toJSON();
    return 0;
}
