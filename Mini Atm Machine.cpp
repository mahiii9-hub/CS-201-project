// MINI ATM MACHINe
#include <iostream>
using namespace std;

double checkBalance(double balance) {
    cout << "Current Balance: " << balance << endl;
    return balance;
}

double deposit(double balance) {
    double amount;
    cout << "Enter amount to deposit: ";
    cin >> amount;
    if (amount > 0) {
        balance += amount;
        cout << "Amount Deposited Successfully!\n";
    } else {
        cout << "Invalid amount!\n";
    }
    return balance;
}

double withdraw(double balance) {
    double amount;
    cout << "Enter amount to withdraw: ";
    cin >> amount;
    if (amount > balance) {
        cout << "Not enough balance!\n";
    } else if (amount <= 0) {
        cout << "Invalid amount!\n";
    } else {
        balance -= amount;
        cout << "Please collect your cash.\n";
    }
    return balance;
}

bool authenticate() {
    int pin, attempts = 0;
    while (attempts < 3) {
        cout << "\nEnter your PIN: ";
        cin >> pin;
        if (pin == 1234) {
            cout << "Login Successful!\n";
            return true;
        } else {
            cout << "Wrong PIN, try again!\n";
            attempts++;
        }
    }
    cout << "\nAccount Locked due to 3 wrong attempts!\n";
    return false;
}

int main() {
    double balance = 12000;
    int choice;

    cout << "\n===== WELCOME TO SMART ATM =====\n";
    cout << "System ready... Please login\n";

    if (!authenticate()) return 0;

    do {
        cout << "\n------ ATM MENU ------\n";
        cout << "1. Check Balance\n2. Deposit\n3. Withdraw\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: balance = checkBalance(balance); break;
            case 2: balance = deposit(balance); break;
            case 3: balance = withdraw(balance); break;
            case 4: cout << "\nThank you for using our ATM!\n"; break;
            default: cout << "Invalid option! Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
