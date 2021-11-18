/*
 * Name        : vectors.cpp
 * Author      : Luke Sathrum
 * Description : Working with Vectors
 */

#include <vector>     // std::vector
#include <stdexcept>  // std::out_of_range
#include <iostream>   // std::cout, std::cerr, std::endl
using std::vector;
using std::cout;
using std::endl;

// Outputting our Vector
void OutputVector(const vector<int> &v) {
  cout << "Size: " << v.size() << "\nContents: ";
  for (unsigned int i = 0; i < v.size(); i++)
    cout << v[i] << " ";
  cout << endl << endl;
}

// Program starts here
int main() {
  // Calling different Constructors
  vector<int> v1;
  cout << "vector<int> v1\n";
  OutputVector(v1);

  cout << "vector<int> v2(10)\n";
  vector<int> v2(10);
  OutputVector(v2);

  cout << "vector<int> v3(10, -1)\n";
  vector<int> v3(10, -1);
  OutputVector(v3);

  int array[] = { 1, 2, 3, 4, 5 };
  cout << "vector<int> v4(array, array + 5)\n";
  vector<int> v4(array, array + 5);
  OutputVector(v4);

  cout << "vector<int> v5(v2)\n";
  vector<int> v5(v2);
  OutputVector(v5);

  // Changing a value in the vector
  // Unsafe
  v2[5] = 5;
  // Safe
  v2.at(6) = 6;
  OutputVector(v2);

  // Unsafe (May crash the program)
  // v2[100] = 10;
  // Safe
  try {
    v2.at(10) = 10;  // vector::at throws an out-of-range
  } catch (const std::out_of_range& oor) {
    std::cerr << "Out of Range error: " << oor.what() << endl;
  }

  // Adding to the end
  v1.push_back(5);
  v1.push_back(6);
  v1.push_back(7);
  cout << "v1.push_back(5), v1.push_back(6), v1.push_back(7)\n";
  OutputVector(v1);

  // This ends our program
  return 0;
}
