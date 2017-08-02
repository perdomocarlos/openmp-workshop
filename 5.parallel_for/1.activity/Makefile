# FILE
TARGET = for
EXT = .c
COMPILER = g++

# CFLAGS
# -O3 Compiler optimization
# -fopenmp OpenMP library
CFLAGS = -std=gnu++11 -O3

run: compile
	@./$(TARGET)
	
compile:
	@$(COMPILER) $(TARGET)$(EXT) -o $(TARGET) $(CFLAGS)

clean:
	@rm -rf *.txt $(TARGET)
