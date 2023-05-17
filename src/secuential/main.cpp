#include <stdio.h>
#include <list> 
#include "mergeSort.h"
#include <time.h>
#include "FileReader.cpp"
#include "FilePrinter.cpp"
#using namespace

int main(){
    FileReader inputData(filename);
    std::list<int> L;
    inputData.getList(&L);

    // print data (test)---------------------------------------- 
    while (!(myList.empty())) {                                                 
        for (int elemento : myList) {                                           
            std::cout << elemento << " ";                                       
        }                                                                       
        std::cout << std::endl;                                                 
        myList.erase(myList.begin(), myList.end());                             
        reader.getList(myList);                                                 
    }                                                                           
    std::cout << std::endl;
    // end print data---------------------------------------- 

    start = time();
    L = MergeSort::sort(L);
    end = time();
    FilePrinter::save(L)
    return 0;
}
