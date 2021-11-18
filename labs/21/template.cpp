/*
 * Name        : template.cpp
 * Author      : Jasmine Vang
 * Description : Various functions using templates. Please note you can just
 *               write the definitions in here. No need for prototypes.
 */
#include <string>
#include <sstream>
using std::string;
using std::stringstream;

/*
 * Function Name: PrepareForDisplay
 * Create a string containing the contents of an array, each element separated
 * by a specified character. For example, if the array contents
 * are {1, 2, 3} and the separator character is ':', the string returned
 * will be "1:2:3". Please note the array can be of any type.
 * If the template function outputs doubles, they should be to a precision of 2.
 * @uses stringstream
 * @param T values[] - An array of any type
 * @param unsigned int size - The size of the array
 * @param char separator - The separator character to use in the returned
 *                         string. Defaults to ','
 * @return string - A string containing the contents of values separated by the
 *                  specified separator character
 */
template <typename Type>
string PrepareForDisplay(Type values[], unsigned int size,
                                        char separator = ',') {
  unsigned int i;
  stringstream ss;
  // Set Perscion will only work when applicable
  ss.setf(std::ios::showpoint | std::ios::fixed);
  ss.precision(2);
  for (i = 0; i < size - 1; i++) {
    ss << values[i] << separator;
  }
  ss << values[i];
  return ss.str();
}

/*
 * Function Name: HasValue
 * Test to see if an array contains a specified value.
 * @param T values[] -  An array of any type
 * @param unsigned int size - The size of the array
 * @param T value_to_find - The value to search for within the array
 * @return bool - true if value is found in the array, otherwise false
 */
template <typename Type>
bool HasValue(Type values[], unsigned int size, Type value_to_find) {
  for (unsigned int i = 0; i < size; i++) {
    if (values[i] == value_to_find)
      return true;
  }
  return false;
}

/*
 * Function Name: ValueAt
 * Return the value from an array at a specified index.
 * @param T values[] -  An array of any type
 * @param unsigned int size - The size of the array
 * @param unsigned int index - The position in the array from which to return a
 *                             value
 * @param bool &error - A flag that will be set to true if index is invalid for
 *                     the array, else it will be set to false
 * @return T - The value at the specified index in the array when error is set
 *               to false. if index is invalid, returns a zero representation of
 *               the type and sets error to true. To get a zero representation
 *               you can return T()
 */
template <typename Type>
Type ValueAt(Type values[], unsigned int size,
                            unsigned int index, bool &error) {
    if (index <= (size - 1)) {
      error = false;
      return values[index];
      } else {
        error = true;
        return Type();
      }
}

/*
 * Function Name: Sum
 * Return the "sum" of the values in the array. Your initial sum should be set
 * to "zero" in your algorithm. To do this use T().
 * @param T values[] - An array of any type
 * @param unsigned int size - The size of the array
 * @return T - The sum of the values in the array
 */
template <typename T>
T Sum(T values[], unsigned int size) {
  T sum = T();
  for (unsigned int i = 0; i < size; i++) {
    sum = sum + values[i];
  }
  return sum;
}

/*
 * Function Name: SwapValues
 * Swap the positions of two values in an array. The two index values must be
 * valid for the array.
 * @param T values[] - An array of any type
 * @param unsigned int size - The size of the array
 * @param unsigned int index1 - The position of the first value to be swapped
 * @param unsigned int index2 - The position of the second value to be swapped
 * @return bool - true if the swap was successful, otherwise false
 */
template <typename T>
bool SwapValues(T values[], unsigned int size,
                            unsigned int index1, unsigned int index2) {
  T holder;
  if (index1 >= 0 && index1 < size && index2 >= 0 && index2 < size) {
    holder = values[index1];
    values[index1] = values[index2];
    values[index2] = holder;
    return true;
  }
  return false;
}

