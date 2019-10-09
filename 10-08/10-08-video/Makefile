# thing_I_want: space-separated ingredients to make that thing
	# TAB!!!
	# terminal commands to make
	# that thing

# $^ = ingredients list
# $@ = name of the "target" (the thing to the left of the colon)

CXX=g++

vectors: vectors.cpp
	# g++ -std=c++11 vectors.cpp -o vectors
	$(CXX) -std=c++11 $^ -o $@

pointers: pointers.cpp
	g++ pointers.cpp -o pointers

TestLinkedList: TestLinkedList.cpp LinkedList.cpp
	g++ TestLinkedList.cpp LinkedList.cpp -o TestLinkedList