#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Student {
private:
    int id;
    string name;
    string program;
    double cgpa;

public:
    // Simple Constructor
    Student(int sId, string sName, string sProgram, double sCgpa) {
        id = sId;
        name = sName;
        program = sProgram;
        cgpa = sCgpa;
    }

    // Getter Functions
    int getId() { return id; }
    string getName() { return name; }
    string getProgram() { return program; }
    double getCgpa() { return cgpa; }

    // Update Function
    void update(string newName, string newProgram, double newCgpa) {
        name = newName;
        program = newProgram;
        cgpa = newCgpa;
    }

    // Display Function
    void display() {
        cout << id << "\t" << name << "\t" << program << "\t" << cgpa << endl;
    }
};

class StudentManagementSystem {
private:
    vector<Student> students;
    int nextId = 1001;

public:
    // 1. Add Student
    void addStudent() {
        string name, program;
        double cgpa;

        cout << "\n--- Add Student ---\n";
        cout << "Enter Name: ";
        cin.ignore(); // Buffer clear karne ke liye
        getline(cin, name);

        cout << "Enter Program: ";
        getline(cin, program);

        cout << "Enter CGPA (0.0 to 4.0): ";
        cin >> cgpa;

        // Validation loop
        while (cgpa < 0.0 || cgpa > 4.0) {
            cout << "Invalid CGPA! Enter between 0.0 and 4.0: ";
            cin >> cgpa;
        }

        // Student object create karke vector mein add kar rahe hain
        Student newStudent(nextId, name, program, cgpa);
        students.push_back(newStudent);

        cout << "Student added successfully! Generated ID: " << nextId << endl;
        nextId++;
    }

    // 2. View All Students
    void viewStudents() {
        cout << "\n--- All Students ---\n";
        if (students.empty()) {
            cout << "No student records found.\n";
            return;
        }

        cout << "ID\tName\tProgram\tCGPA\n";
        cout << "-----------------------------------\n";
        for (int i = 0; i < students.size(); i++) {
            students[i].display();
        }
    }

    // 3. Search Student
    void searchStudent() {
        int id;
        cout << "\nEnter student ID to search: ";
        cin >> id;

        bool found = false;
        for (int i = 0; i < students.size(); i++) {
            if (students[i].getId() == id) {
                cout << "\nStudent Found:\n";
                cout << "ID: " << students[i].getId() << endl;
                cout << "Name: " << students[i].getName() << endl;
                cout << "Program: " << students[i].getProgram() << endl;
                cout << "CGPA: " << students[i].getCgpa() << endl;
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Student with ID " << id << " not found.\n";
        }
    }

    // 4. Update Student
    void updateStudent() {
        int id;
        cout << "\nEnter student ID to update: ";
        cin >> id;

        bool found = false;
        for (int i = 0; i < students.size(); i++) {
            if (students[i].getId() == id) {
                string name, program;
                double cgpa;

                cout << "Enter New Name: ";
                cin.ignore();
                getline(cin, name);

                cout << "Enter New Program: ";
                getline(cin, program);

                cout << "Enter New CGPA: ";
                cin >> cgpa;

                while (cgpa < 0.0 || cgpa > 4.0) {
                    cout << "Invalid CGPA! Enter between 0.0 and 4.0: ";
                    cin >> cgpa;
                }

                students[i].update(name, program, cgpa);
                cout << "Student record updated successfully!\n";
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Student not found.\n";
        }
    }

    // 5. Delete Student
    void deleteStudent() {
        int id;
        cout << "\nEnter student ID to delete: ";
        cin >> id;

        bool found = false;
        for (int i = 0; i < students.size(); i++) {
            if (students[i].getId() == id) {
                students.erase(students.begin() + i);
                cout << "Student deleted successfully!\n";
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Student not found.\n";
        }
    }

    // Main System Loop
    void run() {
        int choice = -1;

        while (choice != 0) {
            cout << "\n========================================\n";
            cout << "      STUDENT MANAGEMENT SYSTEM         \n";
            cout << "========================================\n";
            cout << "1. Add Student\n";
            cout << "2. View All Students\n";
            cout << "3. Search Student\n";
            cout << "4. Update Student\n";
            cout << "5. Delete Student\n";
            cout << "0. Exit\n";
            cout << "========================================\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    addStudent();
                    break;
                case 2:
                    viewStudents();
                    break;
                case 3:
                    searchStudent();
                    break;
                case 4:
                    updateStudent();
                    break;
                case 5:
                    deleteStudent();
                    break;
                case 0:
                    cout << "Exiting system. Goodbye!\n";
                    break;
                default:
                    cout << "Invalid choice! Please try again.\n";
            }
        }
    }
};

int main() {
    StudentManagementSystem sms;
    sms.run();
    return 0;
}