
CFLAGS = -std=c99 -Wall -Wextra

check: test
	@./test

test: test.o ms.o
	$(CC) $^ -o $@ $(CFLAGS)

%.o: %.c
	$(CC) $< -c -o $@ $(CFLAGS)

clean:
	rm -f ms.o test.o test

.PHONY: check clean
