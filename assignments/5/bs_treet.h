/*
 * Name        : Assignment 5 bs_treet.h
 * Author      : Jasmine Vang
 * Description : Working with Trees and Nodes
 */

#ifndef VANS_BS_TREE_H_
#define VANG_BS_TREE_H_

#include "bst_nodet.h"
#include <iostream>
#include <string>
#include <sstream>

using std::string;
using std::stringstream;

template<typename T>
class BSTreeT {
 public:
  // Constructor initialize root to null and size to 0
  BSTreeT();
  // Destructor, calls clear function
  ~BSTreeT();
  // returns the number of nodes in the tree
  unsigned int GetSize() const;
  // Calls private function Clear();
  void Clear();
  // Calls private function Insert()
  unsigned int Insert(T value);
  // Calls private function Exists()
  bool Exists(T value);
  // calls private function findmin()
  int FindMin(BSTNodeT<T>* subroot) const;
  // calls private function Remove()
  int Remove(T value);
  // calls private function Get()
  BSTNodeT<T>* Get(T value);
  // calls private function ToStringForwards()
  string ToStringForwards();
  // calls private function ToStringBackwards()
  string ToStringBackwards();

 private:
  // code here
  BSTNodeT<T>* root_;
  unsigned int size;
  // deletes all the node in tree
  void Clear(BSTNodeT<T>* &subroot);
  // Parameter - value to add
  // if value exists - increment count of node
  // returns the number of times the value is added
  unsigned int Insert(T value, BSTNodeT<T>* &subroot);
  // Search tree for value
  // if found return true else false
  bool Exists(T value, BSTNodeT<T>* &subroot);
  // search tree for value, and decrement count
  // if count is 1 - remove node return count
  // return 0 if removed from tree, return -1 if not found
  int Remove(T value, BSTNodeT<T>* &subroot);
  // searches for value, if found returns pointer to node
  // otherwise return NULL
  BSTNodeT<T>* Get(T value, BSTNodeT<T>* &subroot);
  // ouputs tree in order, comma seperated no space
  // if list is empty - retun empty string
  string ToStringForwards(BSTNodeT<T>* &subroot);
  // outputs tree backwords, comma seperater no space
  // if list is empty - return empty string
  string ToStringBackwards(BSTNodeT<T>* &subroot);
};

// FUNCTION DEFINITIONS HERE

// Constructor initialize root to null and size to 0
template<typename T>
BSTreeT<T>::BSTreeT() {
    root_ = NULL;
    size = 0;
}
// Destructor, calls clear function
template<typename T>
BSTreeT<T>::~BSTreeT() {
    Clear();
}
// returns the number of nodes in the tree
template<typename T>
unsigned int BSTreeT<T>::GetSize() const {
    return size;
}
// Calls private function Clear();
template<typename T>
void BSTreeT<T>::Clear() {
    Clear(root_);
}
// Calls private function Insert()
template<typename T>
unsigned int BSTreeT<T>::Insert(T value) {
    return Insert(value, root_);
}
// Calls private function Exists()
template<typename T>
bool BSTreeT<T>::Exists(T value) {
    return Exists(value, root_);
}
// calls private function Remove()
template<typename T>
int BSTreeT<T>::Remove(T value) {
    return Remove(value, root_);
}
// calls private function Get()
template<typename T>
BSTNodeT<T>* BSTreeT<T>::Get(T value) {
    return Get(value, root_);
}
// calls private function ToStringForwards()
template<typename T>
string BSTreeT<T>::ToStringForwards() {
    return ToStringForwards(root_);
}
// calls private function ToStringBackwards()
template<typename T>
string BSTreeT<T>::ToStringBackwards() {
    return ToStringBackwards(root_);
}

// PRIVATE FUNCTION DEFINITIONS

