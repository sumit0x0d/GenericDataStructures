CC = gcc

TARGET = main

CFLAGS = -std=c17 -O0 -g -Wall -Wpedantic -Wextra -Werror 
# ./doubly_linked_list/doubly_linked_list.c \

main1:
	$(CC) $(CFLAGS) \
	./avl_tree/avl_tree.c \
	./binary_search_tree/binary_search_tree.c \
	./binary_tree/binary_tree.c \
	./deque-array/deque-array.c \
	./deque-linked_list/deque-linked_list.c \
	./dynamic_array/dynamic_array.c \
	./graph-adjacency_list/graph-adjacency_list.c \
	./graph-adjacency_matrix/graph-adjacency_matrix.c \
	./queue-array/queue-array.c \
	./queue-linked_list/queue-linked_list.c \
	./red-black_tree/red-black_tree.c \
	./singly_linked_list/singly_linked_list.c \
	./stack-array/stack-array.c \
	./stack-linked_list/stack-linked_list.c \
	./trie/trie.c \
	./main.c \
	-o $(TARGET)

clean:
	rm $(TARGET)
