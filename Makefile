objects = $(srcDir)main.o $(libDir)inherited/IComparable/IComparable.o $(libDir)inherited/IComparable/Point.o  app/console_application.o
headers = $(libDir)templated/sort.h
libDir = lib/
CXX = c++.exe
main : CXXFLAGS += -std=c++17
main : $(objects)
	$(CXX) $(CXXFLAGS) -o main.exe $(objects)
release : $(objects)
	$(CXX) $(CXXFLAGS) -O3 -o main.exe $(objects)
.PHONY : clean
clean :
	-rm $(objects)