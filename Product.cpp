#include "Product.h"

Product::Product(string name, int price, int quantity){
    this->name = name;
    this->price = price;
    this->quantity = quantity;
}

ostream &operator<<(ostream &dev, const Product &product) {
    dev << "Name of the product: " << product.name << '\n';
    dev << "Price of the product: " << product.price << "$" << '\n';
    dev << "Quantity is: " << product.quantity << '\n';
}

string Product::setName(string name) {
    this->name = name;
}

string Product::getName() {
    return name;
}

int Product::setPrice(int price) {
    this->price = price;
}

int Product::getPrice() {
    return price;
}

istream &operator>>(istream &dev, Product &product) {
    string tempName;
    
    dev >> product.name;
    dev >> tempName;
    dev >> product.price;
    dev >> product.quantity;

    product.name += " ";
    product.name += tempName;
}