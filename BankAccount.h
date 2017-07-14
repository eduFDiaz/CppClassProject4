//
// Created by Eduardo Antonio Fernandez Diaz on 7/13/17.
//

#ifndef UNTITLED1_BANKACCOUNT_H
#define UNTITLED1_BANKACCOUNT_H

#include <string>
#include <iostream>
using namespace std;


class BankAccount {
public:
    BankAccount(unsigned int accountNumber = 0 , const string &customerName = "", float balance=0, bool accountStatus=false);
private:
    unsigned int accountNumber;
    string customerName;
    float balance;
    bool accountStatus;
    float rate;
public:
    float getRate() const;

    void setRate(float rate);

public: //Added these accessors in case they're needed later :)
    unsigned int getAccountNumber() const;

    void setAccountNumber(unsigned int accountNumber);

    const string &getCustomerName() const;

    void setCustomerName(const string &customerName);

    float getBalance() const;

    void setBalance(float balance);

    bool isAccountStatus() const;

    void setAccountStatus(bool accountStatus);

    bool CheckForExceptions(float amount);

    void Deposit(float deposit);

    void Withdraw(float withdraw);

    void DisplayBalance();
};
#endif //UNTITLED1_BANKACCOUNT_H
