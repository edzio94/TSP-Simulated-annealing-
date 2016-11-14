//
// Created by lukasz on 11/6/16.
//

#ifndef TSP_SIMULATED_ANNEALING_TIMETEST_H
#define TSP_SIMULATED_ANNEALING_TIMETEST_H


#include <chrono>
#include "../Menu/MenuTSPManager.h"
#include "../FileReader/FileLoader.h"

class TimeTest {
public:
    MenuTSPManager manager;
    TimeTest();
    std::chrono::steady_clock::time_point start;
    std::chrono::steady_clock::time_point end;
    double testAsync(int times,std::string filename);
    double testSync(int times,std::string filename);
    std::fstream file;
};


#endif //TSP_SIMULATED_ANNEALING_TIMETEST_H
