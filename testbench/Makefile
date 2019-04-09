# Elton B. Costa, April 9th, 2019
# A fairly simple GCC Makefile linked with Octave

help:
	@echo "Type make test to compile your testbench using GCC tools linked to Octave"
	@echo "If compilation is done, type make run"
	@echo "If you want to clean, type make clean"
	
# Main program target
test:
	mkoctfile testbench.cpp --link-stand-alone -o testbench

# Simulation target
run:
	./testbench

# Remove generated files
clean:
	rm -f testbench.o 
	rm -f testbench	