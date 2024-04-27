#include <iostream>
#include <string>

using namespace std;

// Base class representing a person
class Person {
protected:
    string name;
    int age;
    string address;

public:
    // Constructor
    Person() {}

    // Function to input person details
    void input() {
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Age: ";
        cin >> age;
        cout << "Enter Address: ";
        cin.ignore(); // Clear input buffer
        getline(cin, address); // Read entire line including spaces
    }

    // Function to display person details
    void display() const {
        cout << "Name: " << name << ", Age: " << age << ", Address: " << address << endl;
    }

    // Getter functions
    string getName() const { return name; }
    int getAge() const { return age; }
};

// Derived class for faculty
class Faculty : public Person {
private:
    string department;

public:
    // Function to input faculty details
    void input() {
        Person::input(); // Call base class input function
        cout << "Enter Department: ";
        cin >> department;
    }

    // Function to display faculty details
    void display() const {
        cout << "Faculty Details - ";
        Person::display(); // Call base class display function
        cout << "Department: " << department << endl;
    }

    // Getter function for department
    string getDepartment() const { return department; }
};

// Derived class for staff
class Staff : public Person {
private:
    string designation;

public:
    // Function to input staff details
    void input() {
        Person::input(); // Call base class input function
        cout << "Enter Designation: ";
        cin >> designation;
    }

    // Function to display staff details
    void display() const {
        cout << "Staff Details - ";
        Person::display(); // Call base class display function
        cout << "Designation: " << designation << endl;
    }
};

// Derived class for students
class Student : public Person {
private:
    string fieldOfStudy;
    int studentID;

public:
    // Function to input student details
    void input() {
        Person::input(); // Call base class input function
        cout << "Enter Field of Study: ";
        cin >> fieldOfStudy;
        cout << "Enter Student ID: ";
        cin >> studentID;
    }

    // Function to display student details
    void display() const {
        cout << "Student Details - ";
        Person::display(); // Call base class display function
        cout << "Field of Study: " << fieldOfStudy << ", Student ID: " << studentID << endl;
    }

    // Getter function for field of study
    string getFieldOfStudy() const { return fieldOfStudy; }
};

int main() {
    int numFaculty, numStaff, numStudents;
    cout << "Enter number of Faculty: ";
    cin >> numFaculty;
    cout << "Enter number of Staff: ";
    cin >> numStaff;
    cout << "Enter number of Students: ";
    cin >> numStudents;

    // Input faculty details
    cout << "\nEnter Faculty Details:" << endl;
    Faculty* faculty = new Faculty[numFaculty];
    for (int i = 0; i < numFaculty; ++i) {
        cout << "\nEnter Faculty " << i + 1 << " Details:" << endl;
        faculty[i].input();
    }

    // Input staff details
    cout << "\nEnter Staff Details:" << endl;
    Staff* staff = new Staff[numStaff];
    for (int i = 0; i < numStaff; ++i) {
        cout << "\nEnter Staff " << i + 1 << " Details:" << endl;
        staff[i].input();
    }

    // Input student details
    cout << "\nEnter Student Details:" << endl;
    Student* students = new Student[numStudents];
    for (int i = 0; i < numStudents; ++i) {
        cout << "\nEnter Student " << i + 1 << " Details:" << endl;
        students[i].input();
    }

    // Calculate average age of faculty
    int totalFacultyAge = 0;
    for (int i = 0; i < numFaculty; ++i) {
        totalFacultyAge += faculty[i].getAge();
    }
    double avgFacultyAge = numFaculty > 0 ? static_cast<double>(totalFacultyAge) / numFaculty : 0;

    // Calculate average age of staff
    int totalStaffAge = 0;
    for (int i = 0; i < numStaff; ++i) {
        totalStaffAge += staff[i].getAge();
    }
    double avgStaffAge = numStaff > 0 ? static_cast<double>(totalStaffAge) / numStaff : 0;

    // Calculate average age of students
    int totalStudentAge = 0;
    for (int i = 0; i < numStudents; ++i) {
        totalStudentAge += students[i].getAge();
    }
    double avgStudentAge = numStudents > 0 ? static_cast<double>(totalStudentAge) / numStudents : 0;

    // Display average ages
    cout << "\nAverage Age of Faculty: " << avgFacultyAge << endl;
    cout << "Average Age of Staff: " << avgStaffAge << endl;
    cout << "Average Age of Students: " << avgStudentAge << endl;

    // Deallocate memory
    delete[] faculty;
    delete[] staff;
    delete[] students;

    return 0;
}
