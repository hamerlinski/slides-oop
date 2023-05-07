#include <iostream>
#include <memory>

class Command {
 public:
  virtual ~Command() {}
  virtual void Execute() = 0;
};

class Light {
 public:
  void TurnOn() {
    std::cout << "The light is on\n";
  }
  void TurnOff() {
    std::cout << "The light is off\n";
  }
};

class TurnOnLightCommand : public Command {
 public:
  TurnOnLightCommand(std::shared_ptr<Light> light) : light_(light) {}
  void Execute() override {
    light_->TurnOn();
  }
 private:
  std::shared_ptr<Light> light_;
};

class TurnOffLightCommand : public Command {
 public:
  TurnOffLightCommand(std::shared_ptr<Light> light) : light_(light) {}
  void Execute() override {
    light_->TurnOff();
  }
 private:
  std::shared_ptr<Light> light_;
};

class RemoteControl {
 public:
  void ChangeCommand(std::shared_ptr<Command> command) {
    command_ = command;
  }
  void PressButton() {
    command_->Execute();
  }
 private:
  std::shared_ptr<Command> command_;
};

int main() {
  std::shared_ptr<Light> light = std::make_shared<Light>();
  std::shared_ptr<Command> turnOnCommand = std::make_shared<TurnOnLightCommand>(light);
  std::shared_ptr<Command> turnOffCommand = std::make_shared<TurnOffLightCommand>(light);
  RemoteControl remote;
  remote.ChangeCommand(turnOnCommand);
  remote.PressButton(); // prints "The light is on"
  remote.ChangeCommand(turnOffCommand);
  remote.PressButton(); // prints "The light is off"
  return 0;
}
