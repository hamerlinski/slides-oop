#include <mutex>
#include <stdexcept>
#include <iostream>

class Permit {
 public:
  explicit Permit(std::mutex& m) : m_(m) {
    m_.lock();
  }
  
  ~Permit() {
    m_.unlock();
  }
  
  Permit(const Permit&) = delete;
  Permit& operator=(const Permit&) = delete;
  
 private:
  std::mutex& m_;
};

class Foo {
 public:
  void Print(int x) {
    std::unique_lock<std::mutex> lock(mutex_);
    try {
      Permit p(mutex_);
      if (x > 1000) {
        throw std::runtime_error("Too large!");
      }
      std::cout << "x = " << x << std::endl;
    } catch (const std::exception& e) {
      std::cerr << e.what() << std::endl;
    }
  }

 private:
  std::mutex mutex_;
};

int main() {
  Foo foo;
  foo.Print(500);
  foo.Print(2000);
  foo.Print(800);
  return 0;
}
