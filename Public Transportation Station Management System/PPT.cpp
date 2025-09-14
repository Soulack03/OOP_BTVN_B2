#include <iostream>
#include <string>
#include <vector>
using namespace std;

// ================= Base Classes =================
class Vehicle {
protected:
    string route;
    int capacity;
    int bookedSeats;
    double ticketPrice;
public:
    Vehicle(string r, int c, double price)
        : route(r), capacity(c), bookedSeats(0), ticketPrice(price) {}
    virtual ~Vehicle() {}

    virtual double calculateTravelTime(double distance) {
        double avgSpeed = 40.0; // default speed
        return distance / avgSpeed;
    }

    virtual void displayInfo() {
        cout << "Route: " << route
             << " | Capacity: " << capacity
             << " | Booked: " << bookedSeats
             << " | Ticket: $" << ticketPrice << endl;
    }

    virtual void displayTickets() {
        cout << "[Tickets] Route: " << route
             << " | Sold: " << bookedSeats
             << " | Remaining: " << (capacity - bookedSeats)
             << " | Capacity: " << capacity
             << " | Revenue: $" << bookedSeats * ticketPrice << endl;
    }

    bool bookTicket() {
        if (bookedSeats < capacity) {
            bookedSeats++;
            cout << "✅ Ticket booked successfully for route " << route << endl;
            return true;
        } else {
            cout << "❌ Vehicle is full! Cannot book ticket.\n";
            return false;
        }
    }

    string getRoute() const { return route; }
    int getRevenue() const { return bookedSeats * ticketPrice; }
};

// ================= Derived Classes =================
class ExpressBus : public Vehicle {
    double speed;
public:
    ExpressBus(string r, int c, double s, double price)
        : Vehicle(r, c, price), speed(s) {}
    double calculateTravelTime(double distance) override {
        return distance / speed;
    }
    void displayInfo() override {
        cout << "[ExpressBus] Route: " << route
             << " | Speed: " << speed
             << " | Capacity: " << capacity
             << " | Booked: " << bookedSeats
             << " | Ticket: $" << ticketPrice << endl;
    }
};

class Metro : public Vehicle {
public:
    Metro(string r, int c, double price) : Vehicle(r, c, price) {}
    void displayInfo() override {
        cout << "[Metro] Route: " << route
             << " | Capacity: " << capacity
             << " | Booked: " << bookedSeats
             << " | Ticket: $" << ticketPrice << endl;
    }
};

class Train : public Vehicle {
public:
    Train(string r, int c, double price) : Vehicle(r, c, price) {}
    void displayInfo() override {
        cout << "[Train] Route: " << route
             << " | Capacity: " << capacity
             << " | Booked: " << bookedSeats
             << " | Ticket: $" << ticketPrice << endl;
    }
};

class Bike : public Vehicle {
public:
    Bike(string r, int c, double price) : Vehicle(r, c, price) {}
    void displayInfo() override {
        cout << "[Bike] Route: " << route
             << " | Capacity: " << capacity
             << " | Booked: " << bookedSeats
             << " | Ticket: $" << ticketPrice << endl;
    }
};

// ================= Station, Route, Passenger, Schedule =================
class Station {
    string name;
    string location;
public:
    Station(string n, string l) : name(n), location(l) {}
    void display() {
        cout << "Station: " << name << " | Location: " << location << endl;
    }
};

class Route {
    string start;
    string end;
public:
    Route(string s, string e) : start(s), end(e) {}
    void display() {
        cout << "Route: " << start << " -> " << end << endl;
    }
};

class Passenger {
    string name;
public:
    Passenger(string n) : name(n) {}
    void display() {
        cout << "Passenger: " << name << endl;
    }
};

class Schedule {
    string vehicleRoute;
    string stationName;
    string time;
public:
    Schedule(string v, string s, string t) : vehicleRoute(v), stationName(s), time(t) {}
    void display() {
        cout << "Schedule | Vehicle Route: " << vehicleRoute
             << " | Station: " << stationName
             << " | Time: " << time << endl;
    }
};

// ================= Global Data =================
vector<Vehicle*> vehicles;
vector<Station> stations;
vector<Route> routes;
vector<Passenger> passengers;
vector<Schedule> schedules;

// ================= Sub-Menus =================
void vehicleMenu() {
    int choice;
    do {
        system("cls"); // clear screen
        cout << "\n===== Vehicle Menu =====\n";
        cout << "1. Add Vehicle\n";
        cout << "2. View All Vehicles\n";
        cout << "3. Display Tickets\n";
        cout << "0. Back\n";
        cout << "Choose: ";
        cin >> choice;

        system("cls");
        if (choice == 1) {
            int type, cap; string route; double price;
            cout << "Enter route name: "; cin >> route;
            cout << "Enter capacity: "; cin >> cap;
            cout << "Enter ticket price: "; cin >> price;
            cout << "Select type (1=Bus, 2=ExpressBus, 3=Metro, 4=Train, 5=Bike): ";
            cin >> type;
            if (type == 1) vehicles.push_back(new Vehicle(route, cap, price));
            else if (type == 2) {
                double speed; cout << "Enter speed: "; cin >> speed;
                vehicles.push_back(new ExpressBus(route, cap, speed, price));
            }
            else if (type == 3) vehicles.push_back(new Metro(route, cap, price));
            else if (type == 4) vehicles.push_back(new Train(route, cap, price));
            else if (type == 5) vehicles.push_back(new Bike(route, cap, price));
            cout << " Vehicle added!\n";
            system("pause");
        }
        else if (choice == 2) {
            cout << "=== Vehicle List ===\n";
            for (auto v : vehicles) v->displayInfo();
            system("pause");
        }
        else if (choice == 3) {
            cout << "=== Ticket Sales Report ===\n";
            for (auto v : vehicles) v->displayTickets();
            system("pause");
        }
    } while (choice != 0);
}

