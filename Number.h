#ifndef NUMBER_H
#define NUMBER_H

#include <string>
using namespace std;

class Number {
private:
    string number;

public:
    Number();

    void setNumber();
    void printNumber() const;

    friend int right_digits(const Number& n1, const Number& n2);
    friend int right_position(const Number& n1, const Number& n2);
    friend bool compare_numbers(const Number& n1, const Number& n2);
};

#endif
