package pl.poznan.put;

public class ISBN {
  private String value;

  ISBN(String value) {
    this.value = value;
  };

  public String isbnValue() {
    return this.value;
  }
}