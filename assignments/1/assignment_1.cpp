/*
 * Name        : Assignment 1 
 * Author      : Jasmine Vang
 * Description : FILL IN
 * Sources     : FILL IN
 */

#include "assignment_1.h"

// Write Function Definitions Here (What goes below main)
bool CheckAlphabetic(const string &to_check) {
    int size = to_check.size();
    for (int i = 0; i < size; i++) {
       if (!isalpha(to_check[i])) {
          return false;
       }
   }
   return true; //happens after the if statement bc it needs to check every letter
}

bool EncryptString(string to_encrypt, int shift) {
    shift %= 26;
    int size = to_encrypt.size();
    for (int i = 0; i < size; i++) {
        to_encrypt[i] = to_encrypt[i] + shift;
    }
    return true;
}

bool DecryptString(string to_decrypt, int shift) {
   EncryptString(to_decrypt, -shift);
   return true;
}

double ComputeAverage(double list[], int size) {
    double average = 0;
    for (int i = 0; i < size; i++) {
        average = (average + list[i]);
    }
    return average/size;
}

double FindMinValue(double value[], int size) {
    double min = value[0];
    for (int i = 0; i < size; i++) {
        if (value[i] < min) {
            min = value[i];
        }
    }
    return min;
}

double FindMaxValue(double value[], int size) {
    double max = value[0];
    for (int i = 0; i < size; i++) {
        if (value[i] > max) {
            max = value[i];
        }
    }
    return max;
}

//int min = a[0];
// check against min value