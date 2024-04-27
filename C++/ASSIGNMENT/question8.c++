#include <iostream>
#include <string>

using namespace std;

class Dish {
private:
    string dishName;
    string ingredients;
    double price;
    bool prepared;

public:
    // Constructor
    Dish(string dishName, string ingredients, double price) {
        this->dishName = dishName;
        this->ingredients = ingredients;
        this->price = price;
        this->prepared = false; // Initialize as not prepared
    }

    // Method to prepare the dish
    void prepareDish() {
        if (!prepared) {
            cout << "Preparing " << dishName << " with ingredients: " << ingredients << endl;
            prepared = true;
        } else {
            cout << "Dish is already prepared." << endl;
        }
    }

    // Method to serve the dish
    void serveDish() {
        if (prepared) {
            cout << "Serving " << dishName << "." << endl;
            prepared = false;
        } else {
            cout << "Dish is not yet prepared." << endl;
        }
    }

    // Method to bill the dish
    double billDish() const {
        return price;
    }
};

int main() {
    // Example usage of the Dish class
    Dish dish1("Spaghetti Carbonara", "Spaghetti, Eggs, Bacon, Parmesan Cheese", 12.99);

    // Prepare the dish
    dish1.prepareDish();

    // Serve the dish
    dish1.serveDish();

    // Bill the dish
    cout << "Total bill for " << dish1.billDish() << " USD." << endl;

    return 0;
}
