#include <iostream>
#include <fstream>
#include <string>
#include <list>

class FileReader {

private:
    std::ifstream file;
    std::string line;
    char delimiter;

public:
    FileReader(const std::string filename): delimiter{' '}{
        file.open(filename);
        
        if (!file.is_open()) {
            std::cout << "Failed to open the file." << std::endl;
        }
    }

    void toList(std::list<int> &list) {
        std::string::size_type start = 0;
        std::string::size_type end = line.find(delimiter);

        while (end != std::string::npos) {
            list.push_back(std::stoi(line.substr(start, end - start)));
            start = end + 1;
            end = line.find(delimiter, start);
        }

        list.push_back(std::stoi(line.substr(start)));
    }

    void getList(std::list<int> &list) {

        if (std::getline(file, line)) {
            toList(list);
            return;
        }
        file.close();
    }
};

