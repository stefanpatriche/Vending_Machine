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

        string name = p.getName();
        replace(name.begin(), name.end(), '_', ' ');
        p.setName(name);

        availableProducts.push_back(p);
        maxProductIndex++;
    }
    
    minPrice = (*min_element(availableProducts.begin(), availableProducts.end())).getPrice();

}

void VendingMachine::showAvailableProducts() {
    vector<Product>::const_iterator it;

    for(it = availableProducts.begin(); it != availableProducts.end(); it++) {
        cout << (it - availableProducts.begin()) + 1 << ". " << (*it);
    }
}   

void VendingMachine::pickPaymentMethod() {
    cout << "Pick your payment method (1 for card/2 for cash)" << '\n';
    cin >> currentPaymentMethod;

    if (currentPaymentMethod == 1) {
        cardPayment();
    } else if (currentPaymentMethod == 2) {
        cashPayment();
    } else {
        cout << "No payment method with that number!\n";
    }
    
}

void VendingMachine::cardPayment() {
    cout << "Please enter the number of the product you want to purchase:" << "\n";
    int productToPurchase;

    cin >> productToPurchase;
    productToPurchase--;

    if(productToPurchase > maxProductIndex) {
        cout << "There is no product associated with that number!\nExiting...\n";
        exit(5);
    }

    if(checkStock(productToPurchase)) {
        cout << "Please insert your credit card and Enter PIN!\n";
        sleep(2);
        cout << "Processing... \n";
        cout << "The payment was processed successfully!\n";
        sleep(1);
        cout << "Your product has been delivered!\n";
        
        availableProducts.at(productToPurchase).setQuantity(availableProducts.at(productToPurchase).getQuantity() - 1);
        cout << "Thank you! Have a nice day!\n";
            
    } else {
        cout << "The requested product is no longer in stock. Please choose a different one!" << "\n";
    }

}

void VendingMachine::cashPayment() {
    cout << "Please insert the cash!" << '\n';
    int amount;
    cin >> amount;
    
    while(amount > minPrice) {
        cout << "***You have " << amount << " dollars left." << '\n';

        cout << "Please enter the number of the product you want to purchase:" << "\n";

        int productToPurchase;
        cin >> productToPurchase;
        productToPurchase--;

        if(productToPurchase > maxProductIndex) {
            cout << "There is no product associtated with that number!\nExiting...\n";
            exit(5);
        }

        if(checkStock(productToPurchase)) {
            if(amount - availableProducts.at(productToPurchase).getPrice() > 0) {
                amount -= availableProducts.at(productToPurchase).getPrice();
                availableProducts.at(productToPurchase).setQuantity(availableProducts.at(productToPurchase).getQuantity() - 1);
                cout << "Your product has been delivered!\n";
            } else{
                cout << "You don't have enough money to purchase this product!\n";
            }
        } else {
            cout << "The requested product is no longer in stock. Please choose a different one!" << "\n";
        }
    }
}

bool VendingMachine::checkStock(int pickedProduct) {
    if((availableProducts.at(pickedProduct)).getQuantity() == 0) {
        return false;
    }

    return true;
}