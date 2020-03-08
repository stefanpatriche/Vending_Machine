#include "VendingMachine.h"

int main() {
    VendingMachine v;
    v.readProducts();

    while(1) {
        v.showAvailableProducts();
        v.pickPaymentMethod();
        sleep(10);

        // clear the terminal output
        cout << "\033[2J\033[1;1H";
    }

    return 0;
}