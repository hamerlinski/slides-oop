#include <iostream>
#include "Author.h"
#include "ISBN.h"
#include "Title.h"
#include "Book.h"


int main() {
    ISBN isbn("0735619654");
    vector <Author> author;
    Author author("David", "West");
    Title title("Myślenie obiektowe", "Object Thinking");
    int pages = 368;
    Book objectThinking(isbn, author, title, pages);
    std::cout << objectThinking.toJSON();
    return 0;
}
