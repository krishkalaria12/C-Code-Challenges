#include <iostream>
#include <string>

using namespace std;

class Item {
private:
    string itemName;
    double price;
    int quantity;

public:
    // Constructor
    Item(string itemName, double price, int quantity) {
        this->itemName = itemName;
        this->price = price;
        this->quantity = quantity;
    }

    // Method to add quantity of the item
    void addQuantity(int quantityToAdd) {
        if (quantityToAdd > 0) {
            quantity += quantityToAdd;
            cout << quantityToAdd << " " << itemName << " added to the cart." << endl;
        } else {
            cout << "Invalid quantity. Please enter a positive value." << endl;
        }
    }

    // Method to remove quantity of the item
    void removeQuantity(int quantityToRemove) {
        if (quantityToRemove > 0 && quantity >= quantityToRemove) {
            quantity -= quantityToRemove;
            cout << quantityToRemove << " " << itemName << " removed from the cart." << endl;
        } else {
            cout << "Invalid quantity or insufficient quantity in the cart." << endl;
        }
    }

    // Method to update quantity of the item
    void updateQuantity(int newQuantity) {
        if (newQuantity >= 0) {
            quantity = newQuantity;
            cout << "Quantity of " << itemName << " updated to " << quantity << " in the cart." << endl;
        } else {
            cout << "Invalid quantity. Please enter a non-negative value." << endl;
        }
    }
};

int main() {
    // Example usage of the Item class
    Item item1("T-shirt", 25.0, 3);

    // Add items to the cart
    item1.addQuantity(2);

    // Remove items from the cart
    item1.removeQuantity(1);

    // Update quantity in the cart
    item1.updateQuantity(5);

    return 0;
}
