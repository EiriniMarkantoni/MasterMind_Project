#include <iostream>
#include "Number.h"
using namespace std;

/*
    Κύριο πρόγραμμα Mastermind

    Παίκτης 1: εισάγει μυστικό αριθμό
    Παίκτης 2: προσπαθεί να τον μαντέψει σε 10 προσπάθειες
*/

int main() {
    Number secret;       // μυστικός αριθμός
    Number guess;        // προσπάθεια παίκτη

    bool found = false;

    cout << "First player: Enter the secret number.\n";
    secret.setNumber();

    // Καθαρισμός οθόνης (Windows)
    system("cls");

    cout << "Second player: Try to guess the number!\n";

    for (int i = 0; i < 10; i++) {

        cout << "\nAttempt " << i + 1 << " of 10\n";

        guess.setNumber();

        // Υπολογισμός αποτελεσμάτων
        int correctDigits = right_digits(secret, guess);
        int correctPositions = right_position(secret, guess);

        cout << "Correct digits: " << correctDigits << endl;
        cout << "Correct positions: " << correctPositions << endl;

        // Αν είναι σωστός αριθμός > τέλος παιχνιδιού
        if (compare_numbers(secret, guess)) {
            cout << "Congratulations! You guessed the number!\n";
            found = true;
            break;
        }
    }

    // Αν δεν βρεθεί σε 10 προσπάθειες
    if (!found) {
        cout << "\nGame Over! You lost.\n";
        cout << "The correct number was: ";
        secret.printNumber();
    }

    return 0;
}
