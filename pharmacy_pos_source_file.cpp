#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

// Class representing a product in the inventory
class Product {
public:
    // Constructor to initialize the Product object with name, price, and quantity
    Product(string name, double price, int quantity) : name(name), price(price), quantity(quantity) {}

    // Accessor functions to get the attributes of the Product
    string getName() const {
        return name;
    }

    double getPrice() const {
        return price;
    }

    int getQuantity() const {
        return quantity;
    }

    // Mutator/setter function to set the quantity of the Product
    void setQuantity(int newQuantity) {
        quantity = newQuantity;
    }

private:
    string name;
    double price;
    int quantity;
};

// Function to display the inventory
void displayInventory(const vector<Product>& inventory) {
    cout << "Inventory:\n";
    cout << "------------------------------------------\n";
    //set the width of the output characters
    cout << setw(20) << left << "Product Name" << setw(10) << right << "Price" << setw(10) << "Quantity" << endl;
    cout << "------------------------------------------\n";
    for (size_t i = 0; i < inventory.size(); i++) {
        cout << setw(20) << left << inventory[i].getName() << setw(10) << right << fixed << setprecision(2) << inventory[i].getPrice()
             << setw(10) << inventory[i].getQuantity() << endl;
    }
    cout << "------------------------------------------\n";
}

// Function to add items to the cart
void addToCart(vector<Product>& cart, vector<Product>& inventory, const string& productName, int quantity) {
    for (size_t i = 0; i < inventory.size(); i++) {
        if (inventory[i].getName() == productName) {
            if (inventory[i].getQuantity() >= quantity) {
                cart.push_back(Product(inventory[i].getName(), inventory[i].getPrice(), quantity));
                inventory[i].setQuantity(inventory[i].getQuantity() - quantity);
                cout << quantity << " " << inventory[i].getName() << "(s) added to the cart.\n";
                return;
            } else {
                cout << "Insufficient quantity in the inventory.\n";
                return;
            }
        }
    }
    cout << "Product not found in the inventory.\n";
}

// Function to calculate the total amount of the cart
double calculateTotal(const vector<Product>& cart) {
    double total = 0.0;
    for (size_t i = 0; i < cart.size(); i++) {
        total += (cart[i].getPrice() * cart[i].getQuantity());
    }
    return total;
}

// Function for user login
bool login() {
    // Sample username and password (replace these with your real credentials)
    string valid_username = "Sylvia";
    string valid_password = "password";

    // Get user input for username and password
    string username_input, password_input;
    cout << "Enter your username: ";
    cin >> username_input;
    cout << "Enter your password: ";
    cin >> password_input;

    // Check if the input matches the valid credentials
    if (username_input == valid_username && password_input == valid_password) {
        cout << "Login successful! Welcome, " << username_input << ".\n";
        return true;
    } else {
        cout << "Login failed. Invalid username or password.\n";
        return false;
    }
}

int main() {
    if (login()) {
        // Code for logged-in users here

        // Create the inventory vector to store available products in the pharmacy store(vector=dynamic array)
        vector<Product> inventory;
        inventory.push_back(Product("Paracetamol tabs", 20.00, 100));
        inventory.push_back(Product("Esomeprazole caps", 30.00, 150));
        inventory.push_back(Product("Menthodex Syrup", 300.00, 50));
        inventory.push_back(Product("Cetrizine tabs", 10.00, 50));
        inventory.push_back(Product("Duphalac syrup", 450.00, 75));
        inventory.push_back(Product("Ibuprofen tabs", 15.00, 300));
        inventory.push_back(Product("Antacid Suspension", 100.00, 40));
        
        // One can add more inventory items here

        // Create the cart vector to store items added by the customer
        vector<Product> cart;

        int option;
        do {
            cout << "Pharmacy Point of Sale\n";
            cout << "1. Display Inventory\n";
            cout << "2. Add Item to Cart\n";
            cout << "3. View Cart\n";
            cout << "4. Calculate Total\n";
            cout << "5. Exit\n";
            cout << "Enter option: ";
            cin >> option;

            switch (option) {
                case 1:
                    displayInventory(inventory);
                    break;
                case 2: {
                    string productName;
                    int quantity;
                    cout << "Enter product name: ";
                    cin >> productName;
                    cout << "Enter quantity: ";
                    cin >> quantity;
                    addToCart(cart, inventory, productName, quantity);
                    break;
                }
                case 3:
                    displayInventory(cart);
                    break;
                case 4: {
                    double total = calculateTotal(cart);
                    cout << "Total amount: $" << fixed << setprecision(2) << total << endl;
                    break;
                }
                case 5:
                    cout << "Thank you for using the Pharmacy Point of Sale. Goodbye!\n";
                    break;
                default:
                    cout << "Invalid option. Please try again.\n";
                    break;
            }
        } while (option != 5);//continuously displays the main menu and execute the selected option until the user chooses to exit the program (by entering option 5)
    } else {
        // Code for failed login attempt here (optional)
        cout << "You don't have access to restricted content.\n";
    }

    return 0;
}
