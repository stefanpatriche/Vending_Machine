#include "VendingMachine.h"

void VendingMachine::readProducts() {
    fstream input("available_products.txt");

    if (!input) {
        cout << "Cannot read available products." << '\n';
        exit(7);
    }
    
    Product p;

    while(!input.eof()) {
        input >> p;
        availableProducts.push_back(p);
        cout << p;
    }

}