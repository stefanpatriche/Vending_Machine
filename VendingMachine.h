#include "Product.h"

#ifndef _VENDING_MACHINE_H_
#define _VENDING_MACHINE_H_

class VendingMachine {
    vector<Product> availableProducts;
    int currentPaymentMethod;            // 1 - card / 2 - cash
    int maxProductIndex;
    int minPrice;
    
public:
    VendingMachine(){}
    void readProducts();
    void showAvailableProducts();
    void pickPaymentMethod();
    void cardPayment();
    void cashPayment();
    bool checkStock(int);
    
};

#endif