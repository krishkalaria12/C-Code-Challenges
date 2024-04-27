#include <iostream>
#include <string>

using namespace std;

// Base class for book
class Book {
protected:
    string title;
    string category;
public:
    Book(string _title, string _category) : title(_title), category(_category) {}

    virtual int getBorrowDuration() = 0; // Virtual function to get borrow duration
    string getTitle() { return title; }
    string getCategory() { return category; }
};

// Derived classes for different categories of books
class FictionBook : public Book {
public:
    FictionBook(string _title) : Book(_title, "Fiction") {}

    int getBorrowDuration() override { return 0; } // 0 indicates not allowed for this membership
}; 

class NonFictionBook : public Book {
public:
    NonFictionBook(string _title) : Book(_title, "Non-Fiction") {}

    int getBorrowDuration() override { return 0; } // 0 indicates not allowed for this membership
};

class ReferenceBook : public Book {
public:
    ReferenceBook(string _title) : Book(_title, "Reference") {}

    int getBorrowDuration() override { return 0; } // 0 indicates not allowed for this membership
};

// Base class for membership
class Membership {
protected:
    string type;
public:
    Membership(string _type) : type(_type) {}

    virtual int getBorrowDuration(Book* book) = 0; // Virtual function to get borrow duration for a book
    string getType() { return type; }
};

// Derived classes for different types of memberships
class RegularMembership : public Membership {
public:
    RegularMembership() : Membership("Regular") {}

    int getBorrowDuration(Book* book) override { return 14; }
};

class PremiumMembership : public Membership {
public:
    PremiumMembership() : Membership("Premium") {}

    int getBorrowDuration(Book* book) override {
        if (book->getCategory() == "Reference") return 7;
        else return 21;
    }
};

class StudentMembership : public Membership {
public:
    StudentMembership() : Membership("Student") {}

    int getBorrowDuration(Book* book) override {
        if (book->getCategory() == "Fiction") return 7;
        else if (book->getCategory() == "Non-Fiction") return 14;
        else return 21;
    }
};

// Library class
class Library {
public:
    void borrowBook(Membership* member, Book* book) {
        int duration = member->getBorrowDuration(book);
        if (duration == 0) {
            cout << "This membership type is not allowed to borrow this category of book." << endl;
            return;
        }
        cout << "Book '" << book->getTitle() << "' borrowed successfully for " << duration << " days." << endl;
    }

    void returnBook(Book* book) {
        cout << "Book '" << book->getTitle() << "' returned successfully." << endl;
    }
};

int main() {
    // Creating library
    Library library;

    // Creating memberships
    RegularMembership regular;
    PremiumMembership premium;
    StudentMembership student;

    // Creating books
    FictionBook fiction("To Kill a Mockingbird");
    NonFictionBook nonFiction("Sapiens: A Brief History of Humankind");
    ReferenceBook reference("The Oxford English Dictionary");

    // Testing borrowing and returning books
    library.borrowBook(&regular, &fiction);
    library.borrowBook(&premium, &nonFiction);
    library.borrowBook(&student, &reference);

    library.returnBook(&fiction);
    library.returnBook(&nonFiction);
    library.returnBook(&reference);

    return 0;
}