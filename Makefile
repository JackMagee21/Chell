CC      := gcc
CFLAGS  := -Wall -Wextra -O2
TARGET  := main
SRCS    := main.c commands.c inputs.c

.PHONY: all clean install

all: $(TARGET)

$(TARGET): $(SRCS) commands.h inputs.h
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

clean:
	rm -f $(TARGET)

install: $(TARGET)
	./install.sh