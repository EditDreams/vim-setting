OBJS  := sort.c sort.h
TARGET = sort
CC  = gcc
LIB =
CFLAG = -Wall -g -o

$(TARGET):$(OBJS)
	$(CC) $(CFLAG) $@ $<

.PHONY:clean
clean:
	rm -rf *.o
