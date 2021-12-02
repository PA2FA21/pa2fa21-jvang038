/*
 * Name        : Assignment 3c
 * Author      : Jasmine Vang
 * Description : To do lists
 * Sources     : FILL IN
 */

#include "todo_ui.h"

// Constructor Allocates memory for the TodoList object
TodoUI::TodoUI() {
    list = new TodoList;
}

// Destructor Frees the memory associated with the dynamic TodoList object
TodoUI::~TodoUI() {
    delete list;
}

// Logic of function to call based on user input
// calls private functions to preform each task
void TodoUI::Menu() {
    // Declaring genaric value to hold user input
    unsigned int choice = 1;
    // While loop to break when user selects option 7
    // option 7 being quit program
    while (choice != 7) {
        // Display of choices
        Display();
        // collecting the new value for user input
        choice = Welcome();
        if (int_var == 1) {
            // create new item
            NewItem();
        } else if (int_var == 2) {
            // Edit an Item
            EditItem();
        } else if (int_var == 3) {
            // Delete an Item
            Delete();
        } else if (int_var == 4) {
            // View all Items
            ViewAll();
        } else if (int_var == 5) {
            // View specific Item
            View(0);
        } else if (int_var == 6) {
            // Delete ALL items
            DeleteAll();
        }
    }
    // While Loop ends, program end
}

// Welcome message and menu display
void TodoUI::Display() {
    system("clear");
    // Welcom message if there are no items in list
    if (list -> GetSize() == 0) {
        cout << "Welcome! Lets get started with making a To Do List!"
             << endl;
    }
    // menu options
    cout << "Select an option\n\n"
     << "1. Create New Item\n"
     << "2. Edit an Item\n"
     << "3. Delete an Item\n"
     << "4. View ALL Items\n"
     << "5. View Specific Item\n"
     << "6. Delete ALL items\n"
     << "7. Quit Program" << endl;
}

// Logic to collect user input and error handeling
unsigned int TodoUI::Welcome() {
    char_var = 'n';
    while (char_var == 'n' || char_var == 'N') {
        int_var = reader.readInt(1, 7);
        // error handeling for options 2-6 and list is empty
        if (int_var != 1 && int_var != 7 && list -> GetSize() == 0) {
            cout << "No items in list, make a new selection:" << endl;
        } else {
            // verifying user input
            cout << "\nYou entered: " << int_var
                 << " Would you like to proceed? (Y = YES N = NO)"
                 << endl;
            char_var = reader.readChar("YyNn");
            // Display message if user wants to enter a new input
            if (char_var == 'n' || char_var == 'N') {
                cout << "Make a new selection:" << endl;
            }
        }
    }
    system("clear");
    return int_var;
}

// Creates a new item and adds it to the list
// uses user input for item creation
void TodoUI::NewItem() {
    // initializing char_var to n
    char_var = 'n';
    // while loop collecting user input for new item
    // error handeling for user input
    // allows user to add item or go back and create new item
    while (char_var == 'n' || char_var == 'N') {
        cout << "Enter the description of the task:" << endl;
        string_var = reader.readString(false);
        cout << "\nEnter the Priority of the task (1-5):" << endl;
        int_var = reader.readInt(1, 5);
        cout << "\nEnter the completion status "
             << "(T for complete F for incomplete):" << endl;
        bool_var = reader.readBool();
        system("clear");
        // change bool value to be user friendly
        // initalize bool value to string incomplete
        string complete = "Incomplete";
        // logic to adjust bool_var string accordingly
        if (bool_var == true) {
            complete = "Complete";
        }
        // Display item and allow user option to add to list
        cout << "Your item is: " << string_var << "\nPriority: "
             << int_var << "\nCompletion Status: " << complete
             << endl << "\nAdd Item to list? (Y = YES, N = NO)"
             << endl;
        char_var = reader.readChar("YyNn");
        system("clear");
    }
  // adding item to the list
  list -> AddItem(new TodoItem(string_var, int_var, bool_var));
}

