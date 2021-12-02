/*
 * Name        : bs_tree.cpp
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
        ss << InOrder(subroot -> GetLeftChild()) << subroot -> GetContents()
           << " " << InOrder(subroot -> GetRightChild());
        return ss.str();
    }
    return "";
}
