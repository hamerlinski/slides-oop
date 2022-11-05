package lesson4;

interface Money {
  Money multiply(float factor);
  String balance();
}

public class Cash implements Money {
  private final float dollars;
  @Override
  public Cash multiply(float factor) { return new Cash(this.dollars * factor); }
  @Override
  public String balance() { return "$" + dollars; }
  public Cash(float dollars) { this.dollars = dollars; }

  public static void main(String[] args) {
    Cash smallAmount = new Cash(15.0f);
    Cash bigAmount = smallAmount.multiply(10f);
    System.out.println("I have " + bigAmount.balance());
  }
}