CC=gcc
CFLAGS=-Wall -Werror -Wextra -std=c99 -pedantic

SRCSDIR=src
SRCS=*.c
OBJSDIR=obj
OBJS=$(SRCS:.c=.o)

LIBDIR=lib
STATICLIB=my_secmalloc.a
DYNAMICLIB=my_secmalloc.so

all:
	$(CC) $(CFLAGS) $(SRCS) test/main.c

static:
	$(CC) -c $(CFLAGS) $(SRCSDIR)/$(SRCS)
	mv $(OBJS) $(OBJSDIR)
	ar rcs $(LIBDIR)/$(STATICLIB) $(OBJSDIR)/$(OBJS)

dynamic:
	$(CC) -c $(CFLAGS) $(SRCSDIR)/$(SRCS)
	mv $(OBJS) $(OBJSDIR)
	ar rcs $(LIBDIR)/$(DYNAMICLIB) $(OBJSDIR)/$(OBJS)
