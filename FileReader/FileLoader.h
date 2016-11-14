//
// Created by lukasz on 10/29/16.
//

#ifndef TSP_SIMULATED_ANNEALING_FILELOADER_H
#define TSP_SIMULATED_ANNEALING_FILELOADER_H

#include <iostream>
#include <fstream>

class FileLoader {
public:
    std::string filePath;
    std::fstream file;
    FileLoader(const std::string &filePath);
    FileLoader();

private:

};


#endif //TSP_SIMULATED_ANNEALING_FILELOADER_H
