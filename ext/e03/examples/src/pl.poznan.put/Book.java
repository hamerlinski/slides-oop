package pl.poznan.put;

public class Book {
  private ISBN isbn;
  private Author[] authors;
  private Title title;
  private Integer pages;

  Book(ISBN isbn, Author[] authors, Title title, Integer pages) {
    this.isbn = isbn;
    this.authors = authors;
    this.title = title;
    this.pages = pages;
  }

  public String toJSON() {
    return String.format(
        "{\"isbn\":\"%s\", \"author\":\"%s\", \"title\":\"%s\", \"pages\":%d}",
        this.isbn.isbnValue(), this.authors[0].name() ,this.title.title("PL"), this.pages.intValue());
  }

  public static void main(String[] args) {
    ISBN isbn = new ISBN("0735619654");
    Author author = new Author("David", "West");
    Author authors[] = new Author[1];
    authors[0] = author;
    Title title = new Title("Myślenie obiektowe", "Object Thinking");
    Integer pages = 368;
    Book objectThinking = new Book(isbn, authors, title, pages);
    System.out.println(objectThinking.toJSON());
  }
}