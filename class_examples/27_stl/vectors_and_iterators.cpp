/*
 * Name        : vectors_and_iterators.cpp
 * Author      : Luke Sathrum
 * Description : Working with Vectors and Iterators
 */

#include <vector>     // std::vector
#include <stdexcept>  // std::out_of_range
#include <iostream>   // std::cout, std::cerr, std::endl
using std::vector;
using std::cout;
using std::endl;

// Outputting our Vector using iterators
void OutputVector(const vector<int> &v) {
  cout << "Size: " << v.size() << "\nContents: ";
  for (vector<int>::const_iterator it = v.begin(); it != v.end(); it++)
    cout << *it << " ";
  cout << endl << endl;
}

// Program starts here
int main() {
  // Calling different Constructors
  vector<int> v;
  cout << "vector<int> v1\n";

  // Adding to the end
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  cout << "v1.push_back(1), v1.push_back(2), v1.push_back(3)\n";
  OutputVector(v);

  // Inserting an element in the middle
  cout << "v.insert(v.begin() + 2, 10)\n";
  v.insert(v.begin() + 2, 10);
  OutputVector(v);

  // Removing an element in the middle
  cout << "v.erase(v.begin() + 1)\n";
  v.erase(v.begin() + 1);
  OutputVector(v);

  // This ends our program
  return 0;
}
