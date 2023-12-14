// Author: Sumeyye ACAR
// ID: 22103640
// File: Customer.cpp

#include <iostream>
using namespace std;

#include "Account.cpp"

class Customer {
public:
    Customer() {}
    Customer(Customer& c) {
        id = c.id;
        name = c.name;
        accountNum = c.accountNum;
    }
    Customer(const int customer_id, const string customer_name) {
        id = customer_id;
        name = customer_name;
        accountNum = 0;
    }
    ~Customer() {
        name = "";
        id = -1;
        accountNum = 0;
    }

    //methods
    void swapIDs(Customer& c) {
        int temp = c.id;
        c.id = id;
        id = temp;
    }

    void swapNames(Customer& c) {
        string temp = c.name;
        c.name = name;
        name = temp;
    }

    void swapAccountNum(Customer& c) {
        int temp = c.accountNum;
        c.accountNum = accountNum;
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

    // Set Methods
    void setAccountNum( int a ) {
        accountNum = a;
    }

private:
    int id = -1;
    string name = "";
    int accountNum;
};
