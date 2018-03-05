CFLAGS = -O3 -std=c++11
CFLAGS = -g -Wall -std=c++11

heapSort: MAKEFLAGS = $(CFLAGS)

heapSort: main.o heap.o	
		g++ -o $@ $(MAKEFLAGS) main.o heap.o

main.o: main.cpp heapsort.hpp
		g++ -c $(MAKEFLAGS) main.cpp

heap.o: heap.cpp heapsort.hpp
		g++ -c $(MAKEFLAGS) heap.cpp


clean: 
		rm -f *.o heapSort

