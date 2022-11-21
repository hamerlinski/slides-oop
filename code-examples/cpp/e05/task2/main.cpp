#include "Calculator.h"
#include <iostream>
int main() {
  Calculator calc;
  std::cout<< "69/3=" << calc.divide(69, 3) << std::endl;
  calc.divide(420, 0);
  return 0;
}
