#include <iostream>
#include <cmath>
using namespace std;

// -------- Function Declarations --------
void calculateAttendance();
void calculateGrade();
void calculateAverage();
void checkEvenOdd();
void areaOfCircle();

// -------- Functions --------

void calculateAttendance() {
    double total, present;
    cout << "\nEnter Total Classes: ";
    cin >> total;

    if (total <= 0) {
        cout << "Invalid Total Classes!" << endl;
        return;
    }

    cout << "Enter Classes Attended: ";
    cin >> present;

    double percentage = (present / total) * 100;
    cout << "Attendance Percentage: " << percentage << "%" << endl;

    if (percentage < 75)
        cout << "Warning: Attendance Shortage!" << endl;
    else
        cout << "You are eligible for exams." << endl;
}

void calculateGrade() {
    int marks;
    cout << "\nEnter Marks (0-100): ";
    cin >> marks;

    if (marks < 0 || marks > 100) {
        cout << "Invalid Marks!" << endl;
        return;
    }

    if (marks >= 90)
        cout << "Grade: A+" << endl;
    else if (marks >= 80)
        cout << "Grade: A" << endl;
    else if (marks >= 70)
        cout << "Grade: B" << endl;
    else if (marks >= 60)
        cout << "Grade: C" << endl;
    else
        cout << "Grade: F (Fail)" << endl;
}

void calculateAverage() {
    double m1, m2, m3;
    cout << "\nEnter Marks of 3 Subjects: ";
    cin >> m1 >> m2 >> m3;

    double avg = (m1 + m2 + m3) / 3;
    cout << "Average Marks: " << avg << endl;
}

void checkEvenOdd() {
    int num;
    cout << "\nEnter a Number: ";
    cin >> num;

    if (num % 2 == 0)
        cout << num << " is Even." << endl;
    else
        cout << num << " is Odd." << endl;
}

void areaOfCircle() {
    double radius;
    cout << "\nEnter Radius: ";
    cin >> radius;

    if (radius < 0) {
        cout << "Invalid Radius!" << endl;
        return;
    }

    double area = 3.1416 * pow(radius, 2);
    cout << "Area of Circle: " << area << endl;
}

// -------- Main Program --------

int main() {
    int choice;

    do {
        cout << "\n===== SMART STUDENT CALCULATOR =====" << endl;
        cout << "1. Attendance Percentage" << endl;
        cout << "2. Grade Calculator" << endl;
        cout << "3. Average of 3 Subjects" << endl;
        cout << "4. Even / Odd Checker" << endl;
        cout << "5. Area of Circle" << endl;
        cout << "6. Exit" << endl;
        cout << "Choose an option: ";
        cin >> choice;

        switch(choice) {
            case 1:
                calculateAttendance();
                break;
            case 2:
                calculateGrade();
                break;
            case 3:
                calculateAverage();
                break;
            case 4:
                checkEvenOdd();
                break;
            case 5:
                areaOfCircle();
                break;
            case 6:
                cout << "Program Closed. Allah Hafiz!" << endl;
                break;
            default:
                cout << "Invalid Choice! Try Again." << endl;
        }

    } while(choice != 6);

    return 0;
}

