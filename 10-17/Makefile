# thing_I_want: space-separated ingredients to make that thing
	# TAB!!!
	# terminal commands to make
	# that thing

# $^ = ingredients list
# $@ = name of the "target" (the thing to the left of the colon)

CXX=g++

CXXFLAGS=-g -std=c++11

TestLinkedList.o: TestLinkedList.cpp
	g++ -c TestLinkedList.cpp

LinkedList.o: LinkedList.cpp
	g++ -c LinkedList.cpp

TestLinkedList: TestLinkedList.o LinkedList.o
	g++ TestLinkedList.o LinkedList.o -o TestLinkedList

binary_search: binary_search.cpp
	g++ -std=c++11 binary_search.cpp -o binary_search