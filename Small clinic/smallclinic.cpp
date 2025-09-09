//Name: Trần Lê Dũng 
//ID: 24110084
//Generated with assistance from ChatGPT.
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
class Doctor;
class Appointment;
class Patient;
class ChronicPatient;
class Clinic;

// ==================== Lớp Doctor ====================
// Lớp Doctor dùng để lưu trữ thông tin của bác sĩ trong phòng khám
class Doctor {
private:
    string name;       // Tên bác sĩ
    string ID;         // Mã số định danh của bác sĩ
    string specialty;  // Chuyên khoa của bác sĩ (ví dụ: Nội khoa, Tim mạch)

public:
    // Constructor: khởi tạo đối tượng bác sĩ với tên, ID và chuyên khoa
    Doctor(string _name, string _ID, string _specialty) {
        name = _name;
        ID = _ID;
        specialty = _specialty;
    }

    // Getter: trả về tên bác sĩ
    string getName() { return name; }

    // Getter: trả về mã số bác sĩ
    string getID() { return ID; }

    // Getter: trả về chuyên khoa của bác sĩ
    string getSpecialty() { return specialty; }

    // Setter: cập nhật tên bác sĩ
    void setName(string _name) { name = _name; }

    // Setter: cập nhật mã số bác sĩ
    void setID(string _ID) { ID = _ID; }

    // Setter: cập nhật chuyên khoa bác sĩ
    void setSpecialty(string _specialty) { specialty = _specialty; }

    // Hiển thị thông tin chi tiết của bác sĩ ra màn hình
    void displayInfo() {
        cout << "Doctor's Information:" << endl;
        cout << "Name: " << getName() << endl;
        cout << "ID: " << getID() << endl;
        cout << "Specialty: " << getSpecialty() << endl;
    }
};

// ==================== Lớp Patient ====================
// Lớp Patient dùng để lưu trữ thông tin cá nhân và lịch sử khám bệnh của bệnh nhân
class Patient {
private:
    string name;                   // Tên bệnh nhân
    string ID;                     // Mã số định danh bệnh nhân
    int age;                       // Tuổi bệnh nhân
    vector<string> medicalHistory; // Danh sách các lần khám bệnh (lịch sử)

public:
    // Constructor: khởi tạo đối tượng bệnh nhân với tên, ID và tuổi
    Patient(string _name, string _ID, int _age) {
        name = _name;
        ID = _ID;
        age = _age;
    }

    // Getter: trả về tên bệnh nhân
    string getName() { return name; }

    // Getter: trả về mã số bệnh nhân
    string getID() { return ID; }

    // Getter: trả về tuổi bệnh nhân
    int getAge() { return age; }

    // Setter: cập nhật tên bệnh nhân
    void setName(string _name) { name = _name; }

    // Setter: cập nhật mã số bệnh nhân
    void setID(string _ID) { ID = _ID; }

    // Setter: cập nhật tuổi bệnh nhân
    void setAge(int _age) { age = _age; }

    // Hiển thị thông tin cá nhân của bệnh nhân ra màn hình
    void displayInfo() {
        cout << "Patient's Information:" << endl;
        cout << "Name: " << getName() << endl;
        cout << "ID: " << getID() << endl;
        cout << "Age: " << getAge() << endl;
    }

    // Thêm một bản ghi mới vào lịch sử khám bệnh
    void addHistory(string _history) {
        medicalHistory.push_back(_history);
    }

    // Xóa một bản ghi cụ thể khỏi lịch sử khám bệnh
    void removeHistory(string record) {
        for (auto it = medicalHistory.begin(); it != medicalHistory.end(); ++it) {
            if (*it == record) {
                medicalHistory.erase(it);
                break;
            }
        }
    }

    // Hiển thị toàn bộ lịch sử khám bệnh của bệnh nhân
    void showHistory() {
        cout << "========== Medical history of " << getName() << " (ID: " << getID() << ") ==========" << endl;
        if (medicalHistory.empty())
            cout << "No record found...!" << endl;
        else {
            for (int i = 0; i < medicalHistory.size(); i++)
                cout << "#" << i + 1 << ". " << medicalHistory[i] << endl;
        }
    }

