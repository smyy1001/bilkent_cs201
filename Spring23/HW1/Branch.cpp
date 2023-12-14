// Author: Sumeyye ACAR
// ID: 22103640
// File: Branch.cpp

#include <iostream>
using namespace std;

class Branch {
public:
    Branch() {}
    Branch(Branch& b) {
        id = b.id;
        name = b.name;
        accountNum = b.accountNum;
    }
    Branch(const int branch_id, const string branch_name){
        id = branch_id;
        name = branch_name;
        accountNum = 0;
    }
    ~Branch(){
        name = "";
        id = -1;
        accountNum = 0;
    }

    // Methods
    void swapIDs(Branch& b) {
        int temp = b.id;
        b.id = id;
        id = temp;
    }

    void swapNames(Branch& b) {
        string temp = b.name;
        b.name = name;
        name = temp;
    }

    void swapAccountNum(Branch& b) {
        int temp = b.accountNum;
        b.accountNum = accountNum;
        accountNum = temp;
    }

    // Get Methods
    int getID() {
        return id;
    }

    int getAccountNum() {
        return accountNum;
    }

    string getName() {
        return name;
    }

    // Set Method
    void setAccountNum(int i) {
        accountNum = i;
    }

private:
    int id;
    string name;
    int accountNum;
};