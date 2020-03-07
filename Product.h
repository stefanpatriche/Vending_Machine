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

class Product {
    string name;
    int price;
    int quantity;

public:
    Product(){};
    Product(string, int, int);
    friend ostream &operator<<(ostream &, const Product &);
    friend istream &operator>>(istream &, Product &); 
    string setName(string);
    string getName();
    int setPrice(int);
    int getPrice();
    int setQuantity(int);
    int getQuantity();
    bool operator<(const Product &);
};

#endif