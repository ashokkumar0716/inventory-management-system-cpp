#include <iostream>
#include <vector>
using namespace std;

class Product {
public:
    int id;
    string name;
    int quantity;
    float price;

    void input() {
        cout << "Enter Product ID: ";
        cin >> id;

        cout << "Enter Product Name: ";
        cin >> name;

        cout << "Enter Quantity: ";
        cin >> quantity;

        cout << "Enter Price: ";
        cin >> price;
    }

    void display() const {
        cout << "\nID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Quantity: " << quantity << endl;
        cout << "Price: " << price << endl;
    }
};

int main() {
    vector<Product> products;
    int choice;

    while (true) {
        cout << "\n===== Inventory Management System =====" << endl;
        cout << "1. Add Product" << endl;
        cout << "2. View Products" << endl;
        cout << "3. Search Product" << endl;
        cout << "4. Delete Product" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            Product p;
            p.input();
            products.push_back(p);
            cout << "Product added successfully!" << endl;
        }

        else if (choice == 2) {
            if (products.empty()) {
                cout << "No products available!" << endl;
            } else {
                for (const auto &p : products) {
                    p.display();
                }
            }
        }

        else if (choice == 3) {
            int searchId;
            bool found = false;

            cout << "Enter Product ID to search: ";
            cin >> searchId;

            for (const auto &p : products) {
                if (p.id == searchId) {
                    cout << "Product Found!" << endl;
                    p.display();
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "Product not found!" << endl;
            }
        }

        else if (choice == 4) {
            int deleteId;
            bool found = false;

            cout << "Enter Product ID to delete: ";
            cin >> deleteId;

            for (auto it = products.begin(); it != products.end(); ++it) {
                if (it->id == deleteId) {
                    products.erase(it);
                    cout << "Product deleted successfully!" << endl;
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "Product not found!" << endl;
            }
        }

        else if (choice == 5) {
            cout << "Exiting program..." << endl;
            break;
        }

        else {
            cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}
