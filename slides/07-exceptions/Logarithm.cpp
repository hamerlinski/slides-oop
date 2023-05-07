#include <iostream>
#include <cmath>

class Logarithm {
 public:
  Logarithm(double base, double argument) {
    base_ = base;
    argument_ = argument;
  }

  double Calculate() const {
    return std::log(argument_) / std::log(base_);
  }

 private:
  double base_;
  double argument_;
};
