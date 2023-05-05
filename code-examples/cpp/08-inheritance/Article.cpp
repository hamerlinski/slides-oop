#include <iostream>
#include <string>

// Define the Manuscript interface as an abstract class
class Manuscript {
 public:
  virtual ~Manuscript() = default;

  // A pure virtual function that must be overridden by derived classes
  virtual void Print(std::ostream& console) const = 0;
};

// Define the Article interface that extends the Manuscript interface
class Article : public Manuscript {
 public:
  // A pure virtual function that must be overridden by derived classes
  virtual void Submit(const std::string& conference) const = 0;
};

// Implement the Article interface in a derived class
class ResearchArticle : public Article {
 public:
  void Print(std::ostream& console) const override {
    console << "Printing research article..." << std::endl;
  }

  void Submit(const std::string& conference) const override {
    std::cout << "Submitting research article to conference: " << conference << std::endl;
  }
};

int main() {
  ResearchArticle research_article;

  // Use the derived class through the Manuscript interface (subtyping)
  research_article.Print(std::cout);  // Output: Printing research article...

  // Use the derived class through the Article interface (subtyping)
  research_article.Submit("The International Conference on C++");  // Output: Submitting research article to conference: The International Conference on C++

  return 0;
}
