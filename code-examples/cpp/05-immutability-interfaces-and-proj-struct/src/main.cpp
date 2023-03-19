#include <iostream>
#include "../include/Cash.h"

int main() {
  Cash smallCash(99.99f);
  Cash *bigCash = smallCash.MultipliedBalance(10.0f);
  std::cout << "I have " + bigCash->Balance() + ".\nIt ain't much, but it's honest work.";
  return 0;
}
