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
	# the above terminal command forces g++ to recompile both input .cpp
	# files, even if only one of them changed

memerrors: memerrors.o
	g++ memerrors.o -o memerrors

# this compiles but does not link!
# .o files are nice because you don't have to recompile them
# if you make no changes
memerrors.o: memerrors.cpp
	g++ -c memerrors.cpp