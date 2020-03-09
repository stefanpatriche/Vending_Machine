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
     * Vector that holds all of the products
     */
    vector<Product> availableProducts;

    /**
     * Product numbers start from 1 in ascending order
     * and this variable holds the last product index
     */ 
    int maxProductIndex;

    /**
     * Holds the minimum price from the list of product
     * for the cash payment method, when the amount of money
     * is below this value, the purchase cannot continue
     */
    int minPrice;

public:
    VendingMachine(){}
    // Reads the products from the available_products.txt file
    void readProducts();
    // Outputs the products held in the availableProducts vector to the console
    void showAvailableProducts();
    // Lets the user decide what payment method they want to use
    void pickPaymentMethod();
    // Checks if there are any more products left to be sold
    bool checkEmptyMachine();
    
private:
    // Processes the card payments
    void cardPayment();
    // Processes the cash payments
    void cashPayment();
    // Checks if a product is in stock
    bool checkStock(int);
    // Checks the card information entered
    bool checkCardInfo(string, string);
};

#endif