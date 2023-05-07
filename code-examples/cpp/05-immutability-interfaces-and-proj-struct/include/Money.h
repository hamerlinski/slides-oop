#pragma once
#include <string>
class Money {
 public:
  Money(){};
  virtual ~Money(){}
  virtual Money *MultipliedBalance(float factor) = 0;
  virtual std::string Balance() = 0;
};
