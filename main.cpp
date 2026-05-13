#include <iostream>
#include "Number.h"
using namespace std;

/*
    Mastermind Game

    Player 1: Enters the secret number
    Player 2: Tries to guess it in 10 attempts
*/

int main() {
    Number secret;       // Secret number
    Number guess;        // Player's guess

    bool found = false;

    cout << "First player: Enter the secret number.\n";
    secret.setNumber();

    // Clear screen (Windows)
    system("cls");

    cout << "Second player: Try to guess the number!\n";

    for (int i = 0; i < 10; i++) {

        cout << "\nAttempt " << i + 1 << " of 10\n";

        guess.setNumber();

        // Calculate results
        int correctDigits = right_digits(secret, guess);
        int correctPositions = right_position(secret, guess);

        cout << "Correct digits: " << correctDigits << endl;
        cout << "Correct positions: " << correctPositions << endl;

        // If the numbers are exactly the same
        if (compare_numbers(secret, guess)) {
            cout << "Congratulations! You guessed the number!\n";
            found = true;
            break;
        }
    }

    // If the player did not guess in 10 attempts
    if (!found) {
        cout << "\nGame Over! You lost.\n";
        cout << "The correct number was: ";
        secret.printNumber();
    }

    return 0;
}
