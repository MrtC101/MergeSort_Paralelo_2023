secuential.x: ../common/FileReader.o ../common/FilePrinter.o MergeSort_MPI.o
	@echo Generating executable merge sort with mpi
	mpic++ ../common/FileReader.o ../common/FilePrinter.o MergeSort_MPI.o -o mergempi.x

MergeSort_MPI.o: ../common/FileReader.h ../common/FilePrinter.h MergeSort_MPI.cpp
	@echo MergeSort_MPI.o
	mpic++ -c MergeSort_MPI.cpp

FilePrinter.o: ../FilePrinter.cpp
	@echo ../common/FilePrinter.o
	g++ -c ../common/FilePrinter.cpp -o ../common/FilePrinter.o

FileReader.o: ../common/FileReader.cpp
	@echo ../common/FileReader.o
	g++ -c ../common/FileReader.cpp -o ../common/FileReader.o