// deletes all the node in tree
template<typename T>
void BSTreeT<T>::Clear(BSTNodeT<T>* &subroot) {
    if (subroot != NULL) {
        Clear(subroot -> GetLeft());
        Clear(subroot -> GetRight());
        delete subroot;
        subroot = NULL;
        size--;
    }
}
// Parameter - value to add
// if value exists - increment count of node
// returns the number of times the value is added
template<typename T>
unsigned int BSTreeT<T>::Insert(T value, BSTNodeT<T>* &subroot) {
    if (subroot == NULL) {
        subroot = new BSTNodeT<T>(value);
        size++;
        subroot -> IncrementCount();
        return subroot -> GetCount();
    } else if (value < subroot -> GetContents()) {
        return Insert(value, subroot -> GetLeft());
    } else if (value > subroot -> GetContents()) {
        return Insert(value, subroot -> GetRight());
    } else {
        subroot -> IncrementCount();
        return subroot -> GetCount();
    }
}
// Search tree for value
// if found return true else false
template<typename T>
bool BSTreeT<T>::Exists(T value, BSTNodeT<T>* &subroot) {
    if (subroot == NULL) {
        return false;
    } else if (value < subroot -> GetContents()) {
        return Exists(value, subroot -> GetLeft());
    } else if (value > subroot -> GetContents()) {
        return Exists(value, subroot -> GetRight());
    } else {
        return true;
    }
}

template<typename T>
int BSTreeT<T>::FindMin(BSTNodeT<T>* subroot) const {
    if (subroot == NULL) {
      return 0;
    } else if (subroot -> GetLeft() == NULL) {
      return subroot -> GetContents();
    }
    return FindMin(subroot -> GetLeft());
}

// search tree for value, and decrement count
// if count is 1 - remove node return count
// return 0 if removed from tree, return -1 if not found
template<typename T>
int BSTreeT<T>::Remove(T value, BSTNodeT<T>* &subroot) {
    if (Exists(value, subroot) == false) {
        return -1;
    } else if (subroot -> GetCount() > 1) {
        subroot -> DecrementCount();
        return subroot -> GetCount();
    } else if (value < subroot -> GetContents()) {
        return Remove(value, subroot -> GetLeft());
    } else if (value > subroot -> GetContents()) {
        return Remove(value, subroot -> GetRight());
    } else {
        BSTNodeT<T>* iterator_;
        if (subroot -> GetLeft() == NULL &&
            subroot -> GetRight() == NULL) {
            delete subroot;
            subroot = NULL;
            size--;
            return 0;
        } else if (subroot -> GetLeft() != NULL &&
                   subroot -> GetRight() == NULL) {
            iterator_ = subroot;
            subroot = subroot -> GetLeft();
            delete iterator_;
            size--;
            return 0;
        } else if (subroot -> GetLeft() == NULL &&
                   subroot -> GetRight() != NULL) {
            iterator_ = subroot;
            subroot = subroot -> GetRight();
            delete iterator_;
            size--;
            return 0;
        } else {
            subroot -> SetContents(FindMin(subroot -> GetRight()));
            Remove(subroot -> GetContents(), subroot -> GetRight());
            return 0;
        }
    }
}
// searches for value, if found returns pointer to node
// otherwise return NULL
template<typename T>
BSTNodeT<T>* BSTreeT<T>::Get(T value, BSTNodeT<T>* &subroot) {
    if (Exists(value, subroot) == false) {
        return NULL;
    } else {
        // BSTNodeT<T>* iterator_;
        if (value < subroot -> GetContents()) {
            return Get(value, subroot -> GetLeft());
        } else if (value > subroot -> GetContents()) {
            return Get(value, subroot -> GetRight());
        } else {
            return subroot;
        }
    }
}
// ouputs tree in order, comma seperated no space
// if list is empty - retun empty string
template<typename T>
string BSTreeT<T>::ToStringForwards(BSTNodeT<T>* &subroot) {
    if (subroot != NULL) {
        stringstream ss;
        if (subroot -> GetLeft() != NULL) {
            ss << ToStringForwards(subroot -> GetLeft())
               << ", ";
        }
        ss << subroot -> GetContents();
        if (subroot -> GetRight() != NULL) {
            ss << ", " << ToStringForwards(subroot -> GetRight());
        }
        return ss.str();
    }
    return "";
}
// outputs tree backwords, comma seperater no space
// if list is empty - return empty string
template<typename T>
string BSTreeT<T>::ToStringBackwards(BSTNodeT<T>* &subroot) {
    if (subroot != NULL) {
        stringstream ss;
        if (subroot -> GetRight() != NULL) {
            ss << ToStringForwards(subroot -> GetRight())
               << ", ";
        }
        ss << subroot -> GetContents();
        if (subroot -> GetLeft() != NULL) {
            ss << ", " << ToStringForwards(subroot -> GetLeft());
        }
        return ss.str();
    }
    return "";
}

#endif
