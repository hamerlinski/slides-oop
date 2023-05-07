#include <iostream>
#include "../include/Cash.h"
#include "../include/Digital.h"
#include "../include/Employee.h"
int main() {
  Cash smallCash(1.0f);
  Cash *biggerCash = smallCash.MultipliedBalance(69.0f);
  std::cout << "I have " << biggerCash->Balance() << ".\nIt ain't much but it's honest work." << std::endl;
  Money *dollars = new Cash(1000.0f);
  Money *btc = new Digital(0.037f);
  Employee grandfather("Abraham", dollars);
  Employee grandson("Jimmy", btc);
  grandfather.PrintInformation();
  grandson.PrintInformation();
  return 0;
}
