/*
 * Name        : dl_node.h
 * Author      : Jasmine Vang
 * Description : Creating Nodes
 */
 
// HEADER GUARD
#ifndef VANG_DL_NODE_H
#define VANG_DL_NODE_H

#include <cstddef>

class DLNode {
 public:
  // Constructor sets values to NULL
  // set contents to 0
  DLNode();
  // overloaded constructor
  DLNode(int contents);
  // Destructor (empty)
  ~DLNode();
  // Setter to parameter
  void SetContents(int contents);
  // Setter for next node
  void SetNext(DLNode* next_node);
  // Setter for previous node
  void SetPrevious(DLNode* prev_node);
  // Accessor for contents
  unsigned int GetContents() const;
  // Accessor for next node
  DLNode* GetNext() const;
  // Accessor for prev node
  DLNode* GetPrevious() const;

 private:
  DLNode* next_node_;
  DLNode* prev_node_;
  int contents_;
};

#endif
