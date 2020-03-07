#include "VendingMachine.h"

int main() {
    //while(1) {
        VendingMachine v;
        v.readProducts();
        v.showAvailableProducts();
        v.pickPaymentMethod();
    //     sleep(10);
    //     cout << "\033[2J\033[1;1H";
    // }
    return 0;
}