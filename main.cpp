// Eduardo A Fernandez

#include "stdafx.h"

#include <iostream>
#include "BankAccount.h"
#include <vector>
using namespace std;

void ShowMenu();

void TakeAction(char action, unsigned int naccount, vector<BankAccount> &account);
bool indexOfAccount(unsigned int &index, unsigned int &accountNumber, vector<BankAccount> account);

int main() {
    vector<BankAccount> myList;//Class used to store all the accounts
    //myList.push_back(BankAccount(0));//Account 0 created by default for debugging purposes

    char sentinel;//The sentinel value
    unsigned int naccount;//The second parameter account number
    do {
        ShowMenu();//The menu with the different actions
        cin >> sentinel;
        if (sentinel == 'X')
            break;//No need to call any action
        cout << "Enter the number of the account to act on: (any positive value)" << endl;
        cin >> naccount;
        TakeAction(sentinel, naccount, myList);
        //Comment the line below to see the account in time
        //system("clear");//MacOS & Linux
        //system("CLS");//Windows
    } while (sentinel != 'X');

    for (unsigned int i = 0; i < myList.size(); i++) {
        myList.at(i).DisplayBalance();
    }

    return 0;
}

void ShowMenu() {
    cout << "Enter the action character: " << endl;
    cout << "Enter [N] to create a new bank account" << endl;
    cout << "Enter [D] to make a deposit" << endl;
    cout << "Enter [W] to make a withdraw" << endl;
    cout << "Enter [B] to display the account balance" << endl;
    cout << "Enter [I] to credit the account supplied an interest rate" << endl;
    cout << "Enter [S] to subtract a service fee" << endl;
    cout << "Enter [M] to make the account inactive" << endl;
    cout << "Enter [A] to make the account active" << endl;
    cout << "Enter [X] to finish" << endl;
}

void TakeAction(char action, unsigned int accountNumber, vector<BankAccount> &account) {
    //This function performs the requested action from the show Menu
    if (accountNumber < 0) {
        printf("The number #%d for the account is invalid, a positive value or zero\n", accountNumber);
        return;
    }

    unsigned int index;
    bool accExists = indexOfAccount(index, accountNumber, account);
    
    if (accExists == false && action != 'N') {
        printf("The Account with number #%d doesn't exist, so you can't perform any task on it, try creating it first\n", accountNumber);
        return;
    }

    float amount;//var amount is used to deposit/withdraw/etc according the action 
    switch (action) {
    case 'N': {
        if (accExists == false) {//Only create the an account with that number if it doesn't exist
            account.push_back(BankAccount(accountNumber));
            account.at(account.size()-1).setAccountStatus(true);
            printf("Account #%d was created and is active\n", accountNumber);
            break;
        }
        else
        {
            printf("Account with number #%d already exists, try creating another account with a different account number\n", accountNumber);
            break;
        }
    };
    case 'D': {
        cout << "Enter an amount to deposit and press enter: ";
        cin >> amount; account.at(index).Deposit(amount); break;
    };
    case 'W': {
        cout << "Enter an amount to withdraw and press enter: ";
        cin >> amount; account.at(index).Withdraw(amount); break;
    };
    case 'B': {
        account.at(index).DisplayBalance(); break;
    };
    case 'I': {
        cout << "Enter the interest rate to credit the account and press enter: ";
        cin >> amount; account.at(index).setRate(amount); break;
    };
    case 'S': {
        cout << "Enter the service fee you want to subtract from the account and press enter: ";
        cin >> amount; account.at(index).Withdraw(amount); break;
    };
    case 'M': {
        cout << "The account is inactive now...\n";
        account.at(index).setAccountStatus(false); break;
    };
    case 'A': {
        cout << "The account is active now...\n";
        account.at(index).setAccountNumber(index);
        account.at(index).setAccountStatus(true); break;
    };
    default: {
        cout << "Enter a valid option" << endl; break;;
    };
    }
}

bool indexOfAccount(unsigned int &index, unsigned int &accountNumber,vector<BankAccount> account) {
    
    for (unsigned int i = 0; i < account.size(); i++) {
        if (account.at(i).getAccountNumber() == accountNumber) {
            index = i;
            return true;
        }
    }
    return false;
}