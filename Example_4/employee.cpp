#include <iostream>
using namespace std;

// The Employee class represents an employee with a name and salary, and provides a method to display this information.
class Employee {
 private:
     string name;    // Stores the employee's name
    double salary;  // Stores the employee's salary

 public:
    Employee(string name ,double salary){
        this->name=name ;
        this-> salary=salary;
    }
    // Displays the employee's name and salary.
    void displayInfo() {
        cout << "Name: " << name << endl;
        cout << "Salary: " << salary << endl;
    }
};

int main() {
    // Create an Employee object
    Employee employee1("Alice",50000);
    // Display the employee's information
    employee1.displayInfo();

    return 0;
}