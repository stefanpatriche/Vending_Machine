#include "VendingMachine.h"

int main() {
    VendingMachine v;
    v.readProducts();

    while(1) {
        v.showAvailableProducts();

        if(v.checkEmptyMachine()) {
            cout << "The machine is empty!\n";
            return -1;
        }

        v.pickPaymentMethod();

        // this leaves a bit of time for the user to 
        // read the information of the last purchase
        sleep(5);

        // clear the terminal output
        cout << "\033[2J\033[1;1H";
    }

    return 0;
}