//Tran Le Dung
// MSSV:24110084
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include <ctime>
#include <sstream>

using namespace std;

// Forward declarations
class Product;
class Electronics;
class ShoppingCart;
class Order;

// Interface: Discountable (Abstract Class)
class Discountable {
public:
    virtual double applyDiscount(double rate) = 0;
    virtual ~Discountable() {}
};

// Template Class: InventoryList
template <typename T>
class InventoryList {
private:
    vector<T> items;

public:
    // Add item to inventory
    void add(const T& item) {
        items.push_back(item);
    }

    // Remove item from inventory
    bool remove(const T& item) {
        auto it = find(items.begin(), items.end(), item);
        if (it != items.end()) {
            items.erase(it);
            return true;
        }
        return false;
    }

    // Search for item by index
    T* search(int index) {
        if (index >= 0 && index < items.size()) {
            return &items[index];
        }
        return nullptr;
    }

    // Display all items
    void display() const {
        for (int i = 0; i < items.size(); ++i) {
            cout << "Index " << i << ": ";
            if constexpr (is_pointer_v<T>) {
                if (items[i] != nullptr) {
                    items[i]->displayInfo();
                }
            } else {
                cout << items[i] << endl;
            }
        }
    }

    // Get size
    int size() const {
        return items.size();
    }

    // Operator overloading for array access
    T& operator[](int index) {
        if (index < 0 || index >= items.size()) {
            throw out_of_range("Index out of range");
        }
        return items[index];
    }

    // Get all items
    const vector<T>& getItems() const {
        return items;
    }

    // Clear all items
    void clear() {
        items.clear();
    }
};

// Base Class: Product
class Product : public Discountable {
private:
    int id;
    string name;
    double price;
    int stock;
    string description;

public:
    // Constructor
    Product(int id,  string name, double price, int stock,  string description = "")
: id(id), name(name), price(price), stock(stock), description(description) {
        if (price < 0) {
            this->price = 0;
            cout << "Warning: Negative price set to 0" << endl;
        }
        if (stock < 0) {
            this->stock = 0;
            cout << "Warning: Negative stock set to 0" << endl;
        }
    }

    // Virtual destructor
    virtual ~Product() {
        cout << "Product destructor called for: " << name << endl;
    }

    // Virtual method for updating stock
    virtual void updateStock(int quantity) {
        if (stock + quantity < 0) {
            cout << "Error: Cannot reduce stock below 0. Current stock: " << stock << endl;
            return;
        }
        stock += quantity;
        cout << "Stock updated for " << name << ". New stock: " << stock << endl;
    }

    // Virtual method for displaying product information
    virtual void displayInfo() const {
        cout << "Product ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Price: $" << fixed << setprecision(2) << price << endl;
        cout << "Stock: " << stock << endl;
        if (!description.empty()) {
            cout << "Description: " << description << endl;
        }
        cout << "------------------------" << endl;
    }

    // Getters
    int getId()  { return id; }
    string getName()  { return name; }
    double getPrice()  { return price; }
    int getStock()  { return stock; }
    string getDescription()  { return description; }

    // Setters
    void setPrice(double newPrice) {
        if (newPrice >= 0) {
            price = newPrice;
        }
    }

    void setDescription(string newDescription) {
        description = newDescription;
    }

    // Operator overloading: == for comparing products
    bool operator==(const Product& other) const {
        return this->id == other.id;
    }

    // Operator overloading: != for comparing products
    bool operator!=(const Product& other) const {
        return !(*this == other);
    }

    // Interface implementation: Apply discount
    virtual double applyDiscount(double rate) override {
        if (rate < 0 || rate > 1) {
            cout << "Error: Discount rate must be between 0 and 1" << endl;
            return price;
        }
        double discountedPrice = price * (1 - rate);
        cout << "Discount applied to " << name << ": " << (rate * 100) << "% off" << endl;
        cout << "Original price: $" << price << ", Discounted price: $" << discountedPrice << endl;
        return discountedPrice;
    }

    // Check if product is available
    bool isAvailable()  {
        return stock > 0;
    }
};

// Derived Class: Electronics
class Electronics : public Product {
private:
    int warrantyPeriod; // in months
    string brand;
    string model;

public:
    // Constructor
    Electronics(int id,  string name, double price, int stock, 
                int warranty,  string brand, string model = "",
                 string description = ""): Product(id, name, price, stock, description), warrantyPeriod(warranty), brand(brand), model(model) {
        if (warranty < 0) {
            this->warrantyPeriod = 0;
            cout << "Warning: Negative warranty period set to 0" << endl;
        }
    }

