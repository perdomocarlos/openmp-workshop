# FILE
TARGET = matrix
EXT = .c
COMPILER = g++

# CFLAGS
# -O3 Compiler optimization
# -fopenmp OpenMP library
CFLAGS = -O3 -fopenmp

run: compile
	@./$(TARGET)
	
compile:
	@$(COMPILER) $(TARGET)$(EXT) -o $(TARGET) $(CFLAGS)

clean:
	@rm -rf *.txt $(TARGET)
