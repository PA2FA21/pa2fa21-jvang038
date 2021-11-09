/*
 * Name        : sl_list.cpp
 * Author      : Jasmine Vang
 * Description : Creating Nodes
 */

#include "sl_list.h"

// default constructor, sets values head_(NULL) and size_(0)
SLList::SLList() {
    head_ = NULL;
    tail_ = NULL;
    size_ = 0;
}
// destructor, calls the clear function
SLList::~SLList() {
    Clear();
}
// Creates a new SLNode with the contents of the parameter and
// inserts it into the correct position in the list. The list
// will be sorted with the lowest values in the front and the
// largest values in the back.
void SLList::Insert(unsigned int parameter_) {
    if (head_ == NULL || parameter_ <= head_ -> contents()) {
        InsertHead(parameter_);
    } else if (parameter_ >= tail_ -> contents()) {
        InsertTail(parameter_);
    } else {
        SLNode* new_node = new SLNode(parameter_);
        SLNode* iterator_ = head_;
        SLNode* trailer_ = head_;
        while (iterator_ -> contents() <= parameter_) {
            trailer_ = iterator_;
            iterator_ = iterator_ -> next_node();
        }
        new_node -> set_next_node(iterator_);
        trailer_ -> set_next_node(new_node);
        size_++;
    }
}
// Remove the first occurence of the supplied parameter
// found as the data in a node. Return true on successful
// removal or false if the list is empty of if the value
// is not found/removed
bool SLList::RemoveFirstOccurence(unsigned int parameter_) {
    if (head_ != NULL) {
        SLNode* iterator_ = head_;
        SLNode* trailer_ = head_;
        while (iterator_ != NULL && iterator_ -> contents() != parameter_) {
            trailer_ = iterator_;
            iterator_ = iterator_ -> next_node();
        }
        if (iterator_ == NULL) {
            return false;
        } else if (iterator_ == head_) {
            RemoveHead();
            return true;
        } else if (iterator_ == tail_) {
            RemoveTail();
            return true;
        } else {
            trailer_ -> set_next_node(iterator_ -> next_node());
            delete iterator_;
            size_--;
            return true;
        }
    }
    return false;
}
// create a new dynamic SLNode with the contents of
// the parameter and attach as head of list
void SLList::InsertHead(unsigned int contents) {
    // Create the Node to Insert
    SLNode* new_head = new SLNode(contents);
    // Insert it into our list
    // Point the new node to where head is pointing to
    new_head -> set_next_node(head_);
    if (head_ == NULL) {
        tail_ = new_head;
    }
    // Point head to the new node
    head_ = new_head;
    // Increment the Size of the List
    size_++;
}
// Create a new dynamic SLNode with the contents of
// the integer parameter and attach as the tail of the list
void SLList::InsertTail(unsigned int contents) {
    if (head_ == NULL) {
        InsertHead(contents);
    } else {
        SLNode* new_tail = new SLNode(contents);
        tail_ -> set_next_node(new_tail);
        tail_ = new_tail;
        size_++;
    }
}
// remove the head node from the list, or does nothing if
// the list is empty
void SLList::RemoveHead() {
    if (head_ != NULL) {
        SLNode* temp_ = head_;
        head_ = head_ -> next_node();
        delete temp_;
        if (head_ == NULL) {
            tail_ = NULL;
        }
        size_--;
    }
}
// Remove the tail node from the list. Does nothing if the
// list is empty
void SLList::RemoveTail() {
    if (head_ == tail_) {
        RemoveHead();
    } else {
        SLNode* iterator_ = head_;
        while (iterator_ -> next_node() != tail_) {
            iterator_ = iterator_ -> next_node();
        }
        iterator_ -> set_next_node(NULL);
        delete tail_;
        tail_ = iterator_;
        size_--;
    }
}
// Returns the contents of the head node (The node the head is
// pointing to)
// Return 0 if the list is empty
int SLList::GetHead() const {
    if (head_ != NULL) {
        return head_ -> contents();
    }
    return 0;
}
// Returns the contents of the tail node (The node the tail is
// pointing to)
// Return 0 if the list is empty
int SLList::GetTail() const {
    if (tail_ != NULL) {
        return tail_ -> contents();
    }
    return 0;
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
    tail_ = NULL;
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
