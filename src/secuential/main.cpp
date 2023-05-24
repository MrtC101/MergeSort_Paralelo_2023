#include "../common/FileReader.h"
#include "../common/FilePrinter.h"
#include "MergeSort.cpp"

#include <iostream>
#include <list> 
#include <time.h>

int main(int argc, char *argv[]){

    std::string path = "../../data/input.data";
    FileReader input(path);
    FilePrinter output;
    clock_t start, end;
    double duration;

    std::list<int> L;

    input.get_list(L);

    while (!(L.empty())) {                                                 
        start = clock();

        // merge sort ---------------------------------------- 
        MergeSort::sort(&L);
        // ---------------------------------------------------  
        end = clock();
        duration = (double) (end - start) / CLOCKS_PER_SEC;

        // write in file
        output.save(L.size(), 1, duration);

        L.clear();
        input.get_list(L);                                                 
    }                                                                           

    // important! close the file
    output.end_write();

    return 0;
}

