CC = clang
CFLAGS = -Wall -g -std=c99

TARGET = memofibo


SRCS = memofibo.c fibonacci.c
OBJS = $(SRCS:.c=.o)


all: $(TARGET)


$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -rf $(OBJS) $(TARGET) *.dSYM
