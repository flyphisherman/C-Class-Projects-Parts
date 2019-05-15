/***********************
Name: Finite State Machine
Author: Zach Thompson
Version: 1.0 5/8/2019
Purpose: To have fun
Variables:
    currentState As Int
    statesVisited As Int Array
    runState As Boolean
    newState As Int
    stateValue As Int
************************/

#include <iostream>

using namespace std;

// Here is my class for this
class Finite_State_Machine {
    public:
        Finite_State_Machine();
        void updateState(int newState);
        void changeState(int newState);
        void operator<< (int newState);
        void printStatesVisited();
        bool state();
        void showCurrentState();
    private:
        int currentState;
        int statesVisited[6] = { };
        bool runState = false;
};

// The constructor starts at state 1 and sets the runState to true
Finite_State_Machine::Finite_State_Machine() {
    this->currentState = 1;
    this->statesVisited[0] = 1;
    this->runState = true;
}

// This updates states and the tracker
void Finite_State_Machine::updateState(int newState) {
    this->currentState = newState;
    this->statesVisited[newState - 1] = 1;
}

// This is to hold the switch case statement
void Finite_State_Machine::changeState(int newState) {
    switch (newState) {
        case 6: {
            updateState(newState);
            this->runState = false;
            break;
        }
        default: updateState(newState); break;
    }
}

// Here is my overloaded operator
void Finite_State_Machine::operator<<(int newState) {
	changeState(newState);
}

// This returns the runState of the machine
bool Finite_State_Machine::state() {
    return this->runState;
}

// This prints the states that have been visited
void Finite_State_Machine::printStatesVisited() {
    cout << "Stop state reached" << endl;
    cout << "States visited:" << endl;
    for (int i = 0; i < 6; i++) {
        if (this->statesVisited[i] == 1) {
            if (i == 0) {
                cout << "1 (Start), ";
            }
            else if (i < 5) {
                cout << i + 1 << ", ";
            }
            else {
                cout << "6 (Stop)";
            }
        }
    }
}

// This shows the current state
void Finite_State_Machine::showCurrentState() {
    cout << "Current State: " << this->currentState << endl;
}

int main()
{
    // Setting up my variables and objects
    Finite_State_Machine fsm;
    int stateValue = 0;
    // This loops until the stop state has been reached
    while (fsm.state()) {
        cout << "Enter a state (1-6): ";
        cin >> stateValue;
        // If it is in range then good, else it tells you and prints the current state
        if (stateValue <= 6 && stateValue >= 1) {
            fsm<<stateValue;
        }
        else {
            cout << "[!] Number is out of range!" << endl;
            fsm.showCurrentState();
        }
    }
    // Printing out the states visited
    fsm.printStatesVisited();
    cout << endl;
    return 0;
}
