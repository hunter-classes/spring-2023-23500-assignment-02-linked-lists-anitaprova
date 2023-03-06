OBJECTS=List.o main.o Node.o OList.o
CXXFLAGS=-g

main: $(OBJECTS)
	g++ -g -o main $(OBJECTS)

tests: tests.o
	g++ -o tests tests.o

main.o: main.cpp List.h Node.h OList.o

OList.o: OList.cpp Node.h OList.h

List.o: List.cpp Node.h List.h

Node.o: Node.cpp Node.h

clean:
	rm -f main tests $(OBJECTS)
