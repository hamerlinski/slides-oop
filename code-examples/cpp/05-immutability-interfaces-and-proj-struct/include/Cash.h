#include "Money.h"
class Cash : public Money {
 public:
  Cash *MultipliedBalance(float factor) override;
  std::string Balance() override;
  explicit Cash(float dollars);
 private:
  float dollars;
};
