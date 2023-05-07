#include <cassert>
class Response {
 public:
  static Response& Instance() {
    static Response response;
    return response;
  }

 private:
  Response() = default;
  Response(const Response&) = delete;
  Response& operator=(const Response&) = delete;
};

int main() {
  Response& response1 = Response::Instance();
  Response& response2 = Response::Instance();
  assert(&response1 == &response2);
  return 0;
}
