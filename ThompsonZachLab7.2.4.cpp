/***********************
Name: Exceptional Catch Blocking
Author: Zach Thompson
Version: 1.0 4/29/2019
Purpose: To practice using exceptions
Variables:
    a As Float
    b As Float
    rsquare As Float
    rrectangle As Float
    phrase As String
************************/

#include <iostream>
#include <exception>
#include <string>

using namespace std;
//add your own exception class here
//add functions code here

// This is the function to figure out the area of a square
float square_area(float a) throw(string) {
    if (a <= 0.0) {
        throw string("Your input is not valid. The area can't be negative.");
    }
    return a * a;
}

// This is the function to figure out the area of a rectangle
float rectangle_area(float a, float b) throw(string) {
    if (a <= 0.0 || b <= 0.0) {
        throw string("Your input is not valid. The area can't be negative.");
    }
    return a * b;
}

int main() {
    float a, b;
    cout << "Number A: ";
    cin >> a;
    cout << "Number B: ";
    cin >> b;
    try {
        float rsquare = square_area(a);
        float rrectangle = rectangle_area(a,b);
        cout << "Square Area: " << rsquare << endl << "Rectangle Area: " << rrectangle << endl;
    }
    // Here is the catch block
    catch(string &phrase) {
        cout << phrase << endl;
    }
    //add a suitable catch block here
    return 0;
}

