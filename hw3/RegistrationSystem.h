// Author: Sumeyye ACAR
// ID: 22103640
// File: RegistrationSystem.h

// the main header file
#include <iostream>
#include "DoublyLinkedList.cpp"

using namespace std;

class RegistrationSystem {
public:

    // constructor
    RegistrationSystem();
    
    // destructor
    ~RegistrationSystem();

    // method's
    void addStudent( const int studentId , const string firstName , const string lastName );
    void deleteStudent( const int studentId );
    void addCourse( const int studentId , const int courseId , const string courseName );
    void withdrawCourse( const int studentId , const int courseId );
    void cancelCourse( const int courseId );
    
    // display methods
    void showStudent( const int studentId );
    void showCourse( const int courseId );
    void showAllStudents();

    // sorted linear doubly linked list with no dummy head node
    DoublyLinkedList studentList;

}; // end