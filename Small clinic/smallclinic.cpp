#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class Doctor;
class Appointment;
class Patient;
class ChronicPatient;
class Clinic;

// ==================== Lớp Doctor ====================
class Doctor {
private:
    string name;
    string ID;
    string specialty;
public:
    Doctor(string _name, string _ID, string _specialty) {
        name = _name; ID = _ID; specialty = _specialty;
    }
    string getName() { return name; }
    string getID() { return ID; }
    string getSpecialty() { return specialty; }
    void setName(string _name) { name = _name; }
    void setID(string _ID) { ID = _ID; }
    void setSpecialty(string _specialty) { specialty = _specialty; }
    void displayInfo() {
        cout << "Doctor's Information:\n";
        cout << "Name: " << getName() << "\nID: " << getID() << "\nSpecialty: " << getSpecialty() << "\n";
    }
};

// ==================== Lớp Patient ====================
class Patient {
private:
    string name;
    string ID;
    int age;
    vector<string> medicalHistory;
public:
    Patient(string _name, string _ID, int _age) {
        name = _name; ID = _ID; age = _age;
    }
    string getName() { return name; }
    string getID() { return ID; }
    int getAge() { return age; }
    void setName(string _name) { name = _name; }
    void setID(string _ID) { ID = _ID; }
    void setAge(int _age) { age = _age; }
    void displayInfo() {
        cout << "Patient's Information:\n";
        cout << "Name: " << getName() << "\nID: " << getID() << "\nAge: " << getAge() << "\n";
    }
    void addHistory(string _history) { medicalHistory.push_back(_history); }
    void removeHistory(string record) {
        for (auto it = medicalHistory.begin(); it != medicalHistory.end(); ++it) {
            if (*it == record) { medicalHistory.erase(it); break; }
        }
    }
    void showHistory() {
        cout << "========== Medical history of " << getName() << " (ID: " << getID() << ") ==========\n";
        if (medicalHistory.empty()) cout << "No record found...!\n";
        else {
            for (size_t i = 0; i < medicalHistory.size(); ++i)
                cout << "#" << i+1 << ". " << medicalHistory[i] << "\n";
        }
    }
    virtual void scheduleAppointment(string appID, string date, string time, string reason) {
        cout << "Patient " << getName() << " scheduled appointment on " << date << " at " << time << " for " << reason << ".\n";
        addHistory(date + " - " + time + ": " + reason);
    }
    virtual ~Patient() {}
};

// ==================== Lớp ChronicPatient ====================
class ChronicPatient : public Patient {
private:
    string conditionType;
    string lastCheckup;
public:
    ChronicPatient(string _name, string _ID, int _age, string _conditionType, string _lastCheckup)
    : Patient(_name, _ID, _age), conditionType(_conditionType), lastCheckup(_lastCheckup) {}
    string getConditionType() { return conditionType; }
    string getLastCheckup() { return lastCheckup; }
    void setConditionType(string _conditionType) { conditionType = _conditionType; }
    void setLastCheckup(string _lastCheckup) { lastCheckup = _lastCheckup; }
    void scheduleAppointment(string appID, string date, string time, string reason) override {
        cout << "Chronic patient requires regular check-up...!\n";
        cout << "Appointment set on " << date << " at " << time << " for " << reason
             << " (Condition: " << conditionType << ").\n";
        addHistory(date + " - " + time + ": " + reason + " [Chronic]");
    }
};

// ==================== Lớp Appointment ====================
class Appointment {
private:
    string appID, date, time, reason, status;
    Doctor* doctor;
    Patient* patient;
public:
    Appointment(string _appID, string _date, string _time, string _reason, string _status, Doctor* _doctor, Patient* _patient) {
        appID = _appID; date = _date; time = _time; reason = _reason; doctor = _doctor; patient = _patient;
        status = _status;
    }
    string getAppID() { return appID; }
    string getDate() { return date; }
    string getTime() { return time; }
    string getReason() { return reason; }
    string getStatus() { return status; }
    Patient* getPatient() { return patient; }
    Doctor* getDoctor() { return doctor; }
    void setAppID(string _appID) { appID = _appID; }
    void setDate(string _date) { date = _date; }
    void setTime(string _time) { time = _time; }
    void setReason(string _reason) { reason = _reason; }
    void updateStatus(string _status) { status = _status; }
    void cancel() { status = "Cancelled"; }
    void complete() { status = "Completed"; }
    void displayInfo() {
        cout << "Appointment " << getAppID() << " on " << getDate() << " at " << getTime() << ":\n";
        cout << "Doctor: " << doctor->getName() << "\nPatient: " << patient->getName() << "\nReason: " << getReason() << "\n";
        cout << "[Status: " << getStatus() << "]\n";
    }
};

