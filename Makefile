# Makefile for SDL2 VGA Simulation Project
# Supports compilation with debugging information

# Compiler settings
CC = clang
CFLAGS = -g -Wall -Wextra -std=c99
LDFLAGS = $(shell sdl2-config --cflags --libs)

# Target executable
TARGET = vgasim

# Source files
SRCS = VGAsim.c sdl2-test1.c
OBJS = $(SRCS:.c=.o)

# Test target
test: $(TARGET)
	@echo "Running SDL2 test..."
	./$(TARGET)

# Default target
all: $(TARGET)

# Main target
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LDFLAGS)

# Pattern rule for .o files
%.o: %.c
	$(CC) $(CFLAGS) $(shell sdl2-config --cflags) -c $< -o $@

# Clean target
clean:
	rm -f $(OBJS) $(TARGET)

# Debug target
debug: CFLAGS += -DDEBUG
debug: clean all

# Run target
run: $(TARGET)
	./$(TARGET)

.PHONY: all clean debug run