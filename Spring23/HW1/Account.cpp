// Author: Sumeyye ACAR
// ID: 22103640
// File: Account.cpp

#include <iostream>
using namespace std;

class Account {
public:
    Account(){}
    Account(Account& a){
        id = a.id;
        customer = a.customer;
        branch = a.branch;
        amount = a.amount;
    }

    Account(const int id2, const int customer2, const int branch2, const double amount2) {
        id = id2;
        customer = customer2;
        branch = branch2;
        amount = amount2;
    }

    ~Account() {
        id = -1;
        customer = -1;
        branch = -1;
        amount = -1.0;
    }
    
    // Get Methods
    int getID() {
        return id;
    }

    int getCustomerID() {
        return customer;
    }

    int getBranchID() {
        return branch;
    }

    double getAmount() {
        return amount;
    }

private:
    int id = -1;
    int customer = -1;
    int branch = -1;
    double amount = -1.00;
};
