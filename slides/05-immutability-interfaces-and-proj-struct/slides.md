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
colorSchema: 'light'
lineNumbers: true
title: 'Object Oriented Programming'
fonts:
  provider: 'none'
  sans: 'Canela Text'
  local: 'Canela Text'
layout: fact
---

# Poznan University of Technology
## Object Oriented Programming
## Immutability, interfaces, and project structure
Jakub Piotr Hamerliński, M.Eng.

---
layout: image-right
image: 'angela.png'
---

# Object Oriented Programming
## Agenda
Immutability, interfaces, project structure, and task
> _**Dwight**: Give me the punch card.<br>
**Angela**: No. If you want to punch the punch card, you have to take me to the show.<br>
**Dwight**: That is not in the contract.<br>
**Angela**: Well, there's a lot of gray area in that clause. Do you want to re-mediate?<br>
**Dwight**: Alright, fine. I'll go to your little show, but I'm not wearing a cape.
**Angela**: Thank you.<br>
**Angela**: Dwight and I have a contractual agreement to procreate five times, plain and simple. And should he develop feelings for me, well, that would be permissible under item 7C, clause 2, so I would not object._

---
layout: statement
---

# Immutability

---
layout: quote
---

# **immutability** (noun,  BrE /ɪˌmjuːtəˈbɪləti/):<br> the fact of never changing or being changed

Oxford Dictionary

---

# Object Oriented Programming
## Immutability
A good object should never change his encapsulated state.<br>
```cpp
// Bad example:
class Bucks {
 private:
  float amount;
 public:
  void Multiply(float factor) { this->amount *= factor; }
  std::string Balance() {
    return "$" + s; // portion of code to achieve float with proper precision skipped (...)
  }
  explicit Bucks(float amnt) { this->amount = amnt; }
};
int main() {
  Bucks five(5.00f);
  five.Multiply(10.00f);
  std::cout << five.Balance(); // oops! "$50.00" will be printed!
  return 0;
}
```

---

# Object Oriented Programming
## Immutability
A good object should never change his encapsulated state.<br>
```cpp
// Good example:
class Bucks {
  // (...)
  public:
    Bucks MultipliedCash(float factor) { return Bucks(this->amount * factor); }
  // (...)
}

Bucks five(5.00f);
Bucks fifty = five.MultipliedCash(10.00f);
std::cout<<fifty.Balance(); // "$50.00" will be printed :)
```

---

# Object Oriented Programming
## Immutability
A good object should never change his encapsulated state.<br>
Good example:
```cpp
class HTTPStatus: public Status {
 private:
  curlpp::options::Url page;;
 public:
  HTTPStatus(curlpp::options::Url url;) {
    this->page = url;
  };
  std::string ResponseCode() override {
    curlpp::Easy request;
    using namespace curlpp::Options;
    request.setOpt(page);
    request.perform();
    return curlpp::infos::ResponseCode::get(request);
  }
}
```
---

# Object Oriented Programming
## Immutability

* Immutable objects are simpler to construct, test, and use.
* Truly immutable objects are always thread-safe.
* They help avoid temporal coupling.
* Their usage is side-effect free.
* They are much easier to cache.
* They prevent NULL references.

---
layout: statement
---

# Interfaces

---

# Object Oriented Programming
## Interfaces
Interface is a contract that object must obey. It consists of methods declarations.
```cpp
class Money {
 public:
  Money(){};
  virtual ~Money(){}
  virtual std::string Balance() = 0;
};
```
Compared to Java, the C++ does not lack anything in the area of interfaces.

Java creates an artificial distinction between an `interface` and a `class` from the perspective of a C++. An `interface` is simply a `class` with all of its functions being abstract and no data members allowed.

Java imposes this limitation because it does not permit multiple descent that is unrestricted but does permit a class to implement multiple interfaces.

An interface is a class in C++, and vice versa. `implements` and `extends` can both be accomplished through public inheritance.

---

# Object Oriented Programming
## Interfaces
```cpp
#pragma once
#include <string>
class Money {
 public:
  Money(){};
  virtual ~Money(){}
  virtual Money *MultipliedBalance(float factor) = 0;
  virtual std::string Balance() = 0;
};
```
```cpp
class Cash: public Money {
 private:
  float dollars;
 public:
  Cash *MultipliedBalance(float factor){ return new Cash(dollars * factor); }
  std::string Balance(){ return "$"; } /* portion of code to achieve float with proper precision skipped(...) */
  Cash(float dollars){ this->dollars = dollars; }
};
int main() {
  Cash smallCash(1.0f);
  Cash *biggerCash = smallCash.MultipliedBalance(69.0f);
}
```

