/*
 * Name        : lab_24 bs_tree.h
 * Author      : Jasmine Vang
 * Description : Working with Trees and Nodes
 */

#ifndef VANG_BS_TREE_H_
#define VANG_BS_TREE_H_

#include "bst_node.h"
#include <iostream>
#include <string>
#include <sstream>
#include <cstddef>
using std::string;
using std::stringstream;

class BSTree {
 public:
  // Defult constructor
  BSTree();
  // Destructor
  ~BSTree();
  // calls private function Insert(int, root)
  bool Insert(int value);
  // call private function Clear(root)
  void Clear();
  // accessor for size
  unsigned int GetSize() const;
  // call private function InOrder(root)
  string InOrder();

 private:
  BSTNode* root_;
  unsigned int size_;
  // Create a new BSTNode and insert it into the tree, returns
  // true; if integer is already in the tree, does not insert,
  // returns false
  bool Insert(int value, BSTNode* &subroot);
  // Clear the entire contents of the tree, freeing all memory
  // associated with all nodes
  void Clear(BSTNode* &subroot);
  // Creates a string of the data in all nodes in the tree,
  // in ascending order, separate by spaces (there should be a
  // space after the last output value)
  string InOrder(BSTNode* subroot);
};

#endif
