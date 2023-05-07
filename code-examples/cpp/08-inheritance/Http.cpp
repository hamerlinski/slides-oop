#include <iostream>
#include <ctime>
#include <vector>
#include <memory>

class Status {
 public:
  virtual ~Status() = default;
  virtual int Code() const = 0;
};

class HttpStatus : public Status {
 public:
  explicit HttpStatus(int code) : code_(code) {}

  int Code() const override {
    return code_;
  }

 private:
  int code_;
};

class HttpServer {
 public:
  virtual ~HttpServer() = default;
  virtual std::unique_ptr<Status> RequestStatus() = 0;
};

class FakeHttpServer : public HttpServer {
 public:
  FakeHttpServer() {
    srand(static_cast<unsigned>(time(nullptr)));
  }

  std::unique_ptr<Status> RequestStatus() override {
    static const std::vector<int> status_codes = {200, 201, 400, 404, 500};
    int random_code = status_codes[rand() % status_codes.size()];
    return std::make_unique<HttpStatus>(random_code);
  }
};

class HttpRequest {
 public:
  HttpRequest() : status_(nullptr) {}

  void Execute(HttpServer& server) {
    status_ = server.RequestStatus();
  }

  int StatusCode() const {
    return status_->Code();
  }

 private:
  std::unique_ptr<Status> status_;
};

int main() {
  FakeHttpServer server;
  HttpRequest request;

  request.Execute(server);

  std::cout << "HTTP status code: " << request.StatusCode() << std::endl;

  return 0;
}
