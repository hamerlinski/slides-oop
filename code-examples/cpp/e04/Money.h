#ifndef CPP_04_MONEY_H
#define CPP_04_MONEY_H


#include <string>

class Money {
  public:
    virtual Money* multipliedBalance(float factor) = 0;
    virtual std::string balance() = 0;
};


#endif //CPP_04_MONEY_H
