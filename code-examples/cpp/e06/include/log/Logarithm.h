#ifndef E06_SRC_CONTENT_LOGARITHM_H_
#define E06_SRC_CONTENT_LOGARITHM_H_

#include "Number.h"

class Logarithm : public Number {
 private:
  double base, argument;
 public:

  double doubleValue();
  Logarithm(double inputBase, double inputArgument);
};

#endif //E06_SRC_CONTENT_LOGARITHM_H_
