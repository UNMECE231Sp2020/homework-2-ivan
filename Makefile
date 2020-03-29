all: main.o class_functions.o
	g++ main.o Complex.o -o RunTest

main.o: main.cpp my_class.hpp
	g++ -c main.cpp

class_functions.o: class_functions.cpp my_class.hpp
	g++ -c class_functions.cpp -o Complex.o

clean:
	rm *.o
	rm RunTest

