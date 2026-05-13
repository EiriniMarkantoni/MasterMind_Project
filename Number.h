#ifndef NUMBER_H
#define NUMBER_H

/*
    The Number class represents a 4-digit number

    The number is stored as a string,
    so we can easily compare digit by digit
*/

#include <string>
using namespace std;

class Number {
private:
    string number;  // Stores the 4-digit number (e.g. "1234")

public:

    // Constructor: initializes the number as empty
    Number();

    /*
        Reads a number from the user with validation:
        - must contain exactly 4 digits
        - only numeric characters are allowed
        - cannot start with 0
    */
    void setNumber();

    // Prints the number
    void printNumber() const;

    /*
        Friend functions used to compare
        two Number objects
    */

    // Returns how many digits are correct
    // (not necessarily in the correct position)
    friend int right_digits(const Number& n1, const Number& n2);

    // Returns how many digits are correct
    // and in the correct position
    friend int right_position(const Number& n1, const Number& n2);

    // Checks if the two numbers are identical
    friend bool compare_numbers(const Number& n1, const Number& n2);
};

#endif
