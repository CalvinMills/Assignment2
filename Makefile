CC=g++
CXXFLAGS = -std=c++11

LIBDIR=-L./
LDFLAGS=$(LIBDIR)
SOURCES=driver.cpp parsetree.cpp node.cpp tree_iterator.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=driver


all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC)  $(OBJECTS) $(CXXFLAGS) -o $(EXECUTABLE) $(LDFLAGS) -Wl,-rpath=./

run:
	./driver

clean:
	rm *.o $(EXECUTABLE)
