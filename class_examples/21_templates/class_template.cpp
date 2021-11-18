/*
 * Name        : class_template.cpp
 * Author      : Luke Sathrum
 * Description : Creating a templated class
 */

#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;

// A simple struct to show a template class can use a structure/class
struct Height {
  int feet;
  int inches;
};

// This class is a wrapper around a single data member. Since it is templated
// that data member can be of any type
template<typename T>
class Simple {
 public:
  /*
   * Constructor
   * @param T value - An initial value to give. Defaults to "zero"
   */
  Simple(const T &value = T());
  /*
   * Accessor
   * @return T - The value of value_
   */
  T value();
  /*
   * Mutator
   * @param T value - A value to set value_ to
   */
  void set_value(const T &value);
 private:
  T value_;
};

// Program starts here
int main() {
  // Create an object with data of type int
  Simple<int> var(5);
  cout << var.value() << endl;

  // Create an object with data of type string
  Simple<string> var2("Hello");
  cout << var2.value() << endl;

  // Create an object with data of type Height
  Height height = { 5, 7 };
  Simple<Height> var3(height);
  cout << var3.value().feet << "' " << var3.value().inches << "\"" << endl;

  // This ends our program
  return 0;
}

template<typename T>
Simple<T>::Simple(const T &value) {
  value_ = value;
}

template<typename T>
T Simple<T>::value() {
  return value_;
}

template<typename T>
void Simple<T>::set_value(const T &value) {
  value_ = value;
}

