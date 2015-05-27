exe:	main.o Object.o DLLNode.o Integer.o TDAList.o FSArrayList.o LinkedList.o FSCursorList.o
		g++ main.o Object.o DLLNode.o Integer.o TDAList.o FSArrayList.o LinkedList.o FSCursorList.o -o exe
main.o:	main.cpp Object.h TDAList.h FSArrayList.h LinkedList.h
		g++ -c main.cpp
Object.o: Object.h Object.cpp
		g++ -c Object.cpp
DLLNode.o: TDAList.h DLLNode.h DLLNode.cpp
		g++ -c DLLNode.cpp
Integer.o: TDAList.h Integer.h Integer.cpp
		g++ -c Integer.cpp
TDAList.o: Object.h TDAList.h TDAList.cpp
		g++ -c TDAList.cpp
FSArrayList.o: Object.h FSArrayList.h FSArrayList.cpp
		g++ -c FSArrayList.cpp
LinkedList.o: TDAList.h LinkedList.h LinkedList.cpp
		g++ -c LinkedList.cpp
FSCursorList.o: TDAList.h FSCursorList.h FSCursorList.cpp
		g++ -c FSCursorList.cpp