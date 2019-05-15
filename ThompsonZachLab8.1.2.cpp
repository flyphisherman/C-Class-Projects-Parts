/***********************
Name: Operators Non-Natural Usage
Author: Zach Thompson
Version: 1.0 5/6/2019
Purpose: To practice using operators and exceptions
Variables:
    number As Int
    next As Node Object
    head As Node Object
    current As Node Object
    listCounter As Int
    new_head As Node Object
    numbersToEnter As Int
    phrase As String
************************/

#include <iostream>
#include <exception>
#include <string>

using namespace std;

// Setting up the Node class
class Node {
    public:
        Node(int number);
        int number;
        Node* next;
};

// Node constructor
Node::Node(int number) {
    this->number = number;
    this->next = nullptr;
}

// Setting up the List class to keep track of the Nodes
class List {
    public:
        List();
        void push_front(int number);
        bool pop_front();
        void top();
        void operator<< (int number);
        void operator>> (int number);
    private:
        Node* head;
        int listCounter = 0;
};

// List push operator
void List::operator<< (int number) {
    push_front(number);
}

// List pop operator
void List::operator>> (int number) {
    if (this->listCounter > 0) {
        pop_front();
    }
    else {
        throw string ("Stack is empty");
    }
}

// List constructor
List::List() {
    this->head = nullptr;
}

// List top function
void List::top() {
    if (this->listCounter == 0) {
        throw string ("Stack is empty");
    }
    else {
        cout << this->head->number << endl;
    }
}

// List push function
void List::push_front(int number) {
    Node* new_head = new Node(number);
    new_head->next = this->head;
    this->head = new_head;
    this->listCounter++;
}

// List pop function
bool List::pop_front() {
    top();
    if (this->listCounter > 0) {
        this->listCounter--;
        // This is the code that I created
        // It makes a temporary node to store the head node's data
        Node *current = new Node(0);
        current = this->head;
        // Then it deletes the head node
        delete this->head;
        // It then replaces the head node with the second node
        this->head = current->next;
        // Then deletes the temporary copy
        delete current;
        // To see if we should continue
        if (this->head != nullptr) {
            return true;
        } else {
            return false;
        }
    }
    else {

    }
}

// Main function
int main()
{
    int number = 0;
    int numbersToEnter = 0;
    List list;
    cout << "How many numbers would you like to enter: ";
    cin >> numbersToEnter;
    for (int i = 0; i < numbersToEnter; i ++) {
        cout << "Enter a number: ";
        cin >> number;
        list << number;
    }
    cout << "How many numbers would you like to print: ";
    cin >> number;
    try {
        for (int i = 0; i < number; i ++) {
            list >> (number);
        }
    }
    catch (string phrase) {
        cout << "Exception: " << phrase << endl;
    }
    return 0;
}
