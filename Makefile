CC=gcc
CFLAGS=-Wall -Werror -Wextra -pedantic -fcommon -fvisibility=hidden

SRCSDIR=src
SRCS=*.c
OBJSDIR=obj
OBJS=$(SRCS:.c=.o)

LIBDIR=lib
STATICLIB=libmy_secmalloc.a
DYNAMICLIB=libmy_secmalloc.so

TESTDIR=test

all: init clean build static dynamic testbuild

init:
	-mkdir logs obj lib

build:
	$(CC) $(CFLAGS) $(SRCSDIR)/$(SRCS) test/test.c -o $(TESTDIR)/test

static:
	$(CC) -c $(CFLAGS) $(SRCSDIR)/$(SRCS)
	mv $(OBJS) $(OBJSDIR)
	ar rcs $(LIBDIR)/$(STATICLIB) $(OBJSDIR)/$(OBJS)

dynamic:
	$(CC) -c $(CFLAGS) $(SRCSDIR)/$(SRCS)
	mv $(OBJS) $(OBJSDIR)
	ar rcs $(LIBDIR)/$(DYNAMICLIB) $(OBJSDIR)/$(OBJS)

tests:
	-rm logs/logs.txt
	./$(TESTDIR)/test

clean:
	-rm $(TESTDIR)/test
	-rm logs/logs.txt
	-rm $(OBJSDIR)/*.o
	-rm $(LIBDIR)/*.a
	-rm $(LIBDIR)/*.so