# Small Clinic Management System – OOP Assignment

## 📌 Overview
- `smallclinic.cpp` – A simple **Clinic Management System** built with **Object-Oriented Programming (OOP) in C++**.  
- The system manages:
  - **Patients** (regular & chronic)  
  - **Doctors**  
  - **Appointments**  
- Demonstrates **classes, objects, inheritance, encapsulation, and polymorphism**.  

---

## ⚙️ Build & Run Instructions

### On Linux / macOS / WSL:
```bash
g++ smallclinic.cpp -o clinic
./clinic
```

### On Windows (MinGW g++):
```bash
g++ smallclinic.cpp -o clinic.exe
clinic.exe
```

---

## 🤖 AI Disclosure
- Author: **Tran Le Dung – 24110084**  
- Leveraged **ChatGPT** to explore and refine design concepts—such as structuring methods for the  class, implementing virtual function overrides, and enhancing overall code clarity.  
- All code has been **understood, tested, and personalized** before submission.  

---



## 🧠 Reflection

During this assignment, I developed a stronger understanding of **Object-Oriented Programming (OOP)** principles, particularly **inheritance** and **polymorphism**. Designing the `Patient` base class and extending it with the `ChronicPatient` subclass helped me see how inheritance reduces code duplication while allowing for customized behavior across different patient types. Implementing **virtual functions** and **method overrides** gave me practical experience applying polymorphism to real-world scenarios.

At the same time, I encountered several challenges. The most difficult part was maintaining synchronization between a patient’s `medicalHistory` and their associated `Appointment` objects. Although I implemented features such as adding, canceling, and completing appointments, the way these updates reflect in the patient’s history still feels incomplete. This highlighted the complexity of keeping data consistent across multiple classes in a real-world management system—an area I aim to improve in future iterations.

---

