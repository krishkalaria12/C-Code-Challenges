#include<iostream>
#include<string>
using namespace std;

class Voter {
private:
    string name;
    int age;
    bool status;

public:
    // Default constructor
    Voter() {
        name = "";
        age = 0;
        status = false;
    }

    // Parameterized constructor
    Voter(string n, int a, bool s) : name(n), age(a), status(s) {}

    // Input function
    void Input() {
        cout << "Name: ";
        cin >> name;
        cout << "Age: ";
        cin >> age;
        cout << "Status (1 for eligible, 0 for ineligible): ";
        int stat;
        cin >> stat;
        status = (stat == 1);
    }

    friend void displayEligibleVoters(Voter* voters, int n);
};

void displayEligibleVoters(Voter* voters, int n) {
    cout << "\nEligible Voters:\n";
    for (int i = 0; i < n; ++i) {
        if (!voters[i].status && voters[i].age >= 18) {
            cout << "Name: " << voters[i].name << ", Age: " << voters[i].age << endl;
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of Voters: ";
    cin >> n;

    // Dynamically allocate array of Voter objects
    Voter *voters = new Voter[n];

    // Input details for each voter
    for (int i = 0; i < n; ++i) {
        cout << "\nEnter details for Voter " << i + 1 << ":" << endl;
        voters[i].Input();
    }

    // Call friend function to display eligible voters
    displayEligibleVoters(voters, n);

    // Deallocate memory
    delete[] voters;

    return 0;
}
