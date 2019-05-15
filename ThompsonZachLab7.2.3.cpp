/***********************
Name: Exceptional Division 3.0
Author: Zach Thompson
Version: 1.0 4/29/2019
Purpose: To practice more exception handling
Variables:
    arg1 As Float
    arg2 As Float
    a As Float
    b As Float
    r As Float
    result As Float
    phrase As String
************************/

#include <iostream>
#include <exception>
#include <string>

using namespace std;

const int DivideByZero = 111;

// This is a second function, I just tweaked the throw in here
float internaldiv(float arg1, float arg2) throw(string) {
    if (0==arg2) {
        throw string("Your input is not valid. You can't divide by zero.");
    }
    return arg1 / arg2;
}

// I tweaked this one to use throws instead of an if statement and boolean
float div(float arg1, float arg2) throw(string) {
    if(arg2 == 0.0) {
        throw string("Are you kidding me?");
    }
    float result = internaldiv(arg1, arg2);
    return result;
}

// Tweaked to better support exception handling and I added prompts for user input
int main(void) {
    float r, a, b;
    cout << "Numerator: ";
    while(cin >> a) {
        cout << "Denominator: ";
        cin >> b;
        try {
            r = div(a,b);
            cout << "Result: " << r << endl;
        }
        catch (string &phrase) {
            cout << phrase << endl;
        }
        break;
    }
    return 0;
}
