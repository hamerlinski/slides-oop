#include <iostream>
#include <stdexcept>
#include <thread>
#include <vector>

class Permit {
 public:
  explicit Permit(std::mutex& mtx) : lock_(mtx) {}

 private:
  std::unique_lock<std::mutex> lock_;
};

class Foo {
 public:
  void Print(int x) {
    Permit permit(mutex_);

    try {
      if (x > 1000) {
        throw std::runtime_error("Too large!");
      }

      std::cout << "x = " << x << std::endl;
    } catch (const std::runtime_error& e) {
      std::cerr << "Error: " << e.what() << std::endl;
    }
  }

 private:
  std::mutex mutex_;
};

int main() {
  Foo foo;
  std::vector<std::thread> threads;

  for (int i = 0; i < 10; ++i) {
    threads.emplace_back([&foo, i]() { foo.Print(i * 100); });
  }

  for (auto& t : threads) {
    t.join();
  }

  return 0;
}
