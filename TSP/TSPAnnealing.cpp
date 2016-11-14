//
// Created by lukasz on 11/5/16.
//

#include <cstdio>
#include <iostream>
#include "TSPAnnealing.h"
#include <math.h>
#include <cstdlib>

using namespace std;
TSPAnnealing::TSPAnnealing() {
}

TSPAnnealing::TSPAnnealing(int size) {

    distance = new int*[size];
    for (int i = 0 ; i < size; i++) {

        distance[i] = new int[size];
    }

    this->size = size;
}



std::vector<int> TSPAnnealing::getResult() {
    temperature = getStartingTemperature();
    result = generateRandomTour();
    bestTour = result;
    int bestDistance = calucateDistance(bestTour);
    while(temperature > 0.0001 ){
        int x1,x2;

        do {
            x1 = rand() % (result.size()-1);
            x2 = rand() % (result.size()-1);

        }while(x1 == x2);
        swap(result[x1],result[x2]);

        if(result[0] != result[result.size() -1]);
            result[result.size() -1] = result[0];

        int newDistance = calucateDistance(result);

        double chance = ((double) rand() / (RAND_MAX));
        if(acceptanceProbability(bestDistance,newDistance,temperature) > chance) {
            bestTour = result;
            bestDistance = calucateDistance(bestTour);
        }
        else {
            result = bestTour;
        }
        temperature *= coolingRate;
    }
   // printCurrentTour(bestTour);
  //  printf("DISTANCE: %d \n",calucateDistance(bestTour));
    result.clear();
return bestTour;
}


double TSPAnnealing::getStartingTemperature() {
    result = generateRandomTour();
    int newDistance = calucateDistance(result);
     min = newDistance;
     max = newDistance;
    int n = 0;
    while(n++ < result.size()*result.size()){
        int x1,x2;
        do {
            x1 = rand() % (result.size()-1);
            x2 = rand() % (result.size()-1);
        }while(x1 == x2);
        swap(result[x1],result[x2]);
        if(result[0] != result[result.size()-1]) {
            result[result.size() - 1] = result[0];
        }

        newDistance = calucateDistance(result);
        if(newDistance > max)
            max = newDistance;
        if(newDistance < min)
            min = newDistance;

    }
    delta = max-min;
    double tmpTemperature = -(delta)/log(coolingRate);
  //  cout << "STARTING TEMP: " << tmpTemperature << endl;
    return tmpTemperature;

}


std::vector<int> TSPAnnealing::generateRandomTour() {
    bool *city = new bool[size];
    for(int i = 0 ; i < size; i++) {
        city[i] = false;
    }
    std::vector<int> tour;
    do {
        int x= rand() % (size) ;
        if(!city[x]){
            tour.push_back(x);
            city[x] = true;
        }
    } while (tour.size() != size);
    tour.push_back(tour[0]);
    delete [] city;
    return tour;
}

void TSPAnnealing::printCurrentTour(vector<int> x) {
    for (int i = 0 ; i < x.size(); i++) {
        if (i != x.size()-1)
            printf("%d -> ",x[i]);
        else
            printf("%d \n",x[i]);
    }
}

double TSPAnnealing::acceptanceProbability(int distance, int newDistance, double temperature) {
    if (newDistance < distance)
        return 1.0;
    return exp(-(newDistance - distance)/ temperature);
}

int TSPAnnealing::calucateDistance(std::vector<int> tour) {
    int sum = 0;
    for(int i = 0 ; i < tour.size() -1; i++) {
        sum+=distance[tour[i]][tour[i+1]];
    }
    return sum;
}

void TSPAnnealing::deleteArray() {
    for(int i = 0 ; i < size; i++ ){
        delete [] distance[i];
    }
    delete [] distance;
}

void TSPAnnealing::insertDataToArrayFullMatrixAsymetric(std::vector<int> x) {
    for(int i = 0 ; i < size; i++){
        for(int j = 0 ; j < size; j++) {
            distance[i][j] = x[i*size+j];
        }
    }
}

void TSPAnnealing::insertDataToArrayLowerTriangleMatrixSymetric(std::vector<int> x) {
    int counter = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < i + 1; j++) {
            distance[i][j] = x[counter];
            distance[j][i] = x[counter++];
        }
    }


}

void TSPAnnealing::displayData() {
    printf("====== DISPLAY DATA =======");
    for(int i = 0 ; i < size; i++){
        for(int j = 0 ; j< size; j++){
            printf("[%d][%d] = [%d]\n",i,j,distance[i][j]);

        }
    }
    for(int i = 0 ; i < size; i++) {
        for (int j = 0; j < size; j++) {


        }
    }
}

void TSPAnnealing::setCoolingRate(double coolingRatio) {
    if(coolingRatio > 0 && coolingRatio < 1) {
        coolingRate = coolingRatio;
    }
}
