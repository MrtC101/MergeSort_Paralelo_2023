secuential.x: ../common/FileReader.o ../common/FilePrinter.o MergeSort.o main.o
	@echo Generating executable secuential
	g++ ../common/FileReader.o ../common/FilePrinter.o MergeSort.o main.o -o secuential.x

main.o: ../common/FileReader.h ../common/FilePrinter.h MergeSort.o main.cpp 
	@echo main.o
	g++ -c main.cpp

MergeSort.o: MergeSort.cpp
	@echo MergeSort.o
	g++ -c MergeSort.cpp

FilePrinter.o: ../FilePrinter.cpp
	@echo ../common/FilePrinter.o
	g++ -c ../common/FilePrinter.cpp -o ../common/FilePrinter.o

FileReader.o: ../common/FileReader.cpp
	@echo ../common/FileReader.o
	g++ -c ../common/FileReader.cpp -o ../common/FileReader.o
