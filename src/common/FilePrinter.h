#ifndef FILEPRINTER_H
#define FILEPRINTER_H

#include <iostream>
#include <fstream>
#include <vector>

class FilePrinter{
    private:
        std::ofstream file;
        std::string filename;
    public:
        FilePrinter();
        FilePrinter(const std::string filename);
        void save(int size_list, int size_nodes, double time);
        void save_list(std::vector<int> &L);
        void end_write();
};

#endif
