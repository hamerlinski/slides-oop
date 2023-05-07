#include <iostream>
#include <memory>
#include <string>
#include <vector>

class PaymentStrategy {
 public:
  virtual ~PaymentStrategy() {}
  virtual void Pay(double amount) = 0;
};

class CreditCardStrategy : public PaymentStrategy {
 public:
  CreditCardStrategy(const std::string& name, const std::string& cardNumber,
                      const std::string& cvv, const std::string& dateOfExpiry)
      : name_(name), cardNumber_(cardNumber), cvv_(cvv), dateOfExpiry_(dateOfExpiry) {}

  void Pay(double amount) override {
    std::cout << amount << " paid with credit/debit card\n";
  }

 private:
  std::string name_;
  std::string cardNumber_;
  std::string cvv_;
  std::string dateOfExpiry_;
};

class PayPalStrategy : public PaymentStrategy {
 public:
  PayPalStrategy(const std::string& emailId, const std::string& password)
      : emailId_(emailId), password_(password) {}

  void Pay(double amount) override {
    std::cout << amount << " paid using PayPal.\n";
  }

 private:
  std::string emailId_;
  std::string password_;
};

class Item {
 public:
  virtual ~Item() {}
  virtual double Price() const = 0;
};

class ShoppingCart {
 public:
  ShoppingCart(const std::vector<std::unique_ptr<Item>>& items, PaymentStrategy* paymentMethod)
      : items_(items), paymentMethod_(paymentMethod) {}

  void Pay() {
    double totalAmount = CalculateTotal();
    paymentMethod_->Pay(totalAmount);
  }

 private:
  double CalculateTotal() const {
    double total = 0;
    for (const auto& item : items_) {
      total += item->Price();
    }
    return total;
  }

  std::vector<std::unique_ptr<Item>> items_;
  PaymentStrategy* paymentMethod_;
};

class Book : public Item {
 public:
  Book(double price) : price_(price) {}

  double Price() const override {
    return price_;
  }

 private:
  double price_;
};

class Movie : public Item {
 public:
  Movie(double price) : price_(price) {}

  double Price() const override {
    return price_;
  }

 private:
  double price_;
};

int main() {
  std::vector<std::unique_ptr<Item>> items;
  items.emplace_back(std::make_unique<Book>(9.99));
  items.emplace_back(std::make_unique<Movie>(14.99));
  items.emplace_back(std::make_unique<Book>(12.99));
  items.emplace_back(std::make_unique<Movie>(19.99));

  PaymentStrategy* paymentMethod = new CreditCardStrategy("John Doe", "1234 5678 9012 3456", "123", "06/24");

  ShoppingCart cart(items, paymentMethod);

  cart.Pay();

  delete paymentMethod;

  paymentMethod = new PayPalStrategy("john.doe@example.com", "password123");

  cart = ShoppingCart(items, paymentMethod);

  cart.Pay();

  delete paymentMethod;

  return 0;
}
