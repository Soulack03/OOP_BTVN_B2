#include <iostream>
using namespace std;

// The Car class represents a car with a brand and manufacturing year, and provides a method to display this information.
class Car {
 public:
    string brand; // Stores the brand of the car
    int year;     // Stores the manufacturing year of the car
    // Displays the car's brand and year.
    void displayInfo() {
        cout << "Brand: " << brand << endl;
        cout << "Year: " << year << endl;
    }
};

int main() {
    // Create a Car object
    Car car1;
    // Set the car's brand and year
    car1.brand = "Toyota";
    car1.year = 2020;
    // Display the car's information
    car1.displayInfo();
    return 0;
}