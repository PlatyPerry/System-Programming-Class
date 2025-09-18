CC=gcc
CFLAGS=-Wall -g

all: fork_example exec_example fork_exec_example

fork_example: fork_example.c
	$(CC) $(CFLAGS) -o fork_example fork_example.c

exec_example: exec_example.c
	$(CC) $(CFLAGS) -o exec_example exec_example.c

fork_exec_example: fork_exec_example.c
	$(CC) $(CFLAGS) -o fork_exec_example fork_exec_example.c

clean:
	rm -f fork_example exec_example fork_exec_example

run: all
	@echo "=== Running fork_example ==="
	./fork_example
	@echo ""
	@echo "=== Running exec_example ==="
	./exec_example
	@echo ""
	@echo "=== Running fork_exec_example ==="
	./fork_exec_example

.PHONY: all clean run
