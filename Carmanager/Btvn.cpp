#include<bits/stdc++.h>
using namespace std;

map<int, pair<string, string>> fuelSave{
    {1, {"Gasoline", "L/100 km"}},
    {2, {"Diesel", "L/100 km"}},
    {3, {"Electricity", "kWh/100 km"}},
    {4, {"Jet fuel", "L/100 km/seat"}},
    {5, {"Hydrogen", "kg/100 km"}},
    {6, {"Biofuel", "L/100 km"}},
    {7, {"Not use energy", "as far as you can"}}
};

class vehicle {
 private:
   string  Type;
   double maxSpeed;
   int fuelType;
   string timeInvention;
   double fuelEfficiency;
   double avgCost;    

 public:
   string getType() const { return Type; }
   double getMaxSpeed() const { return maxSpeed; }
   int getFuelType() const { return fuelType; }
   string getTimeInvention() const { return timeInvention; }
   double getFuelEfficiency() const { return fuelEfficiency; }
   double getAvgCost() const { return avgCost; }
   
   vehicle(string Type, double maxSpeed, int fuelType, string timeInvention, double fuelEfficiency , double avgCost ) {
       this->Type = Type;
       this->maxSpeed = maxSpeed;
       this->fuelType = fuelType;
       this->timeInvention = timeInvention;
       this->fuelEfficiency = fuelEfficiency;
       this->avgCost = avgCost;
   }
   void displayInfo(){
       cout << "Type: " << Type << endl;
       cout << "+ Max Speed: " << maxSpeed << " km/h" << endl;
       cout << "+ Time of Invention: " << timeInvention << endl;
       cout << "+ Fuel used for : " << fuelSave[fuelType].first << endl;
       cout << "+ Fuel Efficiency: " << fuelEfficiency << " " << fuelSave[fuelType].second << endl;
       cout << "+ Average cost : " << avgCost << endl;
   }
   void displayBehaviors(){
     cout << "Accelerating to " << maxSpeed << " km/h" << endl;
     cout << "fuelUse : " << fuelType << endl;
   }
};

vector<vehicle> v;

vehicle enter_data(){
    string Type;
    double maxSpeed;
    int fuelType;
    string timeInvention;
    double fuelEfficiency;
    double avgCost;

    cin.ignore(); // Ignore leftover newline before first getline
    cout << "Enter vehicle type: ";
    getline(cin, Type);

    cout << "Enter max speed (km/h): ";
    cin >> maxSpeed;
    cin.ignore(); // Ignore newline
    cout<<"Option fuel is releasing in our page :"<<endl;
    for(auto x : fuelSave){
      cout<<x.first<<" : "<<x.second.first<<endl;
    }
    cin >> fuelType;
    cin.ignore(); // Ignore newline

    cout << "Enter time of invention: ";
    getline(cin, timeInvention);

    cout << "Enter fuel efficiency: ";
    cin >> fuelEfficiency;
    cin.ignore(); // Ignore newline

    cout << "Enter average cost: ";
    cin >> avgCost;
    vehicle tmp(Type, maxSpeed, fuelType, timeInvention, fuelEfficiency, avgCost);
    return tmp;
}
bool ASCorderbyAvgCost(vehicle a,vehicle b){
   if(a.getAvgCost()!=b.getAvgCost()) a.getAvgCost()<b.getAvgCost();
   return a.getType()<b.getType();
}
bool DESCorderbyAvgCost(vehicle a, vehicle b) {
    if(a.getAvgCost()!=b.getAvgCost())return a.getAvgCost() > b.getAvgCost();
    return a.getType()<b.getType();
}

// Sort by fuel efficiency ascending
bool ASCorderbyFuelEfficiency(vehicle a, vehicle b) {
    if (a.getFuelEfficiency() != b.getFuelEfficiency())
        return a.getFuelEfficiency() < b.getFuelEfficiency();
    return a.getType() < b.getType();
}

// Sort by fuel efficiency descending
bool DESCorderbyFuelEfficiency(vehicle a, vehicle b) {
    if (a.getFuelEfficiency() != b.getFuelEfficiency())
        return a.getFuelEfficiency() > b.getFuelEfficiency();
    return a.getType() < b.getType();
}

