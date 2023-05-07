#include <iostream>

class Approver {
 public:
  virtual ~Approver() {}
  virtual void Approve(int amount) = 0;
  
 protected:
  Approver* next_approve_ = nullptr;
};

class Manager : public Approver {
 public:
  Manager(Approver* next_approve) : next_approve_(next_approve) {}
  
  void Approve(int amount) override {
    if (amount <= 1000) {
      std::cout << "Manager approved $" << amount << std::endl;
    } else if (next_approve_) {
      next_approve_->Approve(amount);
    }
  }
  
 private:
  Approver* next_approve_;
};

class Director : public Approver {
 public:
  Director(Approver* next_approve) : next_approve_(next_approve) {}
  
  void Approve(int amount) override {
    if (amount <= 10000) {
      std::cout << "Director approved $" << amount << std::endl;
    } else if (next_approve_) {
      next_approve_->Approve(amount);
    }
  }
  
 private:
  Approver* next_approve_;
};

class CEO : public Approver {
 public:
  void Approve(int amount) override {
    if (amount <= 100000) {
      std::cout << "CEO approved $" << amount << std::endl;
    } else {
      std::cout << "Amount too high, approval denied." << std::endl;
    }
  }
};

int main() {
  CEO ceo;
  Director director(&ceo);
  Manager manager(&director);
  manager.Approve(500);
  manager.Approve(5000);
  manager.Approve(50000);
  return 0;
}
