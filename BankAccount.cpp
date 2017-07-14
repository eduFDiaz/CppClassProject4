//
// Created by Eduardo Antonio Fernandez Diaz on 7/13/17.
//

#include "BankAccount.h"

BankAccount::BankAccount(unsigned int accountNumber, const string &customerName, float balance, bool accountStatus)
        : accountNumber(accountNumber), customerName(customerName), balance(balance), accountStatus(accountStatus) {}

unsigned int BankAccount::getAccountNumber() const {
    return accountNumber;
}

void BankAccount::setAccountNumber(unsigned int accountNumber) {
    BankAccount::accountNumber = accountNumber;
}

const string &BankAccount::getCustomerName() const {
    return customerName;
}

void BankAccount::setCustomerName(const string &customerName) {
    BankAccount::customerName = customerName;
}

float BankAccount::getBalance() const {
    return balance;
}

void BankAccount::setBalance(float balance) {
    BankAccount::balance = balance;
}

bool BankAccount::isAccountStatus() const {
    return accountStatus;
}

void BankAccount::setAccountStatus(bool accountStatus) {
    BankAccount::accountStatus = accountStatus;
}

bool BankAccount::CheckForExceptions(float amount) {
    if(!BankAccount::isAccountStatus()) {
        cout << "The account is inactive, can't perform task" << endl;
        return false;
    }
    else if (BankAccount::getBalance()*amount<0) {
        cout << "Cannot deposit/withdraw negative values" << endl;
        return false;
    }
    else
        return true;
}

void BankAccount::Deposit(float deposit) {
    if(BankAccount::CheckForExceptions(deposit)==true){
        BankAccount::balance += deposit;
    }
}

void BankAccount::Withdraw(float withdraw) {
    if(BankAccount::CheckForExceptions(withdraw)==true && (BankAccount::balance - withdraw>0)){
        BankAccount::balance-=withdraw;
    }
    else {
        cout << "You don't have enough funds to withdraw" << endl;
    }
}

void BankAccount::DisplayBalance() {
    printf("AccountNumber: %d, Name: %s, has a balance of $%.2f and is currently %s\n",
           BankAccount::accountNumber + 1,
           BankAccount::customerName.c_str(),
           BankAccount::balance,
           BankAccount::accountStatus ? "active" : "inactive");
}

float BankAccount::getRate() const {
    return rate;
}

void BankAccount::setRate(float rate) {
    BankAccount::rate = rate;
}
