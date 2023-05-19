#ifndef FILEPRINTER_H
#define FILEPRINTER_H

#include <iostream>
#include <fstream>

class FilePrinter{
    private:
        std::ofstream file;
        std::string filename;
    public:
        FilePrinter();
        FilePrinter(const std::string filename);
        void save(int size_list, int size_nodes, double time);
        void end_write();
};

#endif
