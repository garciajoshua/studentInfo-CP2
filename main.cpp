#include <iostream>
#include <string>
using namespace std;




struct Student {
    string firstName;
    string lastName;
    string sex;
    string course;
    string year;
};

void AddStudent(Student students[], int& studentCounter);
void showStudents(Student students[], int studentCount);


int main() {
    const int MAX_STUDENTS = 100;
    const int STUDENTS_PER_PAGE = 5;
    Student students[MAX_STUDENTS];
    int studentCount = 0;
    int currentPage = 0;
    int choice;

    do {
        cout << "\nMain Menu\n"
            << "1. Add Student\n"
            << "2. Show Students\n"
            << "3. Exit\n"
            << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            AddStudent(students, studentCount);
            break;
        case 2:
            showStudents(students, studentCount);
            break;
        }
    } while (choice != 3);

    return 0;
}

void AddStudent(Student students[], int& studentCounter) {
    const int MAX_STUDENTS = 100;
    if (studentCounter >= MAX_STUDENTS) {
        cout << "Maximum number of students reached!" << endl;
        return;
    }

    Student& student = students[studentCounter];
    cin.ignore();

    cout << "-- Student Information Form --\n\n";
    cout << "First Name: ";
    getline(cin, student.firstName);
    cout << "Last Name: ";
    getline(cin, student.lastName);
    cout << "Sex: ";
    getline(cin, student.sex);
    cout << "Course: ";
    getline(cin, student.course);
    cout << "Year: ";
    getline(cin, student.year);

    studentCounter++;
    system("cls");
}

void showStudents(Student students[], int studentCount) {
    const int MAX_STUDENTS = 100;
    const int STUDENTS_PER_PAGE = 5;
    int totalPages = (studentCount - 1) / STUDENTS_PER_PAGE + 1;
    int currentPage = 0;

    char option;
    do {
        system("cls");
        cout << "Page " << currentPage + 1 << " of " << totalPages << "\n";
        for (int i = currentPage * STUDENTS_PER_PAGE; i < min((currentPage + 1) * STUDENTS_PER_PAGE, studentCount); ++i) {
            cout << "\nStudent " << i + 1 << "\n"
                << "First Name: " << students[i].firstName << "\n"
                << "Last Name: " << students[i].lastName << "\n"
                << "Course: " << students[i].course << "\n"
                << "Year: " << students[i].year << "\n";
        }

        cout << "N - Next Page, P - Previous Page, E - Exit to Main Menu\n";
        cout << "Enter option: ";
        cin >> option;

        switch (option) {
        case 'N':
        case 'n':
            if (currentPage < totalPages - 1) {
                currentPage++;
            }
            break;
        case 'P':
        case 'p':
            if (currentPage > 0) {
                currentPage--;
            }
            break;
        }
    } while (option != 'E' && option != 'e');
}
