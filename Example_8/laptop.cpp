#include <iostream>
using namespace std;

// The Laptop class represents a laptop with brand, model, RAM, storage, and GPU specifications.
// It provides methods to display information, check hardware requirements, and upgrade RAM.
class Laptop {
private:
    string brand;   // Stores the brand of the laptop
    string model;   // Stores the model of the laptop
    int ram;        // Stores the RAM size in GB
    int storage;    // Stores the storage size in GB
    float gpu;      // Stores the GPU power (arbitrary units)

public:
    // Constructor: Initializes a Laptop object with brand, model, RAM, storage, and GPU.
    // Parameters:
    //   brand - the brand of the laptop
    //   model - the model of the laptop
    //   ram - the RAM size in GB
    //   storage - the storage size in GB
    //   gpu - the GPU power
    Laptop(string brand, string model, int ram, int storage, float gpu) {
        this->brand = brand;
        this->model = model;
        this->ram = ram;
        this->storage = storage;
        this->gpu = gpu;
    }

    // Displays the basic specifications of the laptop.
    void displayInfo() {
        cout << "Brand: " << brand << endl;
        cout << "Model: " << model << endl;
        cout << "RAM: " << ram << " GB" << endl;
        cout << "Storage: " << storage << " GB" << endl;
        cout << "GPU: " << gpu << " units" << endl;
    }

    // Checks if the laptop's GPU meets the required threshold for running a game.
    // Parameters:
    //   requiredGPU - the minimum GPU power required
    void checkGPU(float requiredGPU) {
        if (gpu >= requiredGPU) {
            cout << "This laptop has enough GPU to run the game." << endl;
        } else {
            cout << "This laptop does not have enough GPU to run the game." << endl;
        }
    }

    // Checks if the laptop's RAM is sufficient for running a specific software.
    // Parameters:
    //   requiredRAM - the minimum RAM required in GB
    void checkRAM(int requiredRAM) {
        if (ram >= requiredRAM) {
            cout << "This laptop has enough RAM to run the software." << endl;
        } else {
            cout << "This laptop does not have enough RAM to run the software." << endl;
        }
    }

    // Adds additional RAM to the laptop and displays the updated RAM value.
    // Parameters:
    //   additionalRAM - the amount of RAM to add in GB
    void upgradeRAM(int additionalRAM) {
        ram += additionalRAM;
        cout << "RAM upgrade successful!" << endl;
        cout << "RAM now: " << ram << " GB" << endl;
    }
};

int main() {
    // Create a Laptop object with sample data
    Laptop laptop1("DELL", "XPS 13", 8, 256, 16);

    // Display laptop specifications
    laptop1.displayInfo();

    // Check if current RAM is enough for a software that requires 16 GB
    laptop1.checkRAM(16);

    // Check if current GPU is enough for a game that requires 12 units
    laptop1.checkGPU(12);

    // Upgrade RAM by 8 GB
    laptop1.upgradeRAM(8);

    // Display updated laptop specifications
    laptop1.displayInfo();

    return 0;
}
