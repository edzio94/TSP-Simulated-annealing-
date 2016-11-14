//
// Created by lukasz on 11/5/16.
//

#include <cstdio>
#include <iostream>
#include <cstdlib>
#include "MenuTSPManager.h"
#include "../FileReader/FileLoader.h"
#include "../TSP/TSPAnnealing.h"


MenuTSPManager::MenuTSPManager() {

}

void MenuTSPManager::showMainMenu() {
    do{
    printf("\n====== MAIN MENU ======\n");
    printf("1. Traveling salesman problem [Symetric]\n");
    printf("2. Traveling salesman problem [Asymetric]\n");
    printf("3. Exit \n");
    printf("Choose option: ");
    std::cin >> optionMenu;
    switch(optionMenu) {
        case 1: {
            syncTSPMenu();
            break;
        }
        case 2: {
            asyncTSPMenu();
            break;
        }
        case 3: {
            exit(0);
        }
    }
    }while(1);
}


void MenuTSPManager::syncTSPMenu() {
    printf("Give filename\n");
    std::string fileName;
    std::cin >> fileName;
    if(fileName.find("_TSP.txt")!= std::string::npos){
        fileLoader = FileLoader(fileName);
        if(fileLoader.file.is_open()) {
            int size;
        dataVector = loadDataToVector();
            printf("change cooling ratio (< 0  = default[0.999]):");
            std::cin >> temp;
            tspAnnealing.setCoolingRate(temp);
        tspAnnealing.insertDataToArrayLowerTriangleMatrixSymetric(dataVector);
        tspAnnealing.getResult();
        } else
            printf("Cannot open a file \n");
    } else {
        printf("Wrong file ! \n");
    }
}

void MenuTSPManager::asyncTSPMenu() {
    printf("Give filename\n");
    std::string fileName;
    std::cin >> fileName;
    if(fileName.find("_ATSP.txt")!= std::string::npos){
        fileLoader = FileLoader(fileName);
        if(fileLoader.file.is_open()){
        dataVector = loadDataToVector();
            printf("change cooling ratio (< 0  = default[0.999]):");
            std::cin >> temp;
            tspAnnealing.setCoolingRate(temp);
        tspAnnealing.insertDataToArrayFullMatrixAsymetric(dataVector);
        tspAnnealing.getResult();
        } else
            printf("Cannot open file \n");
    } else {
        printf("Wrong file ! \n");
    }

}


std::vector<int> MenuTSPManager::loadDataToVector() {
    std::vector<int>x;
    if(fileLoader.file.is_open()) {
        int size;
        fileLoader.file >> size;
        int data;
        tspAnnealing = TSPAnnealing(size);

        while(fileLoader.file >> data) {
            x.push_back(data);
        }

    } else {
        printf("Cannot open a file \n");
    }
    return x;
}

