#ifndef E07_INCLUDE_DEBT_CREDITDEBT_H_
#define E07_INCLUDE_DEBT_CREDITDEBT_H_

#include "Debt.h"
class CreditDebt : public Debt {
 private:
  Month period;
  Date firstPay;
  double amount;
 public:
  void pay(double repayment);

  CreditDebt(Month period, Data firstPay, double amount)

};

#endif //E07_INCLUDE_DEBT_CREDITDEBT_H_
