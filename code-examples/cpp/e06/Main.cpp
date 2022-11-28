#include <iostream>
#include <filesystem>
#include "include/content/FileContent.h"
#include "include/log/Logarithm.h"

int main() {
  int example;
  std::cout << "Select example...\n[0] - FileContent\n[1] - Logarithm\nOption: ";
  std::cin >> example;
  if (example == 0) {
    FileContent file_content("/var/tmp/test.txt");
    std::cout << "File content:\n";
    try {
      file_content.read();
    } catch (std::filesystem::filesystem_error const &ex) {
      std::cout
          << "What: " << ex.what() << '\n'
          << "Where: " << ex.path1() << '\n';
    }
    std::cout << "File content deletion\n";
    try {
      file_content.del();
    } catch (std::filesystem::filesystem_error const &ex) {
      std::cout
          << "What: " << ex.what() << '\n'
          << "Where: " << ex.path1() << '\n';
    }
    std::cout << "File content:\n";
    try {
      file_content.read();
    } catch (std::filesystem::filesystem_error const &ex) {
      std::cout
          << "What: " << ex.what() << '\n'
          << "Where: " << ex.path1() << '\n';
    }

  } else if (example == 1) {
    try {
      Logarithm logarithm(2, 8);
      std::cout << logarithm.doubleValue() << std::endl;
    } catch (std::logic_error ex) {
      std::cout << ex.what() << std::endl;
    }
  }
  return 0;
}
