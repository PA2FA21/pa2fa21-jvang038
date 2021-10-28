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
    // NEED TO loop through array and set all to null
    for (int i = 0; i < cap_; i++) {
        TodoItem[i] = NULL; 
    }
}
// Destructor to clean up dynamic array 
TodoList::~TodoList() {
    delete[] list_;
}
// If there is room in the array add the new dynamic instance 
// to the first available spot (i.e. the current size).
// If the array is full, increase capacity by 10 and then add the item.
void TodoList::AddItem(TodoItem *item) {
    if (size_ != cap_) {
        list_[size_] = item;
        size_++;
    } else {
        cap_ = (cap_ + 10);
        list_[size_] = item;
        size_++;
    }
}
// delete an item from the list and shift the list down
// human readable, if enter delete 1 means delete 0
void TodoList::DeleteItem(int where) {
    // compaction video To delete the 1 item to move it
    //chack to make sure index is valid
    delete list_[where - 1];
}
// Accessor for item 
// if wanting 1 return 0
// for types the star goes to the end
// to do item is a type, a pointer type
TodoItem* TodoList::GetItem(int where) {
    // check validity of index
    return list_[where - 1];
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
    // will still be using lisy_ as the array to sort 
    // once checking priority, dont want to swap priority, want to swap the memory pointer
    // where is it pointing to
    // swap is written on picture of phone
}
// Returns a string containing all TodoItems in the list. 
// Uses the TodoItems ToFilefunction to create. 
// Each item should be on its own line.
string TodoList::ToFile() {
    return "hi";
}

// Overloaded << 
ostream& operator <<(ostream &out, const TodoList &t) {
    return out;
}
// for loop that calls the get functions to print the appropriate item at i
    
// Increases the capacity of the array by 10. 
// Should be called by AddItemat the appropriate time.
void TodoList::AddTen() {
    
}
// Compacts the array to get rid of an empty spot in the array. 
// Should be called by DeleteItemat the appropriate time.
void TodoList::CompactSpace() {
    
}
