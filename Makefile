CXX?=g++ 
CXXFLAGS+= --std=c++17 -O3 -Wextra -I.
SOURCES=src/main.cpp src/utils.cpp src/input.cpp src/rectangle.cpp src/coordinateSystem.cpp src/conio.cpp

BUILDDIR=build

ifeq ($(OS),Windows_NT)
	BUILD=win
	DELETE=del
	
	
else
	UNAME_S := $(shell uname -s)
	ifeq ($(UNAME_S),Linux)
		BUILD=linux
		DELETE=rm
		
	endif
endif

src/%.o: src/%.cpp 
	$(CXX) $(CXXFLAGS) -c -o $@ $<

app: $(SOURCES:.cpp=.o)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(BUILDDIR)/$(BUILD) : $(SOURCES:.cpp=.o)
	$(CXX) $(CXXFLAGS) -o $@ $^

build: $(BUILDDIR)/$(BUILD) 

all: app build

clean:
	cd src && $(DELETE) *.o

cleanall: clean
	$(DELETE) app.exe
	cd $(BUILDDIR) && ($(DELETE) $(BUILD).exe | $(DELETE) $(BUILD).exe)
