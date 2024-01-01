// Topic:
// Write a program to simulate a simple online shop. 
// Create a class Product with attributes like name, price, and quantity in stock. 
// Implement methods for adding products to the shopping cart, calculating the total cost
// Display the contents of the cart.


// Theory:
// The code simulates a simple online shop with two classes, 
// Product representing a product with attributes, and ShoppingCart managing products in a cart. 
// It enables adding products, displaying the cart, and calculating the total cost.


// Code:
#include <iostream>
#include <vector>

using namespace std;

class Product {
public:
    string name;
    double price;
    int quantityInStock;

    void display() const {
        cout << name << " - $" << price << " - In Stock: " << quantityInStock << endl;
    }
};

class ShoppingCart {
public:
    vector<pair<Product, int>> items;

    void addProduct(const Product& product, int quantity) {
        if (product.quantityInStock >= quantity) {
            items.emplace_back(product, quantity);
            cout << quantity << " " << product.name << "(s) added to the cart." << endl;
        } else {
            cout << "Not enough stock available for " << product.name << "." << endl;
        }
    }

    void display() const {
        if (items.empty()) {
            cout << "Shopping cart is empty." << endl;
            return;
        }

        for (const auto& [product, quantity] : items) {
            cout << quantity << " " << product.name << "(s)" << endl;
        }
    }

    double calculateTotalCost() const {
        double totalCost = 0.0;
        for (const auto& [product, quantity] : items) {
            totalCost += product.price * quantity;
        }
        return totalCost;
    }
};

int main() {
    Product laptop{"Laptop", 999.99, 5};
    Product phone{"Phone", 499.99, 10};
    Product headphones{"Headphones", 79.99, 20};

    ShoppingCart cart;
    cart.addProduct(laptop, 2);
    cart.addProduct(phone, 3);
    cart.addProduct(headphones, 1);

    cout << "\nShopping Cart Contents:\n";
    cart.display();

    cout << "\nTotal Cost: $" << cart.calculateTotalCost() << endl;

    return 0;
}


// Conclusion:
// This C++ program demonstrates object-oriented principles, encapsulation, 
// and usage of classes to model an online shopping scenario. 
// It provides a foundation for expanding features and functionalities for a more robust simulation.