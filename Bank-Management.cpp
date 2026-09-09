#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

// Account class: Customer ki information aur actions ke liye
class Account {
private:
    int accNumber;
    string holderName;
    string accType;
    double balance;
    vector<string> history;

public:
    // Constructor
    Account(int num, string name, string type, double bal) {
        accNumber = num;
        holderName = name;
        accType = type;
        balance = bal;
        history.push_back("Opening balance: Rs. " + to_string(bal));
    }

    // Getter functions
    int getNumber() const {
        return accNumber;
    }

    string getName() const {
        return holderName;
    }

    double getBalance() const {
        return balance;
    }

    // Deposit paise jama karne ke liye
    void deposit(double amount) {
        if (amount <= 0) {
            cout << "Invalid amount.\n";
            return;
        }
        balance += amount;
        history.push_back("Deposit: Rs. " + to_string(amount));
        cout << "Deposit successful.\n";
    }

    // Withdraw paise nikalne ke liye
    bool withdraw(double amount) {
        if (amount <= 0 || amount > balance) {
            cout << "Invalid amount or insufficient balance.\n";
            return false;
        }
        balance -= amount;
        history.push_back("Withdrawal: Rs. " + to_string(amount));
        cout << "Withdrawal successful.\n";
        return true;
    }

    // Account Details dikhane ke liye
    void details() const {
        cout << "\nAccount: " << accNumber << "\n";
        cout << "Holder: " << holderName << "\n";
        cout << "Type: " << accType << "\n";
        cout << "Balance: Rs. " << fixed << setprecision(2) << balance << "\n";
    }

    // Transaction History print karne ke liye
    void showHistory() const {
        cout << "\nTransaction history\n";
        for (int i = 0; i < history.size(); i++) {
            cout << "- " << history[i] << "\n";
        }
    }
};

// Bank class: Tamam accounts ko manage karne ke liye
class Bank {
private:
    vector<Account> accounts;
    int nextAccNumber = 1001;

    // Account search karne ke liye helper function
    int findAccount(int accNum) const {
        for (int i = 0; i < accounts.size(); i++) {
            if (accounts[i].getNumber() == accNum) {
                return i;
            }
        }
        return -1; // Agar na mile
    }

public:
    // Naya account banana
    void createAccount() {
        string name, type;
        double initialBalance;

        cin.ignore(); // Buffer clear karne ke liye
        cout << "Holder name: ";
        getline(cin, name);
        
        cout << "Account type: ";
        getline(cin, type);
        
        cout << "Opening balance: Rs. ";
        cin >> initialBalance;

        if (initialBalance < 0) {
            cout << "Balance cannot be negative.\n";
            return;
        }

        // Vector me naya account add karna
        Account newAcc(nextAccNumber, name, type, initialBalance);
        accounts.push_back(newAcc);
        
        cout << "Created. Account number: " << nextAccNumber << "\n";
        nextAccNumber++;
    }

    // Paise deposit karna
    void depositMoney() {
        int accNum;
        double amount;
        
        cout << "Account number: ";
        cin >> accNum;

        int index = findAccount(accNum);
        if (index < 0) {
            cout << "Account not found.\n";
            return;
        }

        cout << "Amount: Rs. ";
        cin >> amount;
        accounts[index].deposit(amount);
    }

    // Paise nikalna
    void withdrawMoney() {
        int accNum;
        double amount;

        cout << "Account number: ";
        cin >> accNum;

        int index = findAccount(accNum);
        if (index < 0) {
            cout << "Account not found.\n";
            return;
        }

        cout << "Amount: Rs. ";
        cin >> amount;
        accounts[index].withdraw(amount);
    }

    // Ek specific account dhoondna
    void searchAccount() {
        int accNum;
        cout << "Account number: ";
        cin >> accNum;

        int index = findAccount(accNum);
        if (index < 0) {
            cout << "Account not found.\n";
        } else {
            accounts[index].details();
        }
    }

    // Sab accounts dikhana
    void showAllAccounts() const {
        if (accounts.empty()) {
            cout << "No accounts yet.\n";
            return;
        }

        for (int i = 0; i < accounts.size(); i++) {
            accounts[i].details();
        }
    }

    // History check karna
    void viewHistory() {
        int accNum;
        cout << "Account number: ";
        cin >> accNum;

        int index = findAccount(accNum);
        if (index < 0) {
            cout << "Account not found.\n";
        } else {
            accounts[index].showHistory();
        }
    }

    // Main Menu system
    void run() {
        int choice;
        
        do {
            cout << "\n===== TRUSTLINE BANKING SYSTEM =====\n";
            cout << "1. Create account\n";
            cout << "2. Deposit\n";
            cout << "3. Withdraw\n";
            cout << "4. Search account\n";
            cout << "5. Show all accounts\n";
            cout << "6. Transaction history\n";
            cout << "0. Exit\n";
            cout << "Choose: ";
            cin >> choice;

            switch (choice) {
                case 1: createAccount(); break;
                case 2: depositMoney(); break;
                case 3: withdrawMoney(); break;
                case 4: searchAccount(); break;
                case 5: showAllAccounts(); break;
                case 6: viewHistory(); break;
                case 0: cout << "Goodbye!\n"; break;
                default: cout << "Invalid option.\n";
            }
        } while (choice != 0);
    }
};

int main() {
    Bank bank;
    bank.run();
    return 0;
}