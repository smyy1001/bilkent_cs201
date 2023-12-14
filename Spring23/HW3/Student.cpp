// Author: Sumeyye ACAR
// ID: 22103640
// File: Student.cpp

#include <iostream>
using namespace std;
#include "SinglyLinkedList.cpp"

class Student {
public:
    // constructor 
    Student(const int enteredId = 0, const string name = "", const string name2 = ""){
        id = enteredId;
        firstName = name;
        lastName = name2;
    }

    // courses = sorted linear singly linked list with no dummy head node
    SinglyLinkedList courses;

    // destructor
    ~Student(){ id = 0; firstName, lastName = ""; }

    //getters
    int getId() {
        return id;
    }

    string getFirstName() {
        return firstName;
    }

    string getLastName() {
        return lastName;
    }

    bool operator<(const Student& other) const {
        return id < other.id;
    }

    bool operator>(const Student& other) const {
        return id > other.id;
    }

    bool operator==(const Student& other) const {
        return id == other.id;
    }

    SinglyLinkedList getCourses() {
        return courses;
    }
    

private:
    // variables
    int id;
    string firstName;
    string lastName;
}; // end