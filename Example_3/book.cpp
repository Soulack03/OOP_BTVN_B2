#include <iostream>
using namespace std;

// The Book class represents a book with a title and an author, and provides a method to display this information.
class Book {
 public:
    string title;   // Stores the title of the book
    string author;  // Stores the author of the book

    // Displays the book's title and author.
    void displayInfo() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
    }
};

int main() {
    // Create a Book object
    Book book1;
    // Set the book's title and author
    book1.title = "C++ Programming";
    book1.author = "Bjarne Stroustrup";
    // Display the book's information
    book1.displayInfo();
    return 0;
}