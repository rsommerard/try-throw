CC	= gcc
CFLAGS	= -Wall -Werror -pedantic -m32
DSOBJS	= display_stack.o
TMOBJS	= try.o try_mul.o
DSEXEC	= display_stack
TMEXEC	= try_mul

all: $(DSEXEC) $(TMEXEC)

display_stack: $(DSOBJS)
	$(CC) $(DSOBJS) -o $@

try_mul: $(TMOBJS)
	$(CC) $(TMOBJS) -o $@

display_stack.o: display_stack.c
try.o: try.c try.h
try_mul.o: try_mul.c try.h

.PHONY: clean
clean:
	rm -f $(DSOBJS) $(TMOBJS) $(DSEXEC) $(TMEXEC) *.~
