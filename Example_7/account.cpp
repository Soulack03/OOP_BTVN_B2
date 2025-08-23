#include<bits/stdc++.h>
using namespace std;

// The Account class represents a simple bank account with basic operations and a minimum balance rule.
class Account{
public:
    string accountNumber; // Stores the account number
    double balance;       // Stores the current balance
    string ownerName;     // Stores the account owner's name

    // Constructor: Initializes an Account object with account number, initial balance, and owner name.
    // Parameters:
    //   accountNumber - the account's unique identifier
    //   balance - the initial balance of the account
    //   ownerName - the name of the account owner
    Account(string accountNumber, double balance, string ownerName){
        this->accountNumber = accountNumber;
        this->balance = balance;
        this->ownerName = ownerName;
    }

    // Deposits a specified amount into the account and prints the deposited amount.
    // Parameters:
    //   amount - the amount to deposit
    void deposit(double amount) {
        balance += amount;
        cout << "Deposited: " << amount << endl;
    }

    // Withdraws a specified amount from the account if sufficient balance remains (minimum 100 vnd required).
    // Prints messages for success, insufficient balance, or invalid withdrawal.
    // Parameters:
    //   amount - the amount to withdraw
    void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient balance!" << endl;
        } else if (amount > balance - 100) {
            cout << "INVALID! You need to have at least 100 vnd in your account.\n";
        } else {
            balance -= amount;
            cout << "SUCCESSFUL!" << endl;
            cout << "Withdrew: " << amount << endl;
        }
    }

    // Displays the account owner's name and the current balance.
    void displayBalance() {
        cout << "The Account Name: " << ownerName << endl;
        cout << "Current balance: " << balance << endl;
    }
};

int main(){
    // Create an Account object with sample data
    Account acc1("123456789", 1000, "Tran Van Ba");

    // Display initial balance
    acc1.displayBalance();

    // Deposit money and display balance
    acc1.deposit(500);
    acc1.displayBalance();

    // Withdraw money and display balance
    acc1.withdraw(200);
    acc1.displayBalance();

    // Attempt to withdraw more than allowed and display balance
    acc1.withdraw(1500);
    acc1.displayBalance();

    // Attempt to withdraw an amount that would violate the minimum balance rule
    acc1.withdraw(1260); 
    acc1.displayBalance();
    return 0;
}