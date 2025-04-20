CC = gcc
CFLAGS = -Wall -Wextra -Werror
TARGET = main

SRCS = main.c temp_functions.c
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
