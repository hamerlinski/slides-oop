#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>
#include <algorithm>
#include <cctype>
#include <string>

// Interface
class Text {
 public:
  virtual ~Text() = default;
  virtual std::string Content() = 0;
};

// Concrete Component
class TextInFile : public Text {
 public:
  explicit TextInFile(const std::string& file_path) : file_path_(file_path) {}

  std::string Content() override {
    std::ifstream file(file_path_);
    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
  }

 private:
  std::string file_path_;
};

// Decorator
class TextDecorator : public Text {
 public:
  virtual ~TextDecorator() = default;
};

// Concrete Decorators
class PrintableText : public TextDecorator {
 public:
  explicit PrintableText(std::unique_ptr<Text> text) : text_(std::move(text)) {}

  std::string Content() override {
    std::string content = text_->Content();
    content.erase(std::remove_if(content.begin(), content.end(), [](char c) { return !std::isprint(c); }), content.end());
    return content;
  }

 private:
  std::unique_ptr<Text> text_;
};

class AllCapsText : public TextDecorator {
 public:
  explicit AllCapsText(std::unique_ptr<Text> text) : text_(std::move(text)) {}

  std::string Content() override {
    std::string content = text_->Content();
    std::transform(content.begin(), content.end(), content.begin(), ::toupper);
    return content;
  }

 private:
  std::unique_ptr<Text> text_;
};

class TrimmedText : public TextDecorator {
 public:
  explicit TrimmedText(std::unique_ptr<Text> text) : text_(std::move(text)) {}

  std::string Content() override {
    std::string content = text_->Content();
    content.erase(content.begin(), std::find_if(content.begin(), content.end(), [](unsigned char c) { return !std::isspace(c); }));
    content.erase(std::find_if(content.rbegin(), content.rend(), [](unsigned char c) { return !std::isspace(c); }).base(), content.end());
    return content;
  }

 private:
  std::unique_ptr<Text> text_;
};

int main() {
  // Create a decorated Text object
  std::unique_ptr<Text> text = std::make_unique<AllCapsText>(
      std::make_unique<TrimmedText>(
          std::make_unique<PrintableText>(
              std::make_unique<TextInFile>("sample.txt"))));

  // Content the text using the decorated Text object
  std::string content = text->Content();

  // Output the content
  std::cout << content << std::endl;

  return 0;
}
