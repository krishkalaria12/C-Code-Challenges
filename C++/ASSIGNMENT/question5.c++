#include <iostream>
#include <string>

using namespace std;

class Account {
private:
    string accountNumber;
    string accountHolderName;
    double balance;

public:
    // Constructor
    Account(string accountNumber, string accountHolderName, double balance = 0.0) {
        this->accountNumber = accountNumber;
        this->accountHolderName = accountHolderName;
        this->balance = balance;
    }

    // Method to deposit money
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful. Current balance: $" << balance << endl;
        } else {
            cout << "Invalid deposit amount. Please enter a positive value." << endl;
        }
    }

    // Method to withdraw money
    void withdraw(double amount) {
        if (amount > 0) {
            if (balance >= amount) {
                balance -= amount;
                cout << "Withdrawal successful. Current balance: $" << balance << endl;
            } else {
                cout << "Insufficient funds. Withdrawal failed." << endl;
            }
        } else {
            cout << "Invalid withdrawal amount. Please enter a positive value." << endl;
        }
    }

    // Method to check balance
    double checkBalance() const {
        return balance;
    }
};

int main() {
    // Example usage of the Account class
    Account account1("123456789", "Alice", 1000.0);

    // Deposit money
    account1.deposit(500.0);

    // Withdraw money
    account1.withdraw(200.0);

    // Check balance
    cout << "Current balance: $" << account1.checkBalance() << endl;

    return 0;
}
