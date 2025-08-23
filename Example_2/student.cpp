#include <iostream>
using namespace std;

// The Student class represents a student with a name and grade, and provides a method to display this information.
class Student {
 public:
    string name;   // Stores the student's name
    double grade;  // Stores the student's grade
    // Displays the student's name and grade.
    void displayInfo() {
        cout << "Name: " << name << endl;
        cout << "Grade: " << grade << endl;
    }
};

int main() {
    // Create a Student object
    Student student1;
    // Set the student's name and grade
    student1.name = "John";
    student1.grade = 8.5;
    // Display the student's information
    student1.displayInfo();

    return 0;
}