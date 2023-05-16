#include <stdio.h>
#include "mergeSort.h"
#include "FileReader.cpp"
#include "FilePrinter.cpp"

int main(){

    list<>* L = FileReader::read();
    L = MergeSort::sort(L);

    return 0;
}