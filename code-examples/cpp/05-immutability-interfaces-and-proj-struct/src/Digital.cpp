#include <sstream>
#include <iomanip>
#include "../include/Digital.h"
Digital *Digital::MultipliedBalance(float factor) {
  Digital *d = new Digital(this->btc * factor);
  return d;
}
std::string Digital::Balance() {
  std::stringstream stream;
  stream << std::fixed << std::setprecision(4) << btc;
  std::string s = stream.str();
  return s + " BTC";
}
Digital::Digital(float btc) { this->btc = btc; }
