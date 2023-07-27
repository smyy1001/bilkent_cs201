// Author: Sumeyye ACAR
// ID: 22103640
// File: Course.cpp

#include <iostream>
using namespace std;

class Course {
public:
    // constructor 
    Course(const int enteredId = -1, const string name2 = ""){
        id = enteredId;
        name = name2;
    }

    // destructor
    ~Course(){ id = -1; name = ""; }

    // getters
    int getId() {
        return id;
    }

    string getName() {
        return name;
    }

    bool operator<(const Course& other) const {
        return id < other.id;
    }

    bool operator>(const Course& other) const {
        return id > other.id;
    }

    bool operator==(const Course& other) const {
        return id == other.id;
    }


private:
    // variables
    int id;
    string name;
}; // end