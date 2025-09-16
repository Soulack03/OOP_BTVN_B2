#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <vector>
using namespace std;

// =============== Time ===============
class Time {
private:
    int day, month, year;
public:
    Time(int d = 1, int m = 1, int y = 2000) : day(d), month(m), year(y) {}
    void display() const {
        cout << setw(2) << setfill('0') << day << "/"
             << setw(2) << setfill('0') << month << "/"
             << year;
    }
};

// =============== Transaction Type Menu ===============
map<int, string> method = {
    {1, "Deposit"},
    {2, "Withdrawal"},
    {3, "Transfer Out"},
    {4, "Transfer In"},
    {5, "Fee"}
};

class Transaction {
private:
    string id; 
    long long amount;
    int type;   // (1:deposit / 2:withdrawal / 3:transfer out / 4:transfer in / 5:fee)
    Time date;
    inline static int cnt = 0;
public:
    Transaction(long long _amount, int _type, const Time& _date) 
        : amount(_amount), type(_type), date(_date) 
    {
        cnt++;
        id = "T" + to_string(cnt);
    }

    int getType() const { return type; }
    long long getAmount() const { return amount; }
    const Time& getDay() const { return date; }

    void display() const {
        cout << "Transaction ID: " << id 
             << " | Amount: " << amount 
             << " | Type: " << method.at(type) 
             << " | Date: ";
        date.display();
        cout << endl;
    }
};

// =============== Account ===============
class Account {
protected:
    string id; 
    string accountNumber;
    long long balance;
    string ownerName;
    vector<Transaction> transHistory;
    inline static int cnt = 0;
public:
    Account(string accNum = "", string owner = "", long long bal = 0) 
        : accountNumber(accNum), ownerName(owner), balance(bal) 
    {
        cnt++;
        id = "A" + to_string(cnt);
    }

    virtual ~Account() {}

    string getAccNo() const { return accountNumber; }

    virtual void deposit(const Transaction& t) {
        balance += t.getAmount();
        transHistory.push_back(t);
    }

    virtual bool withdraw(const Transaction& t) {
        if (t.getAmount() > balance) {
            cout << "Insufficient funds!\n";
            return false;
        }
        balance -= t.getAmount();
        transHistory.push_back(t); 
        return true;
    }

    // Operator += to apply a Transaction
    Account& operator+=(const Transaction& other) {
        if (other.getType() == 1) deposit(other);
        else if (other.getType() == 2) withdraw(other);
        else cout << "Unsupported transaction type for +=.\n";
        return *this;
    }

    // Operator == to compare balance
    bool operator==(const Account& other) const {
        return this->balance == other.balance;
    }

    // Transfer
    bool transferTo(Account& other, long long amount, const Time& date) {
        if (amount > balance) {
            cout << "Insufficient funds for transfer!\n";
            return false;
        }

        balance -= amount;
        transHistory.emplace_back(amount, 3, date); // Transfer Out

        other.balance += amount;
        other.transHistory.emplace_back(amount, 4, date); // Transfer In

        cout << "Transfer " << amount << " from " << accountNumber
             << " to " << other.accountNumber << " successful!\n";
        return true;
    }

    // Operator < and >
    bool operator<(const Account& other) const { return this->balance < other.balance; }
    bool operator>(const Account& other) const { return this->balance > other.balance; }

    // Stream operators
    friend ostream& operator<<(ostream& os, const Account& acc) {
        os << "Account ID: " << acc.id 
           << " | Number: " << acc.accountNumber 
           << " | Owner: " << acc.ownerName 
           << " | Balance: " << acc.balance;
        return os;
    }
    friend istream& operator>>(istream& is, Account& acc) {
        cout << "Enter account number: ";
        is >> acc.accountNumber;
        cout << "Enter owner name: ";
        is >> acc.ownerName;
        cout << "Enter initial balance: ";
        is >> acc.balance;
        return is;
    }

    virtual void displayInfo() const {
        cout << "Account ID: " << id 
             << " | Number: " << accountNumber 
             << " | Owner: " << ownerName 
             << " | Balance: " << balance << endl;
    }

    void showHistory() const {
        if (transHistory.empty()) {
            cout << "No transactions for account " << accountNumber << ".\n";
            return;
        }
        cout << "Transaction history for account " << accountNumber << ":\n";
        for (auto &t : transHistory) t.display();
    }

    long long getBalance() const { return balance; }
};

