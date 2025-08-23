#include <iostream>
using namespace std;

// The Rectangle class represents a rectangle with width and height, and provides a method to calculate its area.
class Rectangle {
 public:
    int width;   // Stores the width of the rectangle
    int height;  // Stores the height of the rectangle

    // Calculates and returns the area of the rectangle.
    // Returns: Area as an integer.
    int calculateArea() {
        return width * height;
    }
};

int main() {
    // Create a Rectangle object
    Rectangle rect1;
    // Set width and height
    rect1.width = 5;
    rect1.height = 10;
    // Display the area of the rectangle
    cout << "Area: " << rect1.calculateArea() << endl;
    return 0;
}