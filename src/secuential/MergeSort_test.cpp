#include <list>
#include <iostream>
#include <random>
#include "MergeSort.cpp"

int main(){
    std::list<int> L;
    for(int i = 0;i<300;i++){                                                 
        L.push_back(rand()%100);       
    } 
    MergeSort::print(&L);                                                                    
    MergeSort::sort(&L);
    MergeSort::print(&L);
    return 0;
}