objects =  $(libDir)inherited/IComparable/IComparable.o $(libDir)inherited/IComparable/Point.o  app/console_application.o
headers = $(libDir)templated/sort.h
libDir = lib/
CXX = c++.exe
CXXFLAGS += -std=c++17

# Emit debug symbols
main : CXXFLAGS += -g
main : $(objects) $(srcDir)main.o
	$(CXX) $(CXXFLAGS) -o main.exe $(objects) $(srcDir)main.o
# Compile with full optimizations
release: CXXFLAGS += -O3
release :  $(objects) $(srcDir)main.o
	$(CXX) $(CXXFLAGS) -o main.exe $(objects) $(srcDir)main.o
bench : CXXFLAGS += -O3
bench : CXXFLAGS += -DBENCHCOUNT=$(COUNT)
bench : $(objects) app/bench.o
	$(CXX) $(CXXFLAGS) -o main.exe $(objects) app/bench.o

.PHONY : clean
clean :
	-rm **/*.o