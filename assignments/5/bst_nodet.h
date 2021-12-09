/*
 * Name        : Assignment 5 bst_nodet.h
 * Author      : Jasmine Vang
 * Description : Working with Trees and Nodes
 */

// Header Guard
#ifndef VANG_BST_NODET_H_
#define VANG_BST_NODET_H_

#include <cstddef>

template<typename T>
class BSTNodeT {
 public:
  // Default constructor
  // sets left and right to null, count to 0
  // sets contents to its default
  BSTNodeT();
  // overloaded constructor
  // sets parameter to contents
  // sets count to 0, left and right to null
  BSTNodeT(T contents);
  // Destructor sets left and right to null
  ~BSTNodeT();
  // sets contents to parameter
  void SetContents(T contents);
  // mutator for left
  void SetLeft(BSTNodeT* node_);
  // mutator for right
  void SetRight(BSTNodeT* node_);
  // mutator for count
  void IncrementCount();
  // mutator for count - decrement
  void DecrementCount();
  // Accessor for contenets
  T GetContents();
  T& GetContents();
  // accessor for left
  BSTNodeT* GetLeft() const;
  BSTNodeT*& GetLeft();
  // Accessor for right
  BSTNodeT* GetRight() const;
  BSTNodeT*& GetRight();
  // Accessor for count
  unsigned int GetCount();
  unsigned int& GetCount();

 private:
  BSTNodeT* left_;
  BSTNodeT* right_;
  T contents_;
  unsigned int count_;
};

// FUNCTION DEFINITIONS

// Default constructor
// sets left and right to null, count to 0
// sets contents to its default
BSTNodeT::BSTNodeT() {
    left_ = NULL;
    right_ = NULL;
    count_ = 0;
    contents_ = T();
}
// overloaded constructor
// sets parameter to contents
// sets count to 0, left and right to null
BSTNodeT::BSTNodeT(T contents) {
    left_ = NULL;
    right_ = NULL;
    count_ = 0;
    contents_ = contents;
}
// Destructor sets left and right to null
BSTNodeT::~BSTNodeT() {
    left_ = NULL;
    right_ = NULL;
}
// sets contents to parameter
void BSTNodeT::SetContents(T contents) {
    contents_ = contents;
}
// mutator for left
void BSTNodeT::SetLeft(BSTNodeT* node_) {
    left_ = node_;
}
// mutator for right
void BSTNodeT::SetRight(BSTNodeT* node_) {
    right = node_;
}
// mutator for count
void BSTNodeT::IncrementCount() {
    count_++;
}
// mutator for count - decrement
void BSTNodeT::DecrementCount() {
    count_--;
}
// Accessor for contenets
T BSTNodeT::GetContents() {
    return contents_;
}
T& BSTNodeT::GetContents() {
    return contents_;
}
// accessor for left
BSTNodeT* BSTNodeT::GetLeft() const {
    return left_;
}
BSTNodeT*& BSTNodeT::GetLeft() {
    return left_;
}
// Accessor for right
BSTNodeT* BSTNodeT::GetRight() const {
    return right_;
}
BSTNodeT*& BSTNodeT::GetRight() {
    return right_;
}
// Accessor for count
unsigned int BSTNodeT::GetCount() {
    return count_;
}
unsigned int& BSTNodeT::GetCount() {
    return count_;
}

#endif
