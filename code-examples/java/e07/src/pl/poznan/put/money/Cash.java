package pl.poznan.put.money;

public class Cash {

  private final Exchange exchange;
  private final float amount;

  public Cash(Exchange exch, float amnt) {
    this.exchange = exch;
    this.amount = amnt;
  }

  public Cash exchangedCash(String currency) {
    return new Cash(this.exchange, (this.amount * this.exchange.rate("USD", currency)));
  }

  @Override
  public String toString() {
    return Float.toString(amount);
  }
}
