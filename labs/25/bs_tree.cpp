/*
 * Name        : lab_25 bs_tree.cpp
 * Author      : Jasmine Vang
 * Description : Working with Trees and Nodes
 */

#include "bs_tree.h"

// Defult constructor
// sets the root to NULL and size to 0
BSTree::BSTree() {
    root_ = NULL;
    size_ = 0;
}
// Destructor
// calls the Clear function
BSTree::~BSTree() {
    Clear();
}
// calls private function Insert(int, root)
bool BSTree::Insert(int value) {
    return Insert(value, root_);
}
// return value by private function return()
bool BSTree::Remove(int value) {
    return Remove(value, root_);
}
// if tree is empty return 0
// else call findmin()
int BSTree::FindMin() {
    return FindMin(root_);
}
// call private function Clear(root)
void BSTree::Clear() {
    Clear(root_);
}
// accessor for size
unsigned int BSTree::GetSize() const {
    return size_;
}
// call private function InOrder(root)
string BSTree::InOrder() {
    return InOrder(root_);
}
// Create a new BSTNode and insert it into the tree, returns
// true. If integer is already in the tree, does not insert,
// returns false
bool BSTree::Insert(int value, BSTNode* &subroot) {
    if (subroot == NULL) {
        subroot = new BSTNode(value);
        size_++;
        return true;
    } else if (value < subroot -> GetContents()) {
        return Insert(value, subroot -> GetLeftChild());
    } else if (value > subroot -> GetContents()) {
        return Insert(value, subroot -> GetRightChild());
    } else {
        return false;
    }
}
// traverse the tree and remove target, return true
// if not found return false
bool BSTree::Remove(int value, BSTNode* &subroot) {
    // code here
    if (subroot == NULL) {
      return false;
    } else if (value < subroot -> GetContents()) {
      return Remove(value, subroot -> GetLeftChild());
    } else if (value > subroot -> GetContents()) {
      return Remove(value, subroot -> GetRightChild());
    } else {
      BSTNode* iterator_;
      if (subroot -> GetLeftChild() == NULL && subroot -> GetRightChild() == NULL) {
        delete subroot;
        subroot = NULL;
        size_--;
        return true;
      } else if (subroot -> GetLeftChild() != NULL && subroot -> GetRightChild() == NULL) {
        iterator_ = subroot;
        subroot = subroot -> GetLeftChild();
        delete iterator_;
        size_--;
        return true;
      } else if (subroot -> GetLeftChild() == NULL && subroot -> GetRightChild() != NULL) {
        iterator_ = subroot;
        subroot = subroot -> GetRightChild();
        delete iterator_;
        size_--;
        return true;
      } else {
        // code for 2 children
        subroot -> SetContents(FindMin(subroot -> GetRightChild()));
        Remove(subroot -> GetContents(), subroot -> GetRightChild());
        return true;
      }
    }
    return false;
}
// returns the value of the smallest node in tree
// helper function for remove()
int BSTree::FindMin(BSTNode* subroot) const {
    if (subroot == NULL) {
      return 0;
    } else if (subroot -> GetLeftChild() == NULL) {
      return subroot->GetContents();
    }
    return FindMin(subroot -> GetLeftChild());
    
}
// Clear the entire contents of the tree, freeing all memory
// associated with all nodes
void BSTree::Clear(BSTNode* &subroot) {
    if (subroot != NULL) {
        Clear(subroot -> GetLeftChild());
        Clear(subroot -> GetRightChild());
        delete subroot;
        subroot = NULL;
        size_--;
    }
}
// Creates a string of the data in all nodes in the tree,
// in ascending order, separate by spaces (there should be a
// space after the last output value)
string BSTree::InOrder(BSTNode* subroot) {
    if (subroot != NULL) {
        stringstream ss;
        ss << InOrder(subroot -> GetLeftChild())
           << subroot -> GetContents()
           << " " << InOrder(subroot -> GetRightChild());
        return ss.str();
    }
    return "";
}
