#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <fstream>

using namespace std;

#ifndef _PRODUCT_H_
#define _PRODUCT_H_

class Product{
    string name;
    int price;

public:
    Product(){};
    Product(string, int);
    friend ostream &operator<<(ostream &, const Product &);
    friend istream &operator>>(istream &, Product &); 

};

#endif