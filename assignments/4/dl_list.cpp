/*
 * Name        : dl_list.cpp
 * Author      : Jasmine Vang
 * Description : Creating Nodes
 */

#include "dl_list.h"

// constructor
DLList::DLList() {
    head_ = NULL;
    tail_ = NULL;
    size = 0;
}
// Destructor
DLList::~DLList() {
    Clear();
}
// accessor for size
unsigned int DLList::GetSize() const {
    return size;
}
// creats DLNode with contents of parameter
// adds node to the FRONT of list
void DLList::PushFront(unsigned int parameter) {
    DLNode* new_head = new DLNode(parameter);
    new_head -> SetNext(head_);
    if (head_ == NULL) {
        tail_ = new_head;
    } else {
        head_ -> SetPrevious(new_head);
    }
    head_ = new_head;
    size++;
}
// creates DLNode with contents of parameter
// adds node to the END of list
void DLList::PushBack(unsigned int parameter) {
    if (head_ == NULL) {
        PushFront(parameter);
    } else {
        DLNode* new_tail = new DLNode(parameter);
        tail_ -> SetNext(new_tail);
        new_tail -> SetPrevious(tail_);
        tail_ = new_tail;
        size++;
    }
}
// returns the head node int value
// if list is empty, output "List Empty" return 0
int DLList::GetFront() const {
    if (head_ != NULL) {
        return head_ -> GetContents();
    } else {
        cerr << "List Empty";
        return 0;
    }
}
// returns the tail node int value
// if list is empty, output "List Empty" return 0
int DLList::GetBack() const {
    if (head_ != NULL) {
        return tail_ -> GetContents();
    } else {
        cerr << "List Empty";
        return 0;
    }
}
// Removes the first node in the list
// if list already empty outputs "List Empty"
void DLList::PopFront() {
    if (head_ != NULL) {
        DLNode* temp_ = head_;
        head_ = head_ -> GetNext();
        delete temp_;
        if (head_ == NULL) {
            tail_ = NULL;
        } else {
            head_ -> SetPrevious(NULL);
        }
        size--;
    } else {
        cerr << "List Empty";
    }
}
// Removes the last node in the list
// if list already empty outputs "List Empty"
void DLList::PopBack() {
    if (head_ == NULL) {
        cerr << "List Empty";
    } else if (head_ == tail_) {
        PopFront();
    } else {
        DLNode* iterator_ = tail_ -> GetPrevious();
        iterator_ -> SetNext(NULL);
        delete tail_;
        tail_ = iterator_;
        size--;
    }
}
// Parameter - int to be found in list
// if value is found, remove only that node from list
// if not found, output "Not Found"
void DLList::RemoveFirst(unsigned int parameter) {
    if (head_ != NULL) {
        DLNode* iterator_ = head_;
        DLNode* trailer_ = head_;

        while (iterator_ != NULL && iterator_ -> GetContents() != parameter) {
            trailer_ = iterator_;
            iterator_ = iterator_ -> GetNext();
        }

        if (iterator_ == NULL) {
            cerr << "Not Found";
        } else if (iterator_ == head_) {
            PopFront();
        } else if (iterator_ == tail_) {
            PopBack();
        } else {
            // Update Forward Link
            trailer_ -> SetNext(iterator_ -> GetNext());
            // Update Back Link
            (iterator_ -> GetNext()) -> SetPrevious(trailer_);
            delete iterator_;
            size--;
        }
    } else {
        cerr << "Not Found";
    }
}
// Parameter - int to be found in list
// remove all values matching parameter
// if non found, output "Not Found"
void DLList::RemoveAll(unsigned int parameter) {
    // if Exists(parameter) == TRUE
    // while parameter exists RemoveFrist()
    // else cout "Not Found"
    if (Exists(parameter) == false) {
        cerr << "Not Found";
    } else {
        while (Exists(parameter) == true) {
            RemoveFirst(parameter);
        }
    }
}
// Parameter - int to be found in list
// if found return True, else False
bool DLList::Exists(unsigned int parameter) {
    if (head_ != NULL) {
        DLNode* iterator_ = head_;
        DLNode* trailer_ = head_;
        while (iterator_ != NULL && iterator_ -> GetContents() != parameter) {
            trailer_ = iterator_;
            iterator_ = iterator_ -> GetNext();
        }
        if (iterator_ == NULL) {
            return false;
        } else {
            return true;
        }
    }
    return false;
}
// deletes all nodes in list
// resets size to 0
// sets head and tail to NULL
void DLList::Clear() {
    DLNode* iterator_ = head_;
    while (head_ != NULL) {
        head_ = head_ -> GetNext();
        delete iterator_;
        iterator_ = head_;
    }
    tail_ = NULL;
    size = 0;
}
// Outputs contents of lists comma seperated
// starting at first and end at last (1, 2, 3)
// if list empty output "List Empty"
string DLList::ToStringForwards() {
    if (head_ == NULL) {
        cerr << "List Empty";
        return "";
    }
    DLNode* iterator_ = head_;
    stringstream ss;
    while (iterator_ != NULL) {
        ss << iterator_ -> GetContents();
        iterator_ = iterator_ -> GetNext();
        if (iterator_ != NULL) {
            ss << ", ";
        }
    }
    return ss.str();
}
// Outputs contents of list comma seperated
// start at end to first (3, 2, 1)
// if list empty output "List Empty"

// HELP SEGMENTATION FAULT IN TO BACKWARDS
// FAILING Forward too and remove first

string DLList::ToStringBackwards() {
    if (head_ == NULL) {
        cerr << "List Empty";
        return "";
    }
    DLNode* iterator_ = tail_;
    unsigned int holder = size;
    stringstream ss;
    while (holder != 0) {
        ss << iterator_ -> GetContents();
        iterator_ = iterator_ -> GetPrevious();
        holder--;
        if (holder != 0) {
            ss << ", ";
        }
    }
    return ss.str();
}