// Sort by max speed ascending
bool ASCorderbyMaxSpeed(vehicle a, vehicle b) {
    if (a.getMaxSpeed() != b.getMaxSpeed())
        return a.getMaxSpeed() < b.getMaxSpeed();
    return a.getType() < b.getType();
}

// Sort by max speed descending
bool DESCorderbyMaxSpeed(vehicle a, vehicle b) {
    if (a.getMaxSpeed() != b.getMaxSpeed())
        return a.getMaxSpeed() > b.getMaxSpeed();
    return a.getType() < b.getType();
}

void displayfollowAvgASC(){
  sort(v.begin(),v.end(),ASCorderbyAvgCost);
  int i = 1; 
  for(auto x : v){
    cout<< i<< " . ";
    x.displayInfo();
    i++;
  }
  cout<<"Finish !";
}
void displayfollowAvgDESC(){
  sort(v.begin(),v.end(),DESCorderbyAvgCost);
  int i = 1; 
  for(auto x : v){
    cout<< i<< " . ";
    x.displayInfo();
    i++;
  }
  cout<<"Finish !";
}

// Display sorted by fuel efficiency ascending
void displayfollowFuelEfficiencyASC() {
    sort(v.begin(), v.end(), ASCorderbyFuelEfficiency);
    int i = 1;
    for (auto x : v) {
        cout << i << " . ";
        x.displayInfo();
        i++;
    }
    cout << "Finish !" << endl;
}

// Display sorted by fuel efficiency descending
void displayfollowFuelEfficiencyDESC() {
    sort(v.begin(), v.end(), DESCorderbyFuelEfficiency);
    int i = 1;
    for (auto x : v) {
        cout << i << " . ";
        x.displayInfo();
        i++;
    }
    cout << "Finish !" << endl;
}

// Display sorted by max speed ascending
void displayfollowMaxSpeedASC() {
    sort(v.begin(), v.end(), ASCorderbyMaxSpeed);
    int i = 1;
    for (auto x : v) {
        cout << i << " . ";
        x.displayInfo();
        i++;
    }
    cout << "Finish !" << endl;
}

// Display sorted by max speed descending
void displayfollowMaxSpeedDESC() {
    sort(v.begin(), v.end(), DESCorderbyMaxSpeed);
    int i = 1;
    for (auto x : v) {
        cout << i << " . ";
        x.displayInfo();
        i++;
    }
    cout << "Finish !" << endl;
}

