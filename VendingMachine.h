#include "Product.h"

#ifndef _VENDING_MACHINE_H_
#define _VENDING_MACHINE_H_

/**
 * This class simulates the behaviour of a vending machine.
 * It can read the products from the input file available_products.txt.
 * It accepts payment through both cash and credit card.
 * It can return change at the end of a purchase for cash purchases.
 */
class VendingMachine {
    /**
     * Vector which holds all the products
     */
    vector<Product> availableProducts;   
    int maxProductIndex;
    int minPrice;
    
public:
    VendingMachine(){}
    // Read the products from the available_products.txt file
    void readProducts();
    void showAvailableProducts();
    void pickPaymentMethod();

private:
    void cardPayment();
    void cashPayment();
    bool checkStock(int);
    bool checkCardInfo(string, string);
};

#endif