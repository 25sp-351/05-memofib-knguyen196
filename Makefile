CC = clang
CFLAGS = -Wall -g -D_CRT_SECURE_NO_WARNINGS
LDFLAGS =

TARGET = memofibo
SRCS = memofibo.c
OBJS = memofibo.o

all: $(TARGET)

$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) -c $< -o $@


$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

clean:
	rm -f $(TARGET) $(OBJS)
