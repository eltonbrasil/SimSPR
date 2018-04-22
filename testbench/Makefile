# Elton B. Costa, March 22, 2018
# A fairly simple GCC Makefile

# CXXFLAGS = -Wall -g

CXXFLAGS = -std=c++11

PROG = test 

FONT = test.cpp

OBJECT = $(FONT:.cpp=.o)

help:
	@echo "Type make test to compile your testench using GCC tools"
	@echo "If compilation is done, type make run"
	@echo "If you want to clean, type make clean"

$(PROG): $(OBJECT)
	g++ $(CXXFLAGS) $(OBJECT) -o $@
run:
	./test
clean:
	-@ rm -f $(OBJECT) $(PROG)
