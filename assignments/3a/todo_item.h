/*
 * Name        : todo_item.h
 * Author      : Jasmine Vang
 * Description : Class Header File
 */

// ADD HEADER GUARD HERE
#ifndef VANG_TODO_ITEM_H_
#define VANG_TODO_ITEM_H_

class TodoItem {
 public: 
    // Constructor 
    TodoItem(string description, int priority = 1, bool completed = true)
        : description_(description),
          priority_(priority),
          completed_(completed) {
              
    }
    
    // Accessor for description_
    string description() const {
        return description_;
    }
    
    // Accessor for priority_
    int priority() const {
        return priority_;
    }
    
    // Accessor for completed
    bool completed() const {
        return completed_;
    }
    
    // Mutator for description 
    void set_description(string description) {
        description_ = description;
    }
    
    // Mutator for priority 
    void set_priority(int priority) {
        priority_ = priority;
    }
    
    // Mutator for completed
    void set_completed(bool completed) {
        completed_ = completed;
    }
    
    // NEED MEMBER FUNCTION TOFILE 
    
    private:
     string description_;
     int priority_;
     bool completed_;
};

#endif

