#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// User ka basic structure
struct Account {
    int accNo;
    string name;
    string type;
    double balance;
    vector<string> history;
};

// Global list aur starting ID
vector<Account> accounts;
int nextId = 1001;

// Specific account find karne ka function
int findAccount(int accNo) {
    for (size_t i = 0; i < accounts.size(); i++) {
        if (accounts[i].accNo == accNo) {
            return i;
        }
    }
    return -1; // Not found
}

// 1. Naya Account Banana
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
        cout << "Error: Amount negative nahi ho sakti!\n";
        return;
    }

    acc.history.push_back("Account opened with Rs. " + to_string(acc.balance));
    accounts.push_back(acc);

    cout << "-> Account created successfully! Your Account Number is: " << acc.accNo << "\n";
}

// 2. Paise Jama Karna
void deposit() {
    int accNo;
    double amount;

    cout << "Enter Account Number: ";
    cin >> accNo;

    int idx = findAccount(accNo);
    if (idx == -1) {
        cout << "Account nahi mila!\n";
        return;
    }

    cout << "Enter Amount to Deposit: Rs. ";
    cin >> amount;

    if (amount <= 0) {
        cout << "Invalid Amount!\n";
        return;
    }

    accounts[idx].balance += amount;
    accounts[idx].history.push_back("Deposited: Rs. " + to_string(amount));
    cout << "-> Deposit successful! New Balance: Rs. " << fixed << setprecision(2) << accounts[idx].balance << "\n";
}

// 3. Paise Nikalna
void withdraw() {
    int accNo;
    double amount;

    cout << "Enter Account Number: ";
    cin >> accNo;

    int idx = findAccount(accNo);
    if (idx == -1) {
        cout << "Account nahi mila!\n";
        return;
    }

    cout << "Enter Amount to Withdraw: Rs. ";
    cin >> amount;

    if (amount <= 0 || amount > accounts[idx].balance) {
        cout << "Error: Invalid amount ya balance kam hai.\n";
        return;
    }

    accounts[idx].balance -= amount;
    accounts[idx].history.push_back("Withdrew: Rs. " + to_string(amount));
    cout << "-> Withdrawal successful! Remaining Balance: Rs. " << fixed << setprecision(2) << accounts[idx].balance << "\n";
}

// 4. Account Info Dikhana
void showDetails() {
    int accNo;
    cout << "Enter Account Number: ";
    cin >> accNo;

    int idx = findAccount(accNo);
    if (idx == -1) {
        cout << "Account nahi mila!\n";
        return;
    }

    cout << "\n-----------------------------\n";
    cout << "Account No : " << accounts[idx].accNo << "\n";
    cout << "Holder Name: " << accounts[idx].name << "\n";
    cout << "Type       : " << accounts[idx].type << "\n";
    cout << "Balance    : Rs. " << fixed << setprecision(2) << accounts[idx].balance << "\n";
    cout << "-----------------------------\n";
}

// 5. Tamam Accounts Display Karna
void showAll() {
    if (accounts.empty()) {
        cout << "Filhal koi accounts nahi hain.\n";
        return;
    }

    cout << "\n=========== ALL ACCOUNTS ===========\n";
    for (const auto& acc : accounts) {
        cout << "ID: " << acc.accNo << " | Name: " << acc.name << " | Balance: Rs. " << fixed << setprecision(2) << acc.balance << "\n";
    }
    cout << "====================================\n";
}

// 6. History Print Karna
void showHistory() {
    int accNo;
    cout << "Enter Account Number: ";
    cin >> accNo;

    int idx = findAccount(accNo);
    if (idx == -1) {
        cout << "Account nahi mila!\n";
        return;
    }

    cout << "\n--- Statement for Account " << accNo << " ---\n";
    for (const string& record : accounts[idx].history) {
        cout << " - " << record << "\n";
    }
}

int main() {
    int choice;

    while (true) {
        cout << "\n--- TRUSTLINE BANKING MENU ---\n";
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
                cout << "Program closed. Khuda Hafiz!\n";
                return 0;
            default: 
                cout << "Ghalat option select kia hai, dobara try karein.\n";
        }
    }

    return 0;
}
