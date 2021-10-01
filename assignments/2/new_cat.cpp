/*
 * Name        : Assignment 2 new_cat.cpp
 * Author      : Jasmine Vang
 * Description : Opening Files
 */
#include <fstream>
#include <string>
#include <iostream>
using std::endl;
using std::string;
using std::cin;
using std::cout;
using std::ifstream;

int main(int argc, char *argv[]) {
    ifstream fin;
    string line;
    if (argc == 1) {
        while (!cin.eof()) {
            // cin get input from user
            getline(cin, line);
            // cout echo out what they inputted
            cout << line << endl;
        }
    } else {
        for (int i = 1; i < argc; i++) {
            fin.open(argv[i]);
            if (!fin) {
                cout << "cat: " << argv[i] << ":"
                     << " No such file or directory\n";
                return 1;
            }
            fin.close();
        }
        for (int i = 1; i < argc; i++) {
            fin.open(argv[i]);
            while (!fin.eof()) {
                line = fin.get();
                cout << line;
                }
            fin.close();
        }
    }
    return 0;
}
