/*
 * Name        : inheritance_chain.cpp
 * Author      : Luke Sathrum
 * Description : Figuring out what gets called when...
 */

#include <iostream>
using std::cout;
using std::endl;

// The base class
class A {
 public:
  A() {
    cout << "A" << endl;
  }
};

// Derived class (from A)
class B : public A {
 public:
  B() {
    cout << "B" << endl;
  }
};

// Derived class (from B)
class C : public B {
 public:
  C() {
    cout << "C" << endl;
  }
};

// Derived class (from C)
class D : public C {
 public:
  D() {
    cout << "D" << endl;
  }
};

// Program starts here
int main() {
  // Create an instance of A
  cout << "Constructing A: " << endl;
  A a;

  // Create an instance of B
  cout << "Constructing B: " << endl;
  B b;

  // Create an instance of C
  cout << "Constructing C: " << endl;
  C c;

  // Create an instance of D
  cout << "Constructing D: " << endl;
  D d;

  // This ends our program
  return 0;
}
