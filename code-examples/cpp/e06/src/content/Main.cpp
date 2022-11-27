#include <iostream>
#include <filesystem>
#include "../../include/content/FileContent.h"

int main() {
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
  return 0;
}
