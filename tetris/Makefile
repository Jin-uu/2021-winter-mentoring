CC = gcc
TARGET = a.out
OBJS = controller.o model.o view.o queue.o
SRCS = controller.c model.c view.c queue.c
OPT = -Wall -pedantic
LIB = -lncurses

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $^ $(OPT) $(LIB)

run:
	./$(TARGET)

.c.o:
	$(CC) -c -o $@ $<

test: all run

clean:
	rm -f $(OBJS)
	rm -f $(TARGET)

debug:
	$(CC) -g $(SRCS) -o $(TARGET) $(OPT) $(LIB)
