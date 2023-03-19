#include "Money.h"
class Digital : public Money {
 public:
  Digital *MultipliedBalance(float factor) override;
  std::string Balance() override;
  explicit Digital(float btc);
 private:
  float btc;
};