    // Đặt lịch hẹn cho bệnh nhân (cơ bản)
    virtual void scheduleAppointment(string appID, string date, string time, string reason) {
        cout << "Patient " << getName() << " scheduled appointment on " << date << " at " << time << " for " << reason << "." << endl;
        addHistory(date + " - " + time + ": " + reason);
    }

    // Destructor ảo: đảm bảo hủy đúng khi có kế thừa
    virtual ~Patient() {}
};

// ==================== Lớp ChronicPatient ====================
// Lớp ChronicPatient kế thừa từ lớp Patient, dùng để quản lý bệnh nhân có bệnh mãn tính
class ChronicPatient : public Patient {
private:
    string conditionType; // Loại bệnh mãn tính (ví dụ: tiểu đường, cao huyết áp)
    string lastCheckup;   // Ngày khám gần nhất của bệnh nhân

public:
    // Constructor: khởi tạo đối tượng bệnh nhân mãn tính với thông tin cá nhân và bệnh lý
    ChronicPatient(string _name, string _ID, int _age, string _conditionType, string _lastCheckup)
        : Patient(_name, _ID, _age) {
        conditionType = _conditionType;
        lastCheckup = _lastCheckup;
    }

    // Getter: trả về loại bệnh mãn tính
    string getConditionType() { return conditionType; }

    // Getter: trả về ngày khám gần nhất
    string getLastCheckup() { return lastCheckup; }

    // Setter: cập nhật loại bệnh mãn tính
    void setConditionType(string _conditionType) { conditionType = _conditionType; }

    // Setter: cập nhật ngày khám gần nhất
    void setLastCheckup(string _lastCheckup) { lastCheckup = _lastCheckup; }

    // Override hàm đặt lịch hẹn: thêm thông báo và ghi chú dành riêng cho bệnh nhân mãn tính
    void scheduleAppointment(string appID, string date, string time, string reason) override {
        cout << "Chronic patient requires regular check-up...!" << endl;
        cout << "Appointment set on " << date << " at " << time << " for " << reason
             << " (Condition: " << conditionType << ")." << endl;

        // Ghi lại lịch sử khám bệnh kèm ghi chú [Chronic]
        addHistory(date + " - " + time + ": " + reason + " [Chronic]");
    }
};
// ==================== Lớp Appointment ====================
// Lớp Appointment dùng để lưu trữ thông tin chi tiết về một cuộc hẹn giữa bệnh nhân và bác sĩ
class Appointment {
private:
    string appID;     // Mã số định danh của cuộc hẹn
    string date;      // Ngày diễn ra cuộc hẹn (định dạng YYYY-MM-DD)
    string time;      // Giờ diễn ra cuộc hẹn (định dạng HH:MM)
    string reason;    // Lý do khám bệnh (ví dụ: kiểm tra tổng quát, xét nghiệm máu)
    string status;    // Trạng thái của cuộc hẹn (Scheduled / Cancelled / Completed)
    Doctor* doctor;   // Con trỏ đến bác sĩ phụ trách cuộc hẹn
    Patient* patient; // Con trỏ đến bệnh nhân tham gia cuộc hẹn

public:
    // Constructor: khởi tạo một cuộc hẹn với thông tin đầy đủ
    Appointment(string _appID, string _date, string _time, string _reason, string _status, Doctor* _doctor, Patient* _patient) {
        appID = _appID;
        date = _date;
        time = _time;
        reason = _reason;
        doctor = _doctor;
        patient = _patient;
        status = "Scheduled"; // Mặc định trạng thái là đã lên lịch
    }

    // Getter: trả về mã số cuộc hẹn
    string getAppID() { return appID; }

    // Getter: trả về ngày hẹn
    string getDate() { return date; }

    // Getter: trả về giờ hẹn
    string getTime() { return time; }

    // Getter: trả về lý do khám
    string getReason() { return reason; }

    // Getter: trả về trạng thái hiện tại của cuộc hẹn
    string getStatus() { return status; }

    // Getter: trả về con trỏ đến bệnh nhân
    Patient* getPatient() { return patient; }

    // Getter: trả về con trỏ đến bác sĩ
    Doctor* getDoctor() { return doctor; }

    // Setter: cập nhật mã số cuộc hẹn
    void setAppID(string _appID) { appID = _appID; }

