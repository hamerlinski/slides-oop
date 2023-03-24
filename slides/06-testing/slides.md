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
## Testing
Jakub Piotr Hamerliński, M.Eng.

---
layout: image-right
image: 'creed.png'
---

# Object Oriented Programming
## Agenda
* Introduction to unit testing
* Task
<br><br>
> "Every week, I'm supposed to take four hours and do a quality spot-check at the paper mill. And of course the one year I blow it off, this happens."

Creed Bratton

---
layout: section
---

# Introduction to unit testing

---

# Object Oriented Programming
## Introduction to unit testing

In testing world it's popular to use mocks for unit testing. One of the flaws of mocking is that these tests became verbose, and because of that, the maintainability is decreased. I think this approach is bad and instead of mocks, we should use fakes.
Fake is a class that mimic behavior of the original one.

```java
public class Cash {
  private final Exchange exchange;
  private final float amount;
  public Cash(Exchange exch, float amnt) {
    this.exchange = exch;
    this.amount = amnt;
  }
  public Cash exchangedCash(String currency) {
    return new Cash(this.exchange, (this.amount * this.exchange.rate("USD", currency)));
  }
  @Override
  public String toString() {
    return Float.toString(amount);
  }
}
```

---

# Object Oriented Programming
## Introduction to unit testing

```java
public interface Exchange {
  float rate(String origin, String target);
  final class Fake implements Exchange {
    @Override
    public float rate(String origin, String target) {
      return 1.2345f;
    }
  }
}
```

---

# Object Oriented Programming
## Introduction to unit testing

```java
public class Application {

  public static void main(String[] args) {
    Exchange exchange = new Exchange.Fake();
    Cash dollar = new Cash(exchange, 500);
    Cash euro = dollar.exchangedCash("EUR");
    assert "617.25".equals(euro.toString());
  }
}
```

---

# Object Oriented Programming
## Task
1. Create class Weather, which encapsulates interface Forecast, which declares method returning todays temperature. Create Fake class inside Forecast, which will return some, always the same, value. Show usage of the class Weather.