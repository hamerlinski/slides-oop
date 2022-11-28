#include "../../include/content/Logarithm.h"
#include "cmath"

// Before refactor
double Logarithm::doubleValue() {
  return log(this->argument) / log(this->base);
}
Logarithm::Logarithm(double inputBase, double inputArgument) {
  this->base = inputBase;
  this->argument = inputArgument;
}