#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Mapping fuel types: ID -> (Name, Unit)
map<int, pair<string, string>> FuelTypes{
    {1, {"Gasoline", "L/100 km"}},
    {2, {"Diesel", "L/100 km"}},
    {3, {"Electricity", "kWh/100 km"}},
    {4, {"Jet Fuel", "L/100 km/seat"}},
    {5, {"Hydrogen", "kg/100 km"}},
    {6, {"Biofuel", "L/100 km"}},
    {7, {"Not use energy", "as far as you can"}}
};

// ================== CLASS DEFINITION ==================
class Vehicle {
 private:
   string type;              // Vehicle type (e.g., Car, Jet, Bus)
   double maxSpeed;          // Maximum speed (km/h)
   int fuelType;             // Fuel type ID (refers to FuelTypes)
   string inventionYear;     // Year of invention
   double fuelEfficiency;    // Fuel efficiency
   double averageCost;       // Average cost in USD

 public:
   // Getters
   string GetType()  { return type; }
   double GetMaxSpeed()  { return maxSpeed; }
   int GetFuelType()  { return fuelType; }
   string GetInventionYear()  { return inventionYear; }
   double GetFuelEfficiency()  { return fuelEfficiency; }
   double GetAverageCost()  { return averageCost; }
   
   // Constructor
   Vehicle(string type, double maxSpeed, int fuelType, string inventionYear,
           double fuelEfficiency , double averageCost ) {
       this->type = type;
       this->maxSpeed = maxSpeed;
       this->fuelType = fuelType;
       this->inventionYear = inventionYear;
       this->fuelEfficiency = fuelEfficiency;
       this->averageCost = averageCost;
   }

   // Display vehicle info
   void DisplayInfo(){
       cout << "Type: " << type << endl;
       cout << "+ Max Speed: " << maxSpeed << " km/h" << endl;
       cout << "+ Time of Invention: " << inventionYear << endl;
       cout << "+ Fuel used for : " << FuelTypes[fuelType].first << endl;
       cout << "+ Fuel Efficiency: " << fuelEfficiency << " " << FuelTypes[fuelType].second << endl;
       cout << "+ Average cost : " << averageCost << "$" << endl;
   }

   // Simulate behaviors
   void DisplayBehaviors(){
     cout << "Accelerating to " << maxSpeed << " km/h" << endl;
     cout << "Fuel Used : " << fuelType << endl;
   }
};

// ================== GLOBAL VARIABLES ==================
vector<Vehicle> vehicleList;

// ================== INPUT DATA ==================
Vehicle EnterData(){
    string type;
    double maxSpeed;
    ll fuelType;
    string inventionYear;
    double fuelEfficiency;
    double averageCost;

    cin.ignore(); // Ignore leftover newline
    cout << "Enter vehicle type: ";
    getline(cin, type);

    cout << "Enter max speed (km/h): ";
    cin >> maxSpeed;
    cin.ignore();

    cout << "Option fuel is releasing in our page :" << endl;
    for(auto x : FuelTypes){
      cout << x.first << " : " << x.second.first << endl;
    }
    cin >> fuelType;
    cin.ignore();

    cout << "Enter time of invention: ";
    getline(cin, inventionYear);

    cout << "Enter fuel efficiency: ";
    cin >> fuelEfficiency;
    cin.ignore();

    cout << "Enter average cost: ";
    cin >> averageCost;

    Vehicle tmp(type, maxSpeed, fuelType, inventionYear, fuelEfficiency, averageCost);
    return tmp;
}

// ================== SORT FUNCTIONS ==================

// Sort by average cost ascending
bool AscOrderByAverageCost(Vehicle a,Vehicle b){
   if(a.GetAverageCost() != b.GetAverageCost()) return a.GetAverageCost() < b.GetAverageCost();
   return a.GetType() < b.GetType();
}

// Sort by average cost descending
bool DescOrderByAverageCost(Vehicle a, Vehicle b) {
    if(a.GetAverageCost() != b.GetAverageCost()) return a.GetAverageCost() > b.GetAverageCost();
    return a.GetType() < b.GetType();
}

// Sort by fuel efficiency ascending
bool AscOrderByFuelEfficiency(Vehicle a, Vehicle b) {
    if (a.GetFuelEfficiency() != b.GetFuelEfficiency())
        return a.GetFuelEfficiency() < b.GetFuelEfficiency();
    return a.GetType() < b.GetType();
}

// Sort by fuel efficiency descending
bool DescOrderByFuelEfficiency(Vehicle a, Vehicle b) {
    if (a.GetFuelEfficiency() != b.GetFuelEfficiency())
        return a.GetFuelEfficiency() > b.GetFuelEfficiency();
    return a.GetType() < b.GetType();
}

