#include <stdio.h>
#include <list> 
#include "mergeSort.h"
#include <time.h>
#include "FileReader.cpp"
#include "FilePrinter.cpp"
#using namespace

int main(){
    list<int>* L = FileReader::read();
    start = time();
    L = MergeSort::sort(L);
    end = time();
    FilePrinter::save(L)
    return 0;
}