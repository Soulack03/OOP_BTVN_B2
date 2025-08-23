#include<bits/stdc++.h>
using namespace std;

// The Person class represents a person with basic information and actions.
class Person{
public :
   string name;        // Stores the person's name
   int age;            // Stores the person's age
   string address;     // Stores the person's address
   string phoneNumber; // Stores the person's phone number

   // Constructor: Initializes a Person object with the given name, age, address, and phone number.
   // Parameters:
   //   name - the person's name
   //   age - the person's age
   //   address - the person's address
   //   phoneNumber - the person's phone number
   Person(string name ,int age,string address,string phoneNumber){
      this->name = name;
      this->age = age; 
      this->address = address;
      this->phoneNumber = phoneNumber;
   }

   // Updates the person's address to a new value and prints the old and new address.
   // Parameters:
   //   newAddress - the new address to update to
   void move(string newAddress){
     cout << "Old address: " << address << endl;
     address = newAddress;
     cout << "After update, " << name << "'s address is now " << address << endl;
   }

   // Displays all information about the person: name, age, address, and phone number.
   void displayInfo(){
      cout << "Name: " << name << endl;
      cout << "Age: " << age << endl;
      cout << "Address: " << address << endl;
      cout << "Phone Number: " << phoneNumber << endl;
   }

   // Checks if the person is an adult (age 18 or older).
   // Returns:
   //   true if the person's age is 18 or older, false otherwise
   bool isAdult(){
     return age >= 18;
   }

   // Prints a greeting message including the person's name.
   void greet(){
    cout << "Hello, my name is " << name << endl;
   }
};

int main(){
    // Create a Person object with sample data
    Person person1("John Doe", 20, "123 Main St", "0923132312");

    // Display the person's information
    person1.displayInfo();

    // Check if the person is an adult and print the result
    if (person1.isAdult()) {
        cout << "This person is an adult." << endl;
    } else {
        cout << "This person is not an adult." << endl;
    }

    // Change the person's address and display the update
    person1.move("Ho Chi Minh");

    // Greet using the person's name
    person1.greet();
}