// Sort by max speed ascending
bool AscOrderByMaxSpeed(Vehicle a, Vehicle b) {
    if (a.GetMaxSpeed() != b.GetMaxSpeed())
        return a.GetMaxSpeed() < b.GetMaxSpeed();
    return a.GetType() < b.GetType();
}

// Sort by max speed descending
bool DescOrderByMaxSpeed(Vehicle a, Vehicle b) {
    if (a.GetMaxSpeed() != b.GetMaxSpeed())
        return a.GetMaxSpeed() > b.GetMaxSpeed();
    return a.GetType() < b.GetType();
}

// ================== DISPLAY FUNCTIONS ==================

// Display sorted by average cost ascending
void DisplayByAverageCostAsc(){
  sort(vehicleList.begin(), vehicleList.end(), AscOrderByAverageCost);
  int i = 1; 
  for(auto x : vehicleList){
    cout<< i<< " . ";
    x.DisplayInfo();
    i++;
  }
  cout<<"Finish !";
}

// Display sorted by average cost descending
void DisplayByAverageCostDesc(){
  sort(vehicleList.begin(), vehicleList.end(), DescOrderByAverageCost);
  int i = 1; 
  for(auto x : vehicleList){
    cout<< i<< " . ";
    x.DisplayInfo();
    i++;
  }
  cout<<"Finish !";
}

// Display sorted by fuel efficiency ascending
void DisplayByFuelEfficiencyAsc() {
    sort(vehicleList.begin(), vehicleList.end(), AscOrderByFuelEfficiency);
    int i = 1;
    for (auto x : vehicleList) {
        cout << i << " . ";
        x.DisplayInfo();
        i++;
    }
    cout << "Finish !" << endl;
}

// Display sorted by fuel efficiency descending
void DisplayByFuelEfficiencyDesc() {
    sort(vehicleList.begin(), vehicleList.end(), DescOrderByFuelEfficiency);
    int i = 1;
    for (auto x : vehicleList) {
        cout << i << " . ";
        x.DisplayInfo();
        i++;
    }
    cout << "Finish !" << endl;
}

// Display sorted by max speed ascending
void DisplayByMaxSpeedAsc() {
    sort(vehicleList.begin(), vehicleList.end(), AscOrderByMaxSpeed);
    int i = 1;
    for (auto x : vehicleList) {
        cout << i << " . ";
        x.DisplayInfo();
        i++;
    }
    cout << "Finish !" << endl;
}

// Display sorted by max speed descending
void DisplayByMaxSpeedDesc() {
    sort(vehicleList.begin(), vehicleList.end(), DescOrderByMaxSpeed);
    int i = 1;
    for (auto x : vehicleList) {
        cout << i << " . ";
        x.DisplayInfo();
        i++;
    }
    cout << "Finish !" << endl;
}

// ================== DATA MANAGEMENT ==================

// Enter multiple vehicles
void AddVehicles(){
    int n ;
    cout << "The amount of vehicles you want to add? ";
    cin >> n;

   if(n <= 0){
    cout << "Please enter a valid number!" << endl;
    return;
   } 
 
   while(n--){
     vehicleList.push_back(EnterData());
   }
   cout << "Complete !" << endl;
}