    // Destructor
    ~Electronics() {
        cout << "Electronics destructor called for: " << getName() << endl;
    }

    void updateStock(int quantity) override {
        if (getStock() + quantity < 0) {
            cout << "Error: Cannot reduce stock below 0. Current stock: " << getStock() << endl;
            return;
        }
        
        Product::updateStock(quantity);
        
        if (quantity < 0) {
            cout << "Electronics handling fee applied for: " << getName() << endl;
        }
    }

    // Override displayInfo method
    void displayInfo() const override {
        cout << "=== ELECTRONICS PRODUCT ===" << endl;
        Product::displayInfo();
        cout << "Brand: " << brand << endl;
        if (!model.empty()) {
            cout << "Model: " << model << endl;
        }
        cout << "Warranty: " << warrantyPeriod << " months" << endl;
        cout << "============================" << endl;
    }

    // Additional methods specific to Electronics
    void extendWarranty(int additionalMonths) {
        if (additionalMonths > 0) {
            warrantyPeriod += additionalMonths;
            cout << "Warranty extended for " << getName() << " by " << additionalMonths << " months." << endl;
            cout << "New warranty period: " << warrantyPeriod << " months" << endl;
        }
    }

    // Getters
    int getWarrantyPeriod() const { return warrantyPeriod; }
    string getBrand() const { return brand; }
    string getModel() const { return model; }
};

// ShoppingCart Class
class ShoppingCart : public Discountable {
private:
    InventoryList<Product*> items;
    double totalPrice;
    inline static int nextCartId=1;
    int cartId;

public:
    // Constructor
    ShoppingCart() : totalPrice(0.0), cartId(nextCartId++) {
        cout << "Shopping cart created with ID: " << cartId << endl;
    }

    // Destructor
    ~ShoppingCart() {
        cout << "Shopping cart " << cartId << " destroyed" << endl;
    }

    // Operator overloading: += for adding products to cart
    ShoppingCart& operator+=(Product* product) {
        if (product == nullptr) {
            cout << "Error: Cannot add null product to cart" << endl;
            return *this;
        }

        if (!product->isAvailable()) {
            cout << "Error: Product '" << product->getName() << "' is out of stock!" << endl;
            return *this;
        }

        items.add(product);
        totalPrice += product->getPrice();
        product->updateStock(-1); // Reduce stock when added to cart
        
        cout << "Product '" << product->getName() << "' added to cart successfully!" << endl;
        cout << "Cart total: $" << fixed << setprecision(2) << totalPrice << endl;
        
        return *this;
    }

    // Remove product from cart
    bool removeProduct(Product* product) {
        if (product == nullptr) {
            cout << "Error: Cannot remove null product from cart" << endl;
            return false;
        }

        if (items.remove(product)) {
            totalPrice -= product->getPrice();
            product->updateStock(1); // Restore stock when removed from cart
            cout << "Product '" << product->getName() << "' removed from cart" << endl;
            cout << "New cart total: $" << fixed << setprecision(2) << totalPrice << endl;
            return true;
        } else {
            cout << "Product '" << product->getName() << "' not found in cart" << endl;
            return false;
        }
    }

    // Calculate total price
    double calculateTotal() {
        totalPrice = 0;
        for (int i = 0; i < items.size(); ++i) {
            if (items[i] != nullptr) {
                totalPrice += items[i]->getPrice();
            }
        }
        return totalPrice;
    }

    // Display cart contents
    void displayCart()  {
        cout << "\n========== SHOPPING CART " << cartId << " ==========" << endl;
        if (items.size() == 0) {
            cout << "Cart is empty" << endl;
        } else {
            cout << "Items in cart:" << endl;
            for (int i = 0; i < items.size(); ++i) {
                cout << (i + 1) << ". ";
                if (items.getItems()[i] != nullptr) {
                    cout << items.getItems()[i]->getName() 
                         << " - $" << fixed << setprecision(2) 
                         << items.getItems()[i]->getPrice() << endl;
                }
            }
        }
        cout << "Total: $" << fixed << setprecision(2) << totalPrice << endl;
        cout << "===============================================" << endl;
    }

    // Interface implementation: Apply discount to entire cart
    double applyDiscount(double rate) override {
        if (rate < 0 || rate > 1) {
            cout << "Error: Discount rate must be between 0 and 1" << endl;
            return totalPrice;
        }

        double originalTotal = totalPrice;
        double discountAmount = totalPrice * rate;
        double discountedTotal = totalPrice - discountAmount;
        
        cout << "\nCart Discount Applied:" << endl;
        cout << "Original total: $" << fixed << setprecision(2) << originalTotal << endl;
        cout << "Discount (" << (rate * 100) << "%): -$" << discountAmount << endl;
        cout << "Final total: $" << discountedTotal << endl;
        
        return discountedTotal;
    }

