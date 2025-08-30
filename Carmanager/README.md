### Full Name : Trần Lê Dũng
### MSSV : 24110084
### AI assistant : github copilot

### Thing it support me : 
- add comment,write document , change the name more readable and some code .

# 🚗 Vehicle Manager: A Scientific Spin 🌟

## 🔬 Requirement Analysis

The Vehicle Manager program demanded a robust system to manage vehicle attributes: type, max speed, fuel type, invention year, fuel efficiency, and cost. A `map` stored fuel types (e.g., Gasoline: L/100 km) for standardized categorization. Key features included adding vehicles, sorting by cost, speed, or efficiency (ascending/descending), displaying details, and modifying properties via an interactive menu. Preloaded data simulated a real-world dataset. I designed a `Vehicle` class for encapsulation and a `vector` for dynamic storage, optimizing for efficient sorting and updates. 📊

## ⚙️ Challenges Faced

Validating fuel type inputs against the `FuelTypes` map was critical to maintain data integrity, addressed with checks in `EnterData`. Sorting equal attributes required a tiebreaker (vehicle type), inspired by scientific classification systems. Mixed input types caused buffer issues, resolved with `cin.ignore()`. The `ChangeProperty` function needed precise object reconstruction to update single attributes without data loss, akin to controlled scientific updates. Each challenge was a mini-experiment solved! 🧬

## 🔧 OOP’s Scientific Edge

OOP powered the program’s structure! **Encapsulation** protected data with private members and getters, like controlled variables. The **constructor** ensured consistent object setup. **Abstraction** in functions like `DisplayInfo` simplified complexity, mirroring scientific models. **Reusability** of the `Vehicle` class and display logic boosted efficiency. OOP made the code scalable and clear, like a well-designed scientific system ready for future iterations. 🚀

## 🖥️ How to Run the Program

To run the Vehicle Manager program, follow these steps:

1. **Save the Code**: Save the C++ code in a file named `Realproblem.cpp`.
2. **Compile**: Use a C++ compiler (e.g., g++) with C++11 or later. Run:

   ```bash
   g++ -std=c++11 Realproblem.cpp -o Realproblem
   ```
3. **Execute**: Run the compiled program:

   ```bash
   ./Realproblem
   ```
4. **Interact**: Use the menu to add, sort, display, or modify vehicles. Select option `0` to exit. Ensure your terminal supports standard I/O. 🖱️
