// Author: Sumeyye ACAR
// ID: 22103640
// File: RegistrationSystem.cpp

// the main c++ file
#include <iostream>
#include "RegistrationSystem.h"
using namespace std;

RegistrationSystem::RegistrationSystem() {}

RegistrationSystem::~RegistrationSystem() {}

void RegistrationSystem::addStudent( const int studentId , const string firstName , const string lastName ) {
    for(int i = 0; i < studentList.length(); i++) {
        if(studentList.getValue(i).getId() == studentId) {
            cout << "Student " << studentId << " already exists" << endl;
            return;
        }
    }
    studentList.insert(Student(studentId, firstName, lastName));
    cout << "Student " << studentId << " has been added" << endl;
    return;
}

void RegistrationSystem::deleteStudent( const int studentId ) {
    if(studentList.length() == 0) {
        cout << "Student " << studentId << " does not exist" << endl;
        return;
    }
    
    for(int i = 0; i < studentList.length(); i++) {
        if(studentList.getValue(i).getId() == studentId) {
            studentList.remove(studentList.getValue(i));
            cout << "Student " << studentId << " has been deleted" << endl;
            return;
        }
    }
    cout << "Student " << studentId << " does not exist" << endl;
}

void RegistrationSystem::addCourse( const int studentId , const int courseId , const string courseName ) {
    for(int j = 0; j < studentList.length(); j++) {
        for(int t = 0; t < studentList.getValue(j).courses.length(); t++) {
            if(studentList.getValue(j).courses.getValue(t).getId() == courseId && studentList.getValue(j).courses.getValue(t).getName().compare(courseName) != 0) {
                cout << "Course " << courseId << " already exists with another name" << endl;
                return;
            }
        }
        if(studentList.getValue(j).getId() == studentId) {
            for(int a = 0; a < studentList.getValue(j).courses.length(); a++) {
                if(studentList.getValue(j).courses.getValue(a).getId() == courseId) {
                    if(studentList.getValue(j).courses.getValue(a).getName()  != courseName) {
                        cout << "Course " << courseId << " already exists with another name" << endl;
                    }
                    else {
                        cout << "Student " << studentId << " is already enrolled in course " << courseId << endl;
                    }
                    return;
                }
            } 
            studentList.getValue(j).courses.insert(Course(courseId, courseName));
            cout << "Course " << courseId << " has been added to student " << studentId << endl;
            return;
        }
    }
    cout << "Student " << studentId << " does not exist" << endl;
}

void RegistrationSystem::withdrawCourse( const int studentId , const int courseId ) {
    for(int i = 0; i < studentList.length(); i++) {
        if(studentList.getValue(i).getId() == studentId) {
            for(int j = 0; j < studentList.getValue(i).courses.length(); j++) {
                if(studentList.getValue(i).courses.getValue(j).getId() == courseId) {
                    studentList.getValue(i).courses.remove(studentList.getValue(i).courses.getValue(j));
                    cout << "Student " << studentId << " has been withdrawn from course " << courseId << endl;
                    return;
                }
            }
            cout << "Student " << studentId << " is not enrolled in course " << courseId << endl;
            return;
        }
    }

    cout << "Student " << studentId << " does not exist" << endl;
}

void RegistrationSystem::cancelCourse( const int courseId ) {
    bool exists = false;
    for(int i = 0; i < studentList.length(); i++) {
        for(int j = 0; j < studentList.getValue(i).courses.length(); j++) {
            if(studentList.getValue(i).courses.getValue(j).getId() == courseId) {
                exists = true;
                studentList.getValue(i).courses.remove(studentList.getValue(i).courses.getValue(j));
            }
        }
    }
    if(exists) {
        cout << "Course " << courseId << " has been cancelled" << endl;
        return;
    }
    cout << "Course " << courseId << " does not exist" << endl;
}

void RegistrationSystem::showStudent( const int studentId ) {
    bool exist = false;
    if(studentList.length() == 0) {
        cout << "Student " << studentId << " does not exist" << endl;
        return;
    }

    for(int i = 0; i < studentList.length(); i++) {
        if(studentList.getValue(i).getId() == studentId) {
            exist = true;
            cout << "Student id First name Last name" << endl;
            cout << studentId << " " << studentList.getValue(i).getFirstName() << " " 
                << studentList.getValue(i).getLastName() << endl; 
            
            if(studentList.getValue(i).courses.length() == 0) {
                return;
            }
            else {
                cout << "Course id Course name" << endl;
                for(int r = 0; r < studentList.getValue(i).courses.length(); r++) {
                    cout << studentList.getValue(i).courses.getValue(r).getId() << " " 
                            << studentList.getValue(i).courses.getValue(r).getName() << endl;
                }
                return;
            }
        }
    }

    if(!exist) {
        cout << "Student " << studentId << " does not exist" << endl;
        return;
    }
}

void RegistrationSystem::showCourse( const int courseId ) {
    int exist = 0;
    
    for(int j = 0; j < studentList.length(); j++) {
        for(int i = 0; i < studentList.getValue(j).courses.length(); i++) {
            if(studentList.getValue(j).courses.getValue(i).getId() == courseId) {
                if(exist == 0) {
                    cout << "Course id Course name" << endl;
                    cout << courseId << " " << studentList.getValue(j).courses.getValue(i).getName() << endl;
                    cout << "Student id First name Last name" << endl;
                    exist++;
                }
                cout << studentList.getValue(j).getId() << " " << studentList.getValue(j).getFirstName() 
                        << " " << studentList.getValue(j).getLastName() << endl;
            }
        }
    }
    
    if(exist == 0) {
        cout << "Course " << courseId << " does not exist" << endl;
    }
}

void RegistrationSystem::showAllStudents() {
    if(studentList.length() == 0) {
        cout << "There are no students in the system" << endl;
        return;
    }

    cout << "Student id First name Last name" << endl;
    for(int i = 0; i < studentList.length(); i++) {
        cout << studentList.getValue(i).getId() << " " << studentList.getValue(i).getFirstName() << " " 
            << studentList.getValue(i).getLastName() <<  endl;
        if(studentList.getValue(i).courses.length() != 0) {
            cout << "Course id Course name" << endl;
            for(int r = 0; r < studentList.getValue(i).courses.length(); r++) {
                cout << studentList.getValue(i).courses.getValue(r).getId() << " " 
                    << studentList.getValue(i).courses.getValue(r).getName() << endl;
            }
        }

    }
} // end