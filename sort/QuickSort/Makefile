CFLAGS = -O3 -std=c++11
CFLAGS = -g -Wall -std=c++11

QuickSort: MAKEFLAGS = $(CFLAGS)

QuickSort: main.o quickSort.o
		g++ -o $@ $(MAKEFLAGS) main.o quickSort.o

main.o: main.cpp quickSort.hpp
		g++ -c $(MAKEFLAGS)  main.cpp 

quickSort.o: quickSort.cpp quickSort.hpp
		g++ -c $(MAKEFLAGS) quickSort.cpp


 clean:
		rm -f *.o QuickSort