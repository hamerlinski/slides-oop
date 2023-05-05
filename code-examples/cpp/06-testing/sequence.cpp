#include <iostream>
#include <memory>
#include <sstream>

class Sequence {
 public:
  virtual int Length() = 0;
};

class FakeSequence : public Sequence {
 public:
  int Length() override { return 100; }
};

class Gene {
 public:
  Gene(std::shared_ptr<Sequence> seq, std::string name)
      : sequence_(seq), name_(name) {}

  std::string JSON() const {
    std::stringstream ss;
    ss << "{";
    ss << "\"name\": \"" << name_ << "\", ";
    ss << "\"length\": " << sequence_->Length() << "";
    ss << "}";
    return ss.str();
  }

 private:
  std::shared_ptr<Sequence> sequence_;
  std::string name_;
};

int main() {
  std::shared_ptr<Sequence> fake_seq = std::make_shared<FakeSequence>();
  Gene gene(fake_seq, "example");
  std::cout << gene.JSON() << std::endl;
  return 0;
}
