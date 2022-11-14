#include <iostream>
#include "Author.h"
#include "ISBN.h"
#include "Title.h"
#include "Book.h"


int main() {
    ISBN isbn("0735619654");
    Author author("David", "West");
    Author *authors = new Author[1];
    authors[0] = author;
    Title title("Myślenie obiektowe", "Object Thinking");
    int pages = 368;
    Book objectThinking(isbn, authors, title, pages);
    std::cout << objectThinking.toJSON();
    return 0;
}
