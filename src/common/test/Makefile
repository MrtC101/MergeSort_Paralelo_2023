test: ../FileReader.o ../FilePrinter.o test.o
	@echo Generating executable test
	g++ ../FileReader.o ../FilePrinter.o test.o -o test

test.o: ../FileReader.h ../FilePrinter.h test.cpp 
	@echo test.o
	g++ -c test.cpp

FileReader.o: ../FileReader.cpp
	@echo ../FileReader.o
	g++ -c ../FileReader.cpp -o ../FileReader.o

FilePrinter.o: ../FilePrinter.cpp
	@echo ../FilePrinter.o
	g++ -c ../FilePrinter.cpp -o ../FilePrinter.o
