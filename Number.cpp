#include "Number.h"
#include <iostream>
using namespace std;

/*
    Constructor
    Αρχικοποιεί τον αριθμό ως κενό string
*/
Number::Number() {
    number = "";
}

/*
    Διαβάζει αριθμό από τον χρήστη με έλεγχο εγκυρότητας
*/
void Number::setNumber() {
    bool valid;

    do {
        valid = true;

        cout << "Give a 4-digit number (first digit not 0): ";
        cin >> number;

        // Έλεγχος μήκους
        if (number.length() != 4) {
            valid = false;
        } else {
            // Δεν επιτρέπεται να ξεκινά με 0
            if (number[0] == '0') {
                valid = false;
            }

            // Έλεγχος ότι όλα είναι ψηφία
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
    Εκτυπώνει τον αριθμό
*/
void Number::printNumber() const {
    cout << number << endl;
}

/*
    Υπολογίζει πόσα ψηφία είναι σωστά (χωρίς να λαμβάνει υπόψη τη θέση)
*/
int right_digits(const Number& n1, const Number& n2) {
    int count = 0;

    bool used1[4] = {false}; // κρατάει ποια ψηφία του n1 έχουν χρησιμοποιηθεί
    bool used2[4] = {false}; // κρατάει ποια ψηφία του n2 έχουν χρησιμοποιηθεί

    // Πρώτα βρίσκουμε τα σωστά στη σωστή θέση
    for (int i = 0; i < 4; i++) {
        if (n1.number[i] == n2.number[i]) {
            count++;
            used1[i] = used2[i] = true;
        }
    }

    // Μετά βρίσκουμε σωστά ψηφία σε λάθος θέση
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
    Υπολογίζει πόσα ψηφία είναι στη σωστή θέση
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
    Ελέγχει αν οι δύο αριθμοί είναι ακριβώς ίδιοι
*/
bool compare_numbers(const Number& n1, const Number& n2) {
    return right_position(n1, n2) == 4;
}
