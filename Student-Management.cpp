#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <limits>
#include <algorithm>
using namespace std;

class Student {
private:
    int id;
    string name;
    string program;
    double cgpa;
public:
    Student(int studentId, string studentName, string studentProgram, double studentCgpa)
        : id(studentId), name(std::move(studentName)), program(std::move(studentProgram)), cgpa(studentCgpa) {}
    int getId() const { return id; }
    string getName() const { return name; }
    string getProgram() const { return program; }
    double getCgpa() const { return cgpa; }
    void update(string newName, string newProgram, double newCgpa) { name = std::move(newName); program = std::move(newProgram); cgpa = newCgpa; }
    void display() const { cout << left << setw(8) << id << setw(24) << name << setw(22) << program << fixed << setprecision(2) << cgpa << '\n'; }
};

class StudentManagementSystem {
private:
    vector<Student> students;
    int nextId = 1001;
    void clearInput() { cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); }
    int readInt(const string& prompt) { int value; while (true) { cout << prompt; if (cin >> value) { clearInput(); return value; } cout << "Invalid input. Try again.\n"; clearInput(); } }
    double readCgpa() { double value; while (true) { cout << "Enter CGPA (0.00 - 4.00): "; if (cin >> value && value >= 0 && value <= 4) { clearInput(); return value; } cout << "CGPA must be between 0 and 4.\n"; clearInput(); } }
    Student* findStudent(int id) { for (auto& student : students) if (student.getId() == id) return &student; return nullptr; }
public:
    void addStudent() { string name, program; cout << "\n--- Add Student ---\nName: "; getline(cin, name); cout << "Program: "; getline(cin, program); double cgpa = readCgpa(); students.emplace_back(nextId++, name, program, cgpa); cout << "Student added successfully. ID: " << students.back().getId() << "\n"; }
    void viewStudents() const { cout << "\n--- All Students ---\n"; if (students.empty()) { cout << "No student records found.\n"; return; } cout << left << setw(8) << "ID" << setw(24) << "Name" << setw(22) << "Program" << "CGPA\n" << string(65, '-') << '\n'; for (const auto& student : students) student.display(); }
    void searchStudent() { int id = readInt("Enter student ID: "); Student* student = findStudent(id); if (student) { cout << "\nStudent found:\n"; cout << "ID: " << student->getId() << "\nName: " << student->getName() << "\nProgram: " << student->getProgram() << "\nCGPA: " << fixed << setprecision(2) << student->getCgpa() << '\n'; } else cout << "Student not found.\n"; }
    void updateStudent() { int id = readInt("Enter student ID to update: "); Student* student = findStudent(id); if (!student) { cout << "Student not found.\n"; return; } string name, program; cout << "New name: "; getline(cin, name); cout << "New program: "; getline(cin, program); double cgpa = readCgpa(); student->update(name, program, cgpa); cout << "Student updated successfully.\n"; }
    void deleteStudent() { int id = readInt("Enter student ID to delete: "); auto it = remove_if(students.begin(), students.end(), [id](const Student& s){ return s.getId() == id; }); if (it != students.end()) { students.erase(it, students.end()); cout << "Student deleted successfully.\n"; } else cout << "Student not found.\n"; }
    void run() { int choice; do { cout << "\n========================================\n      STUDENT MANAGEMENT SYSTEM\n========================================\n1. Add student\n2. View all students\n3. Search student\n4. Update student\n5. Delete student\n0. Exit\n========================================\n"; choice = readInt("Choose an option: "); switch (choice) { case 1: addStudent(); break; case 2: viewStudents(); break; case 3: searchStudent(); break; case 4: updateStudent(); break; case 5: deleteStudent(); break; case 0: cout << "Goodbye!\n"; break; default: cout << "Invalid option.\n"; } } while (choice != 0); }
};

int main() { StudentManagementSystem system; system.run(); return 0; }
