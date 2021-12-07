/*
 * Name        : bst_node.cpp
 * Author      : Jasmine Vang
 * Description : Working with Trees and Nodes
 */

#include "bst_node.h"

// Defult constructor
// sets left and right child to NULL and the contents to 0
BSTNode::BSTNode() {
    left_ = NULL;
    right_ = NULL;
    contents_ = 0;
}
// Overloaded constructor
// int parameter assigned to the contents
BSTNode::BSTNode(unsigned int parameter) {
    left_ = NULL;
    right_ = NULL;
    contents_ = parameter;
}
// Destructor sets left and right child to NULL
BSTNode::~BSTNode() {
    left_ = NULL;
    right_ = NULL;
}
// Mutator for contents_
void BSTNode::SetContents(int contents) {
    contents_ = contents;
}
// Acessor for contents_
int BSTNode::GetContents() const {
    return contents_;
}
// Acessor for contents_ by reference
int& BSTNode::GetContents() {
    return contents_;
}
// Mutator for left
void BSTNode::SetLeftChild(BSTNode* node_) {
    left_ = node_;
}
// Mutator for right
void BSTNode::SetRightChild(BSTNode* node_) {
    right_ = node_;
}
// Accesor for left
BSTNode* BSTNode::GetLeftChild() const {
    return left_;
}

BSTNode*& BSTNode::GetLeftChild() {
    return left_;
}
// Accesor for right
BSTNode* BSTNode::GetRightChild() const {
    return right_;
}

BSTNode*& BSTNode::GetRightChild() {
    return right_;
}
