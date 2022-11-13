package lesson3;

public class Author {
  private final String firstName;
  private final String lastName;

  Author(String firstName, String lastName) {
    this.firstName = firstName;
    this.lastName = lastName;
  }

  public String name() {
    return this.firstName + " " + this.lastName;
  }
}
