/*
 * Name        : money.cpp
 * Author      : Jasmine Vang
 * Description : money file
 */

#include "money.h"

// This function definition provided as an example
const Money operator +(const Money& amount1, const Money& amount2) {
  // Get all the cents of object 1
  int all_cents1 = amount1.cents_ + amount1.dollars_ * 100;
  // Get all the cents of object 2
  int all_cents2 = amount2.cents_ + amount2.dollars_ * 100;
  // Add all the cents together
  int sum_all_cents = all_cents1 + all_cents2;
  // Handle the fact that money can be negative
  int abs_all_cents = abs(sum_all_cents);
  int final_dollars = abs_all_cents / 100;
  int final_cents = abs_all_cents % 100;
  // If the result of the operation was negative, negate final dollars and cents
  if (sum_all_cents < 0) {
    final_dollars = -final_dollars;
    final_cents = -final_cents;
  }
  return Money(final_dollars, final_cents);
}

// CLASS FUNCTION DEFINITIONS GO HERE

const Money operator -(const Money& amount1, const Money& amount2) {
  // Get cent value for both objects
  int all_cents1 = amount1.cents_ + amount1.dollars_ * 100;
  int all_cents2 = amount2.cents_ + amount2.dollars_ * 100;
  // Subtract the total cents
  int sub_all_cents = all_cents1 - all_cents2;
  // Handle negative money amounts
  int abs_all_cents = abs(sub_all_cents);
  // divide back into cents or dollars
  int final_dollars = abs_all_cents / 100;
  int final_cents = abs_all_cents % 100;
  // If result was negative, negate final amounts
  if (sub_all_cents < 0) {
    final_dollars = -final_dollars;
    final_cents = -final_cents;
  }
  return Money(final_dollars, final_cents);
}

bool operator ==(const Money &amount1, const Money &amount2) {
  return ((amount1.cents_ == amount2.cents_)
       && (amount1.dollars_ == amount2.dollars_));
}

const Money operator -(const Money &amount) {
  return Money(-amount.dollars_, -amount.cents_);
}

ostream& operator <<(ostream &out, const Money &amount) {
  int abs_all_cents = abs(amount.cents_);
  int abs_all_money = abs(amount.dollars_);
  if (amount.cents_ < 0 || amount.dollars_ < 0) {
    // setw and setfill happen before the thing you are setting.
    out << "$-" << abs_all_money << '.'
        << setw(2) << setfill('0') << abs_all_cents;
    return out;
  }
  out << '$' << abs_all_money << '.'
      << setw(2) << setfill('0') << abs_all_cents;
  return out;
}
