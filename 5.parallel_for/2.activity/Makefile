# FILE
TARGET = vector_add
EXT = .c
COMPILER = g++

# Compiler optimizations -O3
# Give a compiler optimizations feedback -fopt-info-all
# OpenMP library -fopenmp
CFLAGS = -std=gnu++11


# Run in debug mode
run:  compile
	@date | tee Time.txt
	@echo "\n\t N \t\t\t Estado \tT.Real(sg) \t T.Usuario(sg) \t T.Kernel(sg) \t CPU \t Memoria(KB)" | tee -a Time.txt
	@/usr/bin/time -f "%e \t\t %U \t\t %S \t\t %P \t %M" ./$(TARGET)  2>&1 | tee -a Time.txt

compile:
	@$(COMPILER) $(TARGET)$(EXT) -o $(TARGET) $(CFLAGS) 2>Optimizations.txt

clean:
	@rm -rf $(TARGET) *.txt

