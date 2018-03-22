CXXFLAGS = -Wall -g

PROG = test

FONT = test.cpp

OBJECT = $(FONT:.cpp=.o)

$(PROG): $(OBJECT)
	g++ $(CXXFLAGS) $(OBJECT) -o $@

clean:
	-@ rm -f $(OBJECT) $(PROG)