#ifndef CPP_04_CASH_H
#define CPP_04_CASH_H

#include "Money.h"
#include <iomanip>
#include <sstream>

class Cash : public Money {
  private:
    float dollars;
  public:
      Cash* multiplyBalance(float factor) {
      Cash* b = new Cash(dollars * factor);
      return b;
    }

    std::string balance() {
      std::stringstream stream;
      stream << std::fixed << std::setprecision(2) << dollars;
      std::string s = stream.str();
      return "$" + s;
    }

    Cash(float dollars) {
      this->dollars = dollars;
    }
};


#endif //CPP_04_CASH_H
