/*
 * Name        : Assignment 5 bs_treet.h
 * Author      : Jasmine Vang
 * Description : Working with Trees and Nodes
 */
 
#ifndef VANS_BS_TREE_H_
#define VANG_BS_TREE_H_

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
  // calls private function Remove()
  int Remove(T value);
  // calls private function Get()
  BSTNodeT* Get(T value);
  // calls private function ToStringForwards()
  string ToStringForwards();
  // calls private function ToStringBackwards()
  string ToStringBackwards();
  
 private:
  // code here
  BSTNodeT* root_;
  unsigned int size;
  // deletes all the node in tree
  void Clear(BSTNodeT* &subroot);
  // Parameter - value to add
  // if value exists - increment count of node
  // returns the number of times the value is added
  unsigned int Insert(T value, BSTNodeT* &subroot);
  // Search tree for value
  // if found return true else false
  bool Exists(T value, BSTNodeT* &subroot);
  // search tree for value, and decrement count
  // if count is 1 - remove node return count
  // return 0 if removed from tree, return -1 if not found
  int Remove(T value, BSTNodeT* &subroot);
  // searches for value, if found returns pointer to node
  // otherwise return NULL
  BSTNodeT* Get(T value, BSTNodeT* &subroot);
  // ouputs tree in order, comma seperated no space
  // if list is empty - retun empty string
  string ToStringForwards(BSTNodeT* &subroot);
  // outputs tree backwords, comma seperater no space
  // if list is empty - return empty string
  string ToStringBackwards(BSTNodeT* &subroot);
};

// FUNCTION DEFINITIONS HERE

// Constructor initialize root to null and size to 0
BSTreeT::BSTreeT() {
    root_ = NULL;
    size = 0;
}
// Destructor, calls clear function
BSTreeT::~BSTreeT() {
    Clear();
}
// returns the number of nodes in the tree
unsigned int BSTreeT::GetSize() const {
    return size;
}
// Calls private function Clear();
void BSTreeT::Clear() {
    Clear(root_);
}
// Calls private function Insert()
unsigned int BSTreeT::Insert(T value) {
    return Insert(value, root_);
}
// Calls private function Exists()
bool BSTreeT::Exists(T value) {
    return Exists(value, root_);
}
// calls private function Remove()
int BSTreeT::Remove(T value) {
    return Remove(value, root_);
}
// calls private function Get()
BSTNodeT* BSTreeT::Get(T value) {
    return Get(value, root_);
}
// calls private function ToStringForwards()
string BSTreeT::ToStringForwards() {
    return ToStringForwards(root_);
}
// calls private function ToStringBackwards()
string BSTreeT::ToStringBackwards() {
    return ToStringBackwards(root_);
}

// PRIVATE FUNCTION DEFINITIONS

// deletes all the node in tree
void BSTreeT::Clear(BSTNodeT* &subroot) {
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
unsigned int BSTreeT::Insert(T value, BSTNodeT* &subroot) {
    if (subroot == NULL) {
        subroot = new BSTNodeT(value);
        size++;
        // incremement count? return count?
    }
}
// Search tree for value
// if found return true else false
bool BSTreeT::Exists(T value, BSTNodeT* &subroot);
// search tree for value, and decrement count
// if count is 1 - remove node return count
// return 0 if removed from tree, return -1 if not found
int BSTreeT::Remove(T value, BSTNodeT* &subroot);
// searches for value, if found returns pointer to node
// otherwise return NULL
BSTNodeT* BSTreeT::Get(T value, BSTNodeT* &subroot);
// ouputs tree in order, comma seperated no space
// if list is empty - retun empty string
string BSTreeT::ToStringForwards(BSTNodeT* &subroot) {
    if (subroot != NULL) {
        stringstream ss;
        ss << ToStringForwards(subroot -> GetLeft())
           << subroot -> GetContents() << ","
           << ToStringForwards(subroot -> GetRight())
        return ss.str();
    }
    return "";
}
// outputs tree backwords, comma seperater no space
// if list is empty - return empty string
string BSTreeT::ToStringBackwards(BSTNodeT* &subroot);

#endif
