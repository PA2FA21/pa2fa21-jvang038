/*
 * Name        : dl_list.h
 *               lab 20
 * Author      : Jasmine Vang
 * Description : Creating Nodes
 */
 
// HEADER GUARD
#ifndef VANG_DL_LIST_H
#define VANG_DL_LIST_H

#include "dl_node.h"
#include <iostream>
#include <string>
#include <sstream>
using std::cerr;
using std::cout;
using std::endl;
using std::string;
using std::stringstream;

class DLList {
 public:
  // constructor sets values to null
  // and size to 0
  DLList();
  // Destructor calls clear();
  ~DLList();
  // accessor for size
  unsigned int GetSize() const;
  // creats DLNode with contents of parameter
  // adds node to the FRONT of list
  void PushFront(unsigned int parameter);
  // creates DLNode with contents of parameter
  // adds node to the END of list
  void PushBack(unsigned int parameter);
  // returns the head node int value
  // if list is empty, output "List Empty" return 0
  int GetFront() const;
  // returns the tail node int value
  // if list is empty, output "List Empty" return 0
  int GetBack() const;
  // Removes the first node in the list
  // if list already empty outputs "List Empty"
  void PopFront();
  // Removes the last node in the list
  // if list already empty outputs "List Empty"
  void PopBack();
  // Parameter - int to be found in list
  // if value is found, remove only that node from list
  // if not found, output "Not Found"
  void RemoveFirst(unsigned int parameter);
  // Parameter - int to be found in list
  // remove all values matching parameter
  // if non found, output "Not Found"
  void RemoveAll(unsigned int parameter);
  // Parameter - int to be found in list
  // if found return True, else False
  bool Exists(unsigned int parameter);
  // deletes all nodes in list
  // resets size to 0
  // sets head and tail to NULL
  void Clear();
  // Outputs contents of lists comma seperated
  // starting at first and end at last (1, 2, 3)
  // if list empty output "List Empty"
  string ToStringForwards();
  // Outputs contents of list comma seperated
  // start at end to first (3, 2, 1)
  // if list empty output "List Empty"
  string ToStringBackwards();

 private:
  DLNode *head_;
  DLNode *tail_;
  unsigned int size;
};

#endif
