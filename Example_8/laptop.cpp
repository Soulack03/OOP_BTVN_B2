#include<bits/stdc++.h>
using namespace std;

class Laptop {
public:
    string brand;
    string model;
    int ram; 
    int storage; 
    float gpu;

    // Displays the basic specifications of the laptop
    void displayInfo() {
        cout << "Brand: " << brand << endl;
        cout << "Model: " << model << endl;
        cout << "RAM: " << ram << " GB" << endl;
        cout << "Storage: " << storage << " GB" << endl;
    }

    // Checks if the laptop's GPU meets the required threshold for running a game
    void checkGPU(float requiredGPU) {
        if (gpu >= requiredGPU) {
            cout << "This laptop has enough GPU to run the game." << endl;
        } else {
            cout << "This laptop does not have enough GPU to run the game." << endl;
        }
    }

    // Checks if the laptop's RAM is sufficient for running a specific software
    void checkRAM(int requiredRAM) {
        if (ram >= requiredRAM) {
            cout << "This laptop has enough RAM to run the software." << endl;
        } else {
            cout << "This laptop does not have enough RAM to run the software." << endl;
        }
    }

    // Adds additional RAM to the laptop and displays the updated RAM value
    void upgradeRAM(int additionalRAM) {
        ram += additionalRAM;
        cout << "RAM update successful!" << endl;
        cout << "RAM now: " << ram << " GB" << endl;
    }
};

int main() {
    Laptop laptop1;
    laptop1.brand = "Dell";
    laptop1.model = "XPS 13";
    laptop1.ram = 8;
    laptop1.storage = 256;

    // Display laptop specifications
    laptop1.displayInfo();

    // Check if current RAM is enough for a software that requires 16 GB
    laptop1.checkRAM(16);

    // Upgrade RAM by 90 GB
    laptop1.upgradeRAM(90);

    return 0;
}
