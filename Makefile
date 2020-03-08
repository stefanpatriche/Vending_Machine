CC = g++
EXEC = vending-machine-exec
FLAGS = -O3 -Wall -Wextra
SOURCES = VendingMachine.cpp Product.cpp main.cpp
OBJECTS = VendingMachine.o Product.o main.o

build: $(OBJECTS)
	$(CC) $(OBJECTS) $(FLAGS) -o $(EXEC)

run: build
	./$(EXEC)

VendingMachine.o: VendingMachine.cpp
	$(CC) $(FLAGS) -c VendingMachine.cpp

Product.o: Product.cpp
	$(CC) $(FLAGS) -c Product.cpp

main.o: main.cpp
	$(CC) $(FLAGS) -c main.cpp

clean:
	rm -rf $(OBJECTS) $(EXEC)