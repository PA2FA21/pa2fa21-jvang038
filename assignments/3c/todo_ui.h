/*
 * Name        : todo_ui.h
 *              (3c)
 * Author      : Jasmine Vang
 * Description : todo Header File
 */

// ADD HEADER GUARD HERE
#ifndef VANG_TODO_UI_H_
#define VANG_TODO_UI_H_

#include "todo_item.h"
#include "todo_list.h"
#include <iostream>
#include <string>
#include <sstream>
using std::string;
using std::stringstream;

class TodoUI {
 public:
    // Constructor Allocates memory for the TodoList object
    TodoUI();
    // Destructor Frees the memory associated with the dynamic TodoList object
    ~TodoUI();
    // calls private functions that are in private
    // each one will do the logic for user input
    // menu will have if input then statement 
    void Menu();
 private:
    // dynamic instance of TodoList 
    TodoList** something
    // NEED cinreader
    
    // finds item to edit, deletes current instance, replaces with new value
    void EditAnItem();
    // Displays exit message, quits program
    void Quit();
};

#endif

NOTE functions: Menu, Editanitem, quit, all missing parameters

• Create New Item 
• Edit an Item 
• Delete an Item 
• View All Items 
• View Specific Item 
• Delete All Items 
• Quit Program

// add nothing
// add one
// add two 
// delete one thing
// clear list then
// add to list - did you recreate list