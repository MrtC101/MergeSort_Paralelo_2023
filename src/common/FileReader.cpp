#include "FileReader.h"

#include <iostream>
#include <fstream>
#include <string>
#include <list>

FileReader::FileReader(): FileReader("input.data"){}

FileReader::FileReader(const std::string filename): filename{filename},
                                        delimiter{' '}{
    file.open(filename);
    
    if (!file.is_open()) {
        std::cout << "Failed to open the file." << std::endl;
    }
}

// move to private and test
void FileReader::to_list(std::list<int> &list) {
    std::string::size_type start = 0;
    std::string::size_type end = line.find(delimiter);

    while (end != std::string::npos) {
        list.push_back(std::stoi(line.substr(start, end - start)));
        start = end + 1;
        end = line.find(delimiter, start);
    }

    list.push_back(std::stoi(line.substr(start)));
}

void FileReader::get_list(std::list<int> &list) {

    if (std::getline(file, line)) {
        to_list(list);
        return;
    }
    file.close();
}

