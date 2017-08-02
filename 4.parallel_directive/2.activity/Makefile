# FILE
TARGET = parallel
EXT = .c
COMPILER = g++

# CFLAGS
# -O3 Compiler optimization
# -fopenmp OpenMP library
CFLAGS = -O3

run: compile
	@clear
	@./$(TARGET)

compile:
	@$(COMPILER) $(TARGET)$(EXT) -o $(TARGET) $(CFLAGS)

clean:
	@rm -rf $(TARGET)
