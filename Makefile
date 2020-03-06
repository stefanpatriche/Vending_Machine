build: main.cpp Product.h Product.cpp
	g++ main.cpp Product.h Product.cpp -o vending-machine-exec

run: build
	./vending-machine-exec