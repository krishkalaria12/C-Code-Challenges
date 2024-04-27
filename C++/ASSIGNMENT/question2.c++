#include <iostream>
#include <string>

using namespace std;

class Book {
private:
    string title;
    string author;
    string genre;
    bool available;

public:
    // Constructor
    Book() {}

    // Setter methods
    void setTitle(const string& title) {
        this->title = title;
    }

    void setAuthor(const string& author) {
        this->author = author;
    }

    void setGenre(const string& genre) {
        this->genre = genre;
    }

    void setAvailability(bool available) {
        this->available = available;
    }

    // Getter methods
    string getTitle() const {
        return title;
    }

    string getAuthor() const {
        return author;
    }

    string getGenre() const {
        return genre;
    }

    bool isAvailable() const {
        return available;
    }

    // Method to display book details
    void displayDetails() const {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Genre: " << genre << endl;
        cout << "Availability: " << (available ? "Available" : "Not Available") << endl;
    }

    // Method to get input for book details
    void getInput() {
        cout << "Enter title: ";
        getline(cin, title);

        cout << "Enter author: ";
        getline(cin, author);

        cout << "Enter genre: ";
        getline(cin, genre);

        cout << "Is the book available? (1 for yes, 0 for no): ";
        cin >> available;
        cin.ignore(); // Ignore newline character in the input buffer
    }
};

int main() {
    int numBooks;
    cout << "Enter the number of books: ";
    cin >> numBooks;
    cin.ignore(); // Ignore newline character in the input buffer

    Book* library = new Book[numBooks];

    // Get input for each book
    for (int i = 0; i < numBooks; ++i) {
        cout << "\nEnter details for book " << i + 1 << ":" << endl;
        library[i].getInput();
    }

    // Display details of each book
    cout << "\nLibrary Catalog:" << endl;
    for (int i = 0; i < numBooks; ++i) {
        cout << "\nBook " << i + 1 << " Details:" << endl;
        library[i].displayDetails();
    }

    // Free dynamically allocated memory
    delete[] library;

    return 0;
}
