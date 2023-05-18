#include <list>
#include <iostream>
#include "MergeSort.cpp"

int main(){
    std::list<int> L;
    for(int i = 0;i<10;i++){                                                 
        L.push_back(i+1);       
    } 
    MergeSort::print(&L);                                                                    
    MergeSort::sort(&L);
    MergeSort::print(&L);
    return 0;
}