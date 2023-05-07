#include <iostream>
#include <memory>
#include <cassert>
class Exchange {
 public:
  virtual float rate(std::string origin, std::string target) = 0;
  class Fake;
};

class Exchange::Fake : public Exchange {
 public:
  float rate(std::string origin, std::string target) override {
    return 0.85f;
  }
};

class Cash {
 private:
  std::shared_ptr<Exchange> exchange;
  float amount;
 public:
  Cash(std::shared_ptr<Exchange> exch, float amnt)
      : exchange(exch), amount(amnt) {}
  Cash exchangedCash(std::string currency) {
    return Cash(exchange, amount / exchange->rate("USD", currency));
  }
  float Amount(){
    return amount;
  }
  friend std::ostream& operator<<(std::ostream& os, const Cash& cash) {
    os << cash.amount;
    return os;
  }
};

int main() {
  std::shared_ptr<Exchange> exchange = std::make_shared<Exchange::Fake>();
  Cash cash(exchange, 100.0f);
  std::cout << "Original amount in €: " << cash << std::endl;
  Cash exchanged_cash = cash.exchangedCash("EUR");
  std::cout << "Exchanged amount in $: " << exchanged_cash << std::endl;
  // Test that exchanged_cash is correct
  // Verify exchanged amount is correct
  const float expected_amount = 100.0f / exchange->rate("USD", "EUR");
  const float epsilon = 0.0001f;
  assert(std::abs(exchanged_cash.Amount() - expected_amount) < epsilon); // or assert(exchanged_cash.Amount() == expected_amount);
  return 0;
}