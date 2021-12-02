/*
 * Name        : todo_list.h
 *              (3c)
 * Author      : Jasmine Vang
 * Description : todo Header File
 */

// ADD HEADER GUARD HERE
#ifndef VANG_TODO_LIST_H_
#define VANG_TODO_LIST_H_

#include "todo_item.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using std::string;
using std::setw;
using std::stringstream;
using std::ostream;
using std::endl;

class TodoList {
 public:
  // Constructor to create dynamic array size and set to null
  TodoList();
  // Destructor to clean up dynamic array
  ~TodoList();
  // If there is room in the array add the new dynamic instance
  // to the first available spot (i.e. the current size).
  // If the array is full, increase capacity by 10 and then add the item.
  void AddItem(TodoItem *item);
  // delete an item from the list and shift the list down
  void DeleteItem(unsigned int where);
  // Accessor for item
  // for types the star goes to the end
  TodoItem* GetItem(unsigned int where);
  // Accesor Returns an unsigned integer containing the current size of the list
  unsigned int GetSize();
  // Accesor, Returns an unsigned integer containing the
  // current maximum capacity of the list (number of slots).
  unsigned int GetCapacity();
  // Sorts the array by the priorities of the items.
  // (1 is highest priority, 5 is lowest).
  void Sort();
  // Returns a string containing all TodoItems in the list.
  // Uses the TodoItems ToFilefunction to create.
  // Each item should be on its own line.
  string ToFile();

  // Overloaded <<
  friend ostream& operator <<(ostream &out, const TodoList &t);
  // for loop that calls the get functions to print the appropriate item at i

 private:
    unsigned int size_;
    unsigned int cap_;
    TodoItem** list_;
    // Increases the capacity of the array by 10.
    // Should be called by AddItemat the appropriate time.
    void AddTen();
    // Compacts the array to get rid of an empty spot in the array.
    // Should be called by DeleteItemat the appropriate time.
    void CompactSpace(unsigned int where);
};

#endif