    // Setter: cập nhật ngày hẹn
    void setDate(string _date) { date = _date; }

    // Setter: cập nhật giờ hẹn
    void setTime(string _time) { time = _time; }

    // Setter: cập nhật lý do khám
    void setReason(string _reason) { reason = _reason; }

    // Cập nhật trạng thái cuộc hẹn (tùy chọn)
    void updateStatus(string _status) { status = _status; }

    // Đánh dấu cuộc hẹn là đã hủy
    void cancel() { status = "Cancelled"; }

    // Đánh dấu cuộc hẹn là đã hoàn thành
    void complete() { status = "Completed"; }

    // Hiển thị thông tin chi tiết của cuộc hẹn ra màn hình
    void displayInfo() {
        cout << "Appointment " << getAppID() << " on " << getDate() << " at " << getTime() << ":" << endl;
        cout << "Doctor: " << doctor->getName() << endl;
        cout << "Patient: " << patient->getName() << endl;
        cout << "Reason: " << getReason() << endl;
        cout << "[Status: " << getStatus() << "]" << endl;
    }
};

// ==================== Lớp Clinic ====================
// Lớp Clinic dùng để quản lý toàn bộ hệ thống phòng khám, bao gồm:
// - Danh sách bệnh nhân
// - Danh sách bác sĩ
// - Danh sách các cuộc hẹn khám bệnh
class Clinic {
private:
    vector<Patient*> patients;        // Danh sách các bệnh nhân trong phòng khám
    vector<Doctor*> doctors;          // Danh sách các bác sĩ đang làm việc
    vector<Appointment*> appointments;// Danh sách các cuộc hẹn đã được đặt

public:
    // Thêm bệnh nhân mới vào danh sách quản lý
    void addPatient(Patient* _patient) {
        patients.push_back(_patient);
    }

    // Thêm bác sĩ mới vào danh sách quản lý
    void addDoctor(Doctor* _doctor) {
        doctors.push_back(_doctor);
    }

    // Thêm cuộc hẹn mới vào danh sách quản lý
    void addAppointment(Appointment* _appointment) {
        appointments.push_back(_appointment);
    }

    // Hiển thị toàn bộ danh sách các cuộc hẹn đã được đặt
    void displayAppointmentList() {
        cout << endl << "========== Appointments List ==========" << endl;
        for (int i = 0; i < appointments.size(); i++) {
            cout << "#" << i + 1 << ". ";
            appointments[i]->displayInfo();
            cout << endl;
        }
    }

    // Hiển thị toàn bộ danh sách bệnh nhân
    void displayPatientList() {
        cout << endl << "========== Patients List ==========" << endl;
        for (int i = 0; i < patients.size(); i++) {
            cout << "#" << i + 1 << ". ";
            patients[i]->displayInfo();
            cout << endl;
        }
    }

    // Hiển thị toàn bộ danh sách bác sĩ
    void displayDoctorList() {
        cout << endl << "========== Doctors List ==========" << endl;
        for (int i = 0; i < doctors.size(); i++) {
            cout << "#" << i + 1 << ". ";
            doctors[i]->displayInfo();
            cout << endl;
        }
    }

    // Chọn một cuộc hẹn theo số thứ tự (1-based index)
    Appointment* chooseAppointment(int i) {
        if (i < 1 || i > appointments.size()) return nullptr;
        return appointments[i - 1];
    }

    // Chọn một bệnh nhân theo số thứ tự (1-based index)
    Patient* choosePatient(int i) {
        if (i < 1 || i > patients.size()) return nullptr;
        return patients[i - 1];
    }

    // Chọn một bác sĩ theo số thứ tự (1-based index)
    Doctor* chooseDoctor(int i) {
        if (i < 1 || i > doctors.size()) return nullptr;
        return doctors[i - 1];
    }

    // Destructor: giải phóng bộ nhớ đã cấp phát động cho các đối tượng
    ~Clinic() {
        for (int i = 0; i < patients.size(); i++) delete patients[i];
        for (int i = 0; i < doctors.size(); i++) delete doctors[i];
        for (int i = 0; i < appointments.size(); i++) delete appointments[i];
    }
};
int main() {
    // Create a Clinic instance
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

    return 0;
}