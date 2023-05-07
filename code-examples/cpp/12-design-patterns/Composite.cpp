#include <iostream>
#include <memory>
#include <vector>

class Component {
 public:
  virtual ~Component() {}
  virtual void Operation() = 0;
};

class Leaf : public Component {
 public:
  void Operation() override {
    std::cout << "Leaf operation\n";
  }
};

class Composite : public Component {
 public:
  void Operation() override {
    std::cout << "Composite operation\n";
    for (const auto& child : children_) {
      child->Operation();
    }
  }

  void Add(std::unique_ptr<Component> child) {
    children_.emplace_back(std::move(child));
  }

  void Remove(Component* child) {
    for (auto it = children_.begin(); it != children_.end(); ++it) {
      if (it->get() == child) {
        children_.erase(it);
        break;
      }
    }
  }

  Component* Child(int index) const {
    return children_[index].get();
  }

 private:
  std::vector<std::unique_ptr<Component>> children_;
};

int main() {
  auto composite = std::make_unique<Composite>();
  composite->Add(std::make_unique<Leaf>());
  composite->Add(std::make_unique<Leaf>());
  composite->Operation();
}
