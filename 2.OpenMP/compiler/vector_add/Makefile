# FILE
TARGET = vector_add
EXT = .c
COMPILER = g++

# Compiler optimizations -O3
# Checking compiler loops optimizations -fopt-info-loop
CFLAGS = -std=gnu++11 -O3 -fopt-info-loop
# Run in debug mode
run:  compile
	@clear
	@date | tee Time.txt
	@echo "\n\t N \t\t\t Estado \tT.Real(sg) \t T.Usuario(sg) \t T.Kernel(sg) \t CPU \t Memoria(KB)" | tee -a Time.txt
	@/usr/bin/time -f "%e \t\t %U \t\t %S \t\t %P \t %M" ./$(TARGET)  2>&1 | tee -a Time.txt

compile:
	@$(COMPILER) $(TARGET)$(EXT) -o $(TARGET) $(CFLAGS) 2>Optimizations.txt

clean:
	@rm -rf $(TARGET) *.txt

