#include <iostream>
#include <fstream>
#include "../../include/content/FileContent.h"

void FileContent::read() {
  std::string myText;
  if (std::filesystem::exists(file_path)) {
    std::ifstream MyReadFile(file_path);
    while (getline(MyReadFile, myText)) {
      std::cout << myText;
    }
    std::cout << "\n";
    MyReadFile.close();
  } else {
    std::filesystem::path path(file_path);
    std::error_code error_code;
    throw std::filesystem::filesystem_error("File does not exists", path, error_code);
  }

}
void FileContent::del() {
  if (std::filesystem::exists(file_path)) {
    std::ofstream ofs;
    ofs.open(file_path, std::ofstream::out | std::ofstream::trunc);
    ofs.close();
  } else {
    std::filesystem::path path(file_path);
    std::error_code error_code;
    throw std::filesystem::filesystem_error("File does not exists", path, error_code);
  }

}
FileContent::FileContent(std::string file_path) {
  this->file_path = file_path;
}