#include "Calculator.h"
#include <iostream>
int main() {
  Calculator calc;
  std::cout<< "69/3=" << calc.fraction(69, 3) << std::endl;
  calc.fraction(420, 0);
  return 0;
}
