#include <iostream>
using namespace std;

// The Student class represents a student with a name and grade, and provides a method to display this information.
class Student {
 private:
 string name;// Stores the student's name
 double grade;// Stores the student's grade
 public:
    Student(string name, double grade){
        this->name = name;   
        this->grade= grade;
    }  
    // Displays the student's name and grade.
    void displayInfo() {
        cout << "Name: " << name << endl;
        cout << "Grade: " << grade << endl;
    }
};

int main() {
    // Create a Student object
    // Set the student's name and grade
    Student student1("John",8.5);   
    // Display the student's information
    student1.displayInfo();

    return 0;
}