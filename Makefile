
CFLAGS = -std=c99 -Wall -Wextra -Ideps
SRC = ms.c
DEPS = $(wildcard deps/*/*.c)
OBJS = ms.o $(DEPS:.c=.o)

check: test
	@./test

test: test.o $(OBJS)
	$(CC) $^ -o $@ $(CFLAGS)

%.o: %.c
	$(CC) $< -c -o $@ $(CFLAGS)

clean:
	rm -f $(OBJS) test.o test

.PHONY: check clean
