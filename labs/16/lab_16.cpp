/*
 * Name        : lab_16.cpp
 * Author      : FILL IN
 * Description : Working with a Dynamic Array in a Class
 */
#include <iostream>
#include <string>
#include <cassert>
using std::cout;
using std::cin;
using std::endl;
using std::string;

/*
 * This class creates a Shopping List as a dynamic array of strings.
 */
class ShoppingList {
 public:
  /*
   * Default constructor.
   * Initializes max_items_ to 25, items_ to size max_items_
   * and item_count_ to 0.
   */
  ShoppingList();

  /*
   * Overloaded constructor.
   * Initializes max_items_ to max_items, items_ to size max_items
   * and item_count_ to 0.
   * @param unsigned int max_items - The desired size of the items_ array
   */
  ShoppingList(unsigned int max_items);

  /*
   * Destructor.
   * Frees the memory associated with items_.
   */
  ~ShoppingList();

  /*
   * Accessor for max_items_
   * @return unsigned int - The maximum number of items in this ShoppingList
   */
  unsigned int max_items() const;

  /*
   * Accessor for item_count_
   * @return unsigned int - The count of number of items in this ShoppingList
   */
  unsigned int item_count() const;

  /*
   * Place an item at a specified index in the array and increment the count of
   * items in the array.
   * @param string item - The item to be added to the array
   * @return bool - True if the item can be added, otherwise return false
   */
  bool AddItem(string item);

  /*
   * Retrieve the item at a specified index in the array.
   * The first line of this function is an assertion to check to see if the
   * index is valid.
   * @param unsigned int index - The zero-based index of the item to be
   *                             retrieved
   * @return string - The value of the item at the specified index
   */
  string GetItem(unsigned int index) const;

  /*
   * Retrieve a reference to the item at a specified index in the array.
   * The first line of this function is an assertion to check to see if the
   * index is valid.
   * @param unsigned int index - The zero-based index of the item to be
   *                             retrieved
   * @return string& - A reference to the value of the item at the specified index
   */
  string& GetItem(unsigned int index);

  // Why Two GetItem with the same number/type of parameters?
  // http://www.geeksforgeeks.org/function-overloading-and-const-functions/

  /*
   * Reset the items array by freeing its associated memory and re-allocating to
   * a specified size.
   * The first line of this function is an assertion to check to see if the
   * parameter is greater than 0
   * @param unsigned int max_items - The desired new max size of items_
   */
  void Reset(unsigned int max_items);

 private:
  string* items_;
  unsigned int max_items_;
  unsigned int item_count_;
};

// For testing (DO NOT ALTER)
#include <cctype>
#include <vector>
void UnitTest(int test);
void Test(bool test, int line_number, string more_info = "", string yours = "!",
          string actual = "!");
void OutputFailedTests();
unsigned int ut_passed = 0, ut_failed = 0, ut_total = 0, num_of_tests = 0;
std::vector<int> failed_tests;

// Program Execution Starts Here
int main() {
  // To test your code (DO NOT ALTER)
  int choice;
  cout << "0 to test without Assertions\n"
       << "All other tests below should break on an Assertion\n"
       << "1 - GetItem(0) from an empty list\n"
       << "2 - GetItem(26) from size 25 list\n"
       << "3 - GetItem(0) = \"oranges\" on an empty list\n"
       << "4 - GetItem(1) from a list of size 1\n" << "5 - Reset(0)\n"
       << "6 - GetItem(6) from size 5 list\n" << "Choice: ";
  cin >> choice;
  cout << endl;
  UnitTest(choice);
  // This ends program execution
  return 0;
}

// CODE HERE -- FUNCTION DEFINITIONS


