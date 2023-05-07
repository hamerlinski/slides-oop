// Copyright © 2023 Jakub Piotr Hamerliński

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the 'Software'), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED 'AS IS', WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

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
