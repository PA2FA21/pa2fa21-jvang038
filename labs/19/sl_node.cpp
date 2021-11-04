/*
 * Name        : sl_node.cpp
 * Author      : Jasmine Vang
 * Description : Creating Nodes
 */

#include "sl_node.h"

// Constructure sets values next_node_(NULL)
// and contents_(0)
SLNode::SLNode() {
    next_node_ = NULL;
    contents_ = 0;
}
// overloaded constructor
// int parameter assigned to contents_
SLNode::SLNode(int contents) {
    next_node_ = NULL;
    contents_ = contents;
}
// Destructor
SLNode::~SLNode() {
    // empty
}
// Setter
void SLNode::set_contents(int contents) {
    contents_ = contents;
}
// Accessor for contents
int SLNode::contents() const {
    return contents_;
}
// Setter
void SLNode::set_next_node(SLNode* next_node) {
    next_node_ = next_node;
}
// Accessor for Next Node
SLNode* SLNode::next_node() {
    return next_node_;
}
