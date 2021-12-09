/*
 * Name        : dl_node.cpp
 * Author      : Jasmine Vang
 * Description : Creating Nodes
 */

#include "dl_node.h"

// Constructor
DLNode::DLNode() {
    next_node_ = NULL;
    prev_node_ = NULL;
    contents_ = 0;
}
// Overloaded
DLNode::DLNode(int contents) {
    next_node_ = NULL;
    prev_node_ = NULL;
    contents_ = contents;
}
// Destructor (empty)
DLNode::~DLNode() {
    // empty
}
// Setter to parameter
void DLNode::SetContents(int contents) {
    contents_ = contents;
}
// Setter for next node
void DLNode::SetNext(DLNode* next_node) {
    next_node_ = next_node;
}
// Setter for previous node
void DLNode::SetPrevious(DLNode* prev_node) {
    prev_node_ = prev_node;
}
// Accessor for contents
unsigned int DLNode::GetContents() const {
    return contents_;
}
// Accessor for next node
DLNode* DLNode::GetNext() const {
    return next_node_;
}
// Accessor for prev node
DLNode* DLNode::GetPrevious() const {
    return prev_node_;
}
