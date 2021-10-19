/*
 * Name        : dynamic_objects_in_dynamic_array.cpp
 * Author      : Luke Sathrum
 * Description : Creating a class that has a dynamic array that holds dynamic
 *               objects.
 */

// HELPFUL FOR 3B

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

struct Score {
  int score;
  int max;
};

// This class will create a dynamic array to hold dynamic Score objects
class Scores {
 public:
  // Constructor to create the dynamic array of size
  Scores(int size);
  // Destructor to clean-up our dynamic array
  ~Scores();
  // Will prompt the user to enter the scores
  void FillUp();
  // Will Output all the scores in the array
  void Output();
 private:
  int size_;
  // This is ** because it will point to dynamic Score objects
  Score **values_;
};

// Program starts here
int main() {
  // Create a dynamic instance
  Scores *object = new Scores(2);
  object->FillUp();
  object->Output();
  // Call to delete, which will call the destructor
  delete object;

  // This ends our program
  return 0;
}

Scores::Scores(int size) {
  // Set the internal size to the parameter
  size_ = size;
  // Create the dynamic array // allocate the dynamic array of pointers
  values_ = new Score*[size];
}

Scores::~Scores() {
  // First we delete all of our dynamic Score objects // all the "new" things
  for (int i = 0; i < size_; i++)
    delete values_[i];
  // Then we delete the dynamic values_ array // which was pointing at values_[i]
  delete[] values_;
}

void Scores::FillUp() {
  // Allocate new Score objects
  for (int i = 0; i < size_; i++) {
    values_[i] = new Score; // taking the first thing in an array and pointing it to a new score object
    cout << "Enter score #" << (i + 1) << ": ";
    cin >> values_[i]->score; // access score location in the dynamic object therefor uses ->
    cout << "Enter max value for score #" << (i + 1) << ": ";
    cin >> values_[i]->max; // holds both score and max, access it with -> 
  }
}

void Scores::Output() {
  for (int i = 0; i < size_; i++) {
    cout << "Score #" << (i + 1) << ": " << values_[i]->score << "/"
         << values_[i]->max << endl;
  }
}
