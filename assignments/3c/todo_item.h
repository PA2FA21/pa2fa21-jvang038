/*
 * Name        : todo_item.h
 *              (3c)
 * Author      : Jasmine Vang
 * Description : todo Header File
 */

// ADD HEADER GUARD HERE
#ifndef VANG_TODO_ITEM_H_
#define VANG_TODO_ITEM_H_

#include <iostream>
#include <string>
#include <sstream>
using std::string;
using std::stringstream;

class TodoItem {
 public:
    // Constructor
    TodoItem(string description, int priority = 1, bool completed = false)
        : description_(description),
          priority_(priority),
          completed_(completed) {
    }
    // Accessor for description_
    string description() const;
    // Accessor for priority_
    int priority() const;
    // Accessor for completed
    bool completed() const;
    // Mutator for description
    void set_description(string description);
    // Mutator for priority
    void set_priority(int priority);
    // Mutator for completed
    void set_completed(bool completed);
    /* Return a string containing the descriptioin, priority
     * and completed stauts, seperated by the '@' symbol
     * Uses StringStream
     * Uses the Scrub function to change '@' symbol that
     * may be contained in description_
    */
    string ToFile();

 private:
    string description_;
    int priority_;
    bool completed_;
    /* Replaces all '@'symbols with '`'symbols
     * and returns the modified string.
     */
    string Scrub(string modify);
};

#endif
