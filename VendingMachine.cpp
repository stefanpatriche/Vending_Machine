#include "VendingMachine.h"

void VendingMachine::readProducts() {
    maxProductIndex = 0;
    fstream input("available_products.txt");

    if (!input) {
        cout << "Cannot read available products." << '\n';
        exit(7);
    }
    
    Product p;

    while(!input.eof()) {
        input >> p;
        availableProducts.push_back(p);
        maxProductIndex++;
    }
    
    //cout<< min_element(availableProducts.begin(), availableProducts.end())getPrice;

}

void VendingMachine::showAvailableProducts() {
    vector<Product>::iterator it;

    for(it = availableProducts.begin(); it != availableProducts.end(); it++) {
        cout << (it - availableProducts.begin()) + 1 << ". " << (*it);
    }
}   

void VendingMachine::pickPaymentMethod() {
    cout << "Pick your payment method (1 for card/2 for cash)" << '\n';
    cin >> currentPaymentMethod;

    if (currentPaymentMethod == 1) {
        cardPayment();
    } else {
        cashPayment();
    }
    
}

void VendingMachine::cardPayment() {
    cout << "Please enter the number associated with the product you want to purchase:" << "\n";
    int productToPurchase;
    cin >> productToPurchase;

    if(productToPurchase > maxProductIndex) {
        cout << "There is no product associtated with that number!\nExiting...\n";
        exit(5);
    }

    vector<Product>::iterator it;
    for(it = availableProducts.begin(); it != availableProducts.end(); it++){
        
    }

}

void VendingMachine::cashPayment() {
    cout << "Put the money in the tray " << '\n';
    int amount;
    cin >> amount;
    cout << "You have " << amount << " of money left" << '\n';

    cout << "Please enter the number associated with the product you want to purchase:" << "\n";
    int productToPurchase;
    cin >> productToPurchase;

    if(!checkStock(productToPurchase)) {
        return;
    }

    if(productToPurchase > maxProductIndex) {
        cout << "There is no product associtated with that number!\nExiting...\n";
        exit(5);
    }

    vector<Product>::iterator it;
    for(it = availableProducts.begin(); it != availableProducts.end(); it++){
        
    }
}

bool VendingMachine::checkStock(int pickedProduct) {
    vector<Product>::iterator it = availableProducts.begin();

    for(int i = 0; i < pickedProduct - 1; it++, i++);

    if((*it).getQuantity() == 0) {
        cout << "The requested product is no longer in stock. Please choose a different one!" << "\n";
        return false;
    }

    return true;
}