/*
 * Name        : sl_node.h
 * Author      : Jasmine Vang
 * Description : Creating Nodes
 */

// ADD HEADER GUARD HERE
#ifndef VANG_SL_NODE_H_
#define VANG_SL_NODE_H_

#include <cstddef>

class SLNode {
 public:
  // Constructure sets values next_node_(NULL)
  // and contents_(0)
  SLNode();
  // overloaded constructor
  // int parameter assigned to contents_
  SLNode(int contents);
  // Destructor
  ~SLNode();
  // Setter
  void set_contents(int contents);
  // Accessor for contents
  int contents() const;
  // Setter for Next Node
  void set_next_node(SLNode* next_node);
  // Accessor for Next Node
  SLNode* next_node();
 private:
  SLNode* next_node_;
  int contents_;
};

#endif
