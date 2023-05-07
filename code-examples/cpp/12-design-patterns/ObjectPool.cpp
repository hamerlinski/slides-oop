#include <memory>
#include <iostream>
#include <list>

class PooledObject {
 public:
  virtual ~PooledObject() {}
  virtual void Reset() = 0;
};

class Connection : public PooledObject {
 public:
  bool IsInUse() const { return in_use_; }
  void ChangeUsage() { in_use_ = !in_use_; }
  void Reset() override {
    std::cout << "Connection reset\nUsage false\n";
    // code to reset the connection
  }
  Connection () {
    this->in_use_ = false;
  }

 private:
  bool in_use_ = false;
};

class ConnectionPool {
 public:
  std::shared_ptr<Connection> CreateConnection() {
    std::shared_ptr<Connection> connection;
    if (available_connections_.empty()) {
      connection = std::make_shared<Connection>();  // create a new connection
      std::cout << "New connection created\n";
    } else {
      connection = available_connections_.front();  // return an available connection
      available_connections_.pop_front();
      std::cout << "Existing connection reused\n";
    }
    connection->ChangeUsage();
    in_use_connections_.push_back(connection);
    return connection;
  }
  void ReleaseConnection(std::shared_ptr<Connection> connection);
 private:
  std::list<std::shared_ptr<Connection>> available_connections_;
  std::list<std::shared_ptr<Connection>> in_use_connections_;
};
void ConnectionPool::ReleaseConnection(std::shared_ptr<Connection> connection) {
    connection->Reset();
    in_use_connections_.remove(connection);
    available_connections_.push_back(connection);
    std::cout << "Connection released\n";
  }
int main() {
  ConnectionPool pool;
  std::shared_ptr<Connection> connection1 = pool.CreateConnection();
  std::shared_ptr<Connection> connection2 = pool.CreateConnection();
  pool.ReleaseConnection(connection1);
  std::shared_ptr<Connection> connection3 = pool.CreateConnection();
  pool.ReleaseConnection(connection2);
  pool.ReleaseConnection(connection3);
  return 0;
}
