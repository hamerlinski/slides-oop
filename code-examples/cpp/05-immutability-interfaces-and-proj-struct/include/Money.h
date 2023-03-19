#include <string>

class Money {
 public:
  virtual Money *MultipliedBalance(float factor) = 0;
  virtual std::string Balance() = 0;
};