// For testing (DO NOT ALTER)
void UnitTest(int test) {
  cout << string(40, '-') << endl;
  cout << "UNIT TEST:\n" << string(40, '-') << endl;
  if (num_of_tests != 0)
    cout << "Total Number of Tests: " << num_of_tests << endl;
  string yours = "", actual = "";

  ShoppingList* myList = new ShoppingList;
  cout << "* DEFAULT CONSTRUCTOR *\n\n";

  Test(myList->max_items() == 25, __LINE__, "max_items()");
  Test(myList->item_count() == 0, __LINE__, "item_count()");
  if (test == 1)
    myList->GetItem(0);
  Test(myList->AddItem("apples") == true, __LINE__, "AddItem(\"apples\")");
  Test(myList->item_count() == 1, __LINE__, "item_count()");
  yours = myList->GetItem(0);
  actual = "apples";
  Test(yours == actual, __LINE__, "GetItem(0)", yours, actual);

  myList->GetItem(0) = "oranges";
  yours = myList->GetItem(0);
  actual = "oranges";
  Test(yours == actual, __LINE__, "GetItem(0) = \"oranges\"", yours, actual);

  for (unsigned int i = 0; i < myList->max_items(); i++)
    myList->AddItem("grapes");

  Test(myList->item_count() == 25, __LINE__, "item_count() - Full List");
  Test(myList->AddItem("bananas") == false, __LINE__, "AddItem(\"bananas\")");
  Test(myList->max_items() == 25, __LINE__, "max_items()");
  if (test == 2)
    myList->GetItem(26);

  delete myList;
  myList = new ShoppingList(1);

  cout << "\n* OVERLOADED CONSTRUCTOR *\n\n";
  Test(myList->max_items() == 1, __LINE__, "max_items()");
  Test(myList->item_count() == 0, __LINE__, "item_count()");
  if (test == 3)
    myList->GetItem(0) = "oranges";
  Test(myList->AddItem("apples") == true, __LINE__, "AddItem(\"apples\")");
  Test(myList->item_count() == 1, __LINE__, "item_count()");
  yours = myList->GetItem(0);
  actual = "apples";
  Test(yours == actual, __LINE__, "GetItem(0)", yours, actual);
  if (test == 4)
    myList->GetItem(1);

  cout << "\n* RESET FUNCTION *\n\n";
  if (test == 5)
    myList->Reset(0);

  myList->Reset(5);
  Test(myList->max_items() == 5, __LINE__, "max_items() - Reset to 5");
  Test(myList->item_count() == 0, __LINE__, "item_count()");
  if (test == 6)
    myList->GetItem(6);

  for (unsigned int i = 0; i < myList->max_items(); i++)
    myList->AddItem("grapes");
  Test(myList->item_count() == 5, __LINE__, "item_count() - Full List");
  Test(myList->AddItem("bananas") == false, __LINE__, "AddItem(\"bananas\")");
  Test(myList->max_items() == 5, __LINE__, "max_items()");

  cout << string(40, '-') << endl;
  cout << "Passed: " << ut_passed << " / " << ut_total << endl;
  OutputFailedTests();
  cout << string(40, '-') << endl;
  cout << "END OF UNIT TEST!\n";
  cout << string(40, '-') << endl;
  cout << "Be sure to run 'make style' to check for any style errors.\n"
       << "Please note that 'make style' does NOT check variable names or"
       << " indentation" << endl << endl;
}

// For testing (DO NOT ALTER)
void Test(bool test, int line_number, string more_info, string yours,
          string actual) {
  ut_total++;
  if (test) {
    cout << "PASSED TEST ";
    ut_passed++;
  } else {
    cout << "FAILED TEST ";
    ut_failed++;
    failed_tests.push_back(ut_total);
  }
  cout << ut_total << " " << more_info << "!" << endl;
  if (!test) {
    if (yours != "!")
      cout << "Yours:  \"" << yours << '"' << endl;
    if (actual != "!")
      cout << "Actual: \"" << actual << '"' << endl;
    cout << "  Check Line " << line_number << " for more info" << endl;
  }
}

void OutputFailedTests() {
  if (failed_tests.size()) {
    cout << "Failed test number(s): ";
    for (unsigned int i = 0; i < failed_tests.size() - 1; i++)
      cout << failed_tests.at(i) << ", ";
    cout << failed_tests.at(failed_tests.size() - 1) << endl;
  }
}
