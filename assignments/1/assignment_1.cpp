/*
 * Name        : Assignment 1 
 * Author      : Jasmine Vang
 * Description : FILL IN
 * Sources     : FILL IN
 */

#include "assignment_1.h"

// Write Function Definitions Here (What goes below main)
bool CheckAlphabetic(const string &to_check) {
   for (int i = 0; i < to_check.size(); i++) {
       if (! isalpha(i) || i == 0) {
           return false;
       } else {
           return true; 
       }
   }
    // loop, some way to check isalpha(char)
}

// use + operator on letters.  
// can only go to 25 need % for numbers larger, loop through each char

//int min = a[0];
// check against min value