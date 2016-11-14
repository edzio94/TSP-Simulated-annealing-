//
// Created by lukasz on 11/5/16.
//

#ifndef TSP_SIMULATED_ANNEALING_MENU_H
#define TSP_SIMULATED_ANNEALING_MENU_H


#include <vector>
#include "../FileReader/FileLoader.h"
#include "../TSP/TSPAnnealing.h"

class MenuTSPManager {
public:
   void showMainMenu();
    void asyncTSPMenu();
    void syncTSPMenu();
    std::vector<int> loadDataToVector();
    MenuTSPManager();
    FileLoader fileLoader;
    TSPAnnealing tspAnnealing;
private:
    std::vector<int> dataVector;
    int optionMenu;
    double temp = -1;
};


#endif //TSP_SIMULATED_ANNEALING_MENU_H