    // Get cart items
    const InventoryList<Product*>& getItems() const {
        return items;
    }

    // Get total price
    double getTotalPrice() const {
        return totalPrice;
    }

    // Get cart ID
    int getCartId() const {
        return cartId;
    }

    // Check if cart is empty
    bool isEmpty() const {
        return items.size() == 0;
    }

    // Clear cart
    void clearCart() {
        // Restore stock for all items
        for (int i = 0; i < items.size(); ++i) {
            if (items.getItems()[i] != nullptr) {
                items.getItems()[i]->updateStock(1);
            }
        }
        items.clear();
        totalPrice = 0;
        cout << "Cart cleared" << endl;
    }
};

// Order Class
class Order {
private:
    int orderId;
    vector<Product*> items;
    string orderDate;
    double totalAmount;
    string status;
    inline static int nextOrderId=1000;

    // Helper function to get current date
    string getCurrentDate() {
        time_t now = time(0);
        char* dt = ctime(&now);
        string dateStr(dt);
        // Remove newline character
        if (!dateStr.empty() && dateStr[dateStr.length()-1] == '\n') {
            dateStr.erase(dateStr.length()-1);
        }
        return dateStr;
    }

public:
    // Constructor
    Order(const ShoppingCart& cart) 
        : orderId(nextOrderId++), totalAmount(cart.getTotalPrice()), 
          orderDate(getCurrentDate()), status("Pending") {
        
        // Copy items from cart
        auto cartItems = cart.getItems().getItems();
        for (Product* item : cartItems) {
            if (item != nullptr) {
                items.push_back(item);
            }
        }
        
        cout << "Order created with ID: " << orderId << endl;
    }

    // Destructor
    ~Order() {
        cout << "Order " << orderId << " destroyed" << endl;
    }

    // Process the order
    void processOrder() {
        if (status == "Processed") {
            cout << "Order " << orderId << " has already been processed" << endl;
            return;
        }

        status = "Processed";
        cout << "\nProcessing order " << orderId << "..." << endl;
        cout << "Order processed successfully!" << endl;
        cout << "Status updated to: " << status << endl;
    }

    // Display order details
    void displayOrder() const {
        cout << "\n============ ORDER DETAILS ============" << endl;
        cout << "Order ID: " << orderId << endl;
        cout << "Order Date: " << orderDate << endl;
        cout << "Status: " << status << endl;
        cout << "\nOrdered Items:" << endl;
        
        if (items.empty()) {
            cout << "No items in this order" << endl;
        } else {
            for (size_t i = 0; i < items.size(); ++i) {
                if (items[i] != nullptr) {
                    cout << (i + 1) << ". " << items[i]->getName() 
                         << " - $" << fixed << setprecision(2) 
                         << items[i]->getPrice() << endl;
                }
            }
        }
        
        cout << "\nTotal Amount: $" << fixed << setprecision(2) << totalAmount << endl;
        cout << "=======================================" << endl;
    }

    // Getters
    int getOrderId() const { return orderId; }
    string getStatus() const { return status; }
    double getTotalAmount() const { return totalAmount; }
    const vector<Product*>& getItems() const { return items; }

    // Cancel order
    void cancelOrder() {
        if (status == "Processed") {
            cout << "Cannot cancel processed order" << endl;
            return;
        }
        
        status = "Cancelled";
        // Restore stock for all items
        for (Product* item : items) {
            if (item != nullptr) {
                item->updateStock(1);
            }
        }
        cout << "Order " << orderId << " has been cancelled" << endl;
    }
};


