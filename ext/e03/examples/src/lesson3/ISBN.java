package lesson3;

public class ISBN {
  private final String value;

  ISBN(String value) {
    this.value = value;
  }

  public String isbnValue() {
    return this.value;
  }
}