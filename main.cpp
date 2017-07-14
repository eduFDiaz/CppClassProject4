#include <iostream>
#include "BankAccount.h"

using namespace std;

void ShowMenu();

void TakeAction(char action, unsigned int naccount, BankAccount *account);

int main() {
    BankAccount accounts[10];//An array of bank accounts is created
    BankAccount *ptr = accounts;//Then a pointer to the first element

    char sentinel;//The sentinel value
    unsigned int naccount;//The second parameter account number
    do {
        ShowMenu();//The menu with the different actions
        cin >> sentinel >> naccount;
        TakeAction(sentinel,naccount - 1,ptr);
        //Comment the line below to see the account in time
        //system("clear");//MacOS & Linux
        //system("CLS");//Windows
    } while (sentinel != 'X');
    return 0;
}

void ShowMenu() {
    cout << "Enter one of the following characters followed by the account number that you want to create/modify/show\n"
            "Example: N 1 (to create account 1), W 2 to make a withdraw from account 2, and so on" << endl;
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

void TakeAction(char action, unsigned int index, BankAccount *account) {
    //This function performs the requested action from the show Menu
    if (index < 0 || index >= 10){
        printf("The account number %d is not valid, try numbers from 1 to 10\n",index+1);
        return;
    }
    float amount;
    switch (action) {
        case 'N' : {
            account[index].setAccountNumber(index);
            account[index].setAccountStatus(true);
            printf("Account #%d was created and is active\n",index+1);
            break;
        };
        case 'D' : {
            cout << "Enter an amount to deposit and press enter: ";
            cin >> amount; account[index].Deposit(amount);break;
        };
        case 'W' : {
            cout << "Enter an amount to withdraw and press enter: ";
            cin >> amount; account[index].Withdraw(amount);break;
        };
        case 'B' : {
            account[index].DisplayBalance();break;
        };
        case 'I' : {
            cout << "Enter the interest rate to credit the account and press enter: ";
            cin >> amount; account[index].setRate(amount);break;
        };
        case 'S' : {
            cout << "Enter the service fee you want to subtract from the account and press enter: ";
            cin >> amount; account[index].Withdraw(amount);break;
        };
        case 'M' : {
            cout << "The account is inactive now...\n";
            account[index].setAccountStatus(false);break;
        };
        case 'A' : {
            cout << "The account is active now...\n";
            account[index].setAccountStatus(true);break;
        };
        case 'X' : {
            for (int i=0; i < 10;i++){
                account[i].DisplayBalance();
            }break;
        }
        default: {
            cout << "Enter a valid option" << endl; break;;
        };
    }
}
