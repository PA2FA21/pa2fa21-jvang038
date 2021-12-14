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
//   T& GetContents();
  // accessor for left
  BSTNodeT* GetLeft() const;
  BSTNodeT*& GetLeft();
  // Accessor for right
  BSTNodeT* GetRight() const;
  BSTNodeT*& GetRight();
  // Accessor for count
  unsigned int GetCount();
//   unsigned int& GetCount();

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
template<typename T>
BSTNodeT<T>::BSTNodeT() {
    left_ = NULL;
    right_ = NULL;
    count_ = 0;
    contents_ = T();
}
// overloaded constructor
// sets parameter to contents
// sets count to 0, left and right to null
template<typename T>
BSTNodeT<T>::BSTNodeT(T contents) {
    left_ = NULL;
    right_ = NULL;
    count_ = 0;
    contents_ = contents;
}
// Destructor sets left and right to null
template<typename T>
BSTNodeT<T>::~BSTNodeT() {
    left_ = NULL;
    right_ = NULL;
}
// sets contents to parameter
template<typename T>
void BSTNodeT<T>::SetContents(T contents) {
    contents_ = contents;
}
// mutator for left
template<typename T>
void BSTNodeT<T>::SetLeft(BSTNodeT* node_) {
    left_ = node_;
}
// mutator for right
template<typename T>
void BSTNodeT<T>::SetRight(BSTNodeT* node_) {
    right_ = node_;
}
// mutator for count
template<typename T>
void BSTNodeT<T>::IncrementCount() {
    count_++;
}
// mutator for count - decrement
template<typename T>
void BSTNodeT<T>::DecrementCount() {
    count_--;
}
// Accessor for contenets
template<typename T>
T BSTNodeT<T>::GetContents() {
    return contents_;
}

// template<typename T>
// T& BSTNodeT<T>::GetContents() {
//     return contents_;
// }
// accessor for left
template<typename T>
BSTNodeT<T>* BSTNodeT<T>::GetLeft() const {
    return left_;
}

template<typename T>
BSTNodeT<T>*& BSTNodeT<T>::GetLeft() {
    return left_;
}
// Accessor for right
template<typename T>
BSTNodeT<T>* BSTNodeT<T>::GetRight() const {
    return right_;
}
template<typename T>
BSTNodeT<T>*& BSTNodeT<T>::GetRight() {
    return right_;
}
// Accessor for count
template<typename T>
unsigned int BSTNodeT<T>::GetCount() {
    return count_;
}
// template<typename T>
// unsigned int& BSTNodeT<T>::GetCount() {
//     return count_;
// }

#endif
