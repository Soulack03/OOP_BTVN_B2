# E-Commerce Product Management System

## 📌 Overview
This project is a **C++ console-based e-commerce simulation** that demonstrates key Object-Oriented Programming (OOP) concepts.  
It allows creation of products, management of shopping carts, applying discounts, and placing/canceling orders.  

The project was developed as part of coursework to illustrate:
- **Inheritance**
- **Interfaces (abstract classes)**
- **Operator overloading**
- **Template classes**
- **Polymorphism and virtual functions**

---

## ✨ Features
- **Product Management**
  - Create generic products and specialized electronics.
  - Update stock levels with validation.
- **Shopping Cart**
  - Add and remove products using overloaded operators.
  - Apply discounts to the cart total.
  - Display and clear cart contents.
- **Orders**
  - Generate orders from carts.
  - Track order ID, date, and status (pending, processed, canceled).
- **Template Class (InventoryList<T>)**
  - Manage generic collections of products or categories.
  - Supports add, remove, search, display, and operator `[]`.

---

## ⚙️ Compilation and Execution
### Requirements
- C++17 or later
- g++ compiler

### Compile
```bash
g++ -std=c++17 -O2 E_commerce.cpp -o ecommerce
