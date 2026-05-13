#include "Number.h"
#include <iostream>
using namespace std;

/*
    Constructor
    Initializes the number as an empty string
*/
Number::Number() {
    number = "";
}

/*
    Reads a number from the user with validation
*/
void Number::setNumber() {
    bool valid;

    do {
        valid = true;

        cout << "Give a 4-digit number (first digit not 0): ";
        cin >> number;

        // Check length
        if (number.length() != 4) {
            valid = false;
        } else {
            // First digit cannot be 0
            if (number[0] == '0') {
                valid = false;
            }

            // Check that all characters are digits
            for (int i = 0; i < 4; i++) {
                if (number[i] < '0' || number[i] > '9') {
                    valid = false;
                }
            }
        }

        if (!valid) {
            cout << "Invalid number. Try again.\n";
        }

    } while (!valid);
}

/*
    Prints the number
*/
void Number::printNumber() const {
    cout << number << endl;
}

/*
    Calculates how many digits are correct
    (without considering their position)
*/
int right_digits(const Number& n1, const Number& n2) {
    int count = 0;

    bool used1[4] = {false}; // Keeps track of used digits from n1
    bool used2[4] = {false}; // Keeps track of used digits from n2

    // First find digits in the correct position
    for (int i = 0; i < 4; i++) {
        if (n1.number[i] == n2.number[i]) {
            count++;
            used1[i] = used2[i] = true;
        }
    }

    // Then find correct digits in wrong positions
    for (int i = 0; i < 4; i++) {
        if (!used2[i]) {
            for (int j = 0; j < 4; j++) {
                if (!used1[j] && n2.number[i] == n1.number[j]) {
                    count++;
                    used1[j] = true;
                    break;
                }
            }
        }
    }

    return count;
}

/*
    Calculates how many digits are
    in the correct position
*/
int right_position(const Number& n1, const Number& n2) {
    int count = 0;

    for (int i = 0; i < 4; i++) {
        if (n1.number[i] == n2.number[i]) {
            count++;
        }
    }

    return count;
}

/*
    Checks if the two numbers
    are exactly the same
*/
bool compare_numbers(const Number& n1, const Number& n2) {
    return right_position(n1, n2) == 4;
}
