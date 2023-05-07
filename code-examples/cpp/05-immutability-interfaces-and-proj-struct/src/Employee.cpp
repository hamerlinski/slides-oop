#include "../include/Employee.h"
Employee::Employee(const std::string &name, Money *salary) : name(name), salary(salary) {}
void Employee::PrintInformation() {
  std::cout << "My name is " << this->name << " and I earn " << this->salary->Balance() << std::endl;
}
