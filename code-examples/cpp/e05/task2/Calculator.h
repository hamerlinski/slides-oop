#ifndef TASK2_CALCULATOR_H_
#define TASK2_CALCULATOR_H_

#include "MathOperation.h"
class Calculator : public MathOperation {
 public:
  int divide(int numerator, int denominator) override;
  Calculator();
};

#endif //TASK2_CALCULATOR_H_
