#include <iostream>
#include <string>

using namespace std;

class Book {
private:
    string title;
    string author;
    string genre;

public:
    // Parameterized Constructor
    Book(string title, string author, string genre) {
        this->title = title;
        this->author = author;
        this->genre = genre;
    }

    // Getter methods
    string getTitle() {
        return title;
    }

    string getAuthor() {
        return author;
    }

    string getGenre() {
        return genre;
    }

    // Display method
    void displayInfo() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Genre: " << genre << endl;
    }
};

int main() {
    int numBooks;
    cout << "Enter the number of books: ";
    cin >> numBooks;
    cin.ignore(); // Clear input buffer

    // Create an array of pointers to Book objects
    Book* library[numBooks];

    // Input book details
    for (int i = 0; i < numBooks; ++i) {
        string title, author, genre;
        cout << "\nEnter details for book " << i + 1 << ":" << endl;
        cout << "Title: ";
        getline(cin, title);
        cout << "Author: ";
        getline(cin, author);
        cout << "Genre: ";
        getline(cin, genre);

        // Allocate memory for each book and store its address in the array
        library[i] = new Book(title, author, genre);
    }

    // Display all books in the library
    cout << "\nLibrary Catalog:" << endl;
    for (int i = 0; i < numBooks; ++i) {
        cout << "\nBook " << i + 1 << ":" << endl;
        library[i]->displayInfo();
    }

    // Free dynamically allocated memory
    for (int i = 0; i < numBooks; ++i) {
        delete library[i];
    }

    return 0;
}
