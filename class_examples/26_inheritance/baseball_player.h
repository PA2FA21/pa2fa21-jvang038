/*
 * Name        : baseball_player.h
 * Author      : Luke Sathrum
 * Description : Writing a derived class from person
 */

#ifndef BASEBALL_PLAYER_H_
#define BASEBALL_PLAYER_H_

#include "person.h"

// Baseball Player is a derived class from Person
class BaseballPlayer : public Person {
 public:
  // Constructor
  BaseballPlayer(double batting_average, int home_runs)
      : batting_average_(batting_average),
        home_runs_(home_runs) {
  }

  // Accessor for batting_average_
  double batting_average() const {
    return batting_average_;
  }

  // Accessor for home_runs_
  int home_runs() const {
    return home_runs_;
  }

  // Mutator for batting_average_
  void set_batting_average(double battingAverage) {
    batting_average_ = battingAverage;
  }

  // Mutator for home_runs_
  void set_home_runs(int homeRuns) {
    home_runs_ = homeRuns;
  }

  // Returns a string representation of our baseball player
  // Calls the base ToString()
  string ToString() {
    ostringstream ss;
    ss.setf(std::ios::showpoint | std::ios::fixed);
    ss.precision(3);
    // Add our base ToString to the stream
    ss << Person::ToString();
    ss << "Batting Average: " << batting_average_ << "\nHome Runs: "
       << home_runs_ << endl;
    return ss.str();
  }

 private:
  double batting_average_;
  int home_runs_;
};

#endif /* BASEBALL_PLAYER_H_ */
