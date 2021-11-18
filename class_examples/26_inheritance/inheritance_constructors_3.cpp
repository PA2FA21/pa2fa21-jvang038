/*
 * Name        : inheritance_constructors_3.cpp
 * Author      : Luke Sathrum
 * Description : Wrong way to call the parent constructor
 */

#include <iostream>
using std::cout;
using std::endl;

// The base class
class BaseClass {
 public:
  // The constructor
  BaseClass(int value = 0)
      : value_(value) {
  }
  // A public member variable
  const int value_;
};

// The derived class
class DerivedClass : public BaseClass {
 public:
  // The constructor
  DerivedClass(int value, double d_value = 0.0)
      : d_value_(d_value) {
    value_ = value;
  }
  // A public member variable
  double d_value_;
};

// Program starts here
int main() {
  // Create an instance of base
  BaseClass base(5);
  cout << "The value of base is: " << base.value_ << endl;

  DerivedClass derived(3, 10.5);
  cout << "The d_value of derived is: " << derived.d_value_ << endl;
  cout << "The value of derived is: " << derived.value_ << endl;

  // This ends our program
  return 0;
}
