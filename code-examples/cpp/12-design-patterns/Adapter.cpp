#include <iostream>
#include <memory>
#include <string>

class LegacySystem {
 public:
  virtual void processData(std::string data) = 0;
  virtual ~LegacySystem() = default;
};

class LegacySystemImpl : public LegacySystem {
 public:
  void processData(std::string data) override {
    // code to process data using the legacy system
    std::cout << "Processing data using legacy system: " << data << std::endl;
  }
};

class NewSystem {
 public:
  virtual void process(std::string data) = 0;
  virtual ~NewSystem() = default;
};

class NewSystemAdapter : public NewSystem {
 public:
  NewSystemAdapter(std::shared_ptr<LegacySystem> legacySystem)
      : legacySystem_(legacySystem) {}
  void process(std::string data) override {
    legacySystem_->processData(data);
  }

 private:
  std::shared_ptr<LegacySystem> legacySystem_;
};

int main() {
  auto legacySystem = std::make_shared<LegacySystemImpl>();
  auto adapter = std::make_unique<NewSystemAdapter>(legacySystem);
  adapter->process("data to process");
  return 0;
}
