CC = gcc

TARGET = main

CFLAGS = -std=c99 -O0 -g -Wall -Wpedantic -Wextra -Werror
# CFLAGS = -std=c99 -O0 -g -Wall -Wpedantic -Wextra -Werror -fsanitize=address 

main1:
	$(CC) $(CFLAGS) \
	./Array/Array.c \
	./AVLTree/AVLTree.c \
	./BinarySearchTree/BinarySearchTree.c \
	./CircularQueue/CircularQueue.c \
	./Deque-Array/Deque-Array.c \
	./Deque-LinkedList/Deque-LinkedList.c \
	./DynamicArray/DynamicArray.c \
	./Graph-AdjacencyList/Graph-AdjacencyList.c \
	./Graph-AdjacencyMatrix/Graph-AdjacencyMatrix.c \
	./HashTable-OpenAddressing/HashTable-OpenAddressing.c \
	./HashTable-SeparateChaining/HashTable-SeparateChaining.c \
	./LinkedList/LinkedList.c \
	./Matrix/Matrix.c \
	./PriorityQueue-Array/PriorityQueue-Array.c \
	./PriorityQueue-LinkedList/PriorityQueue-LinkedList.c \
	./Queue-Array/Queue-Array.c \
	./Queue-LinkedList/Queue-LinkedList.c \
	./RedBlackTree/RedBlackTree.c \
	./Stack-Array/Stack-Array.c \
	./Stack-LinkedList/Stack-LinkedList.c \
	./main.c \
	-o $(TARGET)

clean:
	rm $(TARGET)
