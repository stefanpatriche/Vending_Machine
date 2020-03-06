#include "Product.h"

#ifndef _VENDING_MACHINE_H_
#define _VENDING_MACHINE_H_

class VendingMachine {
    vector<Product> availableProducts;
    
public:
    void readProducts();
};

#endif