void stationMenu() {
    int choice;
    do {
        system("cls");
        cout << "\n===== Station Menu =====\n";
        cout << "1. Add Station\n";
        cout << "2. View All Stations\n";
        cout << "0. Back\n";
        cout << "Choose: ";
        cin >> choice;

        system("cls");
        if (choice == 1) {
            string n, l;
            cout << "Enter station name: "; cin >> n;
            cout << "Enter location: "; cin >> l;
            stations.emplace_back(n, l);
            cout << "✅ Station added!\n";
            system("pause");
        }
        else if (choice == 2) {
            cout << "=== Station List ===\n";
            for (auto &s : stations) s.display();
            system("pause");
        }
    } while (choice != 0);
}

void routeMenu() {
    int choice;
    do {
        system("cls");
        cout << "\n===== Route Menu =====\n";
        cout << "1. Add Route\n";
        cout << "2. View All Routes\n";
        cout << "0. Back\n";
        cout << "Choose: ";
        cin >> choice;

        system("cls");
        if (choice == 1) {
            string s, e;
            cout << "Enter start: "; cin >> s;
            cout << "Enter end: "; cin >> e;
            routes.emplace_back(s, e);
            cout << "✅ Route added!\n";
            system("pause");
        }
        else if (choice == 2) {
            cout << "=== Route List ===\n";
            for (auto &r : routes) r.display();
            system("pause");
        }
    } while (choice != 0);
}

void passengerMenu() {
    int choice;
    do {
        system("cls");
        cout << "\n===== Passenger Menu =====\n";
        cout << "1. Book Ticket\n";
        cout << "2. View Passengers\n";
        cout << "0. Back\n";
        cout << "Choose: ";
        cin >> choice;

        system("cls");
        if (choice == 1) {
            string pname; int vid;
            cout << "Enter passenger name: "; cin >> pname;
            cout << "Choose vehicle index:\n";
            for (size_t i = 0; i < vehicles.size(); i++) {
                cout << i << ". "; vehicles[i]->displayInfo();
            }
            cin >> vid;
            if (vid >= 0 && vid < (int)vehicles.size()) {
                if (vehicles[vid]->bookTicket())
                    passengers.emplace_back(pname);
            } else cout << "❌ Invalid vehicle index!\n";
            system("pause");
        }
        else if (choice == 2) {
            cout << "=== Passenger List ===\n";
            for (auto &p : passengers) p.display();
            system("pause");
        }
    } while (choice != 0);
}

void scheduleMenu() {
    int choice;
    do {
        system("cls");
        cout << "\n===== Schedule Menu =====\n";
        cout << "1. Add Schedule\n";
        cout << "2. View Schedules\n";
        cout << "0. Back\n";
        cout << "Choose: ";
        cin >> choice;

        system("cls");
        if (choice == 1) {
            string v, s, t;
            cout << "Enter vehicle route: "; cin >> v;
            cout << "Enter station name: "; cin >> s;
            cout << "Enter time: "; cin >> t;
            schedules.emplace_back(v, s, t);
            cout << " Schedule added!\n";
            system("pause");
        }
        else if (choice == 2) {
            cout << "=== Schedule List ===\n";
            for (auto &sc : schedules) sc.display();
            system("pause");
        }
    } while (choice != 0);
}

void revenueReport() {
    system("cls");
    cout << "=== Revenue Report ===\n";
    double total = 0;
    for (auto v : vehicles) {
        v->displayTickets();
        total += v->getRevenue();
    }
    cout << "Total Revenue: $" << total << endl;
    system("pause");
}

// ================= Init Data =================
void initData() {
    vehicles.push_back(new ExpressBus("RouteA", 2, 60, 5.0));
    vehicles.push_back(new Metro("RouteB", 100, 1.5));
    vehicles.push_back(new Train("RouteC", 200, 10.0));
    vehicles.push_back(new Bike("RouteD", 1, 0.5));

    stations.emplace_back("Central", "Downtown");
    stations.emplace_back("North", "Uptown");

    routes.emplace_back("Central", "North");
    routes.emplace_back("North", "Central");

    schedules.emplace_back("RouteA", "Central", "08:00");
    schedules.emplace_back("RouteB", "North", "09:00");
}

// ================= Main Menu =================
int main() {
    initData();
    int choice;
    do {
        system("cls");
        cout << "\n===== Public Transportation System =====\n";
        cout << "1. Vehicle Menu\n";
        cout << "2. Station Menu\n";
        cout << "3. Route Menu\n";
        cout << "4. Passenger Menu\n";
        cout << "5. Schedule Menu\n";
        cout << "6. Revenue Report\n";
        cout << "0. Exit\n";
        cout << "Choose: ";
        cin >> choice;

        if (choice == 1) vehicleMenu();
        else if (choice == 2) stationMenu();
        else if (choice == 3) routeMenu();
        else if (choice == 4) passengerMenu();
        else if (choice == 5) scheduleMenu();
        else if (choice == 6) revenueReport();
    } while (choice != 0);

    for (auto v : vehicles) delete v;
    return 0;
}
