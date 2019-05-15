/***********************
Name: Operators: iostream and operators
Author: Zach Thompson
Version: 1.0 5/6/2019
Purpose: To practice writing operator code
Variables:
    arrayPtr As Int
    matrix As Int Array
    classiness As TheClass Object
    i As Int
    j As Int
************************/

#include <iostream>

using namespace std;

// Basic class to store the data and print it out
class TheClass {
    public:
        TheClass();
        void push(int number);
        void print();
        void operator<< (int number);
    private:
        int arrayPtr = 0;
        int matrix[2][2] = { };
};

// Basic constructor
TheClass::TheClass() {
    cout << "Hello Class!" << endl;
}

// This is the print function
void TheClass::print() {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << this->matrix[i][j] << " ";
        }
        cout << endl;
    }
}

// This is for the push function
void TheClass::push(int number) {
    if (this->arrayPtr < 2) {
        this->matrix[0][arrayPtr] = number;
        this->arrayPtr++;
    }
    else {
        this->matrix[1][arrayPtr - 2] = number;
        this->arrayPtr++;
    }
}

// This is to be able to practice the operator functions
void TheClass::operator<< (int number) {
    push(number);
}

// Here is the main function
int main()
{
    TheClass classiness;
    int number = 0;
    for (int i = 0; i < 4; i++) {
        cout << "Enter a Number: ";
        cin >> number;
        classiness << number;
    }
    classiness.print();
    return 0;
}
