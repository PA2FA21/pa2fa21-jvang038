/*
 * Name        : iterators.cpp
 * Author      : Luke Sathrum
 * Description : Working with Vectors
 */

#include <vector>     // std::vector
#include <stdexcept>  // std::out_of_range
#include <iostream>   // std::cout, std::cerr, std::endl
using std::vector;
using std::cout;
using std::endl;

// Program starts here
int main() {
  // Create a vector of size 10
  cout << "Creating vector<int> v(5)\n";
  vector<int> v(5);

  // Create an iterator to use with our vector
  vector<int>::iterator it;

  // Let's use the iterator to output the contents of our vector
  for (it = v.begin(); it != v.end(); it++)
    cout << *it << " ";
  cout << endl << endl;

  // Let's use the iterator to change the values in our vector
  cout << "Filling up our Vector with 5s" << endl;
  for (it = v.begin(); it != v.end(); it++)
    *it = 5;

  // Let's use the iterator to output the contents of our vector again
  for (it = v.begin(); it != v.end(); it++)
    cout << *it << " ";
  cout << endl;

  // This ends our program
  return 0;
}
