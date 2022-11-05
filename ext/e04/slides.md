---
theme: apple-basic
colorSchema: 'light'
lineNumbers: true
title: 'Object Oriented Programming'
# canvasWidth: 800
fonts:
  provider: 'none'
  # like font-family in css, you can use `,` to separate multiple fonts for fallback
  sans: 'Canela Text'
  # mark 'Helvetica Neue' as local font
  local: 'Canela Text'
layout: fact
---

# Poznan University of Technology
## Object Oriented Programming
Jakub Piotr Hamerliński, M.Eng.

---

# Object Oriented Programming
## Agenda
* Interfaces
* Immutability
* Task

---
layout: section
---

# Interfaces

---

# Object Oriented Programming
## Interfaces
Interface is a contract that object must obey. It consists of methods declarations.
```java
interface Money {
  Money multiply(float factor);
  String balance();
}
```

---

# Object Oriented Programming
## Interfaces
```java
interface Money {
  Money multiply(float factor);
  String balance();
}
```
```java
public class Cash implements Money {
  private final float dollars;
  @Override
  public Cash multiply(float factor) { return new Cash(this.dollars * factor); }
  @Override
  public String balance() { return "$" + dollars; }
  public Cash(float dollars) { this.dollars = dollars; }
}
```
```java
class Employee {
  private Money salary;
}
```

---

# Object Oriented Programming
## Interfaces
The rule here is simple: every public method in a good object should implement his counterpart from an interface. If your object has public methods that are not inherited from any interface, he is badly designed. There are two practical reasons for this. First, an object working without a contract is impossible to mock in a unit test. Second, a contract-less object is impossible to extend via decoration.

Class exists only because someone needs its service. The service must be documented - it's a contract, an interface.

---
layout: section
---

# Immutability

---
layout: quote
---

**immutability** (noun,  BrE /ɪˌmjuːtəˈbɪləti/):<br>
the fact of never changing or being changed

Oxford Dictionary

---

# Object Oriented Programming
## Immutability
A good object should never change his encapsulated state.<br>
Bad example:
```java
class Cash {
  private int dollars;
  public void multiply(int factor) { this.dollars *= factor; }
}

Cash five = new Cash(5);
five.multiply(10);
System.out.println(five); // oops! "50" will be printed!
```
Good example:
```java
class Cash {
  private final int dollars;
  public Cash multipliedCash(int factor) { return new Cash(this.dollars * factor); }
}

Cash five = new Cash(5);
Cash fifty = five.multiply(10);
System.out.println(fifty); // "50" will be printed :)
```
---

# Object Oriented Programming
## Immutability
A good object should never change his encapsulated state.
```java
final class HTTPStatus implements Status {
  private URL page;
  public HTTPStatus(URL url) {
    this.page = url;
  }
  @Override
  public int read() {
    return HttpURLConnection.class.cast(
      this.page.openConnection()
    ).getResponseCode();
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

# Object Oriented Programming
## Task
Write a interface and **class (choose one from examples - different than in previous exercise)** in Java, which will be immutable and will implement interface.<br><br>
**Class** examples: 1) Movie, 2) Vehicle, 3) Book, 4) Animal, 5) Plant, and 6) Game.

---
layout: fact
---

# Questions?

---
layout: fact
---

# *Fin*
