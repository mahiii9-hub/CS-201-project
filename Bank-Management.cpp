#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// Basic account structure to hold user data
struct Account {
    int accNo;
    string name;
    string type;
    double balance;
    vector<string> history;
};

// Global list of accounts and starting ID
vector<Account> accounts;
int nextId = 1001;

// Helper function to find account index by account number
int findAccount(int accNo) {
    for (size_t i = 0; i < accounts.size(); i++) {
        if (accounts[i].accNo == accNo) {
            return i; // Account found
        }
    }
    return -1; // Account not found
}

// 1. Create a new bank account
void createAccount() {
    Account acc;
    acc.accNo = nextId++;

    cin.ignore();
    cout << "Enter Name: ";
    getline(cin, acc.name);

    cout << "Account Type (Savings/Current): ";
    getline(cin, acc.type);

    cout << "Initial Deposit Amount: Rs. ";
    cin >> acc.balance;

    if (acc.balance < 0) {
        cout << "Error: Initial balance cannot be negative!\n";
        return;
    }

    acc.history.push_back("Account opened with Rs. " + to_string(acc.balance));
    accounts.push_back(acc);

    cout << "-> Account created! Your Account Number is: " << acc.accNo << "\n";
}

// 2. Deposit money into an account
void deposit() {
    int accNo;
    double amount;

    cout << "Enter Account Number: ";
    cin >> accNo;

    int idx = findAccount(accNo);
    if (idx == -1) {
        cout << "Error: Account not found!\n";
        return;
    }

    cout << "Enter Amount to Deposit: Rs. ";
    cin >> amount;

    if (amount <= 0) {
        cout << "Error: Deposit amount must be positive!\n";
        return;
    }

    accounts[idx].balance += amount;
    accounts[idx].history.push_back("Deposited: Rs. " + to_string(amount));
    cout << "-> Deposit successful! Updated Balance: Rs. " << fixed << setprecision(2) << accounts[idx].balance << "\n";
}

// 3. Withdraw money from an account
void withdraw() {
    int accNo;
    double amount;

    cout << "Enter Account Number: ";
    cin >> accNo;

    int idx = findAccount(accNo);
    if (idx == -1) {
        cout << "Error: Account not found!\n";
        return;
    }

    cout << "Enter Amount to Withdraw: Rs. ";
    cin >> amount;

    if (amount <= 0 || amount > accounts[idx].balance) {
        cout << "Error: Invalid amount or insufficient balance.\n";
        return;
    }

    accounts[idx].balance -= amount;
    accounts[idx].history.push_back("Withdrew: Rs. " + to_string(amount));
    cout << "-> Withdrawal successful! Remaining Balance: Rs. " << fixed << setprecision(2) << accounts[idx].balance << "\n";
}

// 4. View specific account details
void showDetails() {
    int accNo;
    cout << "Enter Account Number: ";
    cin >> accNo;

    int idx = findAccount(accNo);
    if (idx == -1) {
        cout << "Error: Account not found!\n";
        return;
    }

    cout << "\n-----------------------------\n";
    cout << "Account No : " << accounts[idx].accNo << "\n";
    cout << "Holder Name: " << accounts[idx].name << "\n";
    cout << "Type       : " << accounts[idx].type << "\n";
    cout << "Balance    : Rs. " << fixed << setprecision(2) << accounts[idx].balance << "\n";
    cout << "-----------------------------\n";
}

// 5. Display list of all registered accounts
void showAll() {
    if (accounts.empty()) {
        cout << "No accounts registered yet.\n";
        return;
    }

    cout << "\n=========== ALL ACCOUNTS ===========\n";
    for (const auto& acc : accounts) {
        cout << "ID: " << acc.accNo << " | Name: " << acc.name << " | Balance: Rs. " << fixed << setprecision(2) << acc.balance << "\n";
    }
    cout << "====================================\n";
}

// 6. View full transaction statement for an account
void showHistory() {
    int accNo;
    cout << "Enter Account Number: ";
    cin >> accNo;

    int idx = findAccount(accNo);
    if (idx == -1) {
        cout << "Error: Account not found!\n";
        return;
    }

    cout << "\n--- Statement for Account " << accNo << " ---\n";
    for (const string& record : accounts[idx].history) {
        cout << " - " << record << "\n";
    }
}

// Main execution menu loop
int main() {
    int choice;

    while (true) {
        cout << "\n--- TRUSTLINE BANKING SYSTEM ---\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Search Account Details\n";
        cout << "5. List All Accounts\n";
        cout << "6. View Transaction History\n";
        cout << "0. Exit\n";
        cout << "Select Choice: ";
        cin >> choice;

        switch (choice) {
            case 1: createAccount(); break;
            case 2: deposit(); break;
            case 3: withdraw(); break;
            case 4: showDetails(); break;
            case 5: showAll(); break;
            case 6: showHistory(); break;
            case 0: 
                cout << "Exiting system. Goodbye!\n";
                return 0;
            default: 
                cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}
