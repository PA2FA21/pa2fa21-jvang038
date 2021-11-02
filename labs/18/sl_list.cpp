/*
 * Name        : sl_list.cpp
 * Author      : Jasmine Vang
 * Description : Creating Nodes
 */

#include "sl_list.h"

// default constructor, sets values head_(NULL) and size_(0)
SLList::SLList() {
    head_ = NULL;
    size_ = 0;
}
// destructor, calls the clear function
SLList::~SLList() {
    Clear();
}
// create a new dynamic SLNode with the contents of
// the parameter and attach as head of list
void SLList::InsertHead(unsigned int contents) {
    // Create the Node to Insert
    SLNode* new_head = new SLNode(contents);
    // Insert it into our list
    // Point the new node to where head is pointing to
    new_head -> set_next_node(head_);
    // Point head to the new node
    head_ = new_head;
    // Increment the Size of the List
    size_++;
}
// remove the head node from the list, or does nothing if
// the list is empty
void SLList::RemoveHead() {
    if (head_ != NULL) {
        SLNode* temp_ = head_;
        head_ = head_ -> next_node();
        delete temp_;
        size_--;
    }
}
// clear the entire contents of the list, freeing all memory
// associated with all nodes
void SLList::Clear() {
    SLNode* iterator_ = head_;
    while (head_ != NULL) {
        head_ = head_ -> next_node();
        delete iterator_;
        iterator_ = head_;
    }
    size_ = 0;
}
// Accessor for size
unsigned int SLList::size() const {
    return size_;
}
// return a string representation of the contents
// of all nodes in the list, in the format
// NUM1, NUM2, ..., LASTNUM
// return empty string on empty list
string SLList::ToString() const {
    if (head_ == NULL) {
        return "";
    }
    SLNode* iterator_ = head_;
    stringstream ss;
    while (iterator_ != NULL) {
        ss << iterator_ -> contents();
        iterator_ = iterator_ -> next_node();
        if (iterator_ != NULL) {
            ss << ", ";
        }
    }
    return ss.str();
}
