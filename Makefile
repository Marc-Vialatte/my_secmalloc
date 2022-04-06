CC=gcc
CFLAGS=-Wall -Wextra -std=c99 -pedantic -fvisibility=hidden 

SRCSDIR=src
SRCS=*.c
OBJSDIR=obj
OBJS=$(SRCS:.c=.o)

LIBDIR=lib
STATICLIB=libmy_secmalloc.a
DYNAMICLIB=libmy_secmalloc.so

all:
	$(CC) $(CFLAGS) $(SRCSDIR)/$(SRCS) test/main.c

static:
	$(CC) -c $(CFLAGS) $(SRCSDIR)/$(SRCS)
	mv $(OBJS) $(OBJSDIR)
	ar rcs $(LIBDIR)/$(STATICLIB) $(OBJSDIR)/$(OBJS)

dynamic:
	$(CC) -c $(CFLAGS) $(SRCSDIR)/$(SRCS)
	mv $(OBJS) $(OBJSDIR)
	ar rcs $(LIBDIR)/$(DYNAMICLIB) $(OBJSDIR)/$(OBJS)