// Change property of an existing vehicle
void ChangeProperty() {
    if (vehicleList.empty()) {
        cout << "No vehicles to change.\n";
        return;
    }
    cout << "This is our vehicle list now:\n";
    DisplayByFuelEfficiencyAsc();
    cout << "Enter the vehicle number you want to change: ";
    int i;
    cin >> i;
    if (i < 1 || i > vehicleList.size()) {
        cout << "Invalid index!\n";
        return;
    }

    Vehicle veh = vehicleList[i - 1]; // Get selected vehicle

    cout << "Which property do you want to change?\n";
    cout << "1. Type\n";
    cout << "2. Max Speed\n";
    cout << "3. Fuel Type\n";
    cout << "4. Time of Invention\n";
    cout << "5. Fuel Efficiency\n";
    cout << "6. Average Cost\n";
    cout << "Enter option: ";
    int opt;
    cin >> opt;
    cin.ignore();

    switch (opt) {
        case 1: {
            cout << "Enter new Type: ";
            string newType;
            getline(cin, newType);
            veh = Vehicle(newType, veh.GetMaxSpeed(), veh.GetFuelType(), veh.GetInventionYear(), veh.GetFuelEfficiency(), veh.GetAverageCost());
            break;
        }
        case 2: {
            cout << "Enter new Max Speed: ";
            double newSpeed;
            cin >> newSpeed;
            veh = Vehicle(veh.GetType(), newSpeed, veh.GetFuelType(), veh.GetInventionYear(), veh.GetFuelEfficiency(), veh.GetAverageCost());
            break;
        }
        case 3: {
            cout << "Option fuel is releasing in our page:\n";
            for (auto x : FuelTypes) {
                cout << x.first << " : " << x.second.first << endl;
            }
            cout << "Enter new Fuel Type: ";
            int newFuel;
            cin >> newFuel;
            veh = Vehicle(veh.GetType(), veh.GetMaxSpeed(), newFuel, veh.GetInventionYear(), veh.GetFuelEfficiency(), veh.GetAverageCost());
            break;
        }
        case 4: {
            cout << "Enter new Time of Invention: ";
            string newTime;
            cin.ignore();
            getline(cin, newTime);
            veh = Vehicle(veh.GetType(), veh.GetMaxSpeed(), veh.GetFuelType(), newTime, veh.GetFuelEfficiency(), veh.GetAverageCost());
            break;
        }
        case 5: {
            cout << "Enter new Fuel Efficiency: ";
            double newEff;
            cin >> newEff;
            veh = Vehicle(veh.GetType(), veh.GetMaxSpeed(), veh.GetFuelType(), veh.GetInventionYear(), newEff, veh.GetAverageCost());
            break;
        }
        case 6: {
            cout << "Enter new Average Cost: ";
            double newCost;
            cin >> newCost;
            veh = Vehicle(veh.GetType(), veh.GetMaxSpeed(), veh.GetFuelType(), veh.GetInventionYear(), veh.GetFuelEfficiency(), newCost);
            break;
        }
        default:
            cout << "Invalid option!\n";
            break;
    }
    cout << "Property updated!\n";
}

// ================== MENU ==================
void Menu() {
    cout << "========= VEHICLE MANAGER =========" << endl;
    cout << "1 : Import data to program" << endl;
    cout << "2 : ASC display vehicles by average cost" << endl;
    cout << "3 : DESC display vehicles by average cost" << endl;
    cout << "4 : ASC display vehicles by fuel efficiency" << endl;
    cout << "5 : DESC display vehicles by fuel efficiency" << endl;
    cout << "6 : ASC display vehicles by max speed" << endl;
    cout << "7 : DESC display vehicles by max speed" << endl;
    cout << "8 : Change property of a vehicle" << endl;
    cout << "0 : Exit" << endl;
    cout << "===================================" << endl;
    cout << "Enter your option: ";
}

// ================== INIT DATA ==================
void InitData() {
    vehicleList.push_back(Vehicle("Car", 180, 1, "1886", 7.5, 25000));
    vehicleList.push_back(Vehicle("Motorbike", 120, 1, "1885", 3.2, 1500));
    vehicleList.push_back(Vehicle("Electric Car", 160, 3, "1996", 15.0, 35000));
    vehicleList.push_back(Vehicle("Jet", 900, 4, "1939", 3.5, 1000000));
    vehicleList.push_back(Vehicle("Hydrogen Bus", 100, 5, "2003", 8.0, 60000));
}

// ================== MAIN ==================
int main() {
    InitData();
    cout << "Welcome to Vehicle Manager created by Soulack" << endl;
    cout << "=======> Have a good day <3 <========="<<endl;
    while (1) {
        Menu();

        bool keepRunning = true;
        int option;
        cin >> option;
        switch (option)
        {
        case 1:
            AddVehicles();
            break;
        case 2:
            cout << "ASC display vehicle follow AVG cost : " << endl;
            DisplayByAverageCostAsc();
            break;
        case 3:
            cout << "DESC display vehicle follow AVG cost : " << endl;
            DisplayByAverageCostDesc();
            break;
        case 4:
            cout << "ASC display vehicle follow fuel efficiency : " << endl;
            DisplayByFuelEfficiencyAsc();
            break;
        case 5:
            cout << "DESC display vehicle follow fuel efficiency : " << endl;
            DisplayByFuelEfficiencyDesc();
            break;
        case 6:
            cout << "ASC display vehicle follow max speed : " << endl;
            DisplayByMaxSpeedAsc();
            break;
        case 7:
            cout << "DESC display vehicle follow max speed : " << endl;
            DisplayByMaxSpeedDesc();
            break;
        case 8:
            ChangeProperty();
            break;
        case 0:
            keepRunning = false;
            break;
        default:
            cout << "Invalid option! Please try again." << endl;
            break;
        }
        if (!keepRunning) {
            cout << "Thank you for your experience <3";
            break;
        }
        system("pause");
        system("cls");
    }
}
