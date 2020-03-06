#include "Product.h"

Product::Product(string name, int price){
    this->name = name;
    this->price = price;
}

ostream &operator<<(ostream &dev, const Product &product) {
    dev << "Name of the product: " << product.name << '\n';
    dev << "Price of the product: " << product.price << "$" <<'\n';
}

istream &operator>>(istream &dev, Product &product) {
    string tempName;
    
    dev >> product.price;
    dev >> product.name;
    dev >> tempName;

    product.name += " ";
    product.name += tempName;
} 