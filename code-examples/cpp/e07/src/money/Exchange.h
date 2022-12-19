#include <string>
class Exchange {
 public:
  virtual float rate(std::string in, std::string out) = 0;
  class Fake {
   public:
    float rate(std::string in, std::string out) {
      return 1.2345;
    };
  };

};