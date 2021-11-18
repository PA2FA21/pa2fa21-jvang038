/*
 * Name        : stl_algorithms.cpp
 * Author      : Luke Sathrum
 * Description : Using STL Algorithms on Vectors
 */

#include <vector>     // std::vector
#include <stdexcept>  // std::out_of_range
#include <algorithm>  // std::min_element, std::max_element, std::find
// std::reverse, std::sort
#include <iostream>   // std::cout, std::cerr, std::endl
using std::vector;
using std::min_element;
using std::max_element;
using std::find;
using std::reverse;
using std::sort;
using std::cout;
using std::endl;

// Outputting our Vector using iterators
void OutputVector(const vector<int> &v) {
  for (vector<int>::const_iterator it = v.begin(); it != v.end(); it++)
    cout << *it << " ";
  cout << endl << endl;
}

// Helper function to sort in descending order
bool SortDescending(int left, int right) {
  return left > right;
}

// Program starts here
int main() {
  // Creating a vector with many random elements
  int my_ints[] = { 32, 71, 12, 45, 26, 80, 53, 33 };
  std::vector<int> v(my_ints, my_ints + 8);
  cout << "The vector: ";
  OutputVector(v);

  // Creating a vector iterator
  vector<int>::iterator it;

  // Finding the largest element
  it = max_element(v.begin(), v.end());
  cout << "The largest value in the vector is:  " << *it << endl;

  // Finding the smallest element
  it = min_element(v.begin(), v.end());
  cout << "The smallest value in the vector is: " << *it << endl;

  // Let's insert a value before the value 26
  cout << "\nAdding 25 before 26\n";
  it = find(v.begin(), v.end(), 26);
  // Just to be safe...
  if (it != v.end())
    v.insert(it, 25);
  cout << "The new vector: ";
  OutputVector(v);

  // Reversing the vector
  cout << "Reversing the vector...\n";
  reverse(v.begin(), v.end());
  cout << "The reversed vector: ";
  OutputVector(v);

  // Basic sort using <
  cout << "Sorting by the default (<)\n";
  sort(v.begin(), v.end());
  cout << "The sorted vector: ";
  OutputVector(v);

  // We can use the SortDesceding Function to sort by >
  cout << "Sorting using function SortDescending (>)\n";
  sort(v.begin(), v.end(), SortDescending);
  cout << "The sorted vector: ";
  OutputVector(v);

  // This ends our program
  return 0;
}
