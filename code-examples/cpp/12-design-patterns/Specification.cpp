#include <iostream>
#include <memory>
#include <vector>

class Product {
 public:
  Product(const std::string& name, double price) : name_(name), price_(price) {}

  const std::string& Name() const { return name_; }
  double Price() const { return price_; }

 private:
  std::string name_;
  double price_;
};

class Specification {
 public:
  virtual ~Specification() = default;
  virtual bool IsSatisfied(const Product& product) const = 0;
};

class PriceSpecification : public Specification {
 public:
  PriceSpecification(double min_price, double max_price)
      : min_price_(min_price), max_price_(max_price) {}

  bool IsSatisfied(const Product& product) const override {
    return product.Price() >= min_price_ && product.Price() <= max_price_;
  }

 private:
  double min_price_;
  double max_price_;
};

class NameSpecification : public Specification {
 public:
  explicit NameSpecification(const std::string& name) : name_(name) {}

  bool IsSatisfied(const Product& product) const override {
    return product.Name() == name_;
  }

 private:
  std::string name_;
};

class AndSpecification : public Specification {
 public:
  AndSpecification(const Specification& spec1, const Specification& spec2)
      : spec1_(spec1), spec2_(spec2) {}

  bool IsSatisfied(const Product& product) const override {
    return spec1_.IsSatisfied(product) && spec2_.IsSatisfied(product);
  }

 private:
  const Specification& spec1_;
  const Specification& spec2_;
};

class Filter {
 public:
  static std::vector<Product> ApplyFilter(
      const std::vector<Product>& products,
      const Specification& specification) {
    std::vector<Product> filtered_products;
    for (const auto& product : products) {
      if (specification.IsSatisfied(product)) {
        filtered_products.push_back(product);
      }
    }
    return filtered_products;
  }
};

int main() {
  std::vector<Product> products = {
      Product("Apple", 1.5),
      Product("Orange", 1.0),
      Product("Apple", 1.9),
      Product("Banana", 0.8),
      Product("Mango", 2.0),
      Product("Apple", 2.1),
  };

  PriceSpecification price_spec(1.0, 2.0);
  NameSpecification name_spec("Apple");
  AndSpecification and_spec(price_spec, name_spec);

  auto filtered_products = Filter::ApplyFilter(products, and_spec);

  for (const auto& product : filtered_products) {
    std::cout << product.Name() << " - " << product.Price() << std::endl;
  }

  return 0;
}