// ==================== Lớp Clinic ====================
class Clinic {
private:
    vector<Patient*> patients;
    vector<Doctor*> doctors;
    vector<Appointment*> appointments;
public:
    void addPatient(Patient* _patient) { patients.push_back(_patient); }
    void addDoctor(Doctor* _doctor) { doctors.push_back(_doctor); }
    void addAppointment(Appointment* _appointment) { appointments.push_back(_appointment); }
    void displayAppointmentList() {
        cout << "\n========== Appointments List ==========\n";
        for (size_t i = 0; i < appointments.size(); ++i) {
            cout << "#" << i+1 << ". ";
            appointments[i]->displayInfo();
            cout << "\n";
        }
    }
    void displayPatientList() {
        cout << "\n========== Patients List ==========\n";
        for (size_t i = 0; i < patients.size(); ++i) {
            cout << "#" << i+1 << ". ";
            patients[i]->displayInfo();
            cout << "\n";
        }
    }
    void displayDoctorList() {
        cout << "\n========== Doctors List ==========\n";
        for (size_t i = 0; i < doctors.size(); ++i) {
            cout << "#" << i+1 << ". ";
            doctors[i]->displayInfo();
            cout << "\n";
        }
    }
    Appointment* chooseAppointment(int i) {
        if (i < 1 || i > (int)appointments.size()) return nullptr;
        return appointments[i-1];
    }
    Patient* choosePatient(int i) {
        if (i < 1 || i > (int)patients.size()) return nullptr;
        return patients[i-1];
    }
    Doctor* chooseDoctor(int i) {
        if (i < 1 || i > (int)doctors.size()) return nullptr;
        return doctors[i-1];
    }
    ~Clinic() {
        for (auto p: patients) delete p;
        for (auto d: doctors) delete d;
        for (auto a: appointments) delete a;
    }
}

// Note: Semicolon after class Clinic is required
;

// ==================== Lớp Medicine ====================
class Medicine {
private:
    string name;
    string dosage;
    double price; // price per unit
public:
    Medicine(string _name, string _dosage, double _price) {
        name = _name; dosage = _dosage; price = _price;
    }
    string getName() { return name; }
    string getDosage() { return dosage; }
    double getPrice() { return price; }
    void setName(string _name) { name = _name; }
    void setDosage(string _dosage) { dosage = _dosage; }
    void setPrice(double _price) { price = _price; }
    void displayInfo() {
        cout << "- Medicine: " << name << " | Dosage: " << dosage << " | Price: " << price << " VND\n";
    }
};

// ==================== Lớp PrescribedMedicine ====================
class PrescribedMedicine {
private:
    Medicine* med;
    int quantity;
public:
    PrescribedMedicine(Medicine* _med, int _quantity) {
        med = _med; quantity = _quantity;
    }
    Medicine* getMedicine() { return med; }
    int getQuantity() { return quantity; }
    double getTotalPrice() { return med->getPrice() * quantity; }
    void displayInfo() {
        cout << "- " << med->getName() << " | Dosage: " << med->getDosage()
             << " | Unit Price: " << med->getPrice() << " VND | Quantity: " << quantity
             << " | Total: " << getTotalPrice() << " VND\n";
    }
};

// ==================== Lớp Prescription ====================
class Prescription {
private:
    string presID;
    Doctor* doctor;
    Patient* patient;
    vector<PrescribedMedicine*> meds;
    double totalCost;
public:
    Prescription(string _presID, Doctor* _doctor, Patient* _patient) {
        presID = _presID; doctor = _doctor; patient = _patient; totalCost = 0.0;
    }

    // Kiểm tra thuốc đã có trong đơn chưa (theo tên)
    bool hasMedicine(const string& medName) {
        for (auto pm : meds) {
            if (pm->getMedicine()->getName() == medName) return true;
        }
        return false;
    }

    // Thêm thuốc: nếu thuốc đã tồn tại -> từ chối (không duplicate)
    // Nếu không tồn tại -> thêm (Prescription sở hữu đối tượng Medicine)
    void addMedicine(Medicine* med, int quantity) {
        if (hasMedicine(med->getName())) {
            cout << "Error: Medicine '" << med->getName() << "' already exists in prescription!\n";
            delete med; // tránh leak vì caller dùng new
            return;
        }
        PrescribedMedicine* pm = new PrescribedMedicine(med, quantity);
        meds.push_back(pm);
        totalCost += pm->getTotalPrice();
        cout << "Medicine '" << med->getName() << "' added successfully.\n";
    }

    // Xóa thuốc theo tên (nếu cần)
    bool removeMedicine(const string& medName) {
        for (auto it = meds.begin(); it != meds.end(); ++it) {
            if ((*it)->getMedicine()->getName() == medName) {
                totalCost -= (*it)->getTotalPrice();
                delete (*it)->getMedicine();
                delete *it;
                meds.erase(it);
                return true;
            }
        }
        return false;
    }

    void displayInfo() {
        cout << "\n========== Prescription " << presID << " ==========\n";
        cout << "Doctor: " << doctor->getName() << "\nPatient: " << patient->getName() << "\n";
        cout << "Medicines List:\n";
        if (meds.empty()) cout << "(No medicines)\n";
        else {
            for (auto pm : meds) pm->displayInfo();
        }
        cout << "Total Cost: " << totalCost << " VND\n";
    }

