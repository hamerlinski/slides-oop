---
# Copyright © 2023 Jakub Piotr Hamerliński

# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the 'Software'), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.

# THE SOFTWARE IS PROVIDED 'AS IS', WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.
theme: apple-basic
colorSchema: light
lineNumbers: true
title: Object Oriented Programming
fonts:
  provider: none
  sans: Canela Text
  local: Canela Text
layout: fact
---

## Poznan University of Technology
## Methods and encapsulation
Jakub Piotr Hamerliński

---
layout: image-right
image: 'kevin.png'
---

# Methods and encapsulation
## Agenda
* Methods
* Evilness of ~~getters~~ and ~~setters~~
* Encapsulation
* Task
<br><br><br>
> _"Me mechanic not speak English. But he know what me mean when me say “car no go”, and we best friends. So me think: why waste time, say lot word when few word do trick?"_
Kevin Malone

---
layout: statement
---

# Methods 

---

# Methods
## Introduction
The message is a request to an object to invoke one of its methods.
The message contains:
* The name of the method,
* The arguments of the method.

A method is associated with a class.
An object invokes one of its class methods as a reaction to the message

---

# Methods
## Examples
```cpp
int Length(...);
std::string ParsedText(...);
void Save();
void Print();
```

---

# Methods
## More advance example - ball
```cpp
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
  };
};
```

---

# Methods
## More advance example - dog
```cpp
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
```

---

# Methods
## More advance example - usage
```cpp
int main() {
  Dog goodBoy;
  goodBoy.NameDog("Piernik");
  Ball ball;
  Ball newBall = ball.Paint("Pink");
  goodBoy.GiveBall(newBall);
  Ball wetBall = goodBoy.TakeBall();
  std::cout << wetBall.CurrentColor();
  return 0;
}
```

---
layout: statement
---

# Encapsulation

---
layout: quote
---

# **encapsulation** (noun, BrE /ɪnˌkæpsjuˈleɪʃn/): <br>the act of expressing the most important parts of something in a few words, <br>a small space or a single object
Oxford Dictionary

---

# Encapsulation
## Examples
```cpp
class Book {
 private:
  std::string isbn;
  std::string author;
  std::string title;
  int pages;
};
```
```cpp
class Article {
 private:
  Doi doi;
  Author* authors;
  Title title;
  int pages;
};
```

---

# Encapsulation
## More technical explanation
The fundamental idea behind object-oriented computing is encapsulation, which gives objects their solidity, coherence, reliability, etc. But what does encapsulation actually mean? Does it only defend against external access to confidential attributes? It is much much more. All layers and forms of naked data are eliminated through encapsulation.

---
layout: statement
---

# Evilness of ~~getters~~ and ~~setters~~

---

# Evilness of ~~getters~~ and ~~setters~~
## Why they are evil?
“It is convenient to have these ~~getters~~, you may say. We are all used to them.
If we want to convert it into JSON, they will be very helpful. (..) There are
many examples, where ~~getters~~ are being actively used. This is not because
they are so effective. This is because we’re so procedural in our way of
thinking. We don’t trust our objects. We only trust the data they store. ”
<br>Yegor Bugayenko

---

# Evilness of ~~getters~~ and ~~setters~~
## Why they are evil?
**V**iolated Encapsulation Principle<br>
**E**xposed Implementation Details<br>
**T**elling Instead Of Asking

---

# Evilness of ~~getters~~ and ~~setters~~
## Violated Encapsulation Principle
They break encapsulation:
```cpp
// wrong example below
class Temperature {
 private:
  int t;
 public:
  void SetTemp(int newTemp){
    this->t = newTemp;
  }
  int GetTemp(){
    return this->t;
  }
};
```

---

# Evilness of ~~getters~~ and ~~setters~~
## Violated Encapsulation Principle
Better do it like this:
```cpp
// good example below
class Temperature {
 private:
  int t = 12;
 public:
  std::string FahrenheitValue() {
    return std::to_string(t) + " °F";
  }
};
```

---

# Evilness of ~~getters~~ and ~~setters~~
## Exposed Implementation Details
Usage of getters, setters leads to data structures/bags, not to classes:
```c
struct Cash {
  int dollars;
}
printf("Cash value is %d", Cash.dollars);     
```

---

# Evilness of ~~getters~~ and ~~setters~~
## Telling Instead Of Asking
Use printers instead of getters:
```cpp
class Book {
 private:
  std::string isbn = "0735619654";
  std::string title = "Object Thinking";
 public:
  std::string JSON() {
    return "{\"isbn\":\"" + this->isbn + "\", \"title\":\"" + this->title + "\"}";
  }
};   
```

---
layout: statement
---

# Task

---

# Methods
## Task
Task
* Write a program in C++, which will demonstrate communication between different objects

---
layout: statement
---

# Thank you
Feel free to reach me via [LinkedIn](https://www.linkedin.com/in/hamerlinski)

---
layout: statement
---

# *Fin*
