// Author: Sumeyye ACAR
// ID: 22103640
// File: BankingSystem.cpp

using namespace std;
#include "BankingSystem.h"

BankingSystem::BankingSystem() {
    branch_number = 0;
    customer_number = 0;
    account_number = 0;
    branches = new Branch[20];
    customers = new Customer[20];
    totalAccounts = new Account[50];
}

BankingSystem::~BankingSystem() {
    delete[] branches;
    delete[] customers;
    delete[] totalAccounts;
}

// Add a new Branch
void BankingSystem::addBranch(const int branchId, const string branchName) {
    for(int i = 0; i < branch_number; i++) {
        if(branches[i].getID() == branchId && branches[i].getName().compare("") != 0) {
            cout << "Branch " << branchId << " already exists" << endl;
            return;
        }
    }
    branches[branch_number] = Branch(branchId, branchName);
    branch_number++;
    size_t newSize = branch_number+2;
    Branch* newArr = new Branch[newSize];
    for(int i = 0; i < branch_number; i++) {
        newArr[i] = branches[i];
    }
    delete[] branches;
    branches = newArr;
    cout << "Branch " << branchId << " has been added" << endl;
}

// Delete a Branch
void BankingSystem::deleteBranch(const int branchId) {
    for(int i = 0; i < branch_number; i++) {
        if(branches[i].getID() == branchId && branches[i].getName().compare("") != 0) {
            for(int k = 0; k < account_number; k++) {
                if(totalAccounts[k].getBranchID()==branchId) {
                    for(int m = 0; m < customer_number; m++) {
                        if(customers[m].getID() == totalAccounts[k].getCustomerID()) {
                            customers[m].setAccountNum(customers[m].getAccountNum()-1);
                        }
                    }
                    Account* newArr = new Account[account_number+10];
                    for(int i = 0; i < account_number; i++) {
                        if(i!=k) { newArr[i] = totalAccounts[i]; }
                    }
                    delete[] totalAccounts;
                    totalAccounts = newArr;
                    k--;
                }
            }
            
            // swap with the last element
            branches[i].swapIDs(branches[branch_number-1]);
            branches[i].swapNames(branches[branch_number-1]);
            branches[i].swapAccountNum(branches[branch_number-1]);

            // delete
            size_t newSize = branch_number+2;
            Branch* newArr = new Branch[newSize];
            for(int i = 0; i < branch_number-1; i++) {
                newArr[i] = branches[i];
            }
            delete [] branches;
            branches = newArr;
            branch_number--;
            cout << "Branch " << branchId << " has been deleted" << endl;
            return;
        }
    }
    cout << "Branch " << branchId << " does not exist" << endl;
}


// Add a Customer
void BankingSystem::addCustomer(const int customerId, const string customerName) {
    for(int i = 0; i < customer_number; i++) {
        if(customers[i].getID() == customerId && customers[i].getName().compare("") != 0) {
            cout << "Customer " << customerId << " already exists" << endl;
            return;
        }
    }
    customers[customer_number] = Customer(customerId, customerName);
    customer_number++;
    size_t newSize = customer_number+2;
    Customer* newArr = new Customer[newSize];
    for(int i = 0; i < customer_number; i++) {
        newArr[i] = customers[i];
    }
    delete[] customers;
    customers = newArr;
    cout << "Customer " << customerId << " has been added" << endl;
}


// Delete a customer
void BankingSystem::deleteCustomer(const int customerId) {
    for(int i = 0; i < customer_number; i++) {
        if(customers[i].getID() == customerId && customers[i].getName().compare("") != 0) {

            for(int b = 0; b < account_number; b++) {
                if(totalAccounts[b].getCustomerID() == customerId) {
                    size_t newSize = account_number+2;
                    Account* newArr = new Account[newSize];
                    for(int i = 0; i < account_number; i++) {
                        if(i!=b) {newArr[i] = totalAccounts[i];}
                    }
                    delete[] totalAccounts;
                    totalAccounts = newArr;
                    b--;
                }
            }

            // swap with the last element
            customers[i].swapIDs(customers[customer_number-1]);
            customers[i].swapNames(customers[customer_number-1]);
            customers[i].swapAccountNum(customers[customer_number-1]);

            // delete
            size_t newSize = customer_number+2;
            Customer* newArr = new Customer[newSize];
            for(int i = 0; i < customer_number-1; i++) {
                newArr[i] = customers[i];
            }
            delete [] customers;
            customers = newArr;
            customer_number--;

            cout << "Customer " << customerId << " has been deleted" << endl;
            return;
        }
    }
    cout << "Customer " << customerId << " does not exist" << endl;
}


// Add a new Account
int BankingSystem::addAccount(const int branchId, const int customerId, const double amount) {
    for(int i = 0; i < branch_number; i++) {
        if(branches[i].getID() == branchId && branches[i].getName().compare("") != 0) {
            for(int j = 0; j < customer_number; j++) {
                if(customers[j].getID() == customerId && customers[j].getName().compare("") != 0) { 
                    
                    totalAccounts[account_number] = Account(account_number+1, customerId, branchId, amount);
                    account_number++;
                    size_t newSize = account_number+2;
                    Account* newArr = new Account[newSize];
                    for(int i = 0; i < account_number; i++) {
                        newArr[i] = totalAccounts[i];
                    }
                    delete[] totalAccounts;
                    totalAccounts = newArr;
                    
                    customers[j].setAccountNum(customers[j].getAccountNum()+1); //customer's
                    branches[i].setAccountNum(branches[i].getAccountNum()+1); //branch's
                    
                    cout << "Account " << account_number  << " added for customer " << customerId << " at branch " << branchId << endl;
                    return account_number;
                }
            }
            cout << "Customer " << customerId << " does not exist" << endl;         
            return -1;
        }
    }
    cout << "Branch " << branchId << " does not exist" << endl;
    return -1;
}


