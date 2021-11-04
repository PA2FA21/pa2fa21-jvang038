/*
 * Name        : Assignment 3b
 * Author      : Jasmine Vang
 * Description : To do lists
 * Sources     : FILL IN
 */
#include "todo_list.h"

// Constructor to create dynamic array size 25 and set to null
TodoList::TodoList() {
    size_ = 0;
    cap_ = 25;
    list_ = new TodoItem*[cap_];
    // Loop through array and set all to null
    for (unsigned int i = 0; i < cap_; i++) {
        list_[i] = NULL;
    }
}
// Destructor to clean up dynamic array
TodoList::~TodoList() {
    for (unsigned int i = 0; i < size_; i++) {
        delete list_[i];
    }
    delete[] list_;
}
// If there is room in the array add the new dynamic instance
// to the first available spot (i.e. the current size).
// If the array is full, increase capacity by 10 and then add the item.
void TodoList::AddItem(TodoItem *item) {
    if (size_ < cap_) {
        list_[size_] = item;
        size_++;
    } else {
        AddTen();
        list_[size_] = item;
        size_++;
    }
}
// delete an item from the list and shift the list down
// human readable, if enter delete 1 means delete 0
void TodoList::DeleteItem(unsigned int where) {
    // compaction video To delete the 1 item to move it
    //check to make sure index is valid
    where--;
    if (where < size_) {
        delete list_[where];
        CompactSpace(where);
        size_--;
    }
}
// Accessor for item
// if wanting 1 return 0
// for types the star goes to the end
// to do item is a type, a pointer type
TodoItem* TodoList::GetItem(unsigned int where) {
    // check validity of index
    where--;
    if (where < size_) {
        return list_[where];
    }
    return NULL;
}
// Accesor Returns an unsigned integer containing the current size of the list
unsigned int TodoList::GetSize() {
    return size_;
}
// Accesor, Returns an unsigned integer containing the
// current maximum capacity of the list (number of slots).
unsigned int TodoList::GetCapacity() {
    return cap_;
}
// Sorts the array by the priorities of the items. (1 is highest priority, 5 is lowest).
void TodoList::Sort() {
    // bubble or insertion, STABLE!
    // look at picture on phone
    // will still be using list_ as the array to sort
    // once checking priority, dont want to swap priority, want to swap the memory pointer
    // where is it pointing to
    // swap is written on picture of phone
    for (unsigned int i = (size_ - 1); i >= 1; i--) {
        for (unsigned int j = 0; j <= (i - 1); j++) {
            if (list_[j] -> priority() > list_[j + 1] -> priority()) {
                TodoItem* temp_ = list_[j];
                list_[j] = list_[j + 1];
                list_[j + 1] = temp_;
            }
        }
    }
}
// Returns a string containing all TodoItems in the list.
// Uses the TodoItems ToFilefunction to create.
// Each item should be on its own line.
string TodoList::ToFile() {
    stringstream ss;
    for (unsigned int i = 0; i < size_; i++) {
        ss << list_[i] -> ToFile() << endl;
    }
    return ss.str();
}

// Overloaded <<
ostream& operator <<(ostream &out, const TodoList &t) {
    for (unsigned int i = 0; i < t.size_; i++) {
        out << "#" << i << t.list_[i] -> description() << " ";
        out << t.list_[i] -> priority() << " ";
        out << t.list_[i] -> completed() << endl;
    }
    return out;
}
// for loop that calls the get functions to print the appropriate item at i
    
// Increases the capacity of the array by 10.
// Should be called by AddItemat the appropriate time.
void TodoList::AddTen() {
    TodoItem** temp_;
    cap_ = (cap_ + 10);
    temp_ = new TodoItem*[cap_];
    for (unsigned int i = 0; i < size_; i++) {
        temp_[i] = list_[i];
    }
    for (unsigned int i = size_; i < cap_; i++) {
        temp_[i] = NULL;
    }
    delete[] list_;
    list_ = temp_;
}
// Compacts the array to get rid of an empty spot in the array.
// Should be called by DeleteItem at the appropriate time.
void TodoList::CompactSpace(unsigned int where) {
    for (unsigned int i = where; i < size_ - 1; i++) {
        list_[i] = list_[i + 1];
    }
    list_[size_ - 1] = NULL;
}
