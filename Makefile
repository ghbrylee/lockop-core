CC = gcc
CFLAGS = -W -Wall
TARGET = lockopd
OBJECTS = main.o

all : $(TARGET)

$(TARGET) : $(OBJECT)
		$(CC) $(CFLAGS) -o $@ $^

clean:
		rm $(OBJECT) $(TARGET)