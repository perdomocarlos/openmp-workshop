# FILE
TARGET = sections
EXT = .c
COMPILER = g++

# Compiler optimizations -O3
# Give a compiler optimizations feedback -fopt-info-all
# OpenMP library -fopenmp
CFLAGS = -std=gnu++11 -O3

# Run in debug mode
run:  compile
	./$(TARGET)

compile:
	@$(COMPILER) $(TARGET)$(EXT) -o $(TARGET) $(CFLAGS)

clean:
	@rm -rf $(TARGET) *.txt

