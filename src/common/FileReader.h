#ifndef FILEREADER_H
#define FILEREADER_H

#include <iostream>
#include <fstream>
#include <string>
#include <list>

class FileReader{
    private:
        std::ifstream file;
        std::string line;
        std::string filename;
        char delimiter;
    public:
        FileReader();
        FileReader(const std::string& filename);
        void to_list(std::list<int> &list);
        void get_list(std::list<int> &list);
};

#endif
