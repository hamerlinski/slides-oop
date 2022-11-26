#include <iostream>
#include <map>
#include <sstream>
#include <iomanip>

class FakeCantor {
 private:
  std::map<std::string, float> rates{{"USD", 1.0366f},
                                     {"GBP", 0.87063f},
                                     {"CHF", 0.9881f},
                                     {"JPY", 145.12f}};
 public:
  FakeCantor() = default;

  float EuroToRate(const std::string &currency) {
    return rates[currency];
  };
};

class Currency {
 public:

  virtual Currency *AddedCurrency(float value, std::string currency) = 0;

  virtual Currency *SubtractedCurrency(float value, std::string currency) = 0;

  virtual std::string Abbreviation() = 0;

  virtual std::string Symbol() = 0;

  virtual std::string Balance() = 0;

  virtual float DollarExchangeRate() = 0;
};

class Euro : public Currency {
 private:
  float amount;
  FakeCantor fc;
 public:
  std::string Symbol() {
    return "€";
  }

  std::string Abbreviation() {
    return "EUR";
  }

  float DollarExchangeRate() {
    return fc.EuroToRate("USD");;
  }

  Euro *AddedCurrency(float value, std::string currency) {
    float rate = fc.EuroToRate(currency);
    Euro *e = new Euro(this->amount + value / rate);
    return e;
  }

  Euro *SubtractedCurrency(float value, std::string currency) {
    float rate = fc.EuroToRate(currency);
    float result = this->amount - value / rate;
    if(result <0){
      std::cout<<"Balance cannot be negative!"<<std::endl;
      return this;
    }
    Euro *e = new Euro(this->amount - value / rate);
    return e;
  }

  std::string Balance() {
    std::stringstream stream;
    stream << std::fixed << std::setprecision(2) << amount;
    std::string s = stream.str();
    return s + this->Symbol();
  }

  Euro(float inputAmount) {
    this->amount = inputAmount;
  }

};

int main() {
  Euro startingEuroBalance(100.0f);
  Euro increasedBalance = *startingEuroBalance.AddedCurrency(10.0f, "USD");
  std::cout << increasedBalance.Balance() << std::endl;
  Euro decreasedBalance = *increasedBalance.SubtractedCurrency(1000.0f, "GBP");
  std::cout << decreasedBalance.Balance() << std::endl;
  return 0;
}
