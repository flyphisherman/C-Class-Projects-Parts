/***********************
Name: Exceptional Dividing Program
Author: Zach Thompson
Version: 1.0 4/29/2019
Purpose: To divide in safety
Variables:
    phrase As String
    a As Int
    b As Int
    c As Float
************************/

#include <iostream>
#include <string>
#include <exception>

using namespace std;

// Made a function to be able to divide in safety
float division(int a, int b) throw(string) {
    if (b == 0) {
        throw string("Your input is not valid, you can't divide by zero.");
    }
    // Just because I can
    else if (a == 0) {
        return 0.0;
    }
    else {
        return a / b;
    }
}

// Here is the main function
int main() {
    int a = 0, b = 0;
    float c;
    cout << "Numerator: ";
    cin >> a;
    cout << "Denominator: ";
    cin >> b;
    // Here is my try/catch set
    try {
        c = division(a, b);
        cout << "Result: " << c << endl;
    }
    catch (string &phrase) {
        cout << phrase << endl;
    }
    return 0;
}
