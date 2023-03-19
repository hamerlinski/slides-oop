#include "Money.h"
#include <iomanip>
#include <sstream>

class Cash : public Money {
 private:
  float dollars;
 public:
  Cash *MultipliedBalance(float factor) override;
  std::string Balance() override;
  explicit Cash(float dollars);
};
