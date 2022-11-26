public interface Currency {
  Currency addedCurrency(float value, String currency);

  Currency subtractedCurrency(float value, String currency);

  String abbreviation();

  String symbol();

  String balance();

  float toDollarExchangeRate();
}
