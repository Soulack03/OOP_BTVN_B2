### Full Name : Trần Lê Dũng
### MSSV : 24110084
### AI assistant : github copilot

# CarManager Project

## Overview
The CarManager project is a C++ application demonstrating Object-Oriented Programming (OOP) principles to manage a collection of cars. It includes a `Car` class to represent individual vehicles and a `CarManager` class to handle operations like adding, removing, and displaying cars. The code is designed to be clean, readable, and follows CamelCase conventions, with comments mapping to OOP concepts like encapsulation and abstraction.

## Features
- **Add Car**: Add a new car with ID, brand, model, and year.
- **Remove Car**: Remove a car by its ID.
- **Display Cars**: Show details of all cars in the system.
- **OOP Principles**: Implements encapsulation (private attributes, getters), abstraction (simplified method interfaces), and modularity (separated responsibilities).

## Setup Instructions
1. **Prerequisites**: A C++ compiler (e.g., g++).
2. **Clone the Repository**: Download the project files, including `CarManager.cpp`.
3. **Compile the Code**: Run `g++ CarManager.cpp -o CarManager` in your terminal.
4. **Run the Program**: Execute `./CarManager` (Linux/Mac) or `CarManager.exe` (Windows).

## Usage
- The program initializes a `CarManager` object and adds sample cars.
- It demonstrates adding, displaying, and removing cars via a simple console interface.
- Example output:
  ```
  Car added successfully!
  All Cars:
  ID: 1, Brand: Toyota, Model: Camry, Year: 2020
  ID: 2, Brand: Honda, Model: Civic, Year: 2018
  ID: 3, Brand: Ford, Model: Mustang, Year: 2022
  Removing car with ID 2:
  Car with ID 2 removed.
  Updated Car List:
  ID: 1, Brand: Toyota, Model: Camry, Year: 2020
  ID: 3, Brand: Ford, Model: Mustang, Year: 2022
  ```

## Project Structure
- `CarManager.cpp`: Main C++ source file with `Car` and `CarManager` classes.

## Notes
- The code uses the C++ Standard Library (e.g., `vector`, `string`) for simplicity.
- Extend the system by adding features like file I/O or a user interface for enhanced functionality.

## Reflection
Analyzing the requirements for the CarManager project involved understanding the need for a system to manage car records using OOP principles. The goal was to create a `Car` class to represent vehicles and a `CarManager` class to handle operations like adding, removing, and displaying cars. The primary challenge was ensuring clean, readable code while mapping it to OOP concepts like encapsulation and abstraction. Designing the `Car` class required careful selection of attributes (ID, brand, model, year) to reflect real-world entities, while keeping methods simple to abstract complex operations. Managing the car collection in `CarManager` posed a challenge in maintaining data integrity during operations like removal, which I addressed using a vector and iterator-based deletion.

OOP concepts were instrumental in the solution. Encapsulation protected car attributes by making them private and accessible via getters, ensuring data integrity. Abstraction simplified the interface, allowing users to interact with methods like `addCar` or `displayAllCars` without knowing internal details. Modularity was achieved by separating responsibilities between `Car` and `CarManager`, improving code maintainability. Following CamelCase conventions enhanced readability, making the code intuitive. A challenge was ensuring comments clearly linked code to OOP theory without cluttering it, which I resolved by placing concise, targeted comments. Overall, OOP principles provided a structured, scalable approach, making the system easy to extend or modify for future requirements.


