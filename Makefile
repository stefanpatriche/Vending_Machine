build: main.cpp Product.h Product.cpp VendingMachine.cpp VendingMachine.h
	g++ main.cpp Product.h Product.cpp VendingMachine.cpp VendingMachine.h -o vending-machine-exec

run: build
	./vending-machine-exec