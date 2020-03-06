#include "VendingMachine.h"

int main() {
    VendingMachine v;
    v.readProducts();
    v.showAvailableProducts();
    v.pickPaymentMethod();
    return 0;
}