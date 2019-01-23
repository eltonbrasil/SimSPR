# Elton B. Costa, January 21, 2019
# A fairly simple GCC Makefile linked with Octave

makefile:

help:
	@echo "Type make all to compile your testbench using GCC tools linked to Octave"
	@echo "If compilation is done, type make run"
	@echo "If you want to clean, type make clean"
	@echo "If you want to plot, type make plot then load 'out.gnu' "

all: testbench

plot:
	gnuplot

clean:
	-rm testbench.o testbench
	rm -i .*

testbench:
	mkoctfile testbench.cpp --link-stand-alone -o testbench

run:
	./testbench

testbench.o: testbench.cpp
	g++ -g -I$(OCTAVE_INCLUDE)
	-I$(OCTAVE_INCLUDE)octave -o testbench.o testbench.cpp