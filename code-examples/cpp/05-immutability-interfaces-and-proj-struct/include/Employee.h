#include <string>
#include <iostream>
#include "Money.h"
class Employee {
 public:
  Employee(const std::string &name, Money *salary);
  void PrintInformation();
 private:
  std::string name;
  Money *salary;
};
