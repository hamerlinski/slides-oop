#include <iostream>
#include "Cash.h"

int main() {
  Cash smallCash(99.99f);
  Cash bigCash = smallCash.multiplyCash(10.0f);
  std::cout << "I have " + bigCash.balance() + ". It ain't much, but it's honest work.";
  return 0;
}
