/*
 * Name        : person.h
 * Author      : Luke Sathrum
 * Description : Writing our base class.
 */

#ifndef PERSON_H_
#define PERSON_H_

#include <string>
#include <iostream>
#include <sstream>
using std::string;
using std::ostringstream;
using std::ostream;
using std::cout;
using std::endl;

// This class models a person
class Person {
 public:
  // Constructor
  Person(string name = "noname", int age = 0, char gender = 'U')
      : name_(name),
        age_(age),
        gender_(gender) {
  }

  // Accessor for name_
  const string& name() const {
    return name_;
  }
  // Accessor for age_
  int age() const {
    return age_;
  }

  // Accessor for gender_
  char gender() const {
    return gender_;
  }

  // Mutator for name_
  void set_name(const string& name) {
    name_ = name;
  }

  // Mutator for age_
  void set_age(int age) {
    age_ = age;
  }

  // Mutator for gender_
  void set_gender(char gender) {
    gender_ = gender;
  }

  // Returns a string representation of our person
  string ToString() {
    ostringstream ss;
    // Add our base ToString to the stream
    ss << name_ << "\nAge: " << age_ << "\nGender: " << gender_ << endl;
    return ss.str();
  }

 private:
  string name_;
  int age_;
  char gender_;
};

#endif /* PERSON_H_ */