// delete Account
void BankingSystem::deleteAccount(const int accountId) {

    for(int j = 0; j < account_number; j++) { 
        if(totalAccounts[j].getID() == accountId) {
            for(int a = 0; a < branch_number; a++) { 
                if(branches[a].getID() == totalAccounts[j].getBranchID() && branches[a].getName().compare("") != 0) {
                    branches[a].setAccountNum((branches[a].getAccountNum())-1); //branch's
                    break;
                }
            }
            for(int b = 0; b < customer_number; b++) { 
                if(customers[b].getID() == totalAccounts[j].getCustomerID() && customers[b].getName().compare("") != 0) {
                    customers[b].setAccountNum((customers[b].getAccountNum())-1); //branch's
                    break;
                }
            }

            size_t newSize = account_number+5;
            Account* newArr = new Account[newSize];
            for(int i = 0; i < account_number; i++) {
                if(i!=j) {newArr[i] = totalAccounts[i];}
            }
            delete[] totalAccounts;
            totalAccounts = newArr;
            cout << "Account " << accountId << " has been deleted" << endl;
            return;
        }
    }
    cout << "Account " << accountId << " does not exist" << endl;
}

void BankingSystem::showAllAccounts(){
    cout << "Account id Branch id Branch name Customer id Customer name Balance" << endl;
    for(int i = 0; i < account_number; i++) {
        if(totalAccounts[i].getID() > 0) {
            cout << totalAccounts[i].getID() << " " << totalAccounts[i].getBranchID() << " ";
            
            for(int j = 0; j < branch_number; j++) {
                if(branches[j].getID() == totalAccounts[i].getBranchID() && branches[j].getName().compare("") != 0) {
                    cout << branches[j].getName() << " ";
                }
            }
            
            cout << totalAccounts[i].getCustomerID() << " ";
            
            for(int k = 0; k < customer_number; k++) {
                if(customers[k].getID() == totalAccounts[i].getCustomerID() && customers[k].getName().compare("") != 0) {
                    cout << customers[k].getName() << " ";
                }
            }
            cout << fixed << setprecision(2) << totalAccounts[i].getAmount();
            cout << endl;
        }
    }
}

void BankingSystem::showBranch(const int branchId){
    bool found = false;
    
    for(int i = 0; i < branch_number; i ++) {
        if(branches[i].getID() == branchId && branches[i].getName().compare("") != 0) {
            found = true;
            cout << "Branch id: " << branchId << " Branch name: "<< branches[i].getName() <<" Number of accounts: " << branches[i].getAccountNum() << endl;
            if( branches[i].getAccountNum() == 0) { return; }
            break;
        }
    }
    
    if(!found) {
        cout << "Branch " << branchId << " does not exist" << endl;
        return;
    }


    cout << "Accounts at this branch:" << endl << "Account id Customer id Customer name Balance" << endl;

    for(int j = 0; j < account_number; j++) {
        if(totalAccounts[j].getID() > 0) {
            if(totalAccounts[j].getBranchID() == branchId) {

                for(int k = 0; k < customer_number; k++) {
                    if(totalAccounts[j].getCustomerID() == customers[k].getID() && customers[k].getName().compare("") != 0) {
                            
                        cout << totalAccounts[j].getID() << " " << totalAccounts[j].getCustomerID() << " " << customers[k].getName() << " ";
                        
                    }
                }
                cout << fixed << setprecision(2) << totalAccounts[j].getAmount();
                cout << endl;
            }
        }
    }
}

void BankingSystem::showCustomer(const int customerId) {
    bool found = false;
    int cust = 0;

    for(int i = 0; i < customer_number; i++) {
        if(customers[i].getID() == customerId && customers[i].getName().compare("") != 0) {
            found =true;
            cust = i;
            cout << "Customer id: " << customerId << " Customer name: " << customers[i].getName() << " Number of accounts: " << customers[i].getAccountNum() << endl;
            if(customers[i].getAccountNum() == 0) { return; }
            break;
        }
    }

    if(!found) {
        cout << "Customer " << customerId << " does not exist" << endl;
        return;
    }

    cout << "Accounts of this customer:" << endl << "Account id Branch id Branch name Balance" << endl;

    for(int j = 0; j < account_number ; j++) {
        if(totalAccounts[j].getID() != -1) {
            if(totalAccounts[j].getCustomerID() == customerId) {

                for(int k = 0; k < branch_number; k++) {
                    if(totalAccounts[j].getBranchID() == branches[k].getID() && branches[k].getName().compare("") != 0) {
                                
                        cout << totalAccounts[j].getID() << " " << totalAccounts[j].getBranchID() << " " << branches[k].getName() << " ";
                        break;
                    }
                }
                cout << fixed << setprecision(2) << totalAccounts[j].getAmount();
                cout << endl;
            }
        }
    }
}
// end 