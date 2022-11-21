#include "Calculator.h"
#include <stdexcept>
#include <iostream>

int Calculator::divide(int numerator, int denominator) {
  try {
    if (denominator == 0)
      throw std::logic_error("error: cannot divide " + std::to_string(numerator) + " by 0\n");
    return numerator / denominator;
  } catch (std::logic_error &e) {
    std::cout << e.what();
    return 0;
  }
}

Calculator::Calculator() = default;