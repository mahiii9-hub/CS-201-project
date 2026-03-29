#include <iostream>
using namespace std;

// Function to check login (call by value)
bool checkLogin(string u, string p)
{
    string users[2] = {"aiman", "admin"};
    string pass[2] = {"123", "456"};

    for (int i = 0; i < 2; i++)
        if (u == users[i] && p == pass[i])
            return true;

    return false;
}

int main()
{
    int choice, attempts = 0;
    string username, password;

    while (true)
    {
        cout << "\n1.Login  2.Exit\nChoice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            if (attempts >= 3)
            {
                cout << "Too many attempts! Access denied.\n";
                break;
            }
            cout << "Username: ";
            cin >> username;
            cout << "Password: ";
            cin >> password;

            if (checkLogin(username, password))
                cout << "Login Successful! Welcome " << username << "\n";
            else
            {
                cout << "Invalid login!\n";
                attempts++;
                cout << "Attempts left: " << 3 - attempts << "\n";
            }
            break;

        case 2:
            return 0;

        default:
            cout << "Invalid choice!\n";
        }
    }
}
