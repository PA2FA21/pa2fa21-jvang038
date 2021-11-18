/*
 * Name        : base_main.cpp
 * Author      : Luke Sathrum
 * Description : Testing our base class. This file uses person.h
 */

#include <iostream>
#include "person.h"
using std::cout;
using std::endl;

// Program starts here
int main() {
  // Create an instance of our base class
  Person me("Abraham Lincoln", 56, 'M');
  cout << me.ToString() << endl;

  // This ends our program
  return 0;
}
