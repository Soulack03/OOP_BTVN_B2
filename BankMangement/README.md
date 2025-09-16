# Banking System Project
## Authored  by: Tran Le Dung
## MSSV: 24110084.

## Overview
The Banking System project is a C++ application demonstrating Object-Oriented Programming (OOP) principles to manage customer bank accounts and transactions. It includes classes such as `Customer`, `Account`, `SavingsAccount`, `Transaction`, and `Time` to handle operations like opening accounts, depositing, withdrawing, transferring funds, and applying interest. The code is clean, readable, uses CamelCase conventions, and includes comments mapping to OOP concepts like encapsulation, inheritance, abstraction, and operator overloading. 
## Features
- **Open Accounts**: Create regular or savings accounts with account number, owner name, and initial balance.
- **Deposit/Withdraw**: Perform deposits and withdrawals, with savings accounts incurring a withdrawal fee.
- **Transfer Funds**: Transfer money between accounts, updating transaction histories.
- **Apply Interest**: Calculate and add interest to savings accounts.
- **Display Information**: Show customer details, account information, and transaction history.
- **OOP Principles**: Implements encapsulation (private attributes, getters), inheritance (`SavingsAccount` derives from `Account`), abstraction (simplified method interfaces), modularity (separated responsibilities), and operator overloading (`+=`, `==`, `<`, `>`, `<<`, `>>`).

## Setup Instructions
1. **Prerequisites**: A C++ compiler (e.g., g++).
2. **Clone the Repository**: Download the project files from the `BankManagement` directory, including `bankM.cpp`.
3. **Compile the Code**: Run `g++ bankM.cpp -o bankM` in your terminal within the `BankManagement` directory.
4. **Run the Program**: Execute `./bankM` (Linux/Mac) or `bankM.exe` (Windows) from the `BankManagement` directory.

## Usage
- The program initializes a `Customer` object and opens sample accounts (regular and savings).
- It demonstrates operations like depositing, withdrawing, transferring funds, and displaying account details via a console interface.
- Example output:
  ```
  Account A1001 opened for Alice with balance 5000
  Savings Account S2001 opened for Alice with balance 10000 and rate 5%
  Customer ID: C01 | Name: Alice | Total Balance: 15000
  Accounts:
  Account ID: A1 | Number: A1001 | Owner: Alice | Balance: 5000
  Savings Account ID: A2 | Number: S2001 | Owner: Alice | Balance: 10000
     Interest Rate: 5%

  Transfer 1500 from A1001 to S2001 successful!
  Customer ID: C01 | Name: Alice | Total Balance: 15000
  Accounts:
  Account ID: A1 | Number: A1001 | Owner: Alice | Balance: 4500
  Savings Account ID: A2 | Number: S2001 | Owner: Alice | Balance: 10500
     Interest Rate: 5%

  Transaction history for account A1001:
  Transaction ID: T1 | Amount: 2000 | Type: Deposit | Date: 15/09/2025
  Transaction ID: T2 | Amount: 1000 | Type: Withdrawal | Date: 16/09/2025
  Transaction ID: T3 | Amount: 1500 | Type: Transfer Out | Date: 17/09/2025

  Transaction history for account S2001:
  Transaction ID: T4 | Amount: 1500 | Type: Transfer In | Date: 17/09/2025

  ===== Operator Overloading Tests =====
  Account 1: Account ID: A1 | Number: A1001 | Owner: Alice | Balance: 4500
  Account 2: Account ID: A2 | Number: S2001 | Owner: Alice | Balance: 10500
  ```

## Project Structure
- `BankingDoc.pdf`: Documentation file containing analysis and code walkthrough.
- `bankM.cpp`: Main C++ source file with `Time`, `Transaction`, `Account`, `SavingsAccount`, and `Customer` classes.
- `bankM.exe`: Compiled executable of the banking system (Windows).
- `README.md`: This documentation file.

