#include "../FileReader.h"
#include "../FilePrinter.h"

#include <iostream>
#include <list> 
#include <chrono>

int main(int argc, char** argv){

    std::list<int> myList;
    std::chrono::high_resolution_clock::time_point start, end;
    std::chrono::high_resolution_clock::duration duration;

    FileReader input;
    FilePrinter output;

    input.get_list(myList);

    while (!(myList.empty())) {                                                 
        start = std::chrono::high_resolution_clock::now();
        for (int elemento : myList) {                                           
            std::cout << elemento << " ";                                       
        }                                                                       
        std::cout << std::endl;                                                 
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;

        // write in file
        output.save(myList.size(), 1, duration.count());

        myList.clear();
        input.get_list(myList);                                                 
    }                                                                           

    // important! close the file
    output.end_write();

    return 0;
}
