/*
 * Name        : Assignment 1
 * Author      : Jasmine Vang
 * Description : Fnction Decleration and includes
 * Sources     : FILL IN
 */

#ifndef ASSIGNMENT_1_H
#define ASSIGNMENT_1_H

// Add any includes and using statements Here

#include <string>
using std::string;
// Declare Function Prototypes Here (What goes above main)
bool CheckAlphabetic(const string &to_check);

bool EncryptString(string &to_encrypt, int shift);

bool DecryptString(string &to_decrypt, int shift);

double ComputeAverage(double list[], int size);

double FindMinValue(double value[], int size);

double FindMaxValue(double value[], int size);

#endif /* ASSIGNMENT_1_H */
