OBJECTS=List.o main.o Node.o OList.o

main: $(OBJECTS)
	g++ -g -o main $(OBJECTS)

tests: tests.o
	g++ -g -o tests tests.o

main.o: main.cpp List.h Node.h OList.o

tests.o: tests.cpp doctest.h OList.o

OList.o: OList.cpp OList.h Node.h 

List.o: List.cpp List.h Node.h 

Node.o: Node.cpp Node.h

clean:
	rm -f main tests $(OBJECTS)
