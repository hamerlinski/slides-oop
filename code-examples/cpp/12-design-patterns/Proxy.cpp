#include <iostream>
#include <string>
class Image {
public:
  virtual void display() = 0;
  virtual ~Image() = default;
};
class RealImage : public Image {
public:
  explicit RealImage(const std::string& fileName) : fileName_{fileName} {
    loadFromDisk(fileName);
  }
  void display() override { std::cout << "Displaying " << fileName_ << "\n"; }
private:
  void loadFromDisk(const std::string& fileName) { std::cout << "Loading " << fileName << "\n"; }
  std::string fileName_;
};
class ImageProxy : public Image {
public:
  explicit ImageProxy(const std::string& fileName) : fileName_{fileName} {}
  void display() override {
    if (!realImage_) {
      realImage_ = std::make_unique<RealImage>(fileName_);
    }
    realImage_->display();
  }
private:
  std::unique_ptr<RealImage> realImage_;
  std::string fileName_;
};
int main() {
  ImageProxy image{"test_10mb.jpg"};
  image.display();
  std::cout << "\n";
  image.display();
}
