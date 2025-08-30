Full Name : Trần Lê Dũng
MSSV : 24110084
AI assistant : github copilot

Thing it support me : add comment,write document , change the name more readable and some code .

## Vehicle Manager  

🔬 Requirement Analysis

The Vehicle Manager program required a system to manage vehicle data (type, speed, fuel type, invention year, efficiency, cost) using a map for fuel types (e.g., Gasoline: L/100 km). It needed functions to add, sort, display, and modify vehicles via a menu, with preloaded data. I chose a Vehicle class for encapsulation and a vector for storage, optimizing for sorting and updates. 📊

⚙️ Challenges Faced

Validating fuel type inputs against the FuelTypes map was tricky, solved with checks in EnterData. Sorting equal attributes needed a tiebreaker (vehicle type), like scientific taxonomies. Input buffer issues were fixed with cin.ignore(). The ChangeProperty function required careful object reconstruction to update single attributes, mimicking precise data control. 🧬

🔧 OOP’s Scientific Edge

OOP was key! Encapsulation protected data via private members and getters, like controlled variables. The constructor ensured consistent object setup. Abstraction in modular functions (e.g., DisplayInfo) simplified complexity, akin to scientific models. Reusability of the Vehicle class and display logic boosted efficiency. OOP made the code scalable and clear, like a well-designed experiment. 🚀

🌌 Conclusion

Building Vehicle Manager was a scientific blast! 🥳 OOP’s structure ensured robust data management, overcoming input and sorting challenges. The program’s design is ready for future tweaks, like a hypothesis awaiting new tests. I’m thrilled to see where this computational journey goes next! 🌠