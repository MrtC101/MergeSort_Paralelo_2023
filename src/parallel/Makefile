secuential.x: ../common/FileReader.o ../common/FilePrinter.o MergeSortMPI.o
	@echo Generating executable merge sort with mpi
	mpic++ ../common/FileReader.o ../common/FilePrinter.o MergeSortMPI.o -o mergempi.x

MergeSortMPI.o: ../common/FileReader.h ../common/FilePrinter.h MergeSortMPI.cpp
	@echo MergeSortMPI.o
	mpic++ -c MergeSortMPI.cpp

FilePrinter.o: ../FilePrinter.cpp
	@echo ../common/FilePrinter.o
	g++ -c ../common/FilePrinter.cpp -o ../common/FilePrinter.o

FileReader.o: ../common/FileReader.cpp
	@echo ../common/FileReader.o
	g++ -c ../common/FileReader.cpp -o ../common/FileReader.o
