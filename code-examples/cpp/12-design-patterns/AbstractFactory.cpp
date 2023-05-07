#include <iostream>
#include <memory>

class Button {
 public:
  virtual ~Button() {}
  virtual void Paint() = 0;
};

class MacOSButton : public Button {
 public:
  void Paint() override {
    std::cout << "You have created MacOSButton." << std::endl;
  }
};

class WindowsButton : public Button {
 public:
  void Paint() override {
    std::cout << "You have created WindowsButton." << std::endl;
  }
};

class GUIFactory {
 public:
  virtual ~GUIFactory() {}
  virtual std::unique_ptr<Button> CreateButton() = 0;
};

class MacOSFactory : public GUIFactory {
 public:
  std::unique_ptr<Button> CreateButton() override {
    return std::make_unique<MacOSButton>();
  }
};

class WindowsFactory : public GUIFactory {
 public:
  std::unique_ptr<Button> CreateButton() override {
    return std::make_unique<WindowsButton>();
  }
};

class Application {
 public:
  explicit Application(std::unique_ptr<GUIFactory> factory)
      : button_(std::move(factory->CreateButton())) {}
  void Paint() {
    button_->Paint();
  }

 private:
  std::unique_ptr<Button> button_;
};

int main() {
  std::unique_ptr<GUIFactory> factory;
  std::string os_name = std::getenv("OS");
  if (os_name.find("Mac") != std::string::npos) {
    factory = std::make_unique<MacOSFactory>();
  } else {
    factory = std::make_unique<WindowsFactory>();
  }
  Application app(std::move(factory));
  app.Paint();
  return 0;
}
