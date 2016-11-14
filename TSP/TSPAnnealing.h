//
// Created by lukasz on 11/5/16.
//

#ifndef TSP_SIMULATED_ANNEALING_TSPANNEALING_H
#define TSP_SIMULATED_ANNEALING_TSPANNEALING_H
#include <vector>
class TSPAnnealing {
public:
    TSPAnnealing();
    TSPAnnealing(int size);

    double temperature;
    double coolingRate = 0.999;
    int size;
    int **distance;

    std::vector<int> result;
    std::vector<int> getResult();
    std::vector<int> bestTour;

    void insertDataToArrayLowerTriangleMatrixSymetric(std::vector<int> x);
    void insertDataToArrayFullMatrixAsymetric(std::vector<int> x);
    void displayData();
    void deleteArray();

    int calucateDistance(std::vector<int> tour);

    double getStartingTemperature();
    void setCoolingRate(double coolingRatio);
private:
    int max,min;
    double delta;
    std::vector<int> generateRandomTour();
    double acceptanceProbability(int energy, int newEnergy, double temperature);
    void printCurrentTour(std::vector<int> x);


};


#endif //TSP_SIMULATED_ANNEALING_TSPANNEALING_H
