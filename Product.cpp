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

    return dev;

}

void Product::setName(string name) {
    this->name = name;
}

string Product::getName() const {
    return name;
}

void Product::setPrice(int price) {
    this->price = price;
}

int Product::getPrice() const {
    return price;
}

void Product::setQuantity(int quantity) {
    this->quantity = quantity;
}

int Product::getQuantity() const {
    return quantity;
}

istream &operator>>(istream &dev, Product &product) {
    dev >> product.name;
    dev >> product.price;
    dev >> product.quantity;
    return dev;
}

bool Product::operator<(const Product &product) {
    return (this->price < product.price);
}