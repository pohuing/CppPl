srcDir = app/
libDir = lib/
objects =  $(libDir)inherited/IComparable/IComparable.o $(libDir)inherited/IComparable/Point.o  $(srcDir)/console_application.o
headers = $(libDir)templated/sort.h
CXX = c++.exe
CXXFLAGS += -std=c++17

# Default benchmarking repetition count
ifndef COUNT
	COUNT = 20
endif

# Emit debug symbols
main : CXXFLAGS += -g
main : $(objects) $(srcDir)main.o
	$(CXX) $(CXXFLAGS) -o main.exe $(objects) $(srcDir)main.o
# Compile with full optimizations
release: CXXFLAGS += -O3
release :  $(objects) $(srcDir)main.o
	$(CXX) $(CXXFLAGS) -o main.exe $(objects) $(srcDir)main.o
# A simplistic benchmark build to compare templated and inherited
bench : CXXFLAGS += -O3
bench : CXXFLAGS += -DBENCHCOUNT=$(COUNT)
bench : $(objects) $(srcDir)/bench.o
	$(CXX) $(CXXFLAGS) -o main.exe $(objects) $(srcDir)bench.o

.PHONY : clean
clean :
	-rm **/*.o