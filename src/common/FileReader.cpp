#include "FileReader.h"

#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <sstream>
#include <vector>

FileReader::FileReader() : filename("input.data"), delimiter(' ') {
    file.open(filename.c_str());
    
    if (!file.is_open()) {
        std::cout << "Failed to open the file." << std::endl;
    }
}

FileReader::FileReader(const std::string& filename) : filename(filename), delimiter(' ') {
    file.open(filename.c_str());
    
    if (!file.is_open()) {
        std::cout << "Failed to open the file." << std::endl;
    }
}

void FileReader::setPath(const std::string filename) {
    if (file.is_open()) {
        file.close();
    }
    this->filename = filename;
    this->delimiter = ' ';
    file.open(filename.c_str());
    if (!file.is_open()) {
        std::cout << "Failed to open the file." << std::endl;
    }
}

void FileReader::to_list(std::list<int>& list) {
    std::string::size_type start = 0;
    std::string::size_type end = line.find(delimiter);
    int num;

    while (end != std::string::npos) {
        std::istringstream iss(line.substr(start, end - start));
        num = 0;
        iss >> num;
        list.push_back(num);
        start = end + 1;
        end = line.find(delimiter, start);
    }

    std::istringstream iss(line.substr(start));
    num = 0;
    iss >> num;
    list.push_back(num);
}

void FileReader::get_list(std::list<int>& list) {
    if (std::getline(file, line)) {
        to_list(list);
        return;
    }
    file.close();
}

void FileReader::to_vector(std::vector<int> &vector) {
    std::string::size_type start = 0;
    std::string::size_type end = line.find(delimiter);
    int num;

    while (end != std::string::npos) {
        std::istringstream iss(line.substr(start, end - start));
        num = 0;
        iss >> num;
        vector.push_back(num);
        start = end + 1;
        end = line.find(delimiter, start);
    }

    std::istringstream iss(line.substr(start));
    num = 0;
    iss >> num;
    vector.push_back(num);
}

void FileReader::get_vector(std::vector<int> &vector) {
    if (std::getline(file, line)) {
        to_vector(vector);
        return;
    }
    file.close();
}
