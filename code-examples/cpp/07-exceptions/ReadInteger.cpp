#include <iostream>
#include <stdexcept>

int readInteger() {
  int value;
  std::cout << "Enter an integer: ";
  std::cin >> value;
  if (std::cin.fail()) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    throw std::invalid_argument("Invalid input");
  }
  return value;
}

int main() {
  try {
    int value = readInteger();
    std::cout << "You entered: " << value << std::endl;
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }
  return 0;
}
