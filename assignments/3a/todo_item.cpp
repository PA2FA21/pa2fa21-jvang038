/*
 * Name        : Assignment 3a
 * Author      : Jasmine Vang
 * Description : To do list with priority and completion status
 * Sources     : FILL IN
 */
#include "todo_item.h"

// Accessor for description_
string TodoItem::description() const {
    return description_;
}

// Accessor for priority_
int TodoItem::priority() const {
    return priority_;
}

// Accessor for completed
bool TodoItem::completed() const {
    return completed_;
}

// Mutator for description
void TodoItem::set_description(string description) {
    description_ = description;
}

// Mutator for priority
void TodoItem::set_priority(int priority) {
    if (priority < 1 || priority > 5) {
        priority = 5;
    }
    priority_ = priority;
}

// Mutator for completed
void TodoItem::set_completed(bool completed) {
    completed_ = completed;
}

// NEED MEMBER FUNCTION TOFILE
string TodoItem::ToFile() {
    stringstream ss;
    string output;
    output = Scrub(description_);
    ss << output << '@' << priority_
       << '@' << completed_;
    return ss.str();
}

string TodoItem::Scrub(string modify) {
    string output = modify;
    for (unsigned int i = 0; i < output.length(); i++) {
        if ((output[i]) == '@') {
            output[i] = '`';
        }
    }
    return output;
}
