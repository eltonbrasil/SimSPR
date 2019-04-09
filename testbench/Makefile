# Elton B. Costa, January 21, 2019
# A fairly simple GCC Makefile linked with Octave

help:
	@echo "Type make test to compile your testbench using GCC tools linked to Octave"
	@echo "If compilation is done, type make run"
	@echo "If you want to clean, type make clean"
	
# Default target
all: spr_curve.png

# Main program target
test:
	mkoctfile testbench.cpp --link-stand-alone -o testbench

# Simulation target
run:
	./testbench

# Output figure (.png)
spr_curve.png : out.gnu reflectance.dat
	gnuplot -e 'set terminal png size 800,700' $< > $@

# Remove generated files
clean:
	rm -f testbench.o 
	rm -f testbench
	