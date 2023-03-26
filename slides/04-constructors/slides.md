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

# Poznan University of Technology
## Object Oriented Programming
## Constructors
Jakub Piotr Hamerliński

---
layout: image-right
image: 'darryl.jpg'
---

# Constructors
## Agenda
* Introduction
* Types
* Delegation
* Code inside constructors
* Destructor
* Task
<br>
> _**Bookstore employee**: Well, if you read a lot, you should check out our e-readers. They're really neat.
<br>**Darryl**: Whoa, I work at a paper company, those things terrify me. They could put us out of business, you know? I heard those machines hold, like, ten books at once.
<br>**Bookstore employee**: Actually, it's ten thousand.
<br>**Darryl**: Holy [bleep]. What? Let me see that. It's so light. Like a croissant._

---
layout: statement
---

# Constructors

---

# Constructors
## Introduction
It's an entry point to a new object.<br>
It accepts some arguments, does something with them, and prepare the object to perform their duties.<br>
Properly constructed class should have many constructors and only a few methods.<br>
> **Number of constructors > Number of methods**

---

# Constructors
## Examples
```cpp
Money defaultCash;
Money floatCash(140.15f);
Money stringCash("128.12");
Money intCash(144);
```

---

# Constructors
## Types
Constructor's main task is to initialize encapsulated properties, using the provided arguments.<br>
One primary constructor with initialization.<br>
Many secondaries constructors, which call the primary one.<br>
This approach reduces complexity and helps to avoid duplication.<br>

---

# Constructors
## Delegation
```cpp
class Money {
 private:
  double amount;
 public:
  double Balance() { return this->amount; };
  Money() { this->amount = 0.0; };
  Money(double mny) { this->amount = mny; };
  Money(float mny) : Money(static_cast<double>(mny)) {};
  Money(int mny) : Money(static_cast<double>(mny)) {};
  Money(std::string mny) : Money(std::stod(mny)) {};
};
```

---

# Constructors
## Delegation
```cpp
int main() {
  Money defaultCash;
  Money doubleCash(69.69);
  Money floatCash(360.01f);
  Money stringCash("21.37");
  Money intCash(420);
  std::cout << defaultCash.Balance() << std::endl;
  std::cout << doubleCash.Balance() << std::endl;
  std::cout << floatCash.Balance() << std::endl;
  std::cout << stringCash.Balance() << std::endl;
  std::cout << intCash.Balance() << std::endl;
  std::cout << "typeid of stringCash.Balance() -> " << typeid(stringCash.Balance()).name();
  return 0;
}
// output:
// 0
// 69.69
// 360.01
// 21.37
// 420
// typeid of stringCash.Balance() -> d
```

---

# Constructors
## Code inside constructors
Any computations done inside a constructor is a bad practice, because they can create side effects that are not requested by the object owner.<br>
> Constructs must be code-free.

---

# Constructors
## Code inside constructors - example
```cpp
class Name {
  virtual std::string FirstName() = 0;
};
class EnglishName : public Name {
 private:
  std::string text;
 public:
  EnglishName(std::string txt) { this->text = txt; }
 public:
  std::string FirstName() {
    return text.substr(0, text.find(" "));
  }
};
```
---

# Constructors
## Destructor

A destructor is a member function that is invoked automatically when the object goes out of scope or is explicitly destroyed by a call to delete. A destructor has the same name as the class, preceded by a tilde (~). For example, the destructor for class String is declared: ~String().

If you don't define a destructor, the compiler provides a default one; for many classes this is sufficient. You only need to define a custom destructor when the class stores handles to system resources that need to be released, or pointers that own the memory they point to.

---

# Constructors
## Destructor example
```cpp
#include <string>
class String {
 public:
  String(char *ch);                  // Declare constructor
  ~String();                         // and destructor.
 private:
  char *_text;
  size_t sizeOfText;
};
String::String(char *ch) {           // Define the constructor.
  sizeOfText = strlen(ch) + 1;
  _text = new char[sizeOfText];      // Dynamically allocate the correct amount of memory.
  if (_text)
    strcpy(_text, ch);               // If the allocation succeeds, copy the initialization string.
}
String::~String() {                  // Define the destructor.
  delete[] _text;                    // Deallocate the memory that was previously reserved for this string.
}
int main() {
  String str("The point is there ain't no point.");
}
```

---
layout: statement
---

# Task

---

# Constructors
## Task
Task
* Write a program which will showcase delegation of the constructors and the flexibility it provides.

---

# Constructors
## Sources
* [Destructors (C++)](https://learn.microsoft.com/en-us/cpp/cpp/destructors-cpp?view=msvc-170)


---
layout: statement
---

# Thank you
Feel free to reach me via [LinkedIn](https://www.linkedin.com/in/hamerlinski)

---
layout: statement
---

# *Fin*