---

# Object Oriented Programming
## Interfaces
The rule here is simple: every public method in a good object should implement his counterpart from an interface. If your object has public methods that are not inherited from any interface, he is badly designed. There are two practical reasons for this. First, an object working without a contract is impossible to mock in a unit test. Second, a contract-less object is impossible to extend via decoration.

> **Class exists only because someone needs its service. The service must be documented - it's a contract, an interface.**

---

# Object Oriented Programming
## Multiple implementation of the interfaces
Let's start with the interface:
```cpp
#pragma once
#include <string>
class Money {
 public:
  Money(){};
  virtual ~Money(){}
  virtual Money *MultipliedBalance(float factor) = 0;
  virtual std::string Balance() = 0;
};
```

---

# Object Oriented Programming
## Multiple implementation of the interfaces
Next we will create two classes: `Cash` and `Digital` in header files `.h`:
```cpp
#include "Money.h"
class Cash : public Money {
 public:
  Cash *MultipliedBalance(float factor) override;
  std::string Balance() override;
  explicit Cash(float dollars);
 private:
  float dollars;
};
```
```cpp
#include "Money.h"
class Digital : public Money {
 public:
  Digital *MultipliedBalance(float factor) override;
  std::string Balance() override;
  explicit Digital(float btc);
 private:
  float btc;
};
```

---

# Object Oriented Programming
## Multiple implementation of the interfaces
Please notice that we only declare methods and constructors. We will implement them in `.cpp` files.
```cpp
#include <sstream>
#include <iomanip>
#include "../include/Cash.h"
std::string Cash::Balance() {
  std::stringstream stream;
  stream << std::fixed << std::setprecision(2) << dollars;
  std::string s = stream.str();
  return "$" + s;
}
Cash *Cash::MultipliedBalance(float factor) {
  Cash *b = new Cash(dollars * factor);
  return b;
}
Cash::Cash(float dollars) { this->dollars = dollars; }
```

---

# Object Oriented Programming
## Multiple implementation of the interfaces
Please notice that we only declare methods and constructors. We will implement them in `.cpp` files.
```cpp
#include <sstream>
#include <iomanip>
#include "../include/Digital.h"
Digital *Digital::MultipliedBalance(float factor) {
  Digital *d = new Digital(this->btc * factor);
  return d;
}
std::string Digital::Balance() {
  std::stringstream stream;
  stream << std::fixed << std::setprecision(4) << btc;
  std::string s = stream.str();
  return s + " BTC";
}
Digital::Digital(float btc) { this->btc = btc; }
```

---

# Object Oriented Programming
## Multiple implementation of the interfaces
Next step is to create a class that fill use Money's implementation:
```cpp
#include <string>
#include <iostream>
#include "Money.h"
class Employee {
 public:
  Employee(const std::string &name, Money *salary);
  void PrintInformation();
 private:
  std::string name;
  Money *salary;
};
```
Similarly to the previous steps, we will implement class in .cpp file.
```cpp
#include "../include/Employee.h"
Employee::Employee(const std::string &name, Money *salary) : name(name), salary(salary) {}
void Employee::PrintInformation() {
  std::cout << "My name is " << this->name << " and I earn " << this->salary->Balance() << std::endl;
}
```
---

# Object Oriented Programming
## Multiple implementation of the interfaces
Usage:
```cpp
#include <iostream>
#include "../include/Cash.h"
#include "../include/Digital.h"
#include "../include/Employee.h"
int main() {
  Money *dollars = new Cash(1000.0f);
  Money *btc = new Digital(0.037f);
  Employee grandfather("Abraham", dollars);
  Employee grandson("Jimmy", btc);
  grandfather.PrintInformation();
  grandson.PrintInformation();
  return 0;
}
```
---
layout: section
---

# Project structure

---

# Object Oriented Programming
## Project structure
```shell
.
├── include
│   ├── weather
│   │   ├── Weather.h
│   │   └── Forecast.h
│   └── math
│       ├── Logarithm.h
│       └── Number.h
└── src
    ├── main.cpp
    ├── weather
    │   └── Forecast.cpp
    └── math
        └── Logarithm.cpp
```

> **Declarations in headers in /include, implementation in cpp files in /src**

Example template can be found here: [cpp-project-template-by-google](https://github.com/hamerlinski/cpp-project-template-by-google)

---
layout: statement
---

# Task

---

# Object Oriented Programming
## Task
Write an **interface** and a **class** which will be immutable and will implement that **interface**.

---
layout: statement
---

# Thank you
Feel free to reach me via [LinkedIn](https://www.linkedin.com/in/hamerlinski)

---
layout: statement
---

# *Fin*
