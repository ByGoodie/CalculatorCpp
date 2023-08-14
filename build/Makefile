CC = g++

all: main.o
	$(CC) main.o Parser.o ../external/gUtils/gUtils.o -o Calculator.out

main.o: Parser.o
	$(CC) -c ../src/main.cpp

Parser.o: 
	$(CC) -c ../src/Parser.cpp

clean:
	rm *.o Calculator.out
