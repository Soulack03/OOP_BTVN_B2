#include<bits/stdc++.h>
using namespace std;

// The Circle class represents a circle with a radius and color, and provides methods for input and calculations.
class Circle {
private:
 double radius; // Stores the radius of the circle
   string color;  // Stores the color of the circle
 public:
   

   // Prompts the user to enter a valid (non-negative) radius for the circle.
   void enter_radius(){
       while(1){
        cout << "Enter the radius : ";
        double rd ; 
        cin >> rd;
        if(rd < 0){
            cout << "Invalid! Negative number is not accepted.\n";
        } else {
         radius = rd;
         break;   
        }
       }
   }

   // Prompts the user to enter the color of the circle.
   void enter_color(){
       string s ; 
       cout << "Enter the color : "; 
       cin >> s; 
       color = s;
   }

   // Calculates and returns the circumference of the circle.
   // Returns: Circumference as a double.
   double circumference() {
       return 2 * M_PI * radius;
   }

   // Calculates and returns the area of the circle.
   // Returns: Area as a double.
   double area() {
       return M_PI * radius * radius;
   }

   // Displays the radius and color of the circle.
   void display_element(){
     cout << "The circle with radius " << radius << " has color " << color << endl; 
   }
};

int main() {
   // Create a Circle object
   Circle circle1;

   // Input radius and color from user
   circle1.enter_radius();
   circle1.enter_color();

   // Display circumference and area
   cout << "Circumference of the circle: " << circle1.circumference() << " units" << endl;
   cout << "Area of the circle: " << circle1.area() << " square units" << endl;

   // Display circle's properties
   circle1.display_element();
   return 0;
 }