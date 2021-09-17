/*
 * Name        : Assignment 1 
 * Author      : Jasmine Vang
 * Description : Manipulating letters, and numbers with varioius methods
 * Sources     : FILL IN
 */

#include "assignment_1.h"

// Write Function Definitions Here (What goes below main)
bool CheckAlphabetic(const string &to_check) {
    int size = to_check.length();
    if (to_check == "") {
        return false;
    }
    for (int i = 0; i < size; i++) {
       if (!isalpha(to_check[i])) {
          return false;
       }
    }
  return true;
  // happens after the if statement bc it needs to check every letter
}

bool EncryptString(string &to_encrypt, int shift) {
    int number = shift % 26;
    int size = to_encrypt.size();
    if (CheckAlphabetic(to_encrypt) == false) {
        return false;
    } else {
        for (int i = 0; i < size; i++) {
            if (isupper(to_encrypt.at(i))) {
                to_encrypt.at(i) = to_encrypt.at(i) + number;
                if (to_encrypt.at(i) > 'Z') {
                    to_encrypt.at(i) = to_encrypt.at(i) - 26;
                } else if (to_encrypt.at(i) < 'A') {
                    to_encrypt.at(i) = to_encrypt.at(i) + 26;
                }
            } else if (islower(to_encrypt.at(i))) {
                to_encrypt.at(i) = to_encrypt.at(i) + number;
                if (to_encrypt.at(i) > 'z' || to_encrypt.at(i) < 0) {
                    to_encrypt.at(i) = to_encrypt.at(i) - 26;
                } else if (to_encrypt.at(i) < 'a') {
                    to_encrypt.at(i) = to_encrypt.at(i) + 26;
                }
            }
        }
    }
    return true;
}

bool DecryptString(string &to_decrypt, int shift) {
  return EncryptString(to_decrypt, -shift);
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
