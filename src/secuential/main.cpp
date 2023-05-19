#include "../common/FileReader.h"
#include "../common/FilePrinter.h"
#include "MergeSort.cpp"

#include <iostream>
#include <list> 
#include <chrono>

int main(int argc, char *argv[]){

    std::string path = "../../data/input.data";
    FileReader input(path);
    FilePrinter output;

    std::list<int> L;

    input.get_list(L);

    while (!(L.empty())) {                                                 
        auto start = std::chrono::system_clock::now();

        // merge sort ---------------------------------------- 
        MergeSort::sort(&L);
        // ---------------------------------------------------  
        auto end = std::chrono::system_clock::now();
        std::chrono::duration<float,std::milli> duration = end - start;

        // write in file
        output.save(L.size(), 1, duration.count());

        L.clear();
        input.get_list(L);                                                 
    }                                                                           

    // important! close the file
    output.end_write();

    return 0;
}

