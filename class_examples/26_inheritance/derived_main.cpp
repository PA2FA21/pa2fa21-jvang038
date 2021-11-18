/*
 * Name        : derived_main.cpp
 * Author      : Luke Sathrum
 * Description : Testing our derived and base class. This file uses person.h,
 *               baseball_player.h, employee.h and supervisor.h
 */

#include <iostream>
#include "person.h"
#include "baseball_player.h"
using std::cout;
using std::endl;

// Program starts here
int main() {
  // Create an instance of our base class
  Person me("Abraham Lincoln", 56, 'M');
  cout << me.ToString() << endl;

  // Create an instance of our derived class
  BaseballPlayer mays(.302, 660);
  cout << mays.ToString() << endl;

  // That's not the right info, let's change it
  mays.set_name("Willie Mays");
  mays.set_age(83);
  mays.set_gender('M');
  cout << mays.ToString() << endl;

  // This ends our program
  return 0;
}