void defaultDisplay(){
  int i = 1;
  for (auto x : v) {
    cout << i << ' . '  ;
    i++;
    x.displayInfo();
  }
}
void enterData(){
    int n ;
    cout<<"The amount of vehicle you want to add ?";
    cin>>n;

   if(n<=0){
    cout<<"Con me may nhap dang hoang vao"<<endl;
    return;
   } 
 
   while(n--){
     v.push_back(enter_data());
   }
   cout<<"Complete !";
}
void changeProperty() {
    if (v.empty()) {
        cout << "No vehicles to change.\n";
        return;
    }
    cout << "This is our element list now:\n";
    defaultDisplay();
    cout << "Enter the element number you want to change: ";
    int i;
    cin >> i;
    if (i < 1 || i > v.size()) {
        cout << "Invalid index!\n";
        return;
    }
    // Get reference to the selected vehicle
    vehicle veh = v[i - 1];

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
    cin.ignore(); // clear newline

    switch (opt) {
        case 1: {
            cout << "Enter new Type: ";
            string newType;
            getline(cin, newType);
            veh = vehicle(newType, veh.getMaxSpeed(), veh.getFuelType(), veh.getTimeInvention(), veh.getFuelEfficiency(), veh.getAvgCost());
            break;
        }
        case 2: {
            cout << "Enter new Max Speed: ";
            double newSpeed;
            cin >> newSpeed;
            veh = vehicle(veh.getType(), newSpeed, veh.getFuelType(), veh.getTimeInvention(), veh.getFuelEfficiency(), veh.getAvgCost());
            break;
        }
        case 3: {
            cout << "Option fuel is releasing in our page:\n";
            for (auto x : fuelSave) {
                cout << x.first << " : " << x.second.first << endl;
            }
            cout << "Enter new Fuel Type: ";
            int newFuel;
            cin >> newFuel;
            veh = vehicle(veh.getType(), veh.getMaxSpeed(), newFuel, veh.getTimeInvention(), veh.getFuelEfficiency(), veh.getAvgCost());
            break;
        }
        case 4: {
            cout << "Enter new Time of Invention: ";
            string newTime;
            cin.ignore();
            getline(cin, newTime);
            veh = vehicle(veh.getType(), veh.getMaxSpeed(), veh.getFuelType(), newTime, veh.getFuelEfficiency(), veh.getAvgCost());
            break;
        }
        case 5: {
            cout << "Enter new Fuel Efficiency: ";
            double newEff;
            cin >> newEff;
            veh = vehicle(veh.getType(), veh.getMaxSpeed(), veh.getFuelType(), veh.getTimeInvention(), newEff, veh.getAvgCost());
            break;
        }
        case 6: {
            cout << "Enter new Average Cost: ";
            double newCost;
            cin >> newCost;
            veh = vehicle(veh.getType(), veh.getMaxSpeed(), veh.getFuelType(), veh.getTimeInvention(), veh.getFuelEfficiency(), newCost);
            break;
        }
        default:
            cout << "Invalid option!\n";
            break;
    }
    cout << "Property updated!\n";
}
void menu() {
    cout << "========= VEHICLE MANAGER =========" << endl;
    cout << "1 : Import data to program" << endl;
    cout << "2 : Display all vehicles (default)" << endl;
    cout << "3 : ASC display vehicles by average cost" << endl;
    cout << "4 : DESC display vehicles by average cost" << endl;
    cout << "5 : ASC display vehicles by fuel efficiency" << endl;
    cout << "6 : DESC display vehicles by fuel efficiency" << endl;
    cout << "7 : ASC display vehicles by max speed" << endl;
    cout << "8 : DESC display vehicles by max speed" << endl;
    cout << "9 : Change property of a vehicle" << endl;
    cout << "0 : Exit" << endl;
    cout << "===================================" << endl;
    cout << "Enter your option: ";
}
void initData() {
    v.push_back(vehicle("Car", 180, 1, "1886", 7.5, 25000));
    v.push_back(vehicle("Motorbike", 120, 1, "1885", 3.2, 1500));
    v.push_back(vehicle("Electric Car", 160, 3, "1996", 15.0, 35000));
    v.push_back(vehicle("Jet", 900, 4, "1939", 3.5, 1000000));
    v.push_back(vehicle("Hydrogen Bus", 100, 5, "2003", 8.0, 60000));
}
int main() {
    initData();
    cout << "Welcome to Vehicle manager create by Soulack" << endl;
    cout << "=======>Have a good day <3<========="<<endl;
    while (1) {
        menu();

        bool k = true;
        int Option;
        cin >> Option;
        switch (Option)
        {
        case 1:
            enterData();
            break;
        case 2:
            defaultDisplay();
            break;
        case 3:
            cout << "ASC display vehicle follow AVG cost : " << endl;
            displayfollowAvgASC();
            break;
        case 4:
            cout << "DESC display vehicle follow AVG cost : " << endl;
            displayfollowAvgDESC();
            break;
        case 5:
            cout << "ASC display vehicle follow fuel efficiency : " << endl;
            displayfollowFuelEfficiencyASC();
            break;
        case 6:
            cout << "DESC display vehicle follow fuel efficiency : " << endl;
            displayfollowFuelEfficiencyDESC();
            break;
        case 7:
            cout << "ASC display vehicle follow max speed : " << endl;
            displayfollowMaxSpeedASC();
            break;
        case 8:
            cout << "DESC display vehicle follow max speed : " << endl;
            displayfollowMaxSpeedDESC();
            break;
        case 9:
            changeProperty();
            break;
        case 0:
            k = false;
            break;
        default:
            cout << "Invalid option! Please try again." << endl;
            break;
        }
        if (!k) {
            cout << "Thank you for your experience <3";
            break;
        }
        system("pause");
        system("cls");
    }
}