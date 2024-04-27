#include <iostream>
#include <string>

using namespace std;

class Car {
private:
    string brand;
    string model;
    int year;
    double price;

public:
    // Constructor
    Car() {}

    // Setter methods
    void setBrand(const string& brand) {
        this->brand = brand;
    }

    void setModel(const string& model) {
        this->model = model;
    }

    void setYear(int year) {
        this->year = year;
    }

    void setPrice(double price) {
        this->price = price;
    }

    // Getter methods
    string getBrand() const {
        return brand;
    }

    string getModel() const {
        return model;
    }

    int getYear() const {
        return year;
    }

    double getPrice() const {
        return price;
    }
};

int main() {
    // Example usage of the Car class
    Car car1;

    // Setting attributes using setter methods
    car1.setBrand("Toyota");
    car1.setModel("Camry");
    car1.setYear(2022);
    car1.setPrice(25000.0);

    // Getting attributes using getter methods and displaying
    cout << "Car 1 Details:" << endl;
    cout << "Brand: " << car1.getBrand() << endl;
    cout << "Model: " << car1.getModel() << endl;
    cout << "Year: " << car1.getYear() << endl;
    cout << "Price: $" << car1.getPrice() << endl;

    return 0;
}
