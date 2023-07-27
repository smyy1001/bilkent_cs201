// Author: Sumeyye ACAR
// ID: 22103640
// File: BankingSystem.h

#include <string>
#include <iostream>
#include <iomanip>
using namespace std;
#include "Customer.cpp"
#include "Branch.cpp"

class BankingSystem {
public:
    BankingSystem();
    ~BankingSystem();

    void addBranch(const int branchId, const string branchName);
    void deleteBranch(const int branchId);

    void addCustomer(const int customerId, const string customerName);
    void deleteCustomer(const int customerId);
    
    int addAccount(const int branchId, const int customerId, const double amount); 
    void deleteAccount(const int accountId);
    
    void showAllAccounts();
    void showBranch(const int branchId);
    void showCustomer(const int customerId);

private:
    int customer_number;
    int branch_number;
    int account_number;
    Branch* branches;
    Customer* customers;
    Account* totalAccounts;
};