// Finds the item to edit, allows user to select what to edit
// deletes current instance and replaces with new
// allows user to edit specific item multiple times before exiting
void TodoUI::EditItem() {
    // display list of items for user to view
    cout << *list << endl;
    // initialize value for loop
    char_var = 'n';
    // First while loop to collect the item to edit
    while (char_var == 'n' || char_var == 'N') {
        cout << "Enter the number for the Item to edit:" << endl;
        int_var = reader.readInt(1, list -> GetSize());
        // verify users choice
        cout << "Edit # " << int_var << " (Y = YES, N = NO)?" << endl;
        char_var = reader.readChar("YyNn");
        system("clear");
    }
    // initialize value to n for following while loop
    char_var = 'n';

    // While loop to edit specific values of item selected
    // allows user to select what to edit, and to edit multiple things
    while (char_var == 'n' || char_var == 'N') {
        // display the item and the options
        cout << "Current item:" << endl;
        View(int_var);
        cout << "\nWhat would you like to edit?\n"
             << "D = Description\nP = Priority \nC = Completion Status"
             << endl;
        char edit = reader.readChar("DdPpCc");
        system("clear");
        // display the current item
        cout << "Current item: " << endl;
        View(int_var);
        // logic for user selction of what to edit
        // edit descrption
        if (edit == 'd' || edit == 'D') {
            cout << "Enter the NEW description of the task:" << endl;
            string_var = reader.readString(false);
            // get the item and mutate the description
            list -> GetItem(int_var) -> set_description(string_var);
        // edit priotity
        } else if (edit == 'p' || edit == 'P') {
            cout << "Enter the NEW priority of the task (1-5):" << endl;
            unsigned int i = reader.readInt(1, 5);
            // get item and mutate priority
            list -> GetItem(int_var) -> set_priority(i);
        // edit completion status
        } else {
            cout << "Enter the NEW completion status "
                 << "(T for complete F for incomplete):" << endl;
            bool_var = reader.readBool();
            // get the item and mutate priority
            list -> GetItem(int_var) -> set_completed(bool_var);
        }

        system("clear");
        // Display new instance of item and allow user to add item
        // or go through and edit the same item again
        cout << "Edited Item:\n" << endl;
        View(int_var);
        cout << "\nAre you done editing "
             << "this item? (Y = YES, N = NO)"
             << endl;
        char_var = reader.readChar("YyNn");
        system("clear");
    }
}

// delete a specific item from the list
void TodoUI::Delete() {
    // Display the list
    cout << *list;
    // initialize value to 'n' for the loop
    char_var = 'n';
    // While loop allowing user to confirm deltion selection
    // or return to main screen without deleting
    while (char_var == 'n' || char_var == 'N') {
        cout << "\nEnter the number for the item you would like to delete"
             << " (0 Returns to main screen):"
             << endl;
        int_var = reader.readInt(0, list -> GetSize());
        char_var = 'y';
        if (int_var != 0) {
            cout << "Delete # " << int_var << " (Y = YES, N = NO)?" << endl;
            char_var = reader.readChar("YyNn");
        }
        system("clear");
    }
    // delete specific item from list
    list -> DeleteItem(int_var);
}

// View all items in list with an exit key to main menu
void TodoUI::ViewAll() {
    cout << *list;
    cout << "\nHit 'R' to return to the main screen" << endl;
    char_var = reader.readChar("Rr");
    system("clear");
}

// view specific item in list, with exit key to main menu
// param and if statements allowing for optional use of exit key
// if param is 0, use exit key
// otherwise param is the item to display without use of exit key
void TodoUI::View(unsigned int param) {
    // initialize int_var to param
    int_var = param;
    // if param is 0, allow user to change int_var
    if (param == 0) {
        cout << "Which item would you like to view?" << endl;
        int_var = reader.readInt(1, list -> GetSize());
    }
    // logic for making bool_var user friendly
    TodoItem *temp = list -> GetItem(int_var);
    string complete = "Incomplete";
    if (temp -> completed() == true) {
        complete = "Complete";
    }
    // display of the item based on user input
    cout << "#" << int_var << " " << temp -> description()
         << setw(20 - (temp -> description()).size())
         << " Priority: " << temp -> priority()
         << setw(15) << " Status: " << complete << endl;
    // logic for use of exit key
    if (param == 0) {
        cout << "\nHit 'R' to return to the main screen" << endl;
        char_var = reader.readChar("Rr");
        system("clear");
    }
}

// Delete all items in the list and create a new empty list
// Allows user to confirm deletion of entire list
void TodoUI::DeleteAll() {
    // Confirmation message
    cout << "Are you sure you want to delete the list?\n"
         << "(Y for DELETE ALL N for go back):" << endl;
    char_var = reader.readChar("YyNn");
    // Only deletes the list if the user selects Yes
    if (char_var == 'y' || char_var == 'Y') {
        delete list;
        list = new TodoList;
    }
  system("clear");
}
