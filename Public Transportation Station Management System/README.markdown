# Tran Le Dung || ID: 24110084 || Class: 24110FIE3

# Public Transportation System – OOP Assignment

## 📌 Overview

- `PPT.cpp` – A Public Transportation Management System built with Object-Oriented Programming (OOP) in C++.
- The system manages:
  - Vehicles (ExpressBus, Metro, Train, Bike)
  - Stations
  - Routes
  - Passengers (with booking features)
  - Schedules
- Demonstrates encapsulation, inheritance, polymorphism, and abstraction in a real-world transportation scenario.

## ⚙️ Build & Run Instructions

### On Linux / macOS / WSL:

```
g++ PPT.cpp -o ptt
./ptt
```

### On Windows (MinGW g++):

```
g++ PPT.cpp -o ptt.exe
ptt.exe
```

## 🧩 Features

* Add, list, and manage Vehicles with different types.
* Add and display Stations.
* Manage Routes between stations.
* Book tickets for passengers on specific vehicles.
* Prevents booking when a vehicle reaches full capacity.
* View ticket sales and revenue reports.
* Display comprehensive schedules linking vehicles, stations, and times.
* Calculates travel time based on distance and vehicle speed (ExpressBus uses custom speed).
* Menu-driven interface for easy navigation and management.

## 🤖 AI Disclosure

- Author: Tran Le Dung – 24110084
- Used Grok AI (built by xAI) for:
  + Brainstorming inheritance hierarchy (Vehicle → ExpressBus, Metro, Train, Bike).
  + Suggestions for polymorphic display methods and revenue calculation.
  + Guidance on vector-based data management and menu system design.
- All code was implemented, tested, and customized before submission.

## 📝 Reflection

This project provided hands-on experience with OOP principles in designing a comprehensive transportation management system.

* Utilizing a base class `Vehicle` with derived classes (`ExpressBus`, `Metro`, `Train`, `Bike`) reinforced my understanding of inheritance and polymorphism.
* Overriding `calculateTravelTime()` and `displayInfo()` in derived classes showed how to implement specialized behaviors while maintaining a unified interface.
* Managing passenger bookings and revenue tracking highlighted object relationships and encapsulation.
* The modular menu system and global data vectors improved my skills in creating user-friendly, scalable applications.

Challenges included ensuring proper memory management with dynamic vehicle allocation and handling user input validation across menus. Future enhancements could include:

- File I/O for data persistence.
- Advanced scheduling with conflict detection.
- GUI integration for better user experience.
- Multi-route optimization algorithms.

