CC = gcc
TARGET = main

CFLAGS = -std=c99 -O0 -g -Wall -Wpedantic -Wextra
# -Werror 
avl_tree:
	$(CC) $(CFLAGS) ./avl_tree/avl_tree.c ./avl_tree/avl_tree-print.c ./avl_tree/test.c -o $(TARGET)

binary_search_tree:
	$(CC) $(CFLAGS) ./binary_search_tree/binary_search_tree.c ./binary_search_tree/binary_search_tree-print.c ./binary_search_tree/test.c -o $(TARGET)

binary_tree:
	$(CC) $(CFLAGS) ./binary_tree/binary_tree.c ./binary_tree/binary_tree-print.c ./binary_tree/test.c -o $(TARGET)

deque-array:
	$(CC) $(CFLAGS) ./deque-array/deque-array.c ./deque-array/deque-array-print.c ./deque-array/test.c -o $(TARGET)

deque-linked_list:
	$(CC) $(CFLAGS) ./deque-linked_list/deque-linked_list.c ./deque-linked_list/deque-linked_list-print.c ./deque-linked_list/test.c -o $(TARGET)

doubly_linked_list:
	$(CC) $(CFLAGS) ./doubly_linked_list/doubly_linked_list.c ./doubly_linked_list/doubly_linked_list-print.c ./doubly_linked_list/test.c -o $(TARGET)

dynamic_array:
	$(CC) $(CFLAGS) ./dynamic_array/dynamic_array.c ./dynamic_array/dynamic_array-print.c ./dynamic_array/test.c -o $(TARGET)

graph-adjacency_list:
	$(CC) $(CFLAGS) ./graph-adjacency_list/graph-adjacency_list.c ./graph-adjacency_list/graph-adjacency_list-print.c ./graph-adjacency_list/test.c -o $(TARGET)

graph-adjacency_matrix:
	$(CC) $(CFLAGS) ./graph-adjacency_matrix/graph-adjacency_matrix.c ./graph-adjacency_matrix/graph-adjacency_matrix-print.c ./graph-adjacency_list/test.c -o $(TARGET)

hash_table:
	$(CC) $(CFLAGS) ./hash_table/test.c -o $(TARGET)

queue-array:
	$(CC) $(CFLAGS) ./queue-array/queue-array.c ./queue-array/queue-array-print.c ./queue-array/test.c -o $(TARGET)

queue-linked_list:
	$(CC) $(CFLAGS) ./queue-linked_list/queue-linked_list.c ./queue-linked_list/queue-linked_list-print.c ./queue-linked_list/test.c -o $(TARGET)

red-black_tree:
	$(CC) $(CFLAGS) ./binary_tree/red-black_tree.c ./binary_tree/red-black_tree-print.c ./red-black_tree/test.c -o $(TARGET)

singly_linked_list:
	$(CC) $(CFLAGS) ./singly_linked_list/singly_linked_list.c ./singly_linked_list/singly_linked_list-print.c ./singly_linked_list/test.c -o $(TARGET)

stack-array:
	$(CC) $(CFLAGS) ./stack-array/stack-array.c ./stack-array/stack-array-print.c ./stack-array/test.c -o $(TARGET)

stack-linked_list:
	$(CC) $(CFLAGS) ./stack-linked_list/stack-linked_list.c ./stack-linked_list/stack-linked_list-print.c ./stack-linked_list/test.c -o $(TARGET)

trie:
	$(CC) $(CFLAGS) ./trie/trie.c ./trie/trie-print.c ./trie/test.c -o $(TARGET)

clean:
	rm $(TARGET)
