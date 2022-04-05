CC=gcc
CFLAGS=-Wall -Werror -Wextra -std=c99 -pedantic

SRCS=src/*.c
OBJS=$(SRCS:.c=.o)

OUT=out/my_secmalloc.a

all:
	$(CC) $(CFLAGS) $(SRCS) test/main.c

static:
	$(CC) -c $(CFLAGS) $(SRCS) src/
	$(CC) -shared -o $(OBJS) static_lib.so 

dynamic:
	$(CC) -c $(CFLAGS) $(SRCS) -o dynamic_lib.o
	$(CC) -shared -o dynamic_lib.so dynamic_lib.o