CC = g++
EXEC = vending-machine-exec
SOURCES=$(wildcard *.cpp)
OBJECTS=$(addsuffix .o, $(basename ${SOURCES}))

build: vendingmachine.o product.o main.o
	$(CC) $(OBJECTS) -o $(EXEC)

vendingmachine.o: VendingMachine.cpp
	$(CC) -c VendingMachine.cpp

product.o: Product.cpp
	$(CC) -c Product.cpp

main.o: main.cpp
	$(CC) -c main.cpp

run: build
	./$(EXEC)

clean:
	rm -rf $(OBJECTS) $(EXEC)