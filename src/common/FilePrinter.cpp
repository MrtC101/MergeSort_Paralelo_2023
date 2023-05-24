#include "FilePrinter.h"
#include <iostream>
#include <fstream>

FilePrinter::FilePrinter(): filename("output.data") {
     file.open(filename.c_str());
     if (!file.is_open()){
         std::cout << "error open file" << std::endl;
     }
}

FilePrinter::FilePrinter(const std::string& filename): filename(filename){
     file.open(filename.c_str());
     if (!file.is_open()){
         std::cout << "error open file" << std::endl;
     }
 }

 void FilePrinter::save(int size_list, int size_nodes, double time){
     file << size_list << "," 
          << size_nodes << "," 
          << time << "\n";
 }

 void FilePrinter::end_write(){
     file.close();
 }
