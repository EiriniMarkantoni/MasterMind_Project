#include "Number.h"
#include <iostream>
using namespace std;

Number::Number() {
    number = "";
}

void Number::setNumber() {
    bool valid;

    do {
        valid = true;

        cout << "Give a 4-digit number (first digit not 0): ";
        cin >> number;

        if (number.length() != 4) {
            valid = false;
        } else {
            if (number[0] == '0') valid = false;

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

void Number::printNumber() const {
    cout << number << endl;
}

int right_position(const Number& n1, const Number& n2) {
    int count = 0;
    for (int i = 0; i < 4; i++) {
        if (n1.number[i] == n2.number[i]) count++;
    }
    return count;
}

int right_digits(const Number& n1, const Number& n2) {
    int count = 0;
    bool used1[4] = {false};
    bool used2[4] = {false};

    for (int i = 0; i < 4; i++) {
        if (n1.number[i] == n2.number[i]) {
            count++;
            used1[i] = used2[i] = true;
        }
    }

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

bool compare_numbers(const Number& n1, const Number& n2) {
    return right_position(n1, n2) == 4;
}
