#include <iostream>
#include <optional>
#include <utility>
#include <vector>

class Ball {
 private:
  std::string color;
 public:
  Ball Paint(std::string newColor) {
    this->color = std::move(newColor);
    return *this;
  }
  std::string CurrentColor() {
    return this->color;
  }
};
class Dog {
 private:
  std::string name;
  std::optional<std::vector<Ball>> dogsBalls;
 public:
  void NameDog(std::string dogsNewName) {
    this->name = std::move(dogsNewName);
  }
  void GiveBall(const Ball &ball) {
    this->dogsBalls->push_back(ball);
  }
  Ball TakeBall() {
    Ball takenFromDog = this->dogsBalls->back();
    this->dogsBalls->pop_back();
    return takenFromDog;
  }
};
class Book {
 private:
  std::string isbn = "0735619654";
  std::string title = "Object Thinking";
 public:
  std::string toJSON() {
    return "{\"isbn\":\"" + this->isbn + "\", \"title\":\"" + this->title + "\"}";
  }
};
class Temperature {
 private:
  int t = 12;
 public:
  std::string FahrenheitValue() {
    return std::to_string(t) + " °F";
  }
};
int main() {
  Book book;
  std::cout<<book.toJSON();

  Dog goodBoy;
  goodBoy.NameDog("Piernik");
  Ball ball;
  Ball newBall = ball.Paint("Pink");
  goodBoy.GiveBall(newBall);
  Ball wetBall = goodBoy.TakeBall();
  std::cout << wetBall.CurrentColor();
  return 0;
}
