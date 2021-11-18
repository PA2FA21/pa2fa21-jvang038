/*
 * Name        : four_max.cpp
 * Author      : Luke Sathrum
 * Description : Example of writing a bunch of overloaded functions that really
 *               do the same thing
 */

#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

// First overloaded function
int Max(int x, int y) {
  if (x > y)
    return x;
  else
    return y;
}

// Second overloaded function
double Max(double x, double y) {
  if (x > y)
    return x;
  else
    return y;
}

// Third overloaded function
char Max(char x, char y) {
  if (x > y)
    return x;
  else
    return y;
}

// Fourth overloaded function
string Max(string x, string y) {
  if (x > y)
    return x;
  else
    return y;
}

// Program starts here
int main() {
  // Call our 4 overloaded functions
  cout << "Which is bigger (5, 10)?     ";
  cout << Max(5, 10) << endl;
  cout << "Which is bigger (5.5, 10.1)? ";
  cout << Max(5.5, 10.1) << endl;
  cout << "Which is bigger ('B', 'a')?   ";
  cout << Max('B', 'a') << endl;
  cout << "Which is bigger (\"Hello\", \"Goodbye\")?   ";
  cout << Max("Hello", "Goodbye") << endl;

  // This ends our program
  return 0;
}
