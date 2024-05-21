all: transc.o
	g++ transc.o test.cpp -o test

transc.o: transc.hpp
	g++ -c transc.cpp

clean-linux:
	rm -rf *.o *.exe

clean:
	del /s /q *.o *.exe