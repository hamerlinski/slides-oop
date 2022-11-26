public class Main {
  public static void main(String[] args) {
    Euro startingEuroBalance = new Euro(100.0f);
    Euro increasedBalance = startingEuroBalance.addedCurrency(10.0f, "USD");
    System.out.println(increasedBalance.balance());
    Euro decreasedBalance = increasedBalance.subtractedCurrency(1000.0f, "GBP");
    System.out.println(decreasedBalance.balance());
  }
}