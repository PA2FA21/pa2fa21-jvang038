/*
 * Name        : functions.cpp
 * Author      : Luke Sathrum
 * Description : Example of a function in C++
 */

#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;

/*
 * TotalCost computes the total cost based on the price and quantity of an item
 */
<<<<<<< HEAD
double TotalCost(int quantity, double price); // COPY AND PASTE, ADD TO THE BOTTOM OUTSIDE MAIN
=======
double TotalCost(int quantity, double price);
>>>>>>> 574ddc81ea76f8cfdc9cdc205547e5bc9ff4a1a8

// Program starts here
int main() {
  // Set up our Variables
  double price, bill;
  int number;

  // Get price and number from the user
  cout << "Enter the number of items purchased: ";
  cin >> number;
  cout << "Enter the price per item $";
  cin >> price;

  // Call function TotalCost
<<<<<<< HEAD
  bill = TotalCost(number, price); //CALLING THE FUNCTION TotalCost(INT, DOUBLE) STORE IN BILL
  // A Magic Formula for setting precision
  cout.setf(std::ios::fixed | std::ios::showpoint);
  cout.precision(2); //PRECISION SETS DECIMAL POINTS TO 2 
=======
  bill = TotalCost(number, price);
  // A Magic Formula for setting precision
  cout.setf(std::ios::fixed | std::ios::showpoint);
  cout.precision(2);
>>>>>>> 574ddc81ea76f8cfdc9cdc205547e5bc9ff4a1a8
  // Output our computed bill
  cout << endl << number << " items @ $" << price << " each.\n"
       << "Final bill: $" << bill << endl;

  // This ends our program
  return 0;
}

<<<<<<< HEAD
double TotalCost(int quantity, double price) { // ADD CURLYS AND WHAT YOUR RETURNING
=======
double TotalCost(int quantity, double price) {
>>>>>>> 574ddc81ea76f8cfdc9cdc205547e5bc9ff4a1a8
  // Calculate and return the total cost
  return price * quantity;
}
