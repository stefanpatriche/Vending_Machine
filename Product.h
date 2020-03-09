#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <unistd.h>

using namespace std;

#ifndef _PRODUCT_H_
#define _PRODUCT_H_

/**
 * This class contains all the information relevant for a product
 * in this vending machine. It hold the name, price and quantity left
 * for a specific product.
 */
class Product {
    string name;
    int price;
    int quantity;

public:
    Product(){};
    Product(string, int, int);
    friend ostream &operator<<(ostream &, const Product &);
    friend istream &operator>>(istream &, Product &); 
    void setName(string);
    string getName() const;
    void setPrice(int);
    int getPrice() const;
    void setQuantity(int);
    int getQuantity() const;
    bool operator<(const Product &);
};

#endif