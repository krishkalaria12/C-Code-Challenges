#include <iostream>
#include <string>

using namespace std;

class Player {
private:
    string name;
    int score;
    int level;

public:
    // Constructor
    Player(string name, int score = 0, int level = 1) {
        this->name = name;
        this->score = score;
        this->level = level;
    }

    // Method to increase score
    void increaseScore(int points) {
        score += points;
    }

    // Method to level up
    void levelUp() {
        ++level;
    }

    // Method to display player details
    void displayDetails() {
        cout << "Name: " << name << endl;
        cout << "Score: " << score << endl;
        cout << "Level: " << level << endl;
    }
};

int main() {
    // Example usage of the Player class
    Player player1("Alice", 100, 5);

    // Display player details
    cout << "Player Details:" << endl;
    player1.displayDetails();

    // Increase player score and level up
    player1.increaseScore(50);
    player1.levelUp();

    // Display updated player details
    cout << "\nUpdated Player Details:" << endl;
    player1.displayDetails();

    return 0;
}
