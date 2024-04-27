#include <iostream>
#include <string>

using namespace std;

class Trip {
private:
    string destination;
    int duration; // Duration in days
    double cost;
    bool booked;

public:
    // Constructor
    Trip(string destination, int duration, double cost) {
        this->destination = destination;
        this->duration = duration;
        this->cost = cost;
        this->booked = false; // Initialize as not booked
    }

    // Method to book the trip
    void bookTrip() {
        if (!booked) {
            cout << "Trip to " << destination << " booked for " << duration << " days. Cost: $" << cost << endl;
            booked = true;
        } else {
            cout << "Trip to " << destination << " is already booked." << endl;
        }
    }

    // Method to cancel the trip
    void cancelTrip() {
        if (booked) {
            cout << "Trip to " << destination << " cancelled." << endl;
            booked = false;
        } else {
            cout << "Trip to " << destination << " is not booked." << endl;
        }
    }

    // Method to modify the trip
    void modifyTrip(int newDuration, double newCost) {
        if (booked) {
            duration = newDuration;
            cost = newCost;
            cout << "Trip to " << destination << " modified. New duration: " << duration << " days. New cost: $" << cost << endl;
        } else {
            cout << "Trip to " << destination << " is not booked. Cannot modify." << endl;
        }
    }
};

int main() {
    // Example usage of the Trip class
    Trip trip1("Paris", 7, 2000.0);

    // Book the trip
    trip1.bookTrip();

    // Modify the trip
    trip1.modifyTrip(10, 2500.0);

    // Cancel the trip
    trip1.cancelTrip();

    return 0;
}
