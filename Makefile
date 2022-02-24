CC = gcc
TARGET = main

CFLAGS = -std=c17 -O0 -Wall -Werror

dynamic_array.c:
	$(CC) $(CFLAGS) ./dynamic_array/dynamic_array.c ./dynamic_array/test.c -o $(TARGET)

singly_linked_list:
	$(CC) $(CFLAGS) ./singly_linked_list/singly_linked_list.c ./singly_linked_list/test.c -o $(TARGET)

doubly_linked_list:
	$(CC) $(CFLAGS) ./doubly_linked_list/doubly_linked_list.c ./doubly_linked_list/test.c -o $(TARGET)

deque-array:
	$(CC) $(CFLAGS) ./deque/deque-array.c ./deque/test.c -o $(TARGET)

deque-linked_list:
	$(CC) $(CFLAGS) ./deque/deque-linked_list.c ./deque/test.c -o $(TARGET)

queue-array:
	$(CC) $(CFLAGS) ./queue/queue-array.c ./queue/test.c -o $(TARGET)

queue-linked_list:
	$(CC) $(CFLAGS) ./queue/queue-linked_list.c ./queue/test.c -o $(TARGET)

stack-array:
	$(CC) $(CFLAGS) ./stack/stack-array.c ./stack/test.c -o $(TARGET)

stack-linked_list:
	$(CC) $(CFLAGS) ./stack/stack-linked_list.c ./stack/test.c -o $(TARGET)

binary_tree:
	$(CC) $(CFLAGS) ./binary_tree/black_tree.c ./binary_tree/test.c -o $(TARGET)

avl_tree:
	$(CC) $(CFLAGS) ./avl_tree/avl_tree.c ./avl_tree/test.c -o $(TARGET)

binary_search_tree:
	$(CC) $(CFLAGS) ./binary_search_tree/binary_search_tree.c ./binary_search_tree/test.c -o $(TARGET)

red-black_tree:
	$(CC) $(CFLAGS) ./binary_tree/red-black_tree.c ./red-black_tree/test.c -o $(TARGET)

hash_table:
	$(CC) $(CFLAGS) ./hash_table/test.c -o $(TARGET)

clean:
	rm $(TARGET)
