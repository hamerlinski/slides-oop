#include <chrono>
#include <iostream>
#include <mutex>
#include <random>
#include <thread>
#include <vector>

class Task {
 public:
  explicit Task(int task_number) : task_number_(task_number) {}

  void Execute() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(100, 1000);
    int sleep_time = distr(gen);

    std::this_thread::sleep_for(std::chrono::milliseconds(sleep_time));

    std::lock_guard<std::mutex> lock(print_mutex_);
    std::cout << "Task " << task_number_ << " completed in "
              << sleep_time << " milliseconds" << std::endl;
  }

 private:
  int task_number_;
  static std::mutex print_mutex_;
};

std::mutex Task::print_mutex_;

class Process {
 public:
  explicit Process(int num_threads) : num_threads_(num_threads) {}

  void Run() {
    std::vector<std::thread> threads;

    for (int i = 0; i < num_threads_; ++i) {
      Task task(i);
      threads.emplace_back(&Task::Execute, task);
    }

    for (auto& thread : threads) {
      if (thread.joinable()) {
        thread.join();
      }
    }
  }

 private:
  int num_threads_;
};

int main() {
  int num_threads = 5;
  Process process(num_threads);
  process.Run();

  return 0;
}
