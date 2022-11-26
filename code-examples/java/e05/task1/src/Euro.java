public class Euro implements Currency {

  private final float amount;
  private FakeCantor fc = new FakeCantor();

  @Override
  public String symbol() {
    return "€";
  }

  @Override
  public String abbreviation() {
    return "EUR";
  }

  @Override
  public float toDollarExchangeRate() {
    return fc.euroToRate("USD");
  }

  @Override
  public Euro addedCurrency(float value, String currency) {
    float rate = fc.euroToRate(currency);
    return new Euro(this.amount + value / rate);
  }

  @Override
  public Euro subtractedCurrency(float value, String currency) {
    float rate = fc.euroToRate(currency);
    try {
      if (this.amount - value / rate < 0) throw new IllegalArgumentException("Balance cannot be negative!");
    } catch (IllegalArgumentException e) {
      System.out.println(e);
      return this;
    }
    return new Euro(this.amount - value / rate);
  }

  @Override
  public String balance() {
    return String.format("%.2f%s", this.amount, this.symbol()) ;
  }

  public Euro(float inputAmount) {
    this.amount = inputAmount;
  }

}
