#ifndef NUMBER_H
#define NUMBER_H

/*
    Η κλάση Number αναπαριστά έναν τετραψήφιο αριθμό

    Ο αριθμός αποθηκεύεται ως πίνακας χαρακτήρων (string),
    ώστε να μπορούμε εύκολα να συγκρίνουμε ψηφίο-ψηφίο
*/

#include <string>
using namespace std;

class Number {
private:
    string number;  // αποθηκεύει τον 4ψήφιο αριθμό (π.χ. "1234")

public:

    // Constructor: αρχικοποιεί τον αριθμό σε κενό
    Number();

    /*
        Διαβάζει αριθμό από τον χρήστη με έλεγχο εγκυρότητας:
        - πρέπει να είναι 4 ψηφία
        - μόνο αριθμοί
        - δεν επιτρέπεται να ξεκινά με 0
    */
    void setNumber();

    // Εκτυπώνει τον αριθμό
    void printNumber() const;

    /*
        Φιλικές συναρτήσεις για σύγκριση δύο αντικειμένων Number
    */

    // Πόσα ψηφία είναι σωστά (όχι απαραίτητα στη σωστή θέση)
    friend int right_digits(const Number& n1, const Number& n2);

    // Πόσα ψηφία είναι σωστά και στη σωστή θέση
    friend int right_position(const Number& n1, const Number& n2);

    // Ελέγχει αν οι αριθμοί είναι ίδιοι
    friend bool compare_numbers(const Number& n1, const Number& n2);
};

#endif
