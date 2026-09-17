#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Book {
private:
    int id;
    string title;
    string author;
    bool is_issued;

public:
    Book(int bId, string bTitle, string bAuthor) {
        id = bId;
        title = bTitle;
        author = bAuthor;
        is_issued = false;
    }

    int getId() {
        return id;
    }

    bool checkStatus() {
        return is_issued;
    }

    void issueBook() {
        is_issued = true;
    }

    void returnBook() {
        is_issued = false;
    }

    void displayDetails() {
        cout << "ID: " << id << ", Title: " << title << ", Author: " << author;
        if (is_issued) {
            cout << " [Issued]\n";
        } else {
            cout << " [Available]\n";
        }
    }
};

class LibrarySystem {
private:
    vector<Book> bookList;

    int findBookIndex(int id) {
        for (size_t i = 0; i < bookList.size(); i++) {
            if (bookList[i].getId() == id) {
                return i;
            }
        }
        return -1;
    }

public:
    void addBook() {
        int id;
        string title, author;

        cout << "Enter Book ID: ";
        cin >> id;
        cin.ignore(); 

        if (findBookIndex(id) != -1) {
            cout << "Error: Book ID already exists!\n";
            return;
        }

        cout << "Enter Title: ";
        getline(cin, title);

        cout << "Enter Author: ";
        getline(cin, author);

        Book newBook(id, title, author);
        bookList.push_back(newBook);
        cout << "Book added successfully.\n";
    }

    void showAllBooks() {
        if (bookList.empty()) {
            cout << "No books available in the library.\n";
            return;
        }

        cout << "\nBook List:\n";
        for (size_t i = 0; i < bookList.size(); i++) {
            bookList[i].displayDetails();
        }
    }

    void searchBook() {
        int id;
        cout << "Enter Book ID to search: ";
        cin >> id;

        int index = findBookIndex(id);
        if (index == -1) {
            cout << "Book not found.\n";
        } else {
            bookList[index].displayDetails();
        }
    }

    void issueBook() {
        int id;
        cout << "Enter Book ID to issue: ";
        cin >> id;

        int index = findBookIndex(id);
        if (index == -1) {
            cout << "Book not found.\n";
        } else if (bookList[index].checkStatus()) {
            cout << "This book is already issued.\n";
        } else {
            bookList[index].issueBook();
            cout << "Book issued successfully.\n";
        }
    }

    void returnBook() {
        int id;
        cout << "Enter Book ID to return: ";
        cin >> id;

        int index = findBookIndex(id);
        if (index == -1) {
            cout << "Book not found.\n";
        } else if (!bookList[index].checkStatus()) {
            cout << "This book was not issued.\n";
        } else {
            bookList[index].returnBook();
            cout << "Book returned successfully.\n";
        }
    }
};

int main() {
    LibrarySystem lib;
    int choice;

    do {
        cout << "\n--- Main Menu ---\n";
        cout << "1. Add Book\n";
        cout << "2. View Books\n";
        cout << "3. Search Book\n";
        cout << "4. Issue Book\n";
        cout << "5. Return Book\n";
        cout << "0. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                lib.addBook();
                break;
            case 2:
                lib.showAllBooks();
                break;
            case 3:
                lib.searchBook();
                break;
            case 4:
                lib.issueBook();
                break;
            case 5:
                lib.returnBook();
                break;
            case 0:
                cout << "Program ended.\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 0);

    return 0;
}