    ~Prescription() {
        for (auto pm : meds) {
            delete pm->getMedicine();
            delete pm;
        }
    }
};

// ==================== main() ====================
int main() {
    Clinic clinic;

    // Test Case 1: Adding Doctors
    cout << "=== Test Case 1: Adding Doctors ===" << endl;
    Doctor* doc1 = new Doctor("Dr. Smith", "D001", "Cardiology");
    Doctor* doc2 = new Doctor("Dr. Johnson", "D002", "Neurology");
    clinic.addDoctor(doc1);
    clinic.addDoctor(doc2);
    clinic.displayDoctorList();

    // Test Case 2: Adding Patients (Regular and Chronic)
    cout << "\n=== Test Case 2: Adding Patients ===" << endl;
    Patient* pat1 = new Patient("John Doe", "P001", 30);
    ChronicPatient* pat2 = new ChronicPatient("Jane Smith", "P002", 45, "Diabetes", "2025-08-01");
    clinic.addPatient(pat1);
    clinic.addPatient(pat2);
    clinic.displayPatientList();

    // Test Case 3: Scheduling Appointments
    cout << "\n=== Test Case 3: Scheduling Appointments ===" << endl;
    Appointment* app1 = new Appointment("A001", "2025-09-10", "10:00", "Chest pain", "Scheduled", doc1, pat1);
    Appointment* app2 = new Appointment("A002", "2025-09-11", "14:00", "Regular check-up", "Scheduled", doc2, pat2);
    clinic.addAppointment(app1);
    clinic.addAppointment(app2);
    clinic.displayAppointmentList();

    // Test Case 4: Adding Medical History
    cout << "\n=== Test Case 4: Adding Medical History ===" << endl;
    pat1->addHistory("2025-09-01 - Diagnosed with hypertension");
    pat2->addHistory("2025-08-01 - Blood sugar test");
    pat1->showHistory();
    pat2->showHistory();

    // Test Case 5: Scheduling Appointment via Patient
    cout << "\n=== Test Case 5: Scheduling Appointment via Patient ===" << endl;
    pat1->scheduleAppointment("A003", "2025-09-12", "09:00", "Follow-up");
    pat2->scheduleAppointment("A004", "2025-09-13", "11:00", "Blood test");

    // Test Case 6: Updating Appointment Status
    cout << "\n=== Test Case 6: Updating Appointment Status ===" << endl;
    Appointment* selectedApp = clinic.chooseAppointment(1);
    if (selectedApp) {
        selectedApp->complete();
        selectedApp->displayInfo();
    }

    // Test Case 7: Cancelling Appointment
    cout << "\n=== Test Case 7: Cancelling Appointment ===" << endl;
    selectedApp = clinic.chooseAppointment(2);
    if (selectedApp) {
        selectedApp->cancel();
        selectedApp->displayInfo();
    }

    // Test Case 8: Removing Medical History
    cout << "\n=== Test Case 8: Removing Medical History ===" << endl;
    pat1->removeHistory("2025-09-01 - Diagnosed with hypertension");
    pat1->showHistory();

    // Test Case 9: Selecting Doctor and Patient
    cout << "\n=== Test Case 9: Selecting Doctor and Patient ===" << endl;
    Doctor* selectedDoc = clinic.chooseDoctor(1);
    if (selectedDoc) {
        cout << "Selected Doctor: " << selectedDoc->getName() << endl;
    }
    Patient* selectedPat = clinic.choosePatient(2);
    if (selectedPat) {
        cout << "Selected Patient: " << selectedPat->getName() << endl;
    }

    // Test Case 10: Display Final State
    cout << "\n=== Test Case 10: Final State ===" << endl;
    clinic.displayDoctorList();
    clinic.displayPatientList();
    clinic.displayAppointmentList();


    // ==================== Test Case 11: Prescription & Medicines ====================
    cout << "\n=== Test Case 11: Prescription & Medicines ===\n";
    Prescription* pres = new Prescription("PR001", doc1, pat1);
    pres->addMedicine(new Medicine("Paracetamol", "500mg x 2/day", 20000), 10); // 10 units
    pres->addMedicine(new Medicine("Amoxicillin", "250mg x 3/day", 50000), 5); // 5 units
    // Thử thêm trùng (sẽ bị từ chối)
    pres->addMedicine(new Medicine("Paracetamol", "500mg x 2/day", 20000), 2);
    pres->displayInfo();

    cout << "\nCheck medicine existence:\n";
    cout << "Paracetamol? " << (pres->hasMedicine("Paracetamol") ? "Yes" : "No") << "\n";
    cout << "Ibuprofen? " << (pres->hasMedicine("Ibuprofen") ? "Yes" : "No") << "\n";

    // Thử remove
    cout << "\nRemove Amoxicillin: " << (pres->removeMedicine("Amoxicillin") ? "Removed" : "Not found") << "\n";
    pres->displayInfo();

    delete pres;

    // Clinic destructor sẽ giải phóng doctors/patients/appointments
    return 0;
}
