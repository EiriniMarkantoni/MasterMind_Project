#include <iostream>
#include <cstdlib>
#include "Number.h"
using namespace std;

int main() {
    Number number;
    Number guessNumber;
    bool found = false;

    cout << "First player, give a 4-digit number using digits 1-9." << endl;
    number.setNumber();

    system("cls"); // se Windows
    // system("clear"); // se Linux/Mac

    cout << "Second player, try to guess the number." << endl;

    for (int i = 0; i < 10; i++) {
        cout << endl;
        cout << "Try " << i + 1 << " of 10." << endl;

        guessNumber.setNumber();

        cout << "Correct digits: " << right_digits(number, guessNumber) << endl;
        cout << "Correct positions: " << right_position(number, guessNumber) << endl;

        if (compare_numbers(number, guessNumber)) {
            cout << "Congratulations! You guessed the right number!" << endl;
            found = true;
            break;
        } else {
            cout << "Wrong guess. Try again." << endl;
        }
    }

    if (!found) {
        cout << endl;
        cout << "Sorry! You lost." << endl;
        cout << "The correct number was: ";
        number.printNumber();
    }

    return 0;
}
