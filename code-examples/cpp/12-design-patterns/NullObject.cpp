#include <iostream>
#include <memory>
#include <string>

class Shape {
 public:
  virtual ~Shape() {}
  virtual void Draw() = 0;
};

class Rectangle : public Shape {
 public:
  void Draw() override {
    std::cout << "Drawing a rectangle." << std::endl;
  }
};

class NullShape : public Shape {
 public:
  void Draw() override {
    // Do nothing
  }
};

class ShapeFactory {
 public:
  std::unique_ptr<Shape> CreateShape(const std::string& shape_type) {
    if (shape_type.empty()) {
      return std::make_unique<NullShape>();
    }
    if (shape_type == "rectangle") {
      return std::make_unique<Rectangle>();
    }
    return std::make_unique<NullShape>();
  }
};

int main() {
  ShapeFactory shape_factory;
  std::unique_ptr<Shape> shape1 = shape_factory.CreateShape("rectangle");
  shape1->Draw();  // Outputs "Drawing a rectangle."
  std::unique_ptr<Shape> shape2 = shape_factory.CreateShape("");
  shape2->Draw();  // Does nothing
  return 0;
}
