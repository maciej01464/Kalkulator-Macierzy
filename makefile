CC = gcc
CFLAGS = -Wall -Wextra -std=c11
TARGET = program
SRC = main.c matrix.c matrix_io.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET) $(TARGET).exe