import pl.poznan.put.money.Cash;
import pl.poznan.put.money.Exchange;

public class Application {

  public static void main(String[] args) {
    Exchange exchange = new Exchange.Fake();
    Cash dollar = new Cash(exchange, 500);
    Cash euro = dollar.exchangedCash("EUR");
    assert "617.25".equals(euro.toString());
  }
}