#include <iostream>
using namespace std;

// The Car class represents a car with a brand and manufacturing year, and provides a method to display this information.
class Car {
 private:
 string brand; // Stores the brand of the car
 int year;  // Stores the manufacturing year of the car
 public:
     Car(string brand,int year){
        this->brand = brand;
        this->year = year;
     }
    // Displays the car's brand and year.
    void displayInfo() {
        cout << "Brand: " << brand << endl;
        cout << "Year: " << year << endl;
    }
};

int main() {
    // Create a Car object
    Car car1("Toyota",2024);
    // Set the car's brand and year
    
    // Display the car's information
    car1.displayInfo();
    return 0;
}