#include "../include/Cash.h"

std::string Cash::Balance() {
  std::stringstream stream;
  stream << std::fixed << std::setprecision(2) << dollars;
  std::string s = stream.str();
  return "$" + s;
}
Cash *Cash::MultipliedBalance(float factor) {
  Cash *b = new Cash(dollars * factor);
  return b;
}
Cash::Cash(float dollars) {
  this->dollars = dollars;
}
