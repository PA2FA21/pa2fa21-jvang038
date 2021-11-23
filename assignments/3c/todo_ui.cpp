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

// calls private functions that are in private
// each one will do the logic for user input
// menu will have if input then statement 
void TodoUI::Menu() {
    // Welcome message
    unsigned int choice = Welcome();
    while (choice != 7) {
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
            list -> ToFile();
        } else if (int_var == 5) {
            // View specific Item
            View();
        } else {
            // option 6
            // Delete ALL items
            DeleteAll();
        }
        choice = Welcome();
    }
    
}

unsigned int TodoUI::Welcome() {
    char_var = 'n';
    while (char_var == 'n' || char_var == 'N') {
        cout << "Welcome, get started and get to work with this to do list!\n"
             << "It's time to increase your productivity.\n"
             << "Select an option to preform (1-7)\n"
             << "1. Create New Item\n"
             << "2. Edit an Item\n"
             << "3. Delete an Item\n"
             << "4. View ALL Items\n"
             << "5. View Specific Item\n"
             << "6. Delete ALL items\n"
             << "7. Quit Program\n" << endl;
        int_var = reader.readInt(1, 7);
        cout << "You entered: " << int_var
             << " Would you like to proceed? (Y = YES N = NO)\n"
             << endl;
        char_var = reader.readChar("YyNn");
        system("clear");
    }
    // enter is this correct loop
    return int_var;
}

void TodoUI::NewItem() {
    while (char_var == 'n' || char_var == 'N') {
        cout << "Enter the description of the task:\n" << endl;
        string_var = reader.readString(false);
        cout << "Enter the Priority of the task (1-5):\n" << endl;
        int_var = reader.readInt(1, 5);
        cout << "Enter the completion status "
             << "(T for complete F for incomplete):\n" << endl;
        bool_var = reader.readBool();
        system("clear");
        cout << "Your item is: " << string_var << " Priority: "
             << int_var << " Completion Status: " << bool_var
             << endl << "Add Item to list? (Y = YES, N = NO)\n" 
             << endl;
        char_var = reader.readChar("YyNn");
        system("clear");
    }
    char_var = 'n';
    
    
    list -> AddItem(new TodoItem(string_var, int_var, bool_var));
    // AddItem(TodoItem(string_var, int_var, bool_var));
}

void TodoUI::EditItem() {
    list -> ToFile();
    while (char_var == 'n' || char_var == 'N') {
        cout << "Enter the number for the Item to edit:\n" << endl;
        int_var = reader.readInt(1, list -> GetSize());
        cout << "Edit # " << int_var << " (Y = YES, N = NO)?" << endl;
        char_var = reader.readChar("YyNn");
        system("clear");
    }
    char_var = 'n';
    while (char_var == 'n' || 'N') {
        cout << list -> GetItem(int_var) << "\nWhat would you like to edit?\n" 
             << "D = Description\n P = Priority \n C = Completion Status"
             << endl;
        char_var = reader.readChar("DdPpCc");
        system("clear");
        cout << list -> GetItem(int_var);
        if (char_var == 'd' || 'D') {
            cout << "Enter the NEW description of the task:\n" << endl;
            string_var = reader.readString(false);
            list[int_var] -> set_description(string_var);
        } else if (char_var == 'p' || 'P') {
            cout << "Enter the NEW priority of the task (1-5):";
            unsigned int i = reader.readInt(1, 5);
            list[int_var] -> set_priority(i);
        } else {
            cout << "Enter the NEW completion status "
                 << "(T for complete F for incomplete):\n" << endl;
            bool_var = reader.readBool();
            list[int_var] -> set_priority(bool_var);
        }
        system("clear");
        cout << "Edited Item:\n" << list -> GetItem(int_var)
             << "\n\nWould you like to conitune editing " 
             << "this item? (Y = YES, N = NO)"
             << endl;
        char_var = reader.readChar("YyNn");
        system("clear");
    }
}

void TodoUI::Delete() {
    list -> ToFile();
    char_var = 'n';
    while (char_var == 'n' || 'N') {
        cout << "Enter the number for the item you would like to delete?"
             << endl;
        int_var = reader.readInt(1, list -> GetSize());
        cout << "Delete # " << int_var << " (Y = YES, N = NO)?" << endl;
        char_var = reader.readChar("YyNn");
        system("clear");
    }
    list -> DeleteItem(int_var);
}

void TodoUI::View() {
    cout << "Which item would you like to view?" << endl;
    int_var = reader.readInt(1, list -> GetSize());
    cout << list -> GetItem(int_var);
    cout << "\n hit 'R' to return to the main screen" << endl;
    char_var = reader.readChar("Rr");
    system("clear");
}

void TodoUI::DeleteAll() {
    cout << "Are you sure you want to delete the list?\n"
         << "(Y for DELETE ALL N for go back):\n" << endl;
    char_var = reader.readChar("YyNn");
    if (char_var == 'y' || 'Y') {
        delete[] list;
        // MAKE A NEW LIST??
    }
    system("clear");
}
