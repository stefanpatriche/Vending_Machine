#include "Product.h"

Product::Product(string name, int price, int quantity){
    this->name = name;
    this->price = price;
    this->quantity = quantity;
}

ostream &operator<<(ostream &dev, const Product &product) {

    dev << product.name 
        << " costs " << product.price << "$ " 
        << "and there are " << product.quantity << " units available.\n"; 
    
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

int Product::getQuantity() {
    return quantity;
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

bool Product::operator<(const Product &product) {
    return (this->price < product.price);
}