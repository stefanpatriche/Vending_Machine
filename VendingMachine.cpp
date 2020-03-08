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

        // the name of the product is found in the file with underscores
        // instead o spaces between the words so we have to replace those
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
    int paymentMethod; // 1 - card / 2 - cash

    cout << "\nPick your payment method (1 for card/2 for cash)" << '\n';
    cin >> paymentMethod;

    if (paymentMethod == 1) {
        cardPayment();
    } else if (paymentMethod == 2) {
        cashPayment();
    } else {
        cout << "No payment method with that number!\n";
        cout << "Restarting...\n";
    }
}

bool VendingMachine::checkEmptyMachine() {
    vector<Product>::const_iterator it;
    int quantitySum = 0;

    for(it = availableProducts.begin(); it != availableProducts.end(); it++) {
        quantitySum += (*it).getQuantity();
    }

    return quantitySum == 0;
}

void VendingMachine::cardPayment() {
    cout << "\nPlease enter the number of the product you want to purchase:" << "\n";
    
    int productToPurchase;
    string cardNumber;
    string pin;

    cin >> productToPurchase;

    // the productToPurchase number is decremented because the numbers 
    // of the products are displayed starting from 1 instead of 0
    productToPurchase--;

    if(productToPurchase > maxProductIndex) {
        cout << "\nThere is no product associated with that number!\nExiting...\n";
        return;
    }

    while(!checkStock(productToPurchase)){
        cout << "\nThe requested product is no longer in stock.\nPlease enter a different number:" << "\n";
        cin >> productToPurchase;
        productToPurchase--;
    }
    
    cout << "\nPlease enter your credit card number:\n";
    cin >> cardNumber;
    cout << "Please enter your PIN:\n";
    cin >> pin;
    cout << "Processing... \n";
    sleep(2);

    if(checkCardInfo(cardNumber, pin)) {
        cout << "\nThe payment was processed successfully!\n";
        
        cout << availableProducts.at(productToPurchase).getPrice();
        cout << " dollars have been deducted from your account!\n";

        cout << "\nYour product \"" << availableProducts.at(productToPurchase).getName();
        cout <<"\" has been delivered!\n";
        
        availableProducts.at(productToPurchase).
            setQuantity(availableProducts.at(productToPurchase).getQuantity() - 1);

        cout << "Thank you for your purchase! Have a nice day!\n";
    } else {
        cout << "Wrong card information!\nRestarting...\n";
    }
}

void VendingMachine::cashPayment() {
    cout << "\nPlease insert the cash:" << '\n';

    int amount;
    cin >> amount;
    
    while(amount >= minPrice) {
        cout << "\n***You have " << amount << " dollars left." << '\n';
        cout << "Please enter the number of the product you want to purchase!\n";
        cout << "If you want change enter R:" << "\n";
        
        // productToPurchase is stored as a char in order to more easily
        // determine when the user asks for change
        char productToPurchase;
        cin >> productToPurchase;
        
        // check if productToPurchase is equal to R or r to deliver change
        if(productToPurchase == 0x52 || productToPurchase == 0x72) {
            cout << "\nDelivering a change of " << amount << " dollars\n";
            cout << "Thank you! Have a nice day!\n";
            return;
        }

        // 0 (ASCII) is subtracted from productToPurchase to 
        // create the index for the vector
        productToPurchase -= 0x31; 

        while(!checkStock(productToPurchase)){
            cout << "\nThe requested product is no longer in stock.\n";
            cout << "Please enter a different number or R for change:" << "\n";
            cin >> productToPurchase;

            if(productToPurchase == 0x52 || productToPurchase == 0x72) {
                cout << "\nDelivering a change of " << amount << " dollars\n";
                cout << "Thank you! Have a nice day!\n";
                return;
            }

            productToPurchase -= 0x31;
        }

        if(productToPurchase > maxProductIndex) {
            cout << "There is no product associtated with that number!\nExiting...\n";
            return;
        }

        if(amount - availableProducts.at(productToPurchase).getPrice() >= 0) {
            amount -= availableProducts.at(productToPurchase).getPrice();

            availableProducts.at(productToPurchase).
                setQuantity(availableProducts.at(productToPurchase).getQuantity() - 1);

            cout << "Your product \"" << availableProducts.at(productToPurchase).getName();
            cout <<"\" has been delivered!\n";
        } else{
            cout << "You don't have enough money to purchase this product!\n";
        }
    }

    if(amount > 0) {
        cout << "You cannot purchase any other product with the money left!\n";
        cout << "Delivering a change of " << amount << " dollars\n";
    }

    cout << "Thank you for your purchase! Have a nice day!\n";
}

bool VendingMachine::checkStock(int pickedProduct) {
    return !(availableProducts.at(pickedProduct).getQuantity() == 0);
}

/**
 * Checks if the length of the cardNumber is 16 and the length of the PIN is 4
 */ 
bool VendingMachine::checkCardInfo(string cardNumber, string pin) {
    return cardNumber.size() == 16 && pin.size() == 4;
}