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
#include "CinReader.h"
#include <iostream>
#include <string>
#include <sstream>
using std::string;
using std::stringstream;
using std::cout;
using std::cin;

class TodoUI {
 public:
    // Constructor Allocates memory for the TodoList object
    TodoUI();
    // Destructor Frees the memory associated with the dynamic TodoList object
    ~TodoUI();
    // calls private functions that are in private
    // each one will preform the logic for user input
    // menu will have if input then statement 
    void Menu();
    unsigned int int_var;
    string string_var;
    bool bool_var;
    char char_var;
 private:
    // dynamic instance of TodoList 
    TodoList* list;
    // Instance of cinreader
    CinReader reader;
    void Display();
    // Welcome message
    unsigned int Welcome();
    // Create new item
    void NewItem();
    // finds item to edit, deletes current instance, replaces with new value
    void EditItem();
    // Delete an Item
    void Delete();
    // View all items in list
    void ViewAll();
    // View Specific Item
    void View();
    // Deletes ALL items
    void DeleteAll();
    // Displays exit message, quits program
    
};

#endif
