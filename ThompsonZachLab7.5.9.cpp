/***********************
Name: IP Address Checker
Author: Zach Thompson
Version: 1.0 4/29/2019
Purpose: To check if an IP Address is valid
Comments: I have not put in catches for reserved IP Addresses
Variables:
    address As String
    periodLocation As Int
    ptrLocation As Int
    numberFound As Int
    number As Int
    addressSegments As Int
    tempNumber As Int
    phrase As String
    addressType As String
************************/

#include <iostream>
#include <string>
#include <exception>

using namespace std;

// I check to see if the address is a valid IP Address at this point.
checkerFunction(string address, string addressType) throw(string) {
    int periodLocation = address.find(".");
    int ptrLocation = 0;
    int numberFound = 0;
    int number;
    int addressSegments[4] = { };
    while (numberFound < 4) {
        number = 0;
        if (periodLocation > (ptrLocation + 1)) {
            while (periodLocation > ptrLocation) {
                int tempNumber = address.at(ptrLocation) - '0';
                ptrLocation++;
                number = (number * 10) + tempNumber;
            }
        }
        else if (numberFound = 3) {
            if (address.length() > (ptrLocation + 1)) {
                while (address.length() > ptrLocation) {
                    int tempNumber = address.at(ptrLocation) - '0';
                    ptrLocation++;
                    number = (number * 10) + tempNumber;
                }
            }
            else {
                number = address.at(ptrLocation) - '0';
            }
        }
        else {
            number = address.at(ptrLocation) - '0';
        }
        addressSegments[numberFound] = number;
        numberFound++;
        if (numberFound < 3) {
            ptrLocation = periodLocation + 1;
            periodLocation = address.find(".", periodLocation + 1);
        }
        else {
            ptrLocation = periodLocation + 1;
        }
    }
    for (int i = 0; i < 4; i++) {
        if (addressSegments[i] < 0 || addressSegments[i] > 255) {
            throw string("Invalid IP Header - " + addressType + " IP Address is invalid.");
        }
    }
}

// This is to separate the addresses from each other
addressChecker(string phrase) throw(string) {
    int commaLocation = phrase.find(",");
    string source = phrase.substr(0, commaLocation);
    string destination = phrase.substr(commaLocation + 2);
    checkerFunction(source, "Source");
    checkerFunction(destination, "Destination");
    cout << "Valid IP Header." << endl;
}

int main()
{
    // We ask for the user to enter the IP address sets and then check them
    string address = "";
    try {
        cout << "First IP Address Set: ";
        getline(cin, address);
        addressChecker(address);
        cout << "Second IP Address Set: ";
        getline(cin, address);
        addressChecker(address);
    }
    catch (string &phrase) {
        cout << phrase << endl;
    }
    return 0;
}
