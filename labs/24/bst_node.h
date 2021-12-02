/*
 * Name        : bst_node.h
 * Author      : Jasmine Vang
 * Description : Working with Trees and Nodes
 */

// Header Guard
#ifndef VANG_BST_NODE_H_
#define VANG_BST_NODE_H_

#include <cstddef>

class BSTNode {
 public:
  // Defult constructor
  // sets left and right child to NULL and the contents to 0
  BSTNode();
  // Overloaded constructor
  // int parameter assigned to the contents
  BSTNode(unsigned int parameter);
  // Destructor sets left and right child to NULL
  ~BSTNode();
  // Mutator for contents_
  void SetContents(int contents);
  // Acessor for contents_
  int GetContents() const;
  // Acessor for contents_ by reference
  int& GetContents();
  // Mutator for left
  void SetLeftChild(BSTNode* node_);
  // Mutator for right
  void SetRightChild(BSTNode* node_);
  // Accesor for left
  BSTNode* GetLeftChild() const;
  BSTNode*& GetLeftChild();
  // Accesor for right
  BSTNode* GetRightChild() const;
  BSTNode*& GetRightChild();

 private:
  BSTNode* left_;
  BSTNode* right_;
  int contents_;
};

#endif
