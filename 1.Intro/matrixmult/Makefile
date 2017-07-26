# FILE
TARGET = matrixmult
EXT = .c
COMPILER = g++

# CFLAGS
# -O3 Compiler optimization
# -fopenmp OpenMP library
CFLAGS = -fopenmp

run: compile
	@date | tee Time.txt
	@echo "\nT.Real(sg) \t T.Usuario(sg) \t T.Kernel(sg) \t CPU \t Memoria(KB)" | tee -a Time.txt
	@/usr/bin/time -f "%e \t\t %U \t\t %S \t\t %P \t %M" ./$(TARGET) 2>&1 | tee -a Time.txt
compile:
	@$(COMPILER) $(TARGET)$(EXT) -o $(TARGET) $(CFLAGS)

clean:
	@rm -rf *.txt $(TARGET)
