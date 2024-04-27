#include <iostream>
#include <string>
using namespace std;

class CD {
    private:
        string title;
        string composer;
        string genre;
        float price;
        int stock;

    public:
        // Default constructor
        CD() {
            price = 0; // Initialize price to 0
        }

        // Parameterized constructor
        CD(string t, string c, string g, float p, int s) {
            title = t;
            composer = c;
            genre = g;
            price = p;
            stock = s;
        }

        string getTitle() const {
            return title;
        }

        string getComposer() const {
            return composer;
        }

        // Destructor
        ~CD() {
            cout << "CD title '" << title << "' is deleted." << endl;
        }

        // Input function to get CD details from user
        void input() {
            cout << "Enter CD title: ";
            cin >> title;
            cout << "Enter composer name: ";
            cin >> composer;
            cout << "Enter music genre: ";
            cin >> genre;
            cout << "Enter price: ";
            cin >> price;
            cout << "Enter stock available: ";
            cin >> stock;
        }

        // Function to check CD availability and calculate total cost
        void checkAvailability(int requiredStock) {
            if (stock >= requiredStock) {
                cout << "CD available!" << endl;
                cout << "Title: " << title << endl;
                cout << "Composer: " << composer << endl;
                cout << "Genre: " << genre << endl;
                cout << "Price: $" << price << endl;
                cout << "Enter number of CDs required: ";
                int requiredCopies;
                cin >> requiredCopies;
                if (requiredCopies <= stock) {
                    cout << "Total cost: $" << requiredCopies * price << endl;
                } else {
                    cout << "The requested copies are not in stock." << endl;
                }
            } else {
                cout << "CD not available." << endl;
            }
        }
};

int main() {
    int n;
    cout << "Enter the number of CDs: ";
    cin >> n;

    // Create an array of n CD objects
    CD *cds = new CD[n];

    // Input CD details for each CD
    for (int i = 0; i < n; ++i) {
        cout << "\nEnter details for CD " << i + 1 << ":" << endl;
        cds[i].input();
    }

    // Search for CD
    string searchTitle, searchComposer;
    cout << "\nEnter title of CD to search: ";
    cin >> searchTitle;
    cout << "Enter composer of CD to search: ";
    cin >> searchComposer;

    bool found = false;
    for (int i = 0; i < n; ++i) {
        if (cds[i].getTitle() == searchTitle && cds[i].getComposer() == searchComposer) {
            cds[i].checkAvailability(1);
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "CD not found." << endl;
    }

    // Delete array of CD objects
    delete[] cds;

    return 0;
}
