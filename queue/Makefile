Node_cpp := ../linked-list/Node.cpp
LinkedList_cpp := ../linked-list/LinkedList.cpp
files :=  Queue.o Node.o LinkedList.o main.o

all: $(files) a.out

Queue.o: Queue.cpp
	g++ -c Queue.cpp -o Queue.o

Node.o: $(Node_cpp)
	g++ -c $(Node_cpp) -o Node.o

LinkedList.o: $(LinkedList_cpp)
	g++ -c $(LinkedList_cpp) -o LinkedList.o

main.o: main.cpp
	g++ -c main.cpp -o main.o

a.out: $(files)
	g++ $(files) -o a.out

clean:
	rm -f $(files) a.out