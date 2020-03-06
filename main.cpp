#include "Product.h"

vector<Product> readProducts() {
    fstream input("available_products.txt");
    
    vector<Product> availableProducts;

    if (!input) {
        cout << "Cannot read available products." << '\n';
        exit(7);
    }
    
    Product p;
    
    while(!input.eof()) {
        input >> p;
        availableProducts.push_back(p);
        cout << p;
    }

    return availableProducts;
}

int main() {
    vector<Product> availableProduct (readProducts());
    return 0;
}