// Main function with comprehensive testing
int main() {
    cout << "=== E-COMMERCE PRODUCT MANAGEMENT SYSTEM ===" << endl;
    cout << "Testing all OOP concepts...\n" << endl;

    try {
        // Create Products (Base and Derived classes)
        cout << "1. CREATING PRODUCTS:" << endl;
        cout << "---------------------" << endl;
        
        Product* laptop = new Electronics(1, "Gaming Laptop", 1500.0, 5, 24, "ASUS", "ROG Strix", "High-performance gaming laptop");
        Product* mouse = new Product(2, "Wireless Mouse", 50.0, 10, "Ergonomic wireless mouse");
        Product* keyboard = new Electronics(3, "Mechanical Keyboard", 120.0, 8, 12, "Corsair", "K95", "RGB mechanical keyboard");
        Product* headphones = new Electronics(4, "Gaming Headset", 200.0, 0, 18, "SteelSeries", "Arctis 7", "Wireless gaming headset");

        cout << "\nProducts created successfully!\n" << endl;

        //  Test Template Class (InventoryList)
        cout << "2. TESTING TEMPLATE CLASS (InventoryList):" << endl;
        cout << "-------------------------------------------" << endl;
        
        InventoryList<Product*> inventory;
        inventory.add(laptop);
        inventory.add(mouse);
        inventory.add(keyboard);
        inventory.add(headphones);
        
        cout << "Inventory size: " << inventory.size() << endl;
        cout << "\nInventory contents:" << endl;
        inventory.display();

        //  Test Inheritance (Virtual methods)
        cout << "\n3. TESTING INHERITANCE (Virtual Methods):" << endl;
        cout << "------------------------------------------" << endl;
        
        cout << "Displaying laptop info (Electronics - derived class):" << endl;
        laptop->displayInfo();
        
        cout << "Displaying mouse info (Product - base class):" << endl;
        mouse->displayInfo();

        // Test overridden method
        cout << "Testing overridden updateStock method:" << endl;
        laptop->updateStock(-1); // Electronics version (with handling fee)
        mouse->updateStock(-1);  // Base Product version

        // Test Operator Overloading
        cout << "\n4. TESTING OPERATOR OVERLOADING:" << endl;
        cout << "---------------------------------" << endl;
        
        // Test == operator
        cout << "Comparing products using == operator:" << endl;
        if (*laptop == *mouse) {
            cout << "Laptop and mouse are the same product" << endl;
        } else {
            cout << "Laptop and mouse are different products" << endl;
        }

        // Test += operator with ShoppingCart
        cout << "\nTesting += operator with ShoppingCart:" << endl;
        ShoppingCart cart;
        cart += laptop;    // Should succeed
        cart += mouse;     // Should succeed  
        cart += keyboard;  // Should succeed
        cart += headphones; // Should fail (out of stock)

        cart.displayCart();

        //  Test Interface (Discountable)
        cout << "\n5. TESTING INTERFACE (Discountable):" << endl;
        cout << "------------------------------------" << endl;
        
        cout << "Applying discount to individual product:" << endl;
        double discountedPrice = laptop->applyDiscount(0.15); // 15% discount
        
        cout << "\nApplying discount to entire cart:" << endl;
        double cartDiscountedTotal = cart.applyDiscount(0.10); // 10% discount

        //  Test Order Creation and Processing
        cout << "\n6. TESTING ORDER CREATION AND PROCESSING:" << endl;
        cout << "-----------------------------------------" << endl;
        
        Order* order = new Order(cart);
        order->displayOrder();
        order->processOrder();
        order->displayOrder(); // Show updated status

        // Step 7: Test Error Handling
        cout << "\n7. TESTING ERROR HANDLING:" << endl;
        cout << "--------------------------" << endl;
        
        cout << "Attempting to add out-of-stock product:" << endl;
        ShoppingCart cart2;
        cart2 += headphones; // Should fail
        
        cout << "\nAttempting invalid discount rates:" << endl;
        mouse->applyDiscount(-0.1); // Invalid negative rate
        mouse->applyDiscount(1.5);  // Invalid rate > 1

        // Step 8: Test Additional Features
        cout << "\n8. TESTING ADDITIONAL FEATURES:" << endl;
        cout << "-------------------------------" << endl;
        
        // Test Electronics-specific features
        Electronics* laptopPtr = dynamic_cast<Electronics*>(laptop);
        if (laptopPtr) {
            cout << "Extending warranty for laptop:" << endl;
            laptopPtr->extendWarranty(6);
        }

        // Test cart operations
        cout << "\nTesting cart removal:" << endl;
        cart.removeProduct(mouse);
        cart.displayCart();

        cout << "\nTesting cart clearing:" << endl;
        cart.clearCart();
        cart.displayCart();

        // Template class with different types
        cout << "\n9. TESTING TEMPLATE WITH DIFFERENT TYPES:" << endl;
        cout << "----------------------------------------" << endl;
        
        InventoryList<string> categoryList;
        categoryList.add("Electronics");
        categoryList.add("Accessories");
        categoryList.add("Gaming");
        
        cout << "Category list size: " << categoryList.size() << endl;
        cout << "Categories:" << endl;
        categoryList.display();

        // Cleanup
        cout << "\nCleaning up resources..." << endl;
        delete laptop;
        delete mouse;
        delete keyboard;
        delete headphones;
        delete order;

        cout << "\nAll tests completed successfully!" << endl;

    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}