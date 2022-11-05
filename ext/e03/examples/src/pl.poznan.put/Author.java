package pl.poznan.put;

public class Author {
  private String firstName;
  private String lastName;

  Author(String firstName, String lastName) {
    this.firstName = firstName;
    this.lastName = lastName;
  }

  public String name() {
    return this.firstName + " " + this.lastName;
  }
}
