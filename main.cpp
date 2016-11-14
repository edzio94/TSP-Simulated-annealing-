#include <iostream>
#include "FileReader/FileLoader.h"
#include "TSP/TSPAnnealing.h"
#include "Menu/MenuTSPManager.h"
#include "TimeTest/TimeTest.h"
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;
int main() {
    srand(time(NULL));
//    MenuTSPManager manager;
//    manager.showMainMenu();
    TimeTest test;
    test.testSync(10,"17_TSP.txt");
    test.testSync(10,"48_TSP.txt");
    test.testSync(10,"120_TSP.txt");

    return 0;
}