// =============== SavingsAccount (Derived) ===============
class SavingsAccount : public Account {
private:
    double interestRate; 
public:
    SavingsAccount(string accNum, string owner, long long bal, double rate)
        : Account(accNum, owner, bal), interestRate(rate) {}

    void applyInterest(const Time& date) {
        long long interest = static_cast<long long>(balance * interestRate);
        balance += interest;
        transHistory.emplace_back(interest, 1, date); 
    }

    bool withdraw(const Transaction& t) override {
        long long fee = 5; 
        if (t.getAmount() + fee > balance) {
            cout << "Savings account: insufficient funds for withdrawal + fee!\n";
            return false;
        }
        balance -= (t.getAmount() + fee);
        transHistory.push_back(t);                        
        transHistory.emplace_back(fee, 5, t.getDay());   
        return true;
    }

    void displayInfo() const override {
        cout << "Savings ";
        Account::displayInfo();
        cout << "   Interest Rate: " << interestRate * 100 << "%\n";
    }
};

// =============== Customer ===============
class Customer {
    string id, name;
    vector<Account*> accounts;
public:
    Customer(string i="", string n=""):id(i),name(n){}

    string getId() const { return id; }
    string getName() const { return name; }

    void openAccount(string accNo, string owner, long long initBalance=0) {
        accounts.push_back(new Account(accNo, owner, initBalance));
        cout << "Account " << accNo << " opened for " << name 
             << " with balance " << initBalance << "\n";
    }

    void openSavings(string accNo, string owner, long long initBalance, double rate) {
        accounts.push_back(new SavingsAccount(accNo, owner, initBalance, rate));
        cout << "Savings Account " << accNo << " opened for " << name 
             << " with balance " << initBalance << " and rate " << rate*100 << "%\n";
    }

    long long getTotalBalance() const {
        long long total = 0;
        for(auto acc : accounts) total += acc->getBalance();
        return total;
    }

    void showInfo() const {
        cout << "\nCustomer ID: " << id
             << " | Name: " << name
             << " | Total Balance: " << getTotalBalance() << "\n";
        if(accounts.empty()) cout << "  (No accounts yet)\n";
        else {
            cout << "Accounts:\n";
            for(auto acc : accounts) acc->displayInfo();
        }
    }

    Account* findAccount(string accNo) {
        for(auto acc : accounts) {
            if(acc->getAccNo() == accNo) return acc;
        }
        return nullptr;
    }

    void showAllAccounts() const {
        for(auto acc : accounts) acc->displayInfo();
    }

    ~Customer() {   
        for(auto acc : accounts) delete acc;
    }
};

// =============== Demo ===============
int main() {
    Customer c1("C01", "Alice");

    c1.openAccount("A1001", "Alice", 5000);
    c1.openSavings("S2001", "Alice", 10000, 0.05);

    c1.showInfo();

    Account* acc1 = c1.findAccount("A1001");
    Account* acc2 = c1.findAccount("S2001");

    if(acc1 && acc2) {
        acc1->deposit(Transaction(2000, 1, Time(15, 9, 2025))); // Deposit
        acc1->withdraw(Transaction(1000, 2, Time(16, 9, 2025))); // Withdraw
        acc1->transferTo(*acc2, 1500, Time(17, 9, 2025)); // Transfer
    }

    c1.showInfo();
    if(acc1) acc1->showHistory();
    if(acc2) acc2->showHistory();
       cout << "\n===== Operator Overloading Tests =====\n";

    // Stream insertion (<<)
    cout << "Account 1: " << *acc1 << endl;
    cout << "Account 2: " << *acc2 << endl;

    // Stream extraction (>>)
    Account tempAcc;
    cout << "\nEnter new account details using >> operator:\n";
    cin >> tempAcc;
    cout << "You entered: " << tempAcc << endl;

    // += (apply transaction)
    cout << "\nTesting operator+= (deposit 500 into acc1)\n";
    Transaction t1(500, 1, Time(18, 9, 2025));
    *acc1 += t1;
    cout << *acc1 << endl;

    // == (balance compare)
    cout << "\nTesting operator==\n";
    if (*acc1 == *acc2) cout << "acc1 and acc2 have EQUAL balance.\n";
    else cout << "acc1 and acc2 do NOT have equal balance.\n";

    // < and >
    cout << "\nTesting operator< and operator>\n";
    if (*acc1 > *acc2) cout << "acc1 has GREATER balance than acc2.\n";
    else if (*acc1 < *acc2) cout << "acc1 has LESS balance than acc2.\n";
    else cout << "They have the same balance.\n";


    return 0;
}
