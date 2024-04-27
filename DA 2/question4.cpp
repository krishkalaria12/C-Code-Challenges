#include <iostream>
#include <string>

using namespace std;

// Base class for Employee
class Employee {
protected:
    string name;
    int age;
    double basicSalary;
public:
    // Constructor
    Employee(string _name, int _age, double _basicSalary) : name(_name), age(_age), basicSalary(_basicSalary) {}

    // Virtual function to compute gross salary
    virtual double computeGrossSalary() = 0;

    // Function to display employee details
    void displayDetails() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Basic Salary: " << basicSalary << endl;
    }
};

// Base class for Department
class Department {
protected:
    string department;
    double otherAllowance;
public:
    // Constructor
    Department(string _department, double _otherAllowance) : department(_department), otherAllowance(_otherAllowance) {}
};

// Derived class for Full Time Employee
class FullTimeEmployee : public Employee, public Department {
public:
    // Constructor
    FullTimeEmployee(string _name, int _age, double _basicSalary, string _department)
        : Employee(_name, _age, _basicSalary), Department(_department, 1000) {}

    // Function to compute gross salary for Full Time Employee
    double computeGrossSalary() override {
        double da = 0.3 * basicSalary;
        double hra = 0.1 * basicSalary;
        return basicSalary + da + hra + otherAllowance;
    }
};

// Derived class for Part Time Employee
class PartTimeEmployee : public Employee, public Department {
public:
    // Constructor
    PartTimeEmployee(string _name, int _age, double _basicSalary, string _department)
        : Employee(_name, _age, _basicSalary), Department(_department, 750) {}

    // Function to compute gross salary for Part Time Employee
    double computeGrossSalary() override {
        double da = 0.15 * basicSalary;
        double hra = 0.05 * basicSalary;
        return basicSalary + da + hra + otherAllowance;
    }
};

// Derived class for Intern
class Intern : public Employee, public Department {
public:
    // Constructor
    Intern(string _name, int _age, double _basicSalary, string _department)
        : Employee(_name, _age, _basicSalary), Department(_department, 500) {}

    // Function to compute gross salary for Intern
    double computeGrossSalary() override {
        double da = 0.05 * basicSalary;
        double hra = 0.02 * basicSalary;
        return basicSalary + da + hra + otherAllowance;
    }
};

int main() {
    string name, department;
    int age;
    double basicSalary;

    // Input data for Full Time Employee
    cout << "Enter details for Full Time Employee:" << endl;
    cout << "Name: ";
    cin >> name;
    cout << "Age: ";
    cin >> age;
    cout << "Basic Salary: ";
    cin >> basicSalary;
    cout << "Department: ";
    cin >> department;

    FullTimeEmployee fullTimeEmployee(name, age, basicSalary, department);
    cout << "Gross Salary: " << fullTimeEmployee.computeGrossSalary() << endl;
    fullTimeEmployee.displayDetails();
    cout << endl;

    // Input data for Part Time Employee
    cout << "Enter details for Part Time Employee:" << endl;
    cout << "Name: ";
    cin >> name;
    cout << "Age: ";
    cin >> age;
    cout << "Basic Salary: ";
    cin >> basicSalary;
    cout << "Department: ";
    cin >> department;

    PartTimeEmployee partTimeEmployee(name, age, basicSalary, department);
    cout << "Gross Salary: " << partTimeEmployee.computeGrossSalary() << endl;
    partTimeEmployee.displayDetails();
    cout << endl;

    // Input data for Intern
    cout << "Enter details for Intern:" << endl;
    cout << "Name: ";
    cin >> name;
    cout << "Age: ";
    cin >> age;
    cout << "Basic Salary: ";
    cin >> basicSalary;
    cout << "Department: ";
    cin >> department;

    Intern intern(name, age, basicSalary, department);
    cout << "Gross Salary: " << intern.computeGrossSalary() << endl;
    intern.displayDetails();
    cout << endl;

    return 0;
}
