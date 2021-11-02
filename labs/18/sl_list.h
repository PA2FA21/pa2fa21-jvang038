/*
 * Name        : sl_list.h
 * Author      : Jasmine Vang
 * Description : Creating Nodes
 */

// ADD HEADER GUARD HERE
#ifndef VANG_SL_LIST_H_
#define VANG_SL_LIST_H_

#include "sl_node.h"
#include <string>
#include <sstream>
using std::string;
using std::stringstream;

class SLList {
 public:
  // default constructor, sets values head_(NULL) and size_(0)
  SLList();
  // destructor, calls the clear function
  ~SLList();
  // create a new dynamic SLNode with the contents of
  // the parameter and attach as head of list
  void InsertHead(unsigned int contents);
  // remove the head node from the list, or does nothing if
  // the list is empty
  void RemoveHead();
  // clear the entire contents of the list, freeing all memory
  // associated with all nodes
  void Clear();
  // Accessor for size
  unsigned int size() const;
  // return a string representation of the contents
  // of all nodes in the list, in the format
  // NUM1, NUM2 , ..., LASTNUM
  // return empty string on empty list
  string ToString() const;

 private:
  SLNode *head_;
  unsigned int size_;
};

#endif
