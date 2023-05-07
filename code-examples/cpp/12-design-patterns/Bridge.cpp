#include <iostream>

class TV {
 public:
  virtual void On() = 0;
  virtual void Off() = 0;
  virtual void TuneChannel(int channel) = 0;
  virtual void ChangeVolume(int volume) = 0;
};

class RemoteControl {
 protected:
  TV* tv;

 public:
  RemoteControl(TV* tv) : tv(tv) {}
  void TurnOn() { tv->On(); }
  void TurnOff() { tv->Off(); }
  void ChangeChannel(int channel) { tv->TuneChannel(channel); }
};

class AdvancedRemoteControl : public RemoteControl {
 public:
  AdvancedRemoteControl(TV* tv) : RemoteControl(tv) {}
  void ChangeVolume(int volume) { tv->ChangeVolume(volume); }
};

class LGTV : public TV {
 public:
  void On() override { std::cout << "LG TV is turned on." << std::endl; }
  void Off() override { std::cout << "LG TV is turned off." << std::endl; }
  void TuneChannel(int channel) override { std::cout << "LG TV tuned to channel: " << channel << std::endl; }
  void ChangeVolume(int volume) override { std::cout << "LG TV volume set to: " << volume << std::endl; }
};

class SonyTV : public TV {
 public:
  void On() override { std::cout << "Sony TV is turned on." << std::endl; }
  void Off() override { std::cout << "Sony TV is turned off." << std::endl; }
  void TuneChannel(int channel) override { std::cout << "Sony TV tuned to channel: " << channel << std::endl; }
  void ChangeVolume(int volume) override { std::cout << "Sony TV volume set to: " << volume << std::endl; }
};

int main() {
  TV* lgTV = new LGTV();
  auto* advancedRemote = new AdvancedRemoteControl(lgTV);
  advancedRemote->TurnOn();             // prints "LG TV is turned on."
  advancedRemote->ChangeVolume(10);     // prints "LG TV volume set to: 10"
  advancedRemote->ChangeChannel(3);     // prints "LG TV tuned to channel: 3"
  advancedRemote->TurnOff();            // prints "LG TV is turned off."

  TV* sonyTV = new SonyTV();
  auto* remote = new RemoteControl(sonyTV);
  remote->TurnOn();            // prints "Sony TV is turned on."
  remote->ChangeChannel(7);    // prints "Sony TV tuned to channel: 7"
  remote->TurnOff();           // prints "Sony TV is turned off."
  delete lgTV, sonyTV, advancedRemote, remote;
  return 